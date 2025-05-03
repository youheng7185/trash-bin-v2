#include <stdint.h>
#include <limits.h> // for INT16_MIN, INT16_MAX
#include <stdio.h>
#include "main.h"
#include "stm32h7xx_hal.h"
#include "nn_process.h"
#include "mic.h"
#include "mfcc_q15.h"
#include "weights.h"
#include "nnom.h"

nnom_model_t *model;

void nnom_init()
{
	model = nnom_model_create();
	model_run(model);
}

/**
 * @brief Quantizes MFCC data to the format required by the NNoM model
 *
 * This function converts MFCC floating-point data to q7_t (int8_t) format
 * based on the quantization parameters from weights.h. It applies the same
 * normalization (division by 32768.0) that was used during model training.
 *
 * @param mfcc_data Pointer to input MFCC data (q15_t format)
 * @param quantized_output Pointer to output buffer for quantized data (q7_t format)
 * @param length Length of the MFCC data array
 */
void quantize_mfcc_for_nnom(q15_t* mfcc_data, q7_t* quantized_output, uint32_t length)
{
    // Input quantization parameters from weights.h
    const int32_t decimal_point = 7;  // 7 based on weights.h
    const int32_t zero_offset = 0; // 0 based on weights.h

    // Use the same normalization factor as during training (32768.0)
    // This matches the Python code: data = np.frombuffer(raw, dtype=np.int16).astype(np.float32) / 32768.0
    const float normalization_factor = 1.0f / 32768.0f;

    // Calculate scaling factor for target quantization
    // We're scaling to q7_t with 'decimal_point' fractional bits
    const float scale_factor = (float)(1 << decimal_point);

    for (uint32_t i = 0; i < length; i++)
    {
        // Convert from q15_t to float with the same normalization as in training
        float float_val = (float)mfcc_data[i] * normalization_factor;

        // Scale and round to nearest integer
        int32_t quantized_val = (int32_t)(float_val * scale_factor + (float_val >= 0 ? 0.5f : -0.5f));

        // Add offset (though it's 0 in this case)
        quantized_val += zero_offset;

        // Clip to q7_t range (-128 to 127)
        if (quantized_val > 127)
            quantized_val = 127;
        else if (quantized_val < -128)
            quantized_val = -128;

        // Store the quantized value
        quantized_output[i] = (q7_t)quantized_val;
    }
}

/**
 * @brief Example usage of the quantization function
 */

void copy_mfcc_to_nnom_input(q7_t* quantized_mfcc)
{
    // Simply copy the 48 values to the nnom_input_data array
    memcpy(nnom_input_data, quantized_mfcc, 624 * sizeof(q7_t));
}

void process_mfcc_example(q15_t* mfcc_features)
{
    // Assuming 48 MFCC coefficients
    const uint32_t mfcc_length = 624;

    // Allocate memory for quantized output
    q7_t quantized_mfcc[mfcc_length];

    // Quantize the MFCC data
    quantize_mfcc_for_nnom(mfcc_features, quantized_mfcc, mfcc_length);

    printf("print quantized val:\r\n");
    for (int i = 500; i < 550; i++)
    {
    	printf("[%d] = %d\r\n", i, quantized_mfcc[i]);
    }

    copy_mfcc_to_nnom_input(quantized_mfcc);

    nnom_status_t predict_result = model_run(model);

    printf("heres result:\r\n");
    for (uint8_t i = 0; i < 4; i++) {
    	printf("output [%d]: %d\r\n", i, nnom_output_data[i]);
    }
}
