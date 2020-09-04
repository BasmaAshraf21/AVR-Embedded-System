################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../I2C.c \
../LCD.c \
../SPI.c \
../Timer.c \
../UART.c \
../eeprom.c \
../keypad.c \
../main.c 

OBJS += \
./ADC.o \
./DIO.o \
./I2C.o \
./LCD.o \
./SPI.o \
./Timer.o \
./UART.o \
./eeprom.o \
./keypad.o \
./main.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./I2C.d \
./LCD.d \
./SPI.d \
./Timer.d \
./UART.d \
./eeprom.d \
./keypad.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


