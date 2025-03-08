/*
 * st7920.c
 *
 *  Created on: Feb 18, 2025
 *      Author: lapchong
 */
#include "main.h"
#include "st7920.h"

#include <string.h>

#include "stm32h7xx.h"
#include "font.h"

extern SPI_HandleTypeDef hspi4;

void st7920_writeCmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(GPIOE, lcd_cs_Pin, SET);
	uint8_t txBuffer[3];
	txBuffer[0] = 0xF8;
	txBuffer[1] = (cmd & 0xF0);
	txBuffer[2] = ((cmd << 4) & 0xF0);

	HAL_SPI_Transmit(&hspi4, txBuffer, 3, HAL_MAX_DELAY);

	HAL_GPIO_WritePin(GPIOE, lcd_cs_Pin, RESET);
}

void st7920_writeData(uint8_t data)
{
	HAL_GPIO_WritePin(GPIOE, lcd_cs_Pin, SET);
	uint8_t txBuffer[3];
	txBuffer[0] = 0xFA;
	txBuffer[1] = (data & 0xF0);
	txBuffer[2] = ((data << 4) & 0xF0);

	HAL_SPI_Transmit(&hspi4, txBuffer, 3, HAL_MAX_DELAY);

	HAL_GPIO_WritePin(GPIOE, lcd_cs_Pin, RESET);
}

void st7920_gfx()
{
	st7920_writeCmd(0x30);  // 8 bit mode
	HAL_Delay(1);
	st7920_writeCmd(0x34);  // switch to Extended instructions
	HAL_Delay(1);
	st7920_writeCmd(0x36);  // enable graphics
	HAL_Delay(1);
}

void st7920_init()
{
	HAL_GPIO_WritePin(GPIOE, lcd_rst_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOE, lcd_rst_Pin, GPIO_PIN_SET);
	HAL_Delay(50);

	st7920_writeCmd(0x30);
	HAL_Delay(1);
	st7920_writeCmd(0x30);
	HAL_Delay(1);
	st7920_writeCmd(0x08);
	HAL_Delay(1);
	st7920_writeCmd(0x01);
	HAL_Delay(1);
	st7920_writeCmd(0x06);
	HAL_Delay(1);
	st7920_writeCmd(0x0C);
	HAL_Delay(1);
	st7920_writeCmd(0x02);
	HAL_Delay(1);
	st7920_gfx();
}

uint8_t framebuffer[64][16];

void st7920_drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t color)
{
	if(color > 1) return;
	uint8_t bit_position = 7 - (pos_x % 8);
	if (color)
	{
		framebuffer[pos_y][pos_x /8] |= (1 << bit_position);
	} else {
		framebuffer[pos_y][pos_x /8] &= ~(1 << bit_position);
	}
}

void st7920_sendBuffer()
{
	for (uint8_t y = 0; y < 64; y++)
	{
		if (y < 32)
		{
			st7920_writeCmd(0x80 | y);
			st7920_writeCmd(0x80);
			for (uint8_t j = 0; j < 16; j++)
			{
				st7920_writeData(framebuffer[y][j]);
			}
		} else {
			st7920_writeCmd(0x80 | (y-32));
			st7920_writeCmd(0x88);
			for (uint8_t j = 0; j < 16; j++)
			{
				st7920_writeData(framebuffer[y][j]);
			}
		}
	}
}

// more features

void st7920_drawChar(uint8_t x, uint8_t y, char c) {
	if (c < 32 || c > 126) return;
    uint8_t charIndex = (c - 32);

    for (uint8_t row = 0; row < 5; row++)
    {
        for (uint8_t col = 0; col < 7; col++)
        {
        	uint8_t fontByte = fontdata[charIndex][col];
        	if (fontByte & (1 << (4 - row)))
            {
                st7920_drawPixel(x + row, y + col, 1);
            } else {
            	st7920_drawPixel(x + row, y + col, 0);
            }
        }
    }
}

void st7920_print(uint8_t x, uint8_t y, const char* str)
{
	while(*str)
	{
		st7920_drawChar(x, y, *str++);
		x+=6;
		if(x > 122)
		{
			y+=8;
			x=1;
		}
	}
}

void st7920_clear() {
	memset(framebuffer, 0x00, sizeof(framebuffer));
	//st7920_writeCmd(0x01);
}
