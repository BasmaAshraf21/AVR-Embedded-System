/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */
#define FCPU 8000000
#include<util/delay.h>
#include"types.h"
#include"registers.h"
#include"macros.h"
#include"LCD_cfg.h"
#include"LCD.h"
#include"DIO.h"

void UART_vidInit(void)
{
	DIO_vidSetPinDirection(4,1,0);
	DIO_vidSetPinDirection(4,0,1);
	//receive Enable
	set_bit(UCSRB,4);
	// asynchronous
	//clr_bit(UCSRC,6);
	//clr_bit(UCSRC,0);
	//transmition disable
	set_bit(UCSRB,3);
	// no parity
	//clr_bit(UCSRC,4);1
	//clr_bit(UCSRC,5);
	//set_bit(UCSRC,7);
	// data bit
	//set_bit(UCSRC,1);
	//set_bit(UCSRC,2);
	clr_bit(UCSRB,2);
	// one bit stop
	//clr_bit(UCSRC,3);
	// 9600
	UBRRL=51;
	clr_bit(UCSRA,4);
	clr_bit(UCSRA,2);
	clr_bit(UCSRA,1);
	UCSRC=0b10000110;
	UCSRC=0;

}

u8 UART_Receiver(void)
{
	while((get_bit(UCSRA,7))==0)
	{

	}
	return UDR;
}

void UART_Transmition(u32 ch)
{
	UDR = ch;
	while((get_bit(UCSRA,6))==0)
	{

	}

}
