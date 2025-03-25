/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "mic.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
extern recording_status_t recording_status;
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define lcd_cs_Pin GPIO_PIN_3
#define lcd_cs_GPIO_Port GPIOE
#define lcd_rst_Pin GPIO_PIN_4
#define lcd_rst_GPIO_Port GPIOE
#define ir_sensor_Pin GPIO_PIN_3
#define ir_sensor_GPIO_Port GPIOA
#define ir_sensor_EXTI_IRQn EXTI3_IRQn
#define xshut4_Pin GPIO_PIN_2
#define xshut4_GPIO_Port GPIOG
#define xshut3_Pin GPIO_PIN_3
#define xshut3_GPIO_Port GPIOG
#define xshut2_Pin GPIO_PIN_4
#define xshut2_GPIO_Port GPIOG
#define xshut1_Pin GPIO_PIN_5
#define xshut1_GPIO_Port GPIOG
#define led_Pin GPIO_PIN_7
#define led_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
