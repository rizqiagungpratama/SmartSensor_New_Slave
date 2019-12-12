################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include myUART/subdir.mk
-include mySmartSensor/subdir.mk
-include mySPI/subdir.mk
-include myADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
SPI_Slave_Sensor_MEGA_V3.lss \

FLASH_IMAGE += \
SPI_Slave_Sensor_MEGA_V3.hex \

EEPROM_IMAGE += \
SPI_Slave_Sensor_MEGA_V3.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_Slave_Sensor_MEGA_V3.elf secondary-outputs

# Tool invocations
SPI_Slave_Sensor_MEGA_V3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_Slave_Sensor_MEGA_V3.map -mmcu=atmega2560 -o "SPI_Slave_Sensor_MEGA_V3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_Slave_Sensor_MEGA_V3.lss: SPI_Slave_Sensor_MEGA_V3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_Slave_Sensor_MEGA_V3.elf  >"SPI_Slave_Sensor_MEGA_V3.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_Slave_Sensor_MEGA_V3.hex: SPI_Slave_Sensor_MEGA_V3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_Slave_Sensor_MEGA_V3.elf  "SPI_Slave_Sensor_MEGA_V3.hex"
	@echo 'Finished building: $@'
	@echo ' '

SPI_Slave_Sensor_MEGA_V3.eep: SPI_Slave_Sensor_MEGA_V3.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SPI_Slave_Sensor_MEGA_V3.elf  "SPI_Slave_Sensor_MEGA_V3.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_Slave_Sensor_MEGA_V3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t SPI_Slave_Sensor_MEGA_V3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_Slave_Sensor_MEGA_V3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
