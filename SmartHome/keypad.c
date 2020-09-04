/*
 * keypad.c
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
#include"keybad.h"
#include"keybad_cfg.h"


void keybad_vidinit(void)
{
	DIO_vidSetPinDirection(keybad_port , R1 , 0);
	DIO_vidSetPinDirection(keybad_port , R2 , 0);
	DIO_vidSetPinDirection(keybad_port , R3 , 0);
	DIO_vidSetPinDirection(keybad_port , R4 , 0);

	DIO_vidSetPinValue(keybad_port , R1 , 1) ;
	DIO_vidSetPinValue(keybad_port , R2 , 1) ;
	DIO_vidSetPinValue(keybad_port , R3 , 1) ;
	DIO_vidSetPinValue(keybad_port , R4 , 1) ;

	DIO_vidSetPinDirection(keybad_port , C1 , 1);
	DIO_vidSetPinDirection(keybad_port , C2 , 1);
	DIO_vidSetPinDirection(keybad_port , C3 , 1);
	DIO_vidSetPinDirection(keybad_port , C4 , 1);
}

u8 keybad_u8GetButtonStatus(u8 butthon_no)
{
	u8 real_col [] = {C1 ,C2 , C3 , C4 } ;
	u8 real_row [] = {R1 , R2 , R3 , R4 } ;
	u8 value ;
	u8 status = 0 ;

	u8 row = ((butthon_no-1)/4)+1;
	u8 col = ((butthon_no-1)%4)+1;

	DIO_vidSetPinValue(keybad_port , C1 , 1);
	DIO_vidSetPinValue(keybad_port , C2 , 1);
	DIO_vidSetPinValue(keybad_port , C3 , 1);
	DIO_vidSetPinValue(keybad_port , C4 , 1);

	DIO_vidSetPinValue(keybad_port , real_col[col-1] , 0);

	value = DIO_u8ReadPinValue(keybad_port , real_row[row-1] );

	if (value == 0 )

	{
		_delay_ms(20);
		value = DIO_u8ReadPinValue(keybad_port , real_row[row-1] );
		if (value == 0)
		{
			status = 1 ;
		}
	}
	return status ;
}
