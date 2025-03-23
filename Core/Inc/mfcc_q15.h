/*
 * mfcc_q15.h
 *
 *  Created on: Mar 23, 2025
 *      Author: lapchong
 */

#ifndef INC_MFCC_Q15_H_
#define INC_MFCC_Q15_H_
#include "arm_math.h"

void mfcc_q15_init();
void convert_mfcc(q15_t * pcm_input);

#endif /* INC_MFCC_Q15_H_ */
