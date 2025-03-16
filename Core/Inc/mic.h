//
// Created by lapchong on 3/3/25.
//

#ifndef MIC_H
#define MIC_H

#include "fatfs.h"
#include "arm_math.h"

void sd_init();
int get_next_audio_filename();
void list_directory(const char *path, uint8_t depth);
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s);
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s);
void write_wav_header(FIL *file, uint32_t data_size);
void start_audio_recording();
void setup_mfcc();
void init_mel_filterbank(float32_t *filterCoefs, uint32_t *filterPos, uint32_t *filterLengths, int numMelFilters, float sampleRate, int fftSize, float freqMin, float freqMax);
void init_dct_matrix(float32_t *dctMatrix, int numDctOutputs, int numMelFilters);

extern char latest_audio_filename[32];
extern FIL file;

#endif //MIC_H
