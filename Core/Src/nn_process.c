#include <stdint.h>
#include <limits.h> // for INT16_MIN, INT16_MAX
#include <stdio.h>
#include "main.h"
#include "stm32h7xx_hal.h"
#include "nn_process.h"
#include "mic.h"
#include "mfcc_q15.h"

#include "nn_process.h"
#include "materials_model.h"
#include "materials_model_data.h"

/* AI objects */
static ai_handle materials_model = AI_HANDLE_NULL;
static ai_buffer *ai_input;
static ai_buffer *ai_output;

/* AI buffers */
AI_ALIGNED(32)
static ai_u8 activations[AI_MATERIALS_MODEL_DATA_ACTIVATIONS_SIZE];
AI_ALIGNED(32)
static float in_data[AI_MATERIALS_MODEL_IN_1_SIZE];
AI_ALIGNED(32)
static float out_data[AI_MATERIALS_MODEL_OUT_1_SIZE];

/**
 * @brief Convert Q15 format MFCC data to float for model inference
 *
 * @param q15_data Pointer to the filled q15_t MFCC data array
 * @param float_data Pointer to float array for storing converted data
 * @param size Size of the arrays (typically 624 for 48x13 MFCC data)
 */
void convert_q15_to_float(const int16_t* q15_data, float* float_data, uint32_t size) {
    // Q15 format uses 16-bit integers scaled to -32768 to 32767
    // Convert to float by dividing by 32768.0f
    for (uint32_t i = 0; i < size; i++) {
        float_data[i] = (float)q15_data[i] / 32768.0f;
    }
}

int aiInit(void)
{
    ai_error err;

    const ai_handle acts[] = { activations };
    err = ai_materials_model_create_and_init(&materials_model, acts, NULL);

    if(err.type != AI_ERROR_NONE)
    {
    	printf("create init failed\r\n");
    }

    ai_input = ai_materials_model_inputs_get(materials_model, NULL);
    ai_output = ai_materials_model_outputs_get(materials_model, NULL);
    printf("ai init finish\r\n");

    return 0;
}

int aiRun(const int16_t* mfcc_q15_data, float* output_data)
{
    /* Convert Q15 MFCC data to float */
    convert_q15_to_float(mfcc_q15_data, in_data, AI_MATERIALS_MODEL_IN_1_SIZE);

    ai_i32 n_batch;
    ai_error error;

    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    n_batch = ai_materials_model_run(materials_model, &ai_input[0], &ai_output[0]);
    if(n_batch != 1)
    {
    	error = ai_materials_model_get_error(materials_model);
    	printf("error value from ai run: %d\r\n", error.code);
    }

    return 0;
}

void do_inference()
{
	aiRun(&mfcc_frame_final[0], out_data);
}
