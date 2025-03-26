################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.c \
../Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.c 

OBJS += \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.o \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.o 

C_DEPS += \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.d \
./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/CMSIS-DSP/Source/BasicMathFunctions/%.o Libs/CMSIS-DSP/Source/BasicMathFunctions/%.su Libs/CMSIS-DSP/Source/BasicMathFunctions/%.cyclo: ../Libs/CMSIS-DSP/Source/BasicMathFunctions/%.c Libs/CMSIS-DSP/Source/BasicMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/src -I../Libs/tinyusb/hw -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-BasicMathFunctions

clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-BasicMathFunctions:
	-$(RM) ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_abs_q15.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f32.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_q15.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mat_vec_mult_f32.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_f32.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_mult_q15.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_f32.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_offset_q31.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_f32.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q15.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_scale_q31.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q15.su ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.cyclo ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.d ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.o ./Libs/CMSIS-DSP/Source/BasicMathFunctions/arm_shift_q31.su

.PHONY: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-BasicMathFunctions

