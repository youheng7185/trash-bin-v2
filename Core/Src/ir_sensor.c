/*
 * ir_sensor.c
 *
 *  Created on: Mar 25, 2025
 *      Author: lapchong
 */

#include "stm32h7xx_hal.h"
#include "main.h"
#include "my_print.h"
#include "ir_sensor.h"
#include "mic.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_3) {
    	my_printf("hello from exti\r\n");
    	if (recording_status == READY)
    	{
    		st7920_clear();
    		st7920_print(1, 10, "record start");
    		st7920_sendBuffer();
    		record_and_convert();
    		st7920_print(1, 20, "record stop");
    		st7920_sendBuffer();
    	} else {
    		my_printf("busy\r\n");
    	}
    }
}
