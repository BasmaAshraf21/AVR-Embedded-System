/*
 * LCD.c
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

#define lcd_8bit

#ifdef lcd_4bit

void LCD_vidWriteChar(u8 data)
{
	DIO_vidSetPinValue(LCD_ControlPort , RW , 0 ) ;
	DIO_vidSetPinValue(LCD_ControlPort , RS , 1 ) ;
	DIO_vidSetPortValue(LCD_DataPort , data) ;

	DIO_vidSetPinValue(LCD_ControlPort , E , 1 ) ;
	_delay_ms(1) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 0 ) ;
	_delay_ms(1) ;


}

void LCD_vidWriteCommand(u8 command)
{
	DIO_vidSetPinValue(LCD_ControlPort , RW , 0 ) ;
	DIO_vidSetPinValue(LCD_ControlPort , RS , 0 ) ;
	DIO_vidSetPortValue(LCD_DataPort , command) ;

	DIO_vidSetPinValue(LCD_ControlPort , E , 1 ) ;
	_delay_ms(1) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 0 ) ;
	_delay_ms(1) ;


}


void LCD_vidInit(void)
{
	DIO_vidSetPinDirection(LCD_ControlPort , RS , 1 );
	DIO_vidSetPinDirection(LCD_ControlPort , RW , 1 );
	DIO_vidSetPinDirection(LCD_ControlPort , E , 1 );

	DIO_vidSetPortDirection(LCD_DataPort , 255 ) ;

	// page 13 , 16 data sheet

	_delay_ms(70);
	LCD_vidWriteCommand(0b00100000) ;
	LCD_vidWriteCommand(0b00100000) ;
	LCD_vidWriteCommand(0b10000000) ;
	_delay_ms(1);
	LCD_vidWriteCommand(0b00000000);
	LCD_vidWriteCommand(0b11000000);
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000000);
	LCD_vidWriteCommand(0b00010000);
}

void LCD_vidWriteString(u8*ptr)
{
	u8 i=0 ;
	while (ptr[i]!=0)  //\0 null character
	{
		LCD_vidWriteChar(ptr[i]);
		i++ ;
	}
}

void LCD_vidWriteNumber(u32 number)
{
	u32 reversed_number = 1 ;
	if (number == 0 )
	{
		LCD_vidWriteChar('0') ;
	}

	while (number!=0)
	{
		reversed_number = number%10 + reversed_number*10 ;
		number/=10 ;
	}
	while (reversed_number != 1 )
	{
		LCD_vidWriteChar(reversed_number%10 + '0');
		reversed_number /= 10 ;
	}
}

void LCD_vidSetPosition(u8 row , u8 colum)
{
	if (row == 0 )
	{
		LCD_vidWriteCommand(128+colum) ;
	}
	else if (row == 1)
	{
		LCD_vidWriteCommand(128+64+colum);
	}
}

#endif



#ifdef lcd_8bit

 void LCD_vidWriteChar(u8 data)
{
	DIO_vidSetPinValue(LCD_ControlPort , RW , 0 ) ;
	DIO_vidSetPinValue(LCD_ControlPort , RS , 1 ) ;
	DIO_vidSetPortValue(LCD_DataPort , data) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 1 ) ;
	_delay_ms(1) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 0 ) ;
	_delay_ms(1) ;
}



void LCD_vidWriteCommand(u8 command)
{
	DIO_vidSetPinValue(LCD_ControlPort , RW , 0 ) ;
	DIO_vidSetPinValue(LCD_ControlPort , RS , 0 ) ;
	DIO_vidSetPortValue(LCD_DataPort , command) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 1 ) ;
	_delay_ms(1) ;
	DIO_vidSetPinValue(LCD_ControlPort , E , 0 ) ;
	_delay_ms(1) ;
}


void LCD_vidInit(void)
{
	DIO_vidSetPinDirection(LCD_ControlPort , RS , 1 );
	DIO_vidSetPinDirection(LCD_ControlPort , RW , 1 );
	DIO_vidSetPinDirection(LCD_ControlPort , E , 1 );

	DIO_vidSetPortDirection(LCD_DataPort , 255) ;

	// page 13 , 16 data sheet

	_delay_ms(50);
	LCD_vidWriteCommand(0b00111000) ;
	_delay_ms(1);
	LCD_vidWriteCommand(0b00001100);
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000001);
}

void LCD_vidWriteString(u8*ptr)
{
	u8 i=0 ;
	while (ptr[i]!=0)  //\0 null character
	{
		LCD_vidWriteChar(ptr[i]);
		i++ ;
	}
}

void LCD_vidWriteNumber(u32 number)
{
	u32 reversed_number = 1 ;
	if (number == 0 )
	{
		LCD_vidWriteChar('0') ;
	}

	while (number!=0)
	{
		reversed_number = number%10 + reversed_number*10 ;
		number/=10 ;
	}
	while (reversed_number != 1 )
	{
		LCD_vidWriteChar(reversed_number%10 + '0');
		reversed_number /= 10 ;
	}
}

void LCD_vidSetPosition(u8 row , u8 colum)
{
	if (row == 0 )
	{
		LCD_vidWriteCommand(128+colum) ;
	}
	else if (row == 1)
	{
		LCD_vidWriteCommand(128+64+colum);
	}
}

#endif
