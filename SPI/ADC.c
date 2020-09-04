/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */
#include"types.h"
#include"registers.h"
#include"macros.h"
#include"DIO.h"
void ADC_vidInit(void)
{
	// I/P
	DIO_vidSetPinDirection(1,0,0);
	//channel 0
	clr_bit(ADMUX,0);
	clr_bit(ADMUX,1);
	clr_bit(ADMUX,2);
	clr_bit(ADMUX,3);
	clr_bit(ADMUX,4);
	//Enable The ADC
	set_bit(ADCSRA,7);
	//V ref
	set_bit(ADMUX,6);
	clr_bit(ADMUX,7);
	//prescaler 128
	set_bit(ADCSRA,0);
	set_bit(ADCSRA,1);
	set_bit(ADCSRA,2);
	//Start Conversion & single conversion
	set_bit(ADCSRA,6);
	// Left ADj
	clr_bit(ADMUX,5);
	// interrupt Enable disactivated
	clr_bit(ADCSRA,3);

}

u8 ADC_u8GetResult(u16* result)
{	u8 flag=0;
	if((get_bit(ADCSRA,4))==1)
	{
		*result=ADCm;
		flag = 1;
		// clear Interrupt flag
		set_bit(ADCSRA,4);
		//Start Conversion & single conversion
		set_bit(ADCSRA,6);
	}
	else if((get_bit(ADCSRA,4))==0)
	{
		flag=0;
	}
	return flag;
}
