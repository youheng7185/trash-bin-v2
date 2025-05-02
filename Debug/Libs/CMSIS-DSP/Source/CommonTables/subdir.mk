################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.c \
../Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.c \
../Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.c 

OBJS += \
./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.o \
./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.o \
./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.o 

C_DEPS += \
./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.d \
./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.d \
./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/CMSIS-DSP/Source/CommonTables/%.o Libs/CMSIS-DSP/Source/CommonTables/%.su Libs/CMSIS-DSP/Source/CommonTables/%.cyclo: ../Libs/CMSIS-DSP/Source/CommonTables/%.c Libs/CMSIS-DSP/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Libs/CMSIS-DSP/Include -I../Libs/tinyusb/src -I../Libs/tinyusb/hw -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables

clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables:
	-$(RM) ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.cyclo ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.d ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.o ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables.su ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.cyclo ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.d ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.o ./Libs/CMSIS-DSP/Source/CommonTables/arm_common_tables_f16.su ./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.cyclo ./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.d ./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.o ./Libs/CMSIS-DSP/Source/CommonTables/arm_const_structs.su

.PHONY: clean-Libs-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables

