/*
 * nn_process.h
 *
 *  Created on: May 3, 2025
 *      Author: lapchong
 */

#ifndef INC_NN_PROCESS_H_
#define INC_NN_PROCESS_H_

#include <stdint.h>

/**
 * @brief Initialize the neural network
 * @return 0 if successful, negative error code otherwise
 */
int aiInit(void);

/**
 * @brief Run inference with the neural network
 * @param mfcc_q15_data Pointer to Q15-formatted MFCC data (624 elements)
 * @param output_data Pointer to store the output classification results (4 elements)
 * @return 0 if successful, negative error code otherwise
 */
int aiRun(const int16_t* mfcc_q15_data, float* output_data);
void test_ai_correctness();

#endif /* INC_NN_PROCESS_H_ */
