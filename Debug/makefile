################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include Libs/tinyusb/src/typec/subdir.mk
-include Libs/tinyusb/src/portable/wch/subdir.mk
-include Libs/tinyusb/src/portable/valentyusb/eptri/subdir.mk
-include Libs/tinyusb/src/portable/ti/msp430x5xx/subdir.mk
-include Libs/tinyusb/src/portable/template/subdir.mk
-include Libs/tinyusb/src/portable/synopsys/dwc2/subdir.mk
-include Libs/tinyusb/src/portable/sunxi/subdir.mk
-include Libs/tinyusb/src/portable/st/typec/subdir.mk
-include Libs/tinyusb/src/portable/st/stm32_fsdev/subdir.mk
-include Libs/tinyusb/src/portable/sony/cxd56/subdir.mk
-include Libs/tinyusb/src/portable/renesas/rusb2/subdir.mk
-include Libs/tinyusb/src/portable/raspberrypi/rp2040/subdir.mk
-include Libs/tinyusb/src/portable/raspberrypi/pio_usb/subdir.mk
-include Libs/tinyusb/src/portable/ohci/subdir.mk
-include Libs/tinyusb/src/portable/nxp/lpc_ip3511/subdir.mk
-include Libs/tinyusb/src/portable/nxp/lpc17_40/subdir.mk
-include Libs/tinyusb/src/portable/nxp/khci/subdir.mk
-include Libs/tinyusb/src/portable/nuvoton/nuc505/subdir.mk
-include Libs/tinyusb/src/portable/nuvoton/nuc121/subdir.mk
-include Libs/tinyusb/src/portable/nuvoton/nuc120/subdir.mk
-include Libs/tinyusb/src/portable/nordic/nrf5x/subdir.mk
-include Libs/tinyusb/src/portable/mindmotion/mm32/subdir.mk
-include Libs/tinyusb/src/portable/microchip/samx7x/subdir.mk
-include Libs/tinyusb/src/portable/microchip/samg/subdir.mk
-include Libs/tinyusb/src/portable/microchip/samd/subdir.mk
-include Libs/tinyusb/src/portable/microchip/pic32mz/subdir.mk
-include Libs/tinyusb/src/portable/microchip/pic/subdir.mk
-include Libs/tinyusb/src/portable/mentor/musb/subdir.mk
-include Libs/tinyusb/src/portable/espressif/esp32sx/subdir.mk
-include Libs/tinyusb/src/portable/ehci/subdir.mk
-include Libs/tinyusb/src/portable/dialog/da146xx/subdir.mk
-include Libs/tinyusb/src/portable/chipidea/ci_hs/subdir.mk
-include Libs/tinyusb/src/portable/chipidea/ci_fs/subdir.mk
-include Libs/tinyusb/src/portable/bridgetek/ft9xx/subdir.mk
-include Libs/tinyusb/src/portable/analog/max3421/subdir.mk
-include Libs/tinyusb/src/host/subdir.mk
-include Libs/tinyusb/src/device/subdir.mk
-include Libs/tinyusb/src/common/subdir.mk
-include Libs/tinyusb/src/class/video/subdir.mk
-include Libs/tinyusb/src/class/vendor/subdir.mk
-include Libs/tinyusb/src/class/usbtmc/subdir.mk
-include Libs/tinyusb/src/class/net/subdir.mk
-include Libs/tinyusb/src/class/msc/subdir.mk
-include Libs/tinyusb/src/class/midi/subdir.mk
-include Libs/tinyusb/src/class/hid/subdir.mk
-include Libs/tinyusb/src/class/dfu/subdir.mk
-include Libs/tinyusb/src/class/cdc/subdir.mk
-include Libs/tinyusb/src/class/bth/subdir.mk
-include Libs/tinyusb/src/class/audio/subdir.mk
-include Libs/tinyusb/src/subdir.mk
-include Libs/CMSIS-DSP/Source/TransformFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/SupportFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/StatisticsFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/MatrixFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/FastMathFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/ComplexMathFunctions/subdir.mk
-include Libs/CMSIS-DSP/Source/CommonTables/subdir.mk
-include Libs/CMSIS-DSP/Source/BasicMathFunctions/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := rubbish-bin-v3
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
rubbish-bin-v3.elf \

MAP_FILES += \
rubbish-bin-v3.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
rubbish-bin-v3.list \


# All Target
all: main-build

# Main-build Target
main-build: rubbish-bin-v3.elf secondary-outputs

# Tool invocations
rubbish-bin-v3.elf rubbish-bin-v3.map: $(OBJS) $(USER_OBJS) C:\Users\lapchong\Downloads\workspace-new\rubbish-bin-v3\STM32H723ZGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "rubbish-bin-v3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\lapchong\Downloads\workspace-new\rubbish-bin-v3\STM32H723ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="rubbish-bin-v3.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

rubbish-bin-v3.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "rubbish-bin-v3.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout rubbish-bin-v3.elf rubbish-bin-v3.list rubbish-bin-v3.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
