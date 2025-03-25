################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.c \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.c \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.c \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.c \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.c \
../Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.c 

OBJS += \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.o \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.o \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.o \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.o \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.o \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.o 

C_DEPS += \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.d \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.d \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.d \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.d \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.d \
./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/CMSIS-DSP/Source/FastMathFunctions/%.o Libs/CMSIS-DSP/Source/FastMathFunctions/%.su Libs/CMSIS-DSP/Source/FastMathFunctions/%.cyclo: ../Libs/CMSIS-DSP/Source/FastMathFunctions/%.c Libs/CMSIS-DSP/Source/FastMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/tinyusb/src -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/hw -I../Libs/CMSIS-DSP/Source -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-FastMathFunctions

clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-FastMathFunctions:
	-$(RM) ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_divide_q15.su ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sin_f32.su ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_sqrt_q31.su ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_f32.su ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q15.su ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.cyclo ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.d ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.o ./Libs/CMSIS-DSP/Source/FastMathFunctions/arm_vlog_q31.su

.PHONY: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-FastMathFunctions

