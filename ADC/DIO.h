/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#ifndef DIO_H_
#define DIO_H_


void DIO_vidSetPortDirection(u8 PortNumber , u8 Value) ;
void DIO_vidSetPortValue(u8 PortNumber , u8 Value);
u8 DIO_u8ReadPort(u8 PortNumber);
void DIO_vidSetPinValue (u8 PortNumber , u8 PinNumber , u8 value );
void DIO_vidSetPinDirection (u8 PortNumber , u8 PinNumber , u8 value );
u8 DIO_u8ReadPinValue (u8 PortNumber , u8 PinNumber );


#endif /* DIO_H_ */
