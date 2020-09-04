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
#include"LCD.h"


int main (void)
{

//  two Direction to Motor with 2 relay
	DIO_vidSetPortDirection(4,255);
		while(1){

		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,0);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,1);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,1);
		DIO_vidSetPinValue(4,1,1);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,1);

		}


	return 1 ;
}
//  two Direction to Motor with 4 NPN
   DIO_vidSetPortDirection(4,255);
		while(1){

		DIO_vidSetPinValue(4,0,1);
		DIO_vidSetPinValue(4,1,0);
		DIO_vidSetPinValue(4,2,1);
		DIO_vidSetPinValue(4,3,0);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,0);
		DIO_vidSetPinValue(4,2,0);
		DIO_vidSetPinValue(4,3,0);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,1);
		DIO_vidSetPinValue(4,2,0);
		DIO_vidSetPinValue(4,3,1);
		_delay_ms(1000);
		DIO_vidSetPinValue(4,0,0);
		DIO_vidSetPinValue(4,1,0);
		DIO_vidSetPinValue(4,2,0);
		DIO_vidSetPinValue(4,3,0);

		}


}

