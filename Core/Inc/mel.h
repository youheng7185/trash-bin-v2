/*
 * mel.h
 *
 *  Created on: Mar 16, 2025
 *      Author: lapchong
 */

#ifndef INC_MEL_H_
#define INC_MEL_H_

#define FRAME_LEN       512      // Frame size
#define FFT_SIZE        512      // FFT size (Power of 2)
#define MEL_FILTERS     20       // Number of Mel filters
#define SAMPLE_RATE     48000.0f // Audio sample rate

extern float32_t input_signal[FFT_SIZE];
extern float32_t mel_spectrogram[MEL_FILTERS];

void mel_spectrogram_init();
void compute_mel();

#endif /* INC_MEL_H_ */
