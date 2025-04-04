//
// Created by lapchong on 3/3/25.
//
#include "stm32h7xx_hal.h"
#include "mic.h"
#include "fatfs.h"
#include <string.h>
#include <stdio.h>
#include "my_print.h"
#include "main.h"
#include <stdint.h>
#include "arm_math.h"
#include "arm_math_types.h"
#include "arm_common_tables.h"
#include "mfcc_q15.h"

FATFS fatfs;
FRESULT fresult;
extern SD_HandleTypeDef hsd1;

void sd_init() {
    if (BSP_SD_Init() == MSD_OK) {
        my_printf("SD card initialized successfully!\r\n");
    } else {
        my_printf("SD card initialization failed!\r\n");
    }

    fresult = f_mount(&fatfs, "", 1);
    if(fresult != FR_OK) {
        my_printf("f_mount failed, %d\r\n", fresult);
        while(1){
            HAL_Delay(1000);
        }
    }
}

char latest_audio_filename[32];
char latest_mfcc_filename[32];
FIL file;
recording_state_t recording_state = NOT_READY;

#define AUDIO_FOLDER "AUDIO"
#define FILE_TEMPLATE "AUDIO%03d.WAV"
#define MFCC_TEMPLATE "MFCC%03d.BIN"

int get_next_audio_filename() {
  DIR dir;
  FILINFO fno;
  int max_number = 0;

  if (f_opendir(&dir, AUDIO_FOLDER) == FR_OK) {
    while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0]) {
      if (strstr(fno.fname, "AUDIO") && strstr(fno.fname, ".WAV")) {
        int num = atoi(fno.fname + 5);
        if (num > max_number) {
          max_number = num;
        }
      }
    }
    f_closedir(&dir);
  } else {
    return -1;
  }

  snprintf(latest_audio_filename, sizeof(latest_audio_filename), AUDIO_FOLDER "/" FILE_TEMPLATE, max_number + 1);
  snprintf(latest_mfcc_filename, sizeof(latest_mfcc_filename), AUDIO_FOLDER "/" MFCC_TEMPLATE, max_number + 1);
  my_printf("new audio file name in pcm should be: %s\r\n", latest_audio_filename);
  my_printf("new mfcc in f32 should be: %s\r\n", latest_mfcc_filename);
  return max_number + 1;
}

void list_directory(const char *path, uint8_t depth) {
    DIR dir;
    FILINFO fno;

    // Try opening the directory
    if (f_opendir(&dir, path) == FR_OK) {
        while (1) {
            // Read directory content
            if (f_readdir(&dir, &fno) != FR_OK || fno.fname[0] == 0) break;  // End of directory

            // Ignore "." and ".."
            if (fno.fname[0] == '.') continue;

            // Indentation for subdirectories
            for (uint8_t i = 0; i < depth; i++) {
                my_printf("  ");
            }

            if (fno.fattrib & AM_DIR) {
                // It's a directory
                my_printf("[DIR] %s\r\n", fno.fname);

                // Recursively list subdirectory
                char new_path[128];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, fno.fname);
                list_directory(new_path, depth + 1);
            } else {
                // It's a file
                my_printf("[FILE] %s (%lu bytes)\r\n", fno.fname, fno.fsize);
            }
        }
        f_closedir(&dir);
    } else {
        my_printf("Failed to open directory: %s\r\n", path);
    }
}

#define SAMPLING_RATE   16000  // 48 kHz
#define PERIOD          2       // 5-second recording
#define BUFFER_SIZE     16384 / 2 // Stereo buffer for 0.5 second, power of 2, just enough for windowing
#define GAIN            5

int16_t i2s_data[BUFFER_SIZE];  // Single buffer (stereo)
volatile uint8_t buffer_ready = 0;
UINT bytes_written;
int16_t left_pcm_buffer[BUFFER_SIZE / 4];
q15_t q15_buffer[BUFFER_SIZE / 4];

// Callback when half buffer is filled
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s) {
    buffer_ready = 1;
}

// Callback when full buffer is filled
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s) {
    buffer_ready = 2;
}

