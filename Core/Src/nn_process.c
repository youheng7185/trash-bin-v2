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
static ai_buffer ai_input[AI_MATERIALS_MODEL_IN_NUM];
static ai_buffer ai_output[AI_MATERIALS_MODEL_OUT_NUM];

/* AI buffers */
AI_ALIGNED(4)
static ai_u8 activations[AI_MATERIALS_MODEL_DATA_ACTIVATIONS_SIZE];
AI_ALIGNED(4)
static float in_data[AI_MATERIALS_MODEL_IN_1_SIZE];
AI_ALIGNED(4)
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

    /* Create the neural network */
    printf("Creating neural network...\n");
    err = ai_materials_model_create(&materials_model, NULL);
    if (err.type != AI_ERROR_NONE) {
        printf("Error creating network: %s (code %d)\n", ai_error_to_str(err), err.code);
        return -1;
    }

    /* Get network info */
    ai_network_report report;
    if (!ai_materials_model_get_report(materials_model, &report)) {
        printf("Error getting network report\n");
        ai_materials_model_destroy(materials_model);
        materials_model = AI_HANDLE_NULL;
        return -2;
    }

    /* Print network info */
    printf("Network created: %s\n", report.model_name);
    printf("Activation size: %u bytes\n", report.activations_size);
    printf("Weights size: %u bytes\n", report.weights_size);
    printf("Memory alignment: %u\n", report.memory_alignment);

    /* Get AI weights */
    const ai_handle weights = ai_materials_model_data_weights_get();
    if (!weights) {
        printf("Error getting weights\n");
        ai_materials_model_destroy(materials_model);
        materials_model = AI_HANDLE_NULL;
        return -2;
    }

    /* Initialize network parameters - METHOD 1: Simple approach */
    ai_network_params params = {
        .params = NULL,
        .activations = {
            .handle = activations
        }
    };

    /* Initialize the neural network */
    printf("Initializing neural network...\n");
    if (!ai_materials_model_init(materials_model, &params)) {
        err = ai_materials_model_get_error(materials_model);
        printf("Error initializing network: %s (code %d)\n", ai_error_to_str(err), err.code);
        ai_materials_model_destroy(materials_model);
        materials_model = AI_HANDLE_NULL;
        return -3;
    }

    /* Get pointers to input/output buffers */
    ai_input[0] = ai_materials_model_inputs_get(materials_model, NULL)[0];
    ai_output[0] = ai_materials_model_outputs_get(materials_model, NULL)[0];

    /* Update data pointers to our buffers */
    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    printf("Network initialized successfully\n");
    return 0;
}

int aiRun(const int16_t* mfcc_q15_data, float* output_data)
{
    /* Convert Q15 MFCC data to float */
    convert_q15_to_float(mfcc_q15_data, in_data, AI_MATERIALS_MODEL_IN_1_SIZE);

    /* Run inference */
    ai_i32 batch = ai_materials_model_run(materials_model, &ai_input[0], &ai_output[0]);
    if (batch != 1) {
        /* Handle error */
        return -1;
    }

    /* Copy output data from output buffer */
    for (int i = 0; i < AI_MATERIALS_MODEL_OUT_1_SIZE; i++) {
        output_data[i] = out_data[i];
    }

    return 0;
}

void aiDeinit(void)
{
    /* Destroy the neural network */
    if (materials_model != AI_HANDLE_NULL) {
        ai_materials_model_destroy(materials_model);
        materials_model = AI_HANDLE_NULL;
    }
}

void inference_test() {
    float results[4];       // For storing classification results
    int ret_init = aiInit();
    // Initialize neural network
    if (ret_init != 0) {
        // Handle initialization error
    	printf("ai init failed, val%d\r\n", ret_init);
        return;
    }

    int ret = aiRun(mfcc_frame_final, results);
    // Run inference
    if (ret) {
        // Process results
        int max_idx = 0;
        float max_val = results[0];

        for (int i = 1; i < 4; i++) {
            if (results[i] > max_val) {
                max_val = results[i];
                max_idx = i;
            }
        }
        printf("result: %d\r\n", max_idx);
        // max_idx now contains the predicted class (0-3)
    } else {
    	printf("model run once, val: %d\r\n", ret);
    }


    // Clean up when done
    //aiDeinit();
}
