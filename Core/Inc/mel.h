/*
 * mel.h
 *
 *  Created on: Mar 16, 2025
 *      Author: lapchong
 */

#ifndef INC_MEL_H_
#define INC_MEL_H_

#define FFT_SIZE        512

extern float32_t input_signal[FFT_SIZE];;
void mel_spectrogram_init();
void compute_mel();

#endif /* INC_MEL_H_ */
