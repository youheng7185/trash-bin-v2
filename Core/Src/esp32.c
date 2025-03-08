//
// Created by lapchong on 3/4/25.
//
#include "esp32.h"
#include "stm32h7xx_hal.h"
#include "main.h"
#include "my_print.h"

#define RX_BUFFER_SIZE 128
uint8_t rx_buffer[RX_BUFFER_SIZE];

extern UART_HandleTypeDef huart5;

void send_at_command(const char *command) {
    HAL_UART_Transmit(&huart5, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);
    //HAL_UART_Transmit(&huart5, (uint8_t *)"\r\n", 2, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart5, (uint8_t *)"\n", 1, HAL_MAX_DELAY);
}

void receive_response() {
  memset(rx_buffer, 0, RX_BUFFER_SIZE);
  HAL_UART_Receive(&huart5, (uint8_t *)rx_buffer, RX_BUFFER_SIZE-1, 100);
  my_printf("esp32 response: %s\r\n", rx_buffer);
}
