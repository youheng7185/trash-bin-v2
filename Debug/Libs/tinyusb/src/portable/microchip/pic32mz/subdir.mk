################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.c 

OBJS += \
./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.o 

C_DEPS += \
./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/tinyusb/src/portable/microchip/pic32mz/%.o Libs/tinyusb/src/portable/microchip/pic32mz/%.su Libs/tinyusb/src/portable/microchip/pic32mz/%.cyclo: ../Libs/tinyusb/src/portable/microchip/pic32mz/%.c Libs/tinyusb/src/portable/microchip/pic32mz/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/src -I../Libs/tinyusb/hw -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-microchip-2f-pic32mz

clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-microchip-2f-pic32mz:
	-$(RM) ./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.cyclo ./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.d ./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.o ./Libs/tinyusb/src/portable/microchip/pic32mz/dcd_pic32mz.su

.PHONY: clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-microchip-2f-pic32mz

