################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\ASUS\eclipse-workspace\WML_SmartSensor_Slave\myADC" -I"C:\Users\ASUS\eclipse-workspace\WML_SmartSensor_Slave\mySmartSensor" -I"C:\Users\ASUS\eclipse-workspace\WML_SmartSensor_Slave\mySPI" -I"C:\Users\ASUS\eclipse-workspace\WML_SmartSensor_Slave\myUART" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


