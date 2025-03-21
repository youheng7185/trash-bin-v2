/*
 * mel_q15.c
 *
 *  Created on: Mar 19, 2025
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
#include "mel_q15.h"
#include "mel_filter_bank.h"

arm_rfft_instance_q15 fft_q15_instance;

void mel_q15_init()
{
	arm_rfft_init_2048_q15(&fft_q15_instance, 0, 0);
}

q15_t input_signal[FFT_SIZE];
q15_t fft_output[FFT_SIZE];
q15_t power_spectrum[FFT_SIZE / 2];
q15_t mel_spectrogram[MEL_FILTERS];
q15_t mel_filter_bank[MEL_FILTERS][FFT_SIZE / 2];

const q15_t hamming_window[FFT_SIZE] = {2621, 2622, 2625, 2631, 2639, 2649, 2662, 2677, 2694, 2713, 2735, 2759, 2785, 2813, 2844, 2877, 2912, 2949, 2989, 3030, 3074, 3121, 3169, 3220, 3273, 3328, 3385, 3444, 3505, 3569, 3635, 3703, 3773, 3845, 3919, 3995, 4074, 4154, 4237, 4321, 4408, 4496, 4587, 4679, 4774, 4870, 4968, 5069, 5171, 5275, 5381, 5489, 5598, 5710, 5823, 5938, 6055, 6174, 6294, 6416, 6540, 6666, 6793, 6922, 7052, 7184, 7318, 7453, 7590, 7728, 7868, 8009, 8152, 8296, 8442, 8589, 8737, 8887, 9038, 9190, 9344, 9499, 9655, 9813, 9971, 10131, 10292, 10454, 10617, 10781, 10946, 11112, 11280, 11448, 11617, 11787, 11958, 12130, 12303, 12476, 12650, 12825, 13001, 13178, 13355, 13533, 13711, 13890, 14070, 14250, 14431, 14612, 14793, 14975, 15158, 15341, 15524, 15708, 15891, 16076, 16260, 16445, 16629, 16814, 16999, 17185, 17370, 17555, 17741, 17926, 18111, 18296, 18482, 18667, 18851, 19036, 19221, 19405, 19589, 19773, 19956, 20139, 20322, 20504, 20686, 20867, 21048, 21229, 21409, 21588, 21767, 21945, 22122, 22299, 22475, 22651, 22825, 22999, 23172, 23345, 23516, 23686, 23856, 24025, 24192, 24359, 24525, 24690, 24853, 25016, 25177, 25338, 25497, 25655, 25812, 25967, 26121, 26274, 26426, 26577, 26726, 26873, 27020, 27165, 27308, 27450, 27591, 27730, 27867, 28003, 28138, 28270, 28402, 28531, 28659, 28786, 28910, 29033, 29155, 29274, 29392, 29508, 29622, 29734, 29845, 29954, 30061, 30166, 30269, 30370, 30469, 30567, 30662, 30756, 30847, 30937, 31024, 31110, 31193, 31275, 31354, 31431, 31507, 31580, 31651, 31720, 31787, 31851, 31914, 31974, 32033, 32089, 32143, 32194, 32244, 32291, 32336, 32379, 32420, 32458, 32495, 32529, 32560, 32590, 32617, 32642, 32665, 32685, 32703, 32719, 32733, 32744, 32754, 32760, 32765, 32767, 32767, 32765, 32760, 32754, 32744, 32733, 32719, 32703, 32685, 32665, 32642, 32617, 32590, 32560, 32529, 32495, 32458, 32420, 32379, 32336, 32291, 32244, 32194, 32143, 32089, 32033, 31974, 31914, 31851, 31787, 31720, 31651, 31580, 31507, 31431, 31354, 31275, 31193, 31110, 31024, 30937, 30847, 30756, 30662, 30567, 30469, 30370, 30269, 30166, 30061, 29954, 29845, 29734, 29622, 29508, 29392, 29274, 29155, 29033, 28910, 28786, 28659, 28531, 28402, 28270, 28138, 28003, 27867, 27730, 27591, 27450, 27308, 27165, 27020, 26873, 26726, 26577, 26426, 26274, 26121, 25967, 25812, 25655, 25497, 25338, 25177, 25016, 24853, 24690, 24525, 24359, 24192, 24025, 23856, 23686, 23516, 23345, 23172, 22999, 22825, 22651, 22475, 22299, 22122, 21945, 21767, 21588, 21409, 21229, 21048, 20867, 20686, 20504, 20322, 20139, 19956, 19773, 19589, 19405, 19221, 19036, 18851, 18667, 18482, 18296, 18111, 17926, 17741, 17555, 17370, 17185, 16999, 16814, 16629, 16445, 16260, 16076, 15891, 15708, 15524, 15341, 15158, 14975, 14793, 14612, 14431, 14250, 14070, 13890, 13711, 13533, 13355, 13178, 13001, 12825, 12650, 12476, 12303, 12130, 11958, 11787, 11617, 11448, 11280, 11112, 10946, 10781, 10617, 10454, 10292, 10131, 9971, 9813, 9655, 9499, 9344, 9190, 9038, 8887, 8737, 8589, 8442, 8296, 8152, 8009, 7868, 7728, 7590, 7453, 7318, 7184, 7052, 6922, 6793, 6666, 6540, 6416, 6294, 6174, 6055, 5938, 5823, 5710, 5598, 5489, 5381, 5275, 5171, 5069, 4968, 4870, 4774, 4679, 4587, 4496, 4408, 4321, 4237, 4154, 4074, 3995, 3919, 3845, 3773, 3703, 3635, 3569, 3505, 3444, 3385, 3328, 3273, 3220, 3169, 3121, 3074, 3030, 2989, 2949, 2912, 2877, 2844, 2813, 2785, 2759, 2735, 2713, 2694, 2677, 2662, 2649, 2639, 2631, 2625, 2622, 2621};

void apply_hamming_window(q15_t *input, q15_t *output, uint32_t size)
{
	arm_mult_q15(input, hamming_window, output, size);
	arm_shift_q15(output, 1, output, size); // Scale up to compensate for precision loss
}

void compute_fft(q15_t *windowed_signal, q15_t *power_spectrum)
{
	arm_rfft_q15(&fft_q15_instance, windowed_signal, fft_output);

	// Scale FFT output to prevent Q15 underflow
	arm_shift_q15(fft_output, 3, fft_output, FFT_SIZE); // Left shift by 3 bits
	// gain

	arm_cmplx_mag_squared_q15(fft_output, power_spectrum, FFT_SIZE / 2);

	// Apply Gain on Power Spectrum
	arm_shift_q15(power_spectrum, 8, power_spectrum, FFT_SIZE / 2);  // Increase magnitude (shift left)

}
/*
void apply_mel_filters(q15_t *power_spectrum, q15_t *mel_spectrogram) {
    q31_t acc; // 32-bit accumulator to prevent overflow

    for (int m = 0; m < MEL_FILTERS; m++) {
        acc = 0;
        for (int k = 0; k < FFT_SIZE / 2; k++) {
            acc += (q31_t) power_spectrum[k] * mel_filter_bank[m][k]; // Multiply and accumulate
        }

        acc <<= 3; // gain

        // Scale down to fit in Q15
        mel_spectrogram[m] = (q15_t) __SSAT(acc >> 15, 16); // Shift and saturate to Q15 range
    }
}
*/
void apply_mel_filters(q15_t *power_spectrum, q15_t *mel_spectrogram) {
    for (int m = 0; m < MEL_FILTERS; m++) {
        mel_spectrogram[m] = 0;
        for (int k = 0; k < FFT_SIZE / 2; k++) {
            mel_spectrogram[m] += power_spectrum[k] * mel_filter_bank[m][k];
        }
        //mel_spectrogram[m] = logf(mel_spectrogram[m] + 1e-10); // Log scale
    }
}

void apply_log_scale(q15_t *mel_spectrogram) {
    arm_vlog_q15(mel_spectrogram, mel_spectrogram, MEL_FILTERS);
}

void compute_mel_spectrogram() {
    apply_hamming_window(input_signal, fft_output, FFT_SIZE);
    compute_fft(fft_output, power_spectrum);
    apply_mel_filters(power_spectrum, mel_spectrogram);
    //apply_log_scale(mel_spectrogram); // Optional log scale
}

void pcm_to_q15(int16_t *pcm_data, q15_t *q15_output, uint32_t size) {
    arm_shift_q15((q15_t *)pcm_data, -1, q15_output, size);  // Optimized for DSP
}

