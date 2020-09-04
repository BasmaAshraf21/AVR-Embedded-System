/*
 * registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x38)
#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)
#define PINC *((volatile u8*)0x33)
#define PIND *((volatile u8*)0x30)
// Interrupt & Timer registers, 8bit
#define SREG *((volatile u8*)0x5F)
#define MCUCR *((volatile u8*)0x55)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)
#define TCNT0 *((volatile u8*)0x52)
#define TCCR0 *((volatile u8*)0x53)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)
#define OCR0 *((volatile u8*)0x5C)
//Interrupt & Timer registers, 16bit
#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define OCR1A *((volatile u16*)0x4A)
#define TNT1H *((volatile u8*)0x4D)
#define TNT1L *((volatile u8*)0x4C)
#define ICR1 *((volatile u16*)0x46)
//ADC
#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCm *((volatile u16*)0x24)
//USART
#define UCSRB *((volatile u8*)0x2A)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UDR *((volatile u8*)0x2C)
// SPI
#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)
// I2C
#define TWDR *((volatile u8*)0x23)
#define TWAR *((volatile u8*)0x22)
#define TWSR *((volatile u8*)0x21)
#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#endif /* REGISTERS_H_ */
