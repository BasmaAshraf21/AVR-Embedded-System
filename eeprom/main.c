/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#define FCPU 8000000
#include<util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"types.h"
#include "registers.h"
#include"macros.h"
#include "DIO.h"
#include "Motor_cfg.h"
#include"LCD.h"
#include "Timer.h"
#include"keybad.h"
#include"keybad_cfg.h"
#include"ADC.h"
#include"Uart.h"
#include"SPI.h"
#include"I2C.h"
#include"eeprom.h"

int main (void)
{
	LCD_vidInit();
	DIO_vidSetPinDirection(3,0,1);
	DIO_vidSetPinDirection(3,1,1);
	u8 data;
	eeprom_init();
	eeprom_write_byte(0x05,0x06);
	_delay_ms(1000);
	data = eeprom_read_byte(0x05);
	LCD_vidWriteNumber(data);


}