// Write WAV header for mono channel, 16-bit, 16kHz sampling rate
void write_wav_header(FIL *file, uint32_t data_size) {
    uint8_t wav_header[44] = {
        'R', 'I', 'F', 'F',
        (data_size + 36) & 0xFF, ((data_size + 36) >> 8) & 0xFF, ((data_size + 36) >> 16) & 0xFF, ((data_size + 36) >> 24) & 0xFF,
        'W', 'A', 'V', 'E', 'f', 'm', 't', ' ',
        16, 0, 0, 0, 1, 0, 1, 0,  // PCM format, 1 channel (mono)
        0x00, 0x3E, 0x00, 0x00,  // 16000 Hz sample rate (0x3E80 = 16000)
        0x00, 0x7D, 0x00, 0x00,  // Byte rate = 16000 * 1 * 16/8 = 32000 (0x7D00)
        2, 0, 16, 0,  // Block align = 2 bytes, Bits per sample = 16
        'd', 'a', 't', 'a',
        data_size & 0xFF, (data_size >> 8) & 0xFF, (data_size >> 16) & 0xFF, (data_size >> 24) & 0xFF
    };
    UINT bytes_written;
    f_write(file, wav_header, 44, &bytes_written);
    f_sync(file);
}

FIL file_mfcc;

void write_mel_spec_data(const char *filename, float *data, uint32_t size)
{
	UINT bytes_written;
	f_write(&file_mfcc, data, size * sizeof(float), &bytes_written);
	f_sync(&file_mfcc);
}

extern I2S_HandleTypeDef hi2s1;

// Start audio recording (writing only left channel)
void start_audio_recording() {
	UINT bytes_written_mfcc;
    buffer_ready = 0;
    my_printf("Starting audio recording...\r\n");

    if (f_open(&file, latest_audio_filename, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK) {
        my_printf("File created successfully\r\n");

        // Write placeholder WAV header
        write_wav_header(&file, 0);

        if (f_open(&file_mfcc, latest_mfcc_filename, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
        {
        	my_printf("start write mfcc failed, filename: %s, error: %d\r\n", latest_mfcc_filename, fresult);
        	f_close(&file_mfcc);
        	return;
        }

        // Start I2S DMA
        HAL_I2S_Receive_DMA(&hi2s1, (uint16_t *)i2s_data, BUFFER_SIZE);

        uint32_t total_samples = 0;

        while (total_samples < SAMPLING_RATE * PERIOD) {
            if (buffer_ready) {
                int16_t *start_ptr = (buffer_ready == 1) ? i2s_data : &i2s_data[BUFFER_SIZE / 2];

                for (uint32_t i = 0; i < BUFFER_SIZE / 2; i += 2)
                {
                	left_pcm_buffer[i / 2] = start_ptr[i] * GAIN;
                }

                // Write only left channel (even indices)

                f_write(&file, left_pcm_buffer, (BUFFER_SIZE / 4) * sizeof(int16_t), &bytes_written);

                total_samples += (BUFFER_SIZE / 4); // Since we write only half the samples

                arm_copy_q15((q15_t*)left_pcm_buffer, q15_buffer, BUFFER_SIZE / 4);

                for (uint8_t i = 0; i < 4; i++)
                {
                	convert_mfcc(&left_pcm_buffer[i * 512]);
                	f_write(&file_mfcc, mfcc_output, 13 * sizeof(q15_t), &bytes_written_mfcc);
                	// fixme unknown error, why after 13 is empty, so lets record until 13
                }

                buffer_ready = 0;
            }
        }

        // Stop DMA
        HAL_I2S_DMAStop(&hi2s1);

        // Update WAV header with actual data size
        f_lseek(&file, 0);
        write_wav_header(&file, total_samples * sizeof(int16_t));

        my_printf("recording stopped!\r\n");

        // Close file
        f_close(&file);
        f_close(&file_mfcc);

        my_printf("Recording complete\r\n");
    } else {
        my_printf("File open failed\r\n");
    }
}

int record_and_convert()
{
	int num = get_next_audio_filename();
	start_audio_recording();
	return num;
}
