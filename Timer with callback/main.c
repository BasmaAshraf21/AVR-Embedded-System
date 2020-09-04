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
#include "Timer.h"


 void callback_timer0_ovf(void)
{
	DIO_vidSetPortDirection(2,255);
	toggle_bit(PORTB,7);
}
int main (void)
{

	 // callback
	  set_callback(callback_timer0_ovf);
		DIO_vidSetPortDirection(2,255);
		Timer_Normal_Mode();
		while(1)
		{

		}










}

