################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Lab3_ClockConfigurations.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lab3_ClockConfigurations.list \

OBJCOPY_BIN += \
Lab3_ClockConfigurations.bin \


# All Target
all: Lab3_ClockConfigurations.elf secondary-outputs

# Tool invocations
Lab3_ClockConfigurations.elf: $(OBJS) $(USER_OBJS) E:\Mastering\ Embedded\ Systems\Unit\ 6\ -\ MicroController\ Architecture\Lesson\ 3\ -\ MCU\ Clocks\Assignment\Lesson\ Labs\Lab3_ClockConfigurations\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Lab3_ClockConfigurations.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Mastering Embedded Systems\Unit 6 - MicroController Architecture\Lesson 3 - MCU Clocks\Assignment\Lesson Labs\Lab3_ClockConfigurations\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lab3_ClockConfigurations.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lab3_ClockConfigurations.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lab3_ClockConfigurations.list"
	@echo 'Finished building: $@'
	@echo ' '

Lab3_ClockConfigurations.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lab3_ClockConfigurations.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
