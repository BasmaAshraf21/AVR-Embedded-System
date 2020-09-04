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
#define __INTR_ATTRS used, externally_visible
u32 counter=0,flag=0,snap1,snap2,snap3;

void __vector_9 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_9 (void)
{
	counter++;

}
void __vector_6 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_6 (void)
{
	if(flag==0)
	{
		counter=0;
		snap1=ICR1;
		// falling edge
		clr_bit(TCCR1B,6);

	}
	else if(flag==1)
	{
		snap2=ICR1+(counter*65536);
		//raising edge
		set_bit(TCCR1B,6);

	}
	else if(flag==2)
	{
		snap3=ICR1+(counter*65536);
	}
	flag++;

}

int main (void)
{
	// Write PWM on 8 bit & Read PWM
	 *
 	LCD_vidInit();
	u32 duty_cycle,freq;
	//fast PWM mode
	set_bit(TCCR0,0);
	clr_bit(TCCR0,1);
	set_bit(TCCR0,2);
	set_bit(TCCR0,3);
	clr_bit(TCCR0,4);
	set_bit(TCCR0,5);
	set_bit(TCCR0,6);
	// OCR
	OCR0=128;
	// set CO0 o/p
	DIO_vidSetPinDirection(2,3,1);

	// set ICP i/p
	DIO_vidSetPinDirection(4,6,0);
	// raising edge
	set_bit(TCCR1B,6);
	// timer1 normal mode
	clr_bit(TCCR1A,0);
	clr_bit(TCCR1A,1);
	clr_bit(TCCR1A,4);
	clr_bit(TCCR1A,5);
	clr_bit(TCCR1A,6);
	clr_bit(TCCR1A,7);
	clr_bit(TCCR1B,3);
	clr_bit(TCCR1B,4);
	// timer prescaler
	set_bit(TCCR1B,0);
	clr_bit(TCCR1B,1);
	clr_bit(TCCR1B,2);
	//enable global
	set_bit(SREG,7);
	set_bit(TIMSK,5);
	set_bit(TIMSK,2);
	while(1){
	if(flag==3)
	{
		clr_bit(SREG,7);
		duty_cycle=((snap2-snap1)*100)/(snap3-snap1);
		freq=8000000/(snap3-snap1);
		LCD_vidSetPosition(0,0);
		LCD_vidWriteNumber(duty_cycle);
		LCD_vidSetPosition(1,0);
		LCD_vidWriteNumber(freq);
		flag=0;
		clr_bit(TIFR,5);
		set_bit(SREG,7);
	}
	}

}

