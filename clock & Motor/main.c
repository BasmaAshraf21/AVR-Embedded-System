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
 //ISR
	 #define __INTR_ATTRS used, externally_visible
	u16 counter=0, sec=0,mins=0,hours=0;

	void __vector_11 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
	void __vector_11 (void)
	{
		counter++;
		if(counter==31250){
		sec++;
		counter=0;}
		if(sec==60)
		{
			mins++;
			sec=0;
		}
		if(mins==60)
		{
			hours++;
			mins=0;
		}


}
int main (void)
{

	// Clock & Motor

	 u8 i , value,direction=0;
	 u8 keyflag[16] = {0} ;

	keybad_vidinit() ;
	Timer_Normal_Mode();
	//Motor & Keypad

	DIO_vidSetPortDirection(MOTOR_PORT,255);
	clr_bit(PORTB,0);
	clr_bit(PORTB,1);


			while (1)
			{
				LCD_vidInit() ;
				if(hours<10){
					LCD_vidSetPosition(0,0);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(hours);
					}
					else{
					LCD_vidSetPosition(0,0);
					LCD_vidWriteNumber(hours);
					}
					LCD_vidSetPosition(0,2);
					LCD_vidWriteChar(0b00111010);
					if(mins<10){
					LCD_vidSetPosition(0,3);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(mins);
					}
					else
					{
						LCD_vidSetPosition(0,3);
						LCD_vidWriteNumber(mins);
					}
					LCD_vidSetPosition(0,5);
					LCD_vidWriteChar(0b00111010);
					if(sec<10){
					LCD_vidSetPosition(0,6);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(sec);
					}
					else
					{
						LCD_vidSetPosition(0,6);
						LCD_vidWriteNumber(sec);
					}
				for (i=1 ; i<4 ; i++)
				{
					value = keybad_u8GetButtonStatus(i);
					if (value == 1 && keyflag[i]==0 )
					{
						if(i==1)
						{
							if(direction!= 0)
							{

								clr_bit(PORTB,0);
								clr_bit(PORTB,1);
								direction=0;
							}
							else if(direction!=1)
							{
								set_bit(PORTB,0);
								set_bit(PORTB,1);
								direction=1;
							}
							keyflag[i]=1;
						}
						else if(i==2)
						{
							clr_bit(PORTB,0);
							set_bit(PORTB,1);
							keyflag[i]=1;
						}
						else if(i==3)
						{
							clr_bit(PORTB,0);
							clr_bit(PORTB,1);
							direction=0;
							keyflag[i]=1;
						}
						else
						{
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

