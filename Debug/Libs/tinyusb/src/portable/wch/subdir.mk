################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.c \
../Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.c 

OBJS += \
./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.o \
./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.o 

C_DEPS += \
./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.d \
./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/tinyusb/src/portable/wch/%.o Libs/tinyusb/src/portable/wch/%.su Libs/tinyusb/src/portable/wch/%.cyclo: ../Libs/tinyusb/src/portable/wch/%.c Libs/tinyusb/src/portable/wch/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/tinyusb/src -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/hw -I../Libs/CMSIS-DSP/Source -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-wch

clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-wch:
	-$(RM) ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.cyclo ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.d ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.o ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbfs.su ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.cyclo ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.d ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.o ./Libs/tinyusb/src/portable/wch/dcd_ch32_usbhs.su

.PHONY: clean-Libs-2f-tinyusb-2f-src-2f-portable-2f-wch

