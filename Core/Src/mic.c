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
#include "mel.h"

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
char latest_f32_filename[32];
char latest_mfcc_filename[32];
FIL file;

#define AUDIO_FOLDER "AUDIO"
#define FILE_TEMPLATE "AUDIO%03d.WAV"
#define F32_TEMPLATE "FLOAT%03d.BIN"
#define MFCC_TEMPLATE "MFCC%03d.BIN"

int get_next_audio_filename() {
  DIR dir;
  FILINFO fno;
  int max_number = 0;

  if (f_opendir(&dir, AUDIO_FOLDER) == FR_OK) {
    while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0]) {
      if (strstr(fno.fname, "AUDIO") && strstr(fno.fname, ".WAV")) {
        int num = atoi(fno.fname + 6);
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
  snprintf(latest_f32_filename, sizeof(latest_f32_filename), AUDIO_FOLDER "/" F32_TEMPLATE, max_number + 1);
  snprintf(latest_mfcc_filename, sizeof(latest_mfcc_filename), AUDIO_FOLDER "/" MFCC_TEMPLATE, max_number + 1);
  my_printf("new audio file name in pcm should be: %s\r\n", latest_audio_filename);
  my_printf("new audio file name in f32 should be: %s\r\n", latest_f32_filename);
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

#define SAMPLING_RATE   22000  // 22 kHz
#define PERIOD          10       // 5-second recording
#define BUFFER_SIZE     (SAMPLING_RATE * 2) // Stereo buffer for 1 second

int16_t i2s_data[BUFFER_SIZE];  // Single buffer (stereo)
volatile uint8_t buffer_ready = 0;
UINT bytes_written;
float32_t float_buffer[BUFFER_SIZE / 4];
int16_t left_q15_buffer[BUFFER_SIZE / 4];

// mfcc starts here
#define SAMPLE_RATE     22000       // Your sample rate
#define FRAME_LEN       512         // Frame size (e.g., 512 samples)
#define NUM_FFT_POINTS  512         // FFT size (must be power of 2)
#define NUM_MEL_FILTERS 20          // Number of Mel filters
#define NUM_MFCC_COEFFS 13          // Number of MFCC coefficients

// mfcc
float32_t f32_pcm_data[FRAME_LEN];
float32_t mfcc_out[NUM_MFCC_COEFFS];
float32_t mfcc_buffer[FRAME_LEN * 2];
// fixme need to figure out how to fill these array
float32_t dctCoefs[NUM_MFCC_COEFFS * NUM_MEL_FILTERS];  // DCT matrix coefficients
uint32_t filterPos[NUM_MEL_FILTERS + 1];                // Filter bank positions
uint32_t filterLengths[NUM_MEL_FILTERS];                // Length of each filter
float32_t filterCoefs[NUM_MEL_FILTERS * (NUM_FFT_POINTS / 2)]; // Filter bank coefficients
float32_t windowCoefs[FRAME_LEN];                       // Hamming or Hanning window

//#define float_t float32_t

arm_mfcc_instance_f32 mfcc;

void setup_mfcc() {
	for (int i = 0; i < FRAME_LEN; i++) {
		windowCoefs[i] = 0.54 - 0.46 * cosf(2 * M_PI * i / (FRAME_LEN - 1)); // Hamming window
	}

	init_mel_filterbank(filterCoefs, filterPos, filterLengths, NUM_MEL_FILTERS, SAMPLE_RATE, NUM_FFT_POINTS, 80, 7600);

	init_dct_matrix(dctCoefs, NUM_MFCC_COEFFS, NUM_MEL_FILTERS);

	if(arm_mfcc_init_f32(&mfcc, NUM_FFT_POINTS, NUM_MEL_FILTERS, NUM_MFCC_COEFFS, dctCoefs, filterPos, filterLengths, filterCoefs, windowCoefs) == ARM_MATH_SUCCESS)
	{
		my_printf("mfcc init success\r\n");
	} else {
		my_printf("mfcc init failed\r\n");
	}
}

// Callback when half buffer is filled
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s) {
    buffer_ready = 1;
}

// Callback when full buffer is filled
void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s) {
    buffer_ready = 2;
}

// Write WAV header for mono channel
void write_wav_header(FIL *file, uint32_t data_size) {
    uint8_t wav_header[44] = {
        'R', 'I', 'F', 'F',
        (data_size + 36) & 0xFF, ((data_size + 36) >> 8) & 0xFF, ((data_size + 36) >> 16) & 0xFF, ((data_size + 36) >> 24) & 0xFF,
        'W', 'A', 'V', 'E', 'f', 'm', 't', ' ',
        16, 0, 0, 0, 1, 0, 1, 0,
        0x22, 0x56, 0x00, 0x00,
        0x22, 0x56, 0x00, 0x00,
        2, 0, 16, 0, 'd', 'a', 't', 'a',
        data_size & 0xFF, (data_size >> 8) & 0xFF, (data_size >> 16) & 0xFF, (data_size >> 24) & 0xFF
    };
    f_write(file, wav_header, 44, &bytes_written);
    f_sync(file);
}

FIL file_f32;
FIL file_mfcc;

void write_float32_data(const char *filename, float *data, uint32_t size)
{
	UINT bytes_written;
	f_write(&file_f32, data, size * sizeof(float), &bytes_written);
	f_sync(&file_f32);
}

extern I2S_HandleTypeDef hi2s1;

