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
int record_and_convert();

extern char latest_audio_filename[32];
extern FIL file;

typedef enum {
	NOT_READY,
	READY,
	DO_RECORDING,
	RECORDING
} recording_state_t;

extern recording_state_t recording_state;

#endif //MIC_H
