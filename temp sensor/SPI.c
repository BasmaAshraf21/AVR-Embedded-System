/*
 * SPI.c
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

void SPI_vidMasterInit(void)
{
	DIO_vidSetPinDirection(2,5,1); //MOSI
	DIO_vidSetPinDirection(2,6,0); //MISO
	DIO_vidSetPinDirection(2,7,1); //SCK
	DIO_vidSetPinDirection(2,4,1);
	DIO_vidSetPinValue(2,4,0);
	DIO_vidSetPinDirection(4,0,1);
	DIO_vidSetPinValue(4,0,0);
	clr_bit(SPCR,7); // flag
	set_bit(SPCR,6); // SPI enable
	set_bit(SPCR,5); // LSB
	set_bit(SPCR,4); // master
	clr_bit(SPCR,3); // rising
	clr_bit(SPCR,2); // clock phase
	// clock rate select
	set_bit(SPCR,1);
	set_bit(SPCR,0);
	set_bit(SPSR,0);

}
void SPI_vidSlaveInit(void)
{
	DIO_vidSetPinDirection(2,5,0); //MOSI
	DIO_vidSetPinDirection(2,6,1); //MISO
	DIO_vidSetPinDirection(2,7,0); //SCK
	DIO_vidSetPinDirection(2,4,0); // chip select active low i/p
	clr_bit(SPCR,7); // flag
	set_bit(SPCR,6); // SPI enable
	set_bit(SPCR,5); // LSB
	clr_bit(SPCR,4); // slave
	clr_bit(SPCR,3); // clock polarity rising
	clr_bit(SPCR,2); // clock phase

}

u8 SPI_Transiver(u8 data)
{
	SPDR=data;
	while(get_bit(SPSR,7)==0)
	{

	}
	return SPDR;
}
