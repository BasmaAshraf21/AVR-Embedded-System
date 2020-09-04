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
	 //SPI

	  // slave
		SPI_vidMasterInit();
		LCD_vidInit();
		u8 data;
		u8 recive;
		_delay_ms(3000);
		while(1)
		{

		recive=SPI_Transiver(5);
		_delay_ms(3000);
		LCD_vidWriteChar(recive);
		}
	  // master
		SPI_vidMasterInit();
		LCD_vidInit();
		u8 data;
		u8 recive;
		_delay_ms(3000);
		while(1)
		{

		recive=SPI_Transiver(5);
		_delay_ms(3000);
		LCD_vidWriteChar(recive);
		}


}

