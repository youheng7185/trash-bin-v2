################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.c \
../Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.c 

OBJS += \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.o \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.o 

C_DEPS += \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.d \
./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/CMSIS-DSP/Source/SupportFunctions/%.o Libs/CMSIS-DSP/Source/SupportFunctions/%.su Libs/CMSIS-DSP/Source/SupportFunctions/%.cyclo: ../Libs/CMSIS-DSP/Source/SupportFunctions/%.c Libs/CMSIS-DSP/Source/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/src -I../Libs/tinyusb/hw -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-SupportFunctions

clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-SupportFunctions:
	-$(RM) ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_barycenter_f32.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f32.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_copy_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_float.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f16_to_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_float.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_f64_to_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f32.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_fill_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.cyclo
	-$(RM) ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_float_to_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_float.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q15_to_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_float.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q31_to_q7.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_f64.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_float.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q15.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_q7_to_q31.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f16.su ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.cyclo ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.d ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.o ./Libs/CMSIS-DSP/Source/SupportFunctions/arm_weighted_average_f32.su

.PHONY: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-SupportFunctions

