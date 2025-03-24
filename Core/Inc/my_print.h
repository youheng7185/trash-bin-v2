//
// Created by lapchong on 3/1/25.
//

#ifndef MY_PRINT_H
#define MY_PRINT_H

#include "stm32h7xx_hal.h"
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tusb.h"
/*
static inline int my_printf(const char *format, ...) {
    char buf[128]; // Buffer for formatted output
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    if (len <= 0 || len >= sizeof(buf)) {
        return -1; // Error or truncation occurred
    }

    // Check if CDC is connected
    if (!tud_cdc_n_connected(0)) {
        return -2; // Not connected
    }

    // Write data when buffer has enough space
    if (tud_cdc_n_write_available(0) >= len) {
        uint32_t written = tud_cdc_n_write(0, buf, len);
        tud_cdc_n_write_flush(0);
        return written;
    }

    return 0; // No space available
}
*/
extern UART_HandleTypeDef hlpuart1;

static inline void my_printf(const char *format, ...)
{
    char buffer[256];  // Adjust size as needed
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    HAL_UART_Transmit(&hlpuart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}


#endif //MY_PRINT_H
