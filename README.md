
# Recycle bin firmware

A brief description of what this project does and who it's for


## Usage

### GPIO Assignments

* PA3  - ir-sensor (Input)

* PE3  - lcd_cs (Output)

* PE4  - lcd_rst (Output)

* PG2  - xshut4 (Output)

* PG3  - xshut3 (Output)

* PG4  - xshut2 (Output)

* PG5  - xshut1 (Output)

* PG7  - led (Output)

### Timers for servo motor

* PA0  - TIM2_CH1_ETR

* PA1  - TIM2_CH2

### UART Interfaces

#### LPUART1, communication with pc

* PA9  - LPUART1_TX

* PA10 - LPUART1_RX

#### UART5, communication with esp32

* PB12 - UART5_RX

* PB13 - UART5_TX

### I2S Interface

I2S1, mic inmp441

* PA4  - I2S1_WS

* PA5  - I2S1_CK

* PA6  - I2S1_SDI

### SPI Interfaces

SPI4, lcd st7920

* PE2  - SPI4_SCK

* PE5  - SPI4_MISO

* PE6  - SPI4_MOSI
## Installation

Import to stm32cubeide to compile

    
