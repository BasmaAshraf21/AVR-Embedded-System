/*
 * Timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */
#include"types.h"
#include"registers.h"
#include "macros.h"
#define __INTR_ATTRS used, externally_visible
u16 counter=0;
void(*ptr)(void);
void __vector_11 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_11 (void)
{

	counter++;
	if(counter==33){
	ptr();
	counter=0;
	}



}
void set_callback(void(*callback)(void))
{
	ptr = callback;
}

void Timer_Normal_Mode(void)
{
	// Timer with normal mode
				set_bit(TCCR0,0);
				clr_bit(TCCR0,1);
				clr_bit(TCCR0,2);
				clr_bit(TCCR0,3);
				clr_bit(TCCR0,4);
				clr_bit(TCCR0,5);
				clr_bit(TCCR0,6);
				clr_bit(TCCR0,7);
				set_bit(TIMSK,0);
				clr_bit(TIMSK,1);
				set_bit(SREG,7);

}

