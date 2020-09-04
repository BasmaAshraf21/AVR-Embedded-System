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

	 //Piano
	   u8 i , value;
		u8 keyflag[16] = {0} ;
		keybad_vidinit() ;
		//fast PWM mode
			//set_bit(TCCR0,0);
			set_bit(TCCR0,1);
			//set_bit(TCCR0,2);
			set_bit(TCCR0,3);
			set_bit(TCCR0,4);
			//set_bit(TCCR0,5);
			//set_bit(TCCR0,6);
			// OCR
			// set CO0 o/p
			DIO_vidSetPinDirection(2,3,1);
	while (1)
	{
		for (i=1 ; i<17 ; i++)
						{
							value = keybad_u8GetButtonStatus(i);
							if (value == 1 && keyflag[i]==0 )
							{
								if(i==1)
								{
									OCR0=240;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==2)
								{
									OCR0=212;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==3)
								{
									OCR0=188;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==4)
								{
									OCR0=180;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==5)
								{
									OCR0=160;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==6)
								{
									OCR0=142;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==7)
								{
									OCR0=126;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==8)
								{
									OCR0=120;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==9)
								{
									OCR0=106;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==10)
								{
									OCR0=94;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==11)
								{
									OCR0=90;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==12)
								{
									OCR0=80;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==13)
								{
									OCR0=71;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==14)
								{
									OCR0=63;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==15)
								{
									OCR0=60;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==16)
								{
									OCR0=0;
									keyflag[i]=1;
								}

							}
							else if(value == 0)
							{
								keyflag[i]=0;
							}
						}

	}


}

