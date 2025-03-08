/*
 * st7920.h
 *
 *  Created on: Feb 18, 2025
 *      Author: lapchong
 */

#ifndef ST7920_H_
#define ST7920_H_

void st7920_init();
void ST7920_ClearScreen(void);
void st7920_test();
void st7920_sendBuffer();
void st7920_drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t color);
void st7920_print(uint8_t x, uint8_t y, const char* str);
void st7920_clear();

#endif /* INC_ST7920_H_ */
