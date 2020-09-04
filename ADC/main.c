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

	 //ADC
	  LCD_vidInit();
	u16 result,v_digital,v_analog;
	u8 right_number,second_number;
	u8 flag;
	ADC_vidInit();

	while(1)
	{
		flag = ADC_u8GetResult(&result);
	if (flag==1)
	{
		v_digital = result;
		v_analog= (v_digital*5)/1023;
		right_number = (((u32)v_digital *500)/1023)/100;
		second_number = (((u32)v_digital *500)/1023)%100;
		LCD_vidSetPosition(0,0);
		LCD_vidWriteNumber(right_number);
		LCD_vidWriteChar(0b00101110);
		LCD_vidWriteNumber(second_number);
		LCD_vidWriteString("  ");
		LCD_vidSetPosition(1,0);
		LCD_vidWriteNumber(v_digital);
		LCD_vidWriteString("  ");
	}
	}

}

