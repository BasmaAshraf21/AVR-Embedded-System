/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */


#include"types.h"
#include"registers.h"
#include "macros1.h"


void DIO_vidSetPortDirection(u8 PortNumber , u8 Value)
{
	switch (PortNumber)
	{
	case 1 :
		DDRA = Value ;
		break ;
	case 2 :
		DDRB = Value ;
		break ;
	case 3 :
		DDRC = Value ;
		break ;
	case 4 :
		DDRD = Value ;
		break ;
	}
}
void DIO_vidSetPortValue(u8 PortNumber , u8 Value)
{
	switch (PortNumber)
	{
	case 1 :
		PORTA = Value ;
		break ;
	case 2 :
		PORTB = Value ;
		break ;
	case 3 :
		PORTC = Value ;
		break ;
	case 4 :
		PORTD = Value ;
		break ;
	}
}

u8 DIO_u8ReadPort(u8 PortNumber)
{
	u8 value ;
	switch (PortNumber)
	{
	case 1 :
		value = PINA ;
		break ;
	case 2 :
		value = PINB ;
		break ;
	case 3 :
		value = PINC ;
		break ;
	case 4 :
		value = PIND ;
		break ;
	}
	return value ;
}

void DIO_vidSetPinValue (u8 PortNumber , u8 PinNumber , u8 value )
{
	switch(PortNumber)
	{
	case 1 :
		if (value == 1 )
		{
			set_bit(PORTA,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(PORTA , PinNumber);
		}
		break ;

	case 2 :
		if (value == 1 )
		{
			set_bit(PORTB,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(PORTB , PinNumber);
		}
		break ;
	case 3 :
		if (value == 1 )
		{
			set_bit(PORTC,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(PORTC , PinNumber);
		}
		break ;

	case 4 :
		if (value == 1 )
		{
			set_bit(PORTD,PinNumber) ;
		}

		else if (value == 0 )
		{
			clr_bit(PORTD , PinNumber);
		}
		break ;
	}
}

void DIO_vidSetPinDirection (u8 PortNumber , u8 PinNumber , u8 value )
{
	switch(PortNumber)
	{
	case 1 :
		if (value == 1 )
		{
			set_bit(DDRA,PinNumber) ;

		}
		else if (value == 0 )
		{
			clr_bit(DDRA , PinNumber);
		}
		break ;

	case 2 :
		if (value == 1 )
		{
			set_bit(DDRB,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(DDRB , PinNumber);
		}
		break ;
	case 3 :
		if (value == 1 )
		{
			set_bit(DDRC,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(DDRC , PinNumber);
		}
		break ;
	case 4 :
		if (value == 1 )
		{
			set_bit(DDRD,PinNumber) ;
		}
		else if (value == 0 )
		{
			clr_bit(DDRD , PinNumber);
		}
		break ;
	}
}
u8 DIO_u8ReadPinValue (u8 PortNumber , u8 PinNumber )
{
	u8 value ;
	switch (PortNumber)
	{
	case 1 :
		value = get_bit(PINA , PinNumber) ;
		break ;

	case 2 :
		value = get_bit(PINB , PinNumber) ;
		break ;

	case 3 :
		value = get_bit(PINC , PinNumber) ;
		break ;

	case 4 :
		value = get_bit(PIND , PinNumber) ;
		break ;

	}
	return value ;
}
