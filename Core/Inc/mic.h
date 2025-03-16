//
// Created by lapchong on 3/3/25.
//

#ifndef MIC_H
#define MIC_H

#include "fatfs.h"

void sd_init();
int get_next_audio_filename();
void list_directory(const char *path, uint8_t depth);
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s);
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s);
void write_wav_header(FIL *file, uint32_t data_size);
void start_audio_recording();
void setup_mfcc();
void convert_mfcc();

extern char latest_audio_filename[32];
extern FIL file;

#endif //MIC_H
