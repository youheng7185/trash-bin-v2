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
