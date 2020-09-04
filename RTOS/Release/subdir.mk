################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../LCD.c \
../RTOS_LAB1_ATMEGA32.c \
../croutine.c \
../heap_3.c \
../lcd_4bit.c \
../list.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO.o \
./LCD.o \
./RTOS_LAB1_ATMEGA32.o \
./croutine.o \
./heap_3.o \
./lcd_4bit.o \
./list.o \
./port.o \
./queue.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO.d \
./LCD.d \
./RTOS_LAB1_ATMEGA32.d \
./croutine.d \
./heap_3.d \
./lcd_4bit.d \
./list.d \
./port.d \
./queue.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


