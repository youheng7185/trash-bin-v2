/*
 * nn_process.h
 *
 *  Created on: May 3, 2025
 *      Author: lapchong
 */

#ifndef INC_NN_PROCESS_H_
#define INC_NN_PROCESS_H_

#include "arm_math.h"

void nnom_init();
void process_mfcc_example(q15_t* mfcc_features);
void test_nnom();

#endif /* INC_NN_PROCESS_H_ */
