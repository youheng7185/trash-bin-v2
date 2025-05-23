//
// Created by lapchong on 3/2/25.
//
#include "servo.h"
#include "main.h"
#include "stm32h7xx_hal.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim2;

void servo360_init(void) {
    for (int i = 100; i < 200; i++) {
        set_servo_speed(i);
        HAL_Delay(10);
    }
}

// for 180 degree servo
void set_servo_angle(uint8_t angle) {
    uint32_t pulse = 50 + ((250 - 50) * angle) / 180; // Convert angle to timer counts
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
}

/**
* for 360 degree servo
* pwm_value=150, stop
* pwm_value < 150 anticlockwise, > 150 clockwise
 */
void set_servo_speed(uint16_t pwm_value) {
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pwm_value - 5); // Small pre-step
    HAL_Delay(20); // Let the servo register a small change
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pwm_value); // Set final speed
}

// 360 deg motor to rotate to compartment
void rotate_to_compartment(int n)
{
	int target_angle = 30 + (n - 1) * 90;
	int half_angle = target_angle / 2;

	uint32_t pulse = 50 + ((250 - 50) * half_angle) / 180;
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pulse);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, pulse);
}

// 180 deg motor to drop rubbish
void yeet(void)
{
	set_servo_angle(120);
	HAL_Delay(700);
	set_servo_angle(0);
}