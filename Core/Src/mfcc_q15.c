/*
 * mfcc_q15.c
 *
 *  Created on: Mar 23, 2025
 *      Author: lapchong
 */
#include "my_print.h"
#include "mfcc_q15.h"
#include "main.h"
#include "arm_math.h"
#include "dct_coefficients.h"
#include "filter_bank.h"

arm_mfcc_instance_q15 mfcc_inst;

void mfcc_q15_init() {
	arm_status status;

	status = arm_mfcc_init_q15(
	    &mfcc_inst,                  // S (instance pointer)
	    512,                         // fftLen
	    26,                          // nbMelFilters
	    13,                          // nbDctOutputs (typical MFCC count)
	    dct_matrix,                  // dctCoefs (from dct_coefficients.h)
	    mel_filter_positions,        // filterPos
	    mel_filter_lengths,          // filterLengths
	    mel_filter_coeffs,           // filterCoefs
	    hamming_window               // windowCoefs
	);

	if(status == ARM_MATH_SUCCESS)
	{
		my_printf("mfcc init success\r\n");
	} else {
		my_printf("mfcc init failed\r\n");
	}
}

q15_t mfcc_output[26];
// input buffer is 512
q31_t tmp_buffer[512 * 2];

void convert_mfcc(q15_t * pcm_input)
{
	arm_status status;
	status = arm_mfcc_q15(&mfcc_inst, pcm_input, mfcc_output, tmp_buffer);
	if (status != ARM_MATH_SUCCESS)
	{
		my_printf("failed mfcc conversion\r\n");
	}
}

