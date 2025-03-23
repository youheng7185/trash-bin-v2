/*
 * mel_q15.h
 *
 *  Created on: Mar 19, 2025
 *      Author: lapchong
 */

#ifndef INC_MEL_Q15_H_
#define INC_MEL_Q15_H_

#define FFT_SIZE 2048
#define MEL_FILTERS 40
#define SAMPLE_RATE 48000

extern q15_t input_signal[FFT_SIZE];
extern q15_t mel_spectrogram[MEL_FILTERS];
extern q15_t fft_output[FFT_SIZE];
extern q15_t power_spectrum[FFT_SIZE / 2];

void mel_q15_init();
void compute_mel_spectrogram();

#endif /* INC_MEL_Q15_H_ */
