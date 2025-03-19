/*
 * mel.c
 *
 *  Created on: Mar 16, 2025
 *      Author: lapchong
 */

#include "stm32h7xx_hal.h"
#include "fatfs.h"
#include <string.h>
#include <stdio.h>
#include "my_print.h"
#include "main.h"
#include <stdint.h>
#include "arm_math.h"
#include "arm_math_types.h"
#include "arm_common_tables.h"
#include "mel.h"

arm_rfft_fast_instance_f32 fft_instance;

void mel_spectrogram_init()
{
	arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);
}

float32_t input_signal[FFT_SIZE];
float32_t fft_output[FFT_SIZE];
float32_t fft_input[FFT_SIZE];
float32_t power_spectrum[FFT_SIZE / 2];  // Power spectrum
float32_t mel_spectrogram[MEL_FILTERS];  // Mel spectrogram output
float32_t mel_filter_bank[MEL_FILTERS][FFT_SIZE / 2]; // Mel filters

void apply_hamming_window(float32_t *input, float32_t *output, uint32_t size)
{
	for (int i = 0; i < size; i++)
	{
		output[i] = input[i] * (0.54 - 0.46 * cosf(2 * M_PI * i / (size -1)));
	}
}

void compute_fft(float32_t *windowed_singal, float32_t *power_spectrum)
{
	arm_rfft_fast_f32(&fft_instance, windowed_singal, fft_output, 0);

	for (int i = 0; i < FFT_SIZE / 2; i++)
	{
		float real = fft_output[2*i];
		float imag = fft_output[2*i+1];
		power_spectrum[i] = (real * real) + (imag * imag);
	}
}

void generate_mel_filter_bank()
{
	float mel_min = 2595 * log10f(1 + 300.0 / 700.0);
    float mel_max = 2595 * log10f(1 + (SAMPLE_RATE / 2.0) / 700.0);

    float mel_points[MEL_FILTERS + 2];
    float freq_points[MEL_FILTERS + 2];

    // Convert Mel to Hz
    for (int i = 0; i < MEL_FILTERS + 2; i++) {
        mel_points[i] = mel_min + (mel_max - mel_min) * i / (MEL_FILTERS + 1);
        freq_points[i] = 700 * (powf(10, mel_points[i] / 2595) - 1);
    }

    // Convert Hz to FFT bin
    int bin_points[MEL_FILTERS + 2];
    for (int i = 0; i < MEL_FILTERS + 2; i++) {
        bin_points[i] = (int)((FFT_SIZE + 1) * freq_points[i] / SAMPLE_RATE);
    }

    // Create triangular filters
    for (int m = 1; m <= MEL_FILTERS; m++) {
        for (int k = bin_points[m - 1]; k < bin_points[m]; k++) {
            mel_filter_bank[m - 1][k] = (float)(k - bin_points[m - 1]) / (bin_points[m] - bin_points[m - 1]);
        }
        for (int k = bin_points[m]; k < bin_points[m + 1]; k++) {
            mel_filter_bank[m - 1][k] = (float)(bin_points[m + 1] - k) / (bin_points[m + 1] - bin_points[m]);
        }
    }
}

void apply_mel_filters(float32_t *power_spectrum, float32_t *mel_spectrogram) {
    for (int m = 0; m < MEL_FILTERS; m++) {
        mel_spectrogram[m] = 0;
        for (int k = 0; k < FFT_SIZE / 2; k++) {
            mel_spectrogram[m] += power_spectrum[k] * mel_filter_bank[m][k];
        }
        mel_spectrogram[m] = logf(mel_spectrogram[m] + 1e-10); // Log scale
    }
}

void compute_mel()
{
	/*
    for (int i = 0; i < 512; i++) {
        my_printf("Mel input %d: %f\n", i, input_signal[i]);
    }
    my_printf("started compute fft\r\n");
	*/


	apply_hamming_window(input_signal, fft_output, FFT_SIZE);

	compute_fft(fft_input, power_spectrum);

	generate_mel_filter_bank();

	apply_mel_filters(power_spectrum, mel_spectrogram);


	/*
    for (int i = 0; i < MEL_FILTERS; i++) {
        my_printf("Mel bin %d: %f\n", i, mel_spectrogram[i]);
    }
    my_printf("mel spectrum: \r\n");
    */
}