// Start audio recording (writing only left channel)
void start_audio_recording() {
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

        if (f_open(&file_f32, latest_f32_filename, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
        {
        	my_printf("start write f32 failed\r\n");
        	f_close(&file_f32);
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
                	left_q15_buffer[i / 2] = start_ptr[i];
                }

                // Write only left channel (even indices)

                f_write(&file, left_q15_buffer, (BUFFER_SIZE / 4) * sizeof(int16_t), &bytes_written);

                total_samples += (BUFFER_SIZE / 4); // Since we write only half the samples

                arm_q15_to_float(left_q15_buffer, float_buffer, BUFFER_SIZE / 4);

                write_float32_data(latest_f32_filename, float_buffer, BUFFER_SIZE / 4);

                buffer_ready = 0;
            }
        }

        // Stop DMA
        HAL_I2S_DMAStop(&hi2s1);

        // Update WAV header with actual data size
        f_lseek(&file, 0);
        write_wav_header(&file, total_samples * sizeof(int16_t));

        // source - float_buffer, destination - f32_pcm_data
        /*
        for (int i = 0; i < 21; i++) // fixme later will reach out of bound
        {
        	memcpy(f32_pcm_data, &float_buffer[i * FRAME_LEN], 512 * sizeof(float32_t));
        	arm_mfcc_f32(&mfcc, f32_pcm_data, mfcc_out, mfcc_buffer);
        	UINT bytes_written;
        	f_write(&file_mfcc, mfcc_out, NUM_MFCC_COEFFS * sizeof(float32_t), &bytes_written);
        	f_sync(&file_mfcc);
        }
        */
        my_printf("recording stopped!\r\n");

        for (uint32_t i = 0; i < 512; i++)
        {
        	input_signal[i] = float_buffer[i];
        }

        compute_mel();

        // Close file
        f_close(&file);
        f_close(&file_f32);
        f_close(&file_mfcc);

        my_printf("Recording complete\r\n");
    } else {
        my_printf("File open failed\r\n");
    }
}

void init_mel_filterbank(float32_t *filterCoefs, uint32_t *filterPos, uint32_t *filterLengths,
                         int numMelFilters, float sampleRate, int fftSize, float freqMin, float freqMax) {
    float melMin = 1125.0f * logf(1.0f + freqMin / 700.0f);
    float melMax = 1125.0f * logf(1.0f + freqMax / 700.0f);
    float melStep = (melMax - melMin) / (numMelFilters + 1);

    float melFrequencies[numMelFilters + 2];
    float binFrequencies[numMelFilters + 2];
    int fftBins = fftSize / 2 + 1;

    for (int i = 0; i < numMelFilters + 2; i++) {
        melFrequencies[i] = melMin + i * melStep;
        binFrequencies[i] = 700.0f * (expf(melFrequencies[i] / 1125.0f) - 1.0f);
        filterPos[i] = (uint32_t) (binFrequencies[i] / (sampleRate / fftSize));
    }

    for (int i = 0; i < numMelFilters; i++) {
        filterLengths[i] = filterPos[i + 2] - filterPos[i];

        for (int j = filterPos[i]; j < filterPos[i + 1]; j++) {
            filterCoefs[j] = (float)(j - filterPos[i]) / (filterPos[i + 1] - filterPos[i]);
        }
        for (int j = filterPos[i + 1]; j < filterPos[i + 2]; j++) {
            filterCoefs[j] = 1.0f - ((float)(j - filterPos[i + 1]) / (filterPos[i + 2] - filterPos[i + 1]));
        }
    }
}

void init_dct_matrix(float32_t *dctMatrix, int numDctOutputs, int numMelFilters) {
    float scale = sqrtf(2.0f / numMelFilters);
    for (int i = 0; i < numDctOutputs; i++) {
        for (int j = 0; j < numMelFilters; j++) {
            dctMatrix[i * numMelFilters + j] = scale * cosf((M_PI / numMelFilters) * i * (j + 0.5f));
        }
    }
}




/*
FIL file_pcm;
FIL file_mfcc;

void convert_mfcc() {
	UINT bytes_read, bytes_written;
	uint32_t file_size;

	if(f_open(&file_f32, latest_f32_filename, FA_READ) != FR_OK)
	{
		my_printf("open pcm f32 failed\r\n");
		return;
	}
	my_printf("latest f32 filename is: %s", latest_f32_filename);

	if(f_open(&file_mfcc, latest_mfcc_filename, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
	{
		my_printf("open mfcc write failed\r\n");
		return;
	}

	file_size = f_size(&file_f32);
	my_printf("Processing file: %s (size: %lu bytes)\r\n", latest_f32_filename, file_size);

	while(1)
	{
		//f_lseek(&file_pcm, read_location);
		if(f_read(&file_f32 , pcm_data, sizeof(pcm_data), &bytes_read) != FR_OK || bytes_read == 0)
		{
			break;
		}

		arm_mfcc_f32(&mfcc, pcm_data, mfcc_out, mfcc_buffer);

		for (int i = 0; i < 5; i++)
		{
			my_printf("pcm_in[%d]: %f mfcc_out[%d]: %f\r\n", i, pcm_data[i], i, mfcc_out[i]);

		}

		if(f_write(&file_mfcc, mfcc_out, sizeof(mfcc_out), &bytes_written) != FR_OK)
		{
			my_printf("write mfcc failed\r\n");
			return;
		}
	}

	f_close(&file_f32);
	f_close(&file_mfcc);

	my_printf("mfcc convert done\r\n");
}
*/

