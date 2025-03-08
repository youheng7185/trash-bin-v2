//
// Created by lapchong on 3/2/25.
//

#ifndef SERVO_H
#define SERVO_H
#include <stdint.h>

void servo360_init(void);
void set_servo_angle(uint8_t angle);
void set_servo_speed(uint16_t pwm_value);

#endif //SERVO_H
