/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#define FCPU 8000000
#define pass 6
#include<util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"types.h"
#include "registers.h"
#include"macros.h"
#include "DIO.h"
#include "Motor_cfg.h"
#include"LCD.h"
#include "Timer.h"
#include"keybad.h"
#include"keybad_cfg.h"
#include"ADC.h"
#include"Uart.h"
#include"SPI.h"
#include"I2C.h"
#include"eeprom.h"
/*
 //bit field

typedef union
{
	struct
	{
		u8 bit0:1;
		u8 bit1:1;
		u8 bit2:1;
		u8 bit3:1;
		u8 bit4:1;
		u8 bit5:1;
		u8 bit6:1;

	};
	u8 byte;
}my_register;
#define newDDRB (*((my_register*)0x37))
#define newPORTB (*((my_register*)0x38))*/

int main (void)
{

	 //smart home

	  //UART

			LCD_vidInit();
			UART_vidInit();
			DIO_vidSetPinDirection(2,6,1);
			u8 value=0;
			// Servo 90 & 180 & 0 Degree with Fast PWM & 16 bit
					 // Fast PWM
						clr_bit(TCCR1A,0);
						set_bit(TCCR1A,1);
						clr_bit(TCCR1A,3);
						set_bit(TCCR1B,3);
						set_bit(TCCR1B,4);

						// set @ top clear @ match
						clr_bit(TCCR1A,4);
						set_bit(TCCR1A,5);
						clr_bit(TCCR1A,6);
						set_bit(TCCR1A,7);

						// prescaler = 8
						clr_bit(TCCR1B,0);
						set_bit(TCCR1B,1);
						clr_bit(TCCR1B,2);

						set_bit(TCCR1B,6);

						// O/P
						DIO_vidSetPinDirection(4,5,1);
						//20,000->ISR
						ICR1 =20000;

			u16 password = 0;
			u16 done = 0;
			while(done == 0){
			password = UART_Receiver();
			if(password == pass)
			{
				UART_Transmition('E');
				done = 6;
			while(1)
			{

				value = UART_Receiver();
				if(value==1)
				{
				 DIO_vidSetPinValue(2,6,1);
				 UART_Transmition('N');
				}
				if(value==2)
				{
					DIO_vidSetPinValue(2,6,0);
					UART_Transmition('F');

				}
				if(value==3)
				{
					OCR1A = 300;
					_delay_ms(1000);
					OCR1A = 1250;
					_delay_ms(1000);
					OCR1A = 2300;
					_delay_ms(1000);
					OCR1A = 1250;
					_delay_ms(1000);

				}
				LCD_vidWriteNumber(value);

			}

			}
			else
				{
					UART_Transmition('try agin');
				}
			}//end of pro

	/*
// stepper Motor

	DIO_vidSetPortDirection(4,255);
while(1){
	DIO_vidSetPortValue(4,0b00001001);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00000001);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00000011);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00000010);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00000110);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00000100);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00001100);
	_delay_ms(50);
	DIO_vidSetPortValue(4,0b00001000);
	_delay_ms(50);
} // end of code




 //bit field
	newDDRB.byte =255;
	newPORTB.bit4 = 1;
*/


	/*
	 *
	 // pasword with eeprom
	DIO_vidSetPinDirection(3,0,1);
	DIO_vidSetPinDirection(3,1,1);
	eeprom_init();
	u8 x=123;
	//eeprom_write_byte(0x05,x);
	_delay_ms(1000);
	u8 password;
	password = eeprom_read_byte(0x05);
	keybad_vidinit();
	LCD_vidInit();
	//LCD_vidWriteNumber(password);
	u8 pass =0,newpass=0,confpass=0;
	//u32 password=567;
	LCD_vidWriteString("Enter Password");
	LCD_vidSetPosition(1,1);
	u8 i,k=0,j=0,p=0,value,result=0,button;
	u8 keyflag[16] = {0} ;
	u8 A[3]={0};
		while (1)
		{

		for (i=1 ; i<13 ; i++)
		{
			value = keybad_u8GetButtonStatus(i);
			if (value == 1 && keyflag[i]==0 )
			{
				if(i<11)
				{
					LCD_vidWriteChar(0b00101010);
					A[j] = i;
					j++;
					keyflag[i]=1;

				}
				else if(i==11)
				{
					LCD_vidWriteCommand(0x01);
					keyflag[i]=1;
					j=0;
				}
				else if(i==12)
				{
					p++;
					keyflag[i]=1;

				if(j==3)
				{
				if(p==1){
				for(k=0; k<3;k++)
				{

					pass = 10*pass+A[k];

				}
				if(pass == password)
				{
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Welcome");
					_delay_ms(1000);
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Enter New pass");
					LCD_vidSetPosition(1,1);
					j=0;


				}
				else
				{

					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Error1,try Again");
					_delay_ms(3000);

				}
				}
				else if(p==2)
				{
					for(k=0; k<3;k++)
					{
						newpass = 10*newpass+A[k];
					}
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Enter Confirm pass");
					LCD_vidSetPosition(1,1);
					j=0;
				}
				else if(p==3)
				{
				for(k=0; k<3;k++)
				{
					confpass = 10*confpass+A[k];
				}
				if(newpass == confpass)
					{
						LCD_vidWriteCommand(0x01);
						LCD_vidWriteString("Done");
						j=0;
						eeprom_init();
						eeprom_write_byte(0x05,confpass);
						_delay_ms(1000);

					}
				else
				{

					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Error,try Again");
					_delay_ms(3000);

				}

				}
				}
				}


	}
		else if(value == 0)
		{
			keyflag[i]=0;
		}

		}
		}
	 //eeprom
	  LCD_vidInit();
	DIO_vidSetPinDirection(3,0,1);
	DIO_vidSetPinDirection(3,1,1);
	u8 data;
	eeprom_init();
	//eeprom_write_byte(0x05,0x06);
	//_delay_ms(1000);
	data = eeprom_read_byte(0x05);
	LCD_vidWriteNumber(data);
	 // callback
	  void callback_timer0_ovf(void)
{
	DIO_vidSetPortDirection(2,255);
	toggle_bit(PORTB,7);
}
	  set_callback(callback_timer0_ovf);

	DIO_vidSetPortDirection(2,255);
	Timer_Normal_Mode();
	while(1)
	{

	}
	 //SPI
	  *
	  // slave
	   SPI_vidMasterInit();
		LCD_vidInit();
		u8 data;
		u8 recive;
		_delay_ms(3000);
		while(1)
		{

		recive=SPI_Transiver(5);
		_delay_ms(3000);
		LCD_vidWriteChar(recive);
		}
	  // master
	 SPI_vidMasterInit();
	LCD_vidInit();
	u8 data;
	u8 recive;
	_delay_ms(3000);
	while(1)
	{

	recive=SPI_Transiver(5);
	_delay_ms(3000);
	LCD_vidWriteChar(recive);
	}

	 //UART
	  u8 value=0;
		LCD_vidInit();
		UART_vidInit();

		while(1)
		{

			value = UART_Receiver();
			LCD_vidWriteChar(value);
		}

	 // lid sensor
	  LCD_vidInit();
		u16 result,v_digital;
		u8 right_number;
		u8 flag;
		ADC_vidInit();

		while(1)
		{
			flag = ADC_u8GetResult(&result);
		if (flag==1)
		{
			v_digital = result;
			LCD_vidSetPosition(0,0);
			LCD_vidWriteNumber(v_digital);
			LCD_vidWriteString("  ");
		}
		}

	 //temp sensor
	   LCD_vidInit();
		u16 result,v_digital;
		u8 right_number;
		u8 flag;
		ADC_vidInit();

		while(1)
		{
			flag = ADC_u8GetResult(&result);
		if (flag==1)
		{
			v_digital = result;
			right_number = (((u32)v_digital *500)/1023);
			LCD_vidSetPosition(0,0);
			LCD_vidWriteNumber(right_number);
			LCD_vidWriteString("  ");
		}
		}
	 //ADC
	  LCD_vidInit();
	u16 result,v_digital,v_analog;
	u8 right_number,second_number;
	u8 flag;
	ADC_vidInit();

	while(1)
	{
		flag = ADC_u8GetResult(&result);
	if (flag==1)
	{
		v_digital = result;
		v_analog= (v_digital*5)/1023;
		right_number = (((u32)v_digital *500)/1023)/100;
		second_number = (((u32)v_digital *500)/1023)%100;
		LCD_vidSetPosition(0,0);
		LCD_vidWriteNumber(right_number);
		LCD_vidWriteChar(0b00101110);
		LCD_vidWriteNumber(second_number);
		LCD_vidWriteString("  ");
		LCD_vidSetPosition(1,0);
		LCD_vidWriteNumber(v_digital);
		LCD_vidWriteString("  ");
	}
	}
	 //Piano
	   u8 i , value;
			u8 keyflag[16] = {0} ;
				keybad_vidinit() ;
		//fast PWM mode
			//set_bit(TCCR0,0);
			set_bit(TCCR0,1);
			//set_bit(TCCR0,2);
			set_bit(TCCR0,3);
			set_bit(TCCR0,4);
			//set_bit(TCCR0,5);
			//set_bit(TCCR0,6);
			// OCR

			// set CO0 o/p
			DIO_vidSetPinDirection(2,3,1);
	while (1)
	{
		for (i=1 ; i<17 ; i++)
						{
							value = keybad_u8GetButtonStatus(i);
							if (value == 1 && keyflag[i]==0 )
							{
								if(i==1)
								{
									OCR0=240;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==2)
								{
									OCR0=212;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==3)
								{
									OCR0=188;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==4)
								{
									OCR0=180;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==5)
								{
									OCR0=160;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==6)
								{
									OCR0=142;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==7)
								{
									OCR0=126;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==8)
								{
									OCR0=120;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==9)
								{
									OCR0=106;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==10)
								{
									OCR0=94;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==11)
								{
									OCR0=90;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==12)
								{
									OCR0=80;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==13)
								{
									OCR0=71;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==14)
								{
									OCR0=63;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==15)
								{
									OCR0=60;
									_delay_ms(500);
									OCR0 = 0;
									keyflag[i]=1;
								}
								else if(i==16)
								{
									OCR0=0;
									keyflag[i]=1;
								}

							}
							else if(value == 0)
							{
								keyflag[i]=0;
							}
						}

	}

	// Write PWM on 8 bit & Read PWM (ICU)
	 *
	 #define __INTR_ATTRS used, externally_visible
u32 counter=0,flag=0,snap1,snap2,snap3;

void __vector_9 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_9 (void)
{
	counter++;

}
void __vector_6 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_6 (void)
{
	if(flag==0)
	{
		counter=0;
		snap1=ICR1;
		// falling edge
		clr_bit(TCCR1B,6);

	}
	else if(flag==1)
	{
		snap2=ICR1+(counter*65536);
		//raising edge
		set_bit(TCCR1B,6);

	}
	else if(flag==2)
	{
		snap3=ICR1+(counter*65536);
	}
	flag++;

}

int main (void)
{ 	LCD_vidInit();
	u32 duty_cycle,freq;
	//fast PWM mode
	set_bit(TCCR0,0);
	clr_bit(TCCR0,1);
	set_bit(TCCR0,2);
	set_bit(TCCR0,3);
	clr_bit(TCCR0,4);
	set_bit(TCCR0,5);
	set_bit(TCCR0,6);
	// OCR
	OCR0=128;
	// set CO0 o/p
	DIO_vidSetPinDirection(2,3,1);

	// set ICP i/p
	DIO_vidSetPinDirection(4,6,0);
	// raising edge
	set_bit(TCCR1B,6);
	// timer1 normal mode
	clr_bit(TCCR1A,0);
	clr_bit(TCCR1A,1);
	clr_bit(TCCR1A,4);
	clr_bit(TCCR1A,5);
	clr_bit(TCCR1A,6);
	clr_bit(TCCR1A,7);
	clr_bit(TCCR1B,3);
	clr_bit(TCCR1B,4);
	// timer prescaler
	set_bit(TCCR1B,0);
	clr_bit(TCCR1B,1);
	clr_bit(TCCR1B,2);
	//enable global
	set_bit(SREG,7);
	set_bit(TIMSK,5);
	set_bit(TIMSK,2);
	while(1){
	if(flag==3)
	{
		clr_bit(SREG,7);
		duty_cycle=((snap2-snap1)*100)/(snap3-snap1);
		freq=8000000/(snap3-snap1);
		LCD_vidSetPosition(0,0);
		LCD_vidWriteNumber(duty_cycle);
		LCD_vidSetPosition(1,0);
		LCD_vidWriteNumber(freq);
		flag=0;
		clr_bit(TIFR,5);
		set_bit(SREG,7);
	}
	}

// Servo 90 & 180 & 0 Degree with Fast PWM & 16 bit
 // Fast PWM
	clr_bit(TCCR1A,0);
	set_bit(TCCR1A,1);
	clr_bit(TCCR1A,3);
	set_bit(TCCR1B,3);
	set_bit(TCCR1B,4);

	// set @ top clear @ match
	clr_bit(TCCR1A,4);
	set_bit(TCCR1A,5);
	clr_bit(TCCR1A,6);
	set_bit(TCCR1A,7);

	// prescaler = 8
	clr_bit(TCCR1B,0);
	set_bit(TCCR1B,1);
	clr_bit(TCCR1B,2);

	set_bit(TCCR1B,6);

	// O/P
	DIO_vidSetPinDirection(4,5,1);
	//20,000->ISR
	ICR1 =20000;
	while(1)
	{

		OCR1A = 300;
		_delay_ms(1000);
		OCR1A = 1250;
		_delay_ms(1000);
		OCR1A = 2300;
		_delay_ms(1000);
		OCR1A = 1250;
		_delay_ms(1000);

	}


	// Clock & Motor
	 //ISR
	 #define __INTR_ATTRS used, externally_visible
u16 counter=0, sec=0,mins=0,hours=0;

void __vector_11 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_11 (void)
{
	counter++;
	if(counter==31250){
	sec++;
	counter=0;}
	if(sec==60)
	{
		mins++;
		sec=0;
	}
	if(mins==60)
	{
		hours++;
		mins=0;
	}


}
//main
	 u8 i , value,direction=0;
	u8 keyflag[16] = {0} ;

	keybad_vidinit() ;
	Timer_Normal_Mode();
	//Motor & Keypad

	DIO_vidSetPortDirection(MOTOR_PORT,255);
	clr_bit(PORTB,0);
	clr_bit(PORTB,1);


			while (1)
			{
				LCD_vidInit() ;
				if(hours<10){
					LCD_vidSetPosition(0,0);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(hours);
					}
					else{
					LCD_vidSetPosition(0,0);
					LCD_vidWriteNumber(hours);
					}
					LCD_vidSetPosition(0,2);
					LCD_vidWriteChar(0b00111010);
					if(mins<10){
					LCD_vidSetPosition(0,3);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(mins);
					}
					else
					{
						LCD_vidSetPosition(0,3);
						LCD_vidWriteNumber(mins);
					}
					LCD_vidSetPosition(0,5);
					LCD_vidWriteChar(0b00111010);
					if(sec<10){
					LCD_vidSetPosition(0,6);
					LCD_vidWriteNumber(0);
					LCD_vidWriteNumber(sec);
					}
					else
					{
						LCD_vidSetPosition(0,6);
						LCD_vidWriteNumber(sec);
					}
				for (i=1 ; i<4 ; i++)
				{
					value = keybad_u8GetButtonStatus(i);
					if (value == 1 && keyflag[i]==0 )
					{
						if(i==1)
						{
							if(direction!= 0)
							{

								clr_bit(PORTB,0);
								clr_bit(PORTB,1);
								direction=0;
							}
							else if(direction!=1)
							{
								set_bit(PORTB,0);
								set_bit(PORTB,1);
								direction=1;
							}
							keyflag[i]=1;
						}
						else if(i==2)
						{
							clr_bit(PORTB,0);
							set_bit(PORTB,1);
							keyflag[i]=1;
						}
						else if(i==3)
						{
							clr_bit(PORTB,0);
							clr_bit(PORTB,1);
							direction=0;
							keyflag[i]=1;
						}
						else
						{
							keyflag[i]=1;
						}

					}
					else if(value == 0)
					{
						keyflag[i]=0;
					}
				}
			}


// Timer with CTC mode
#define __INTR_ATTRS used, externally_visible
u16 counter=0;
void __vector_11 (void) __attribute__ ((signal,__INTR_ATTRS)) ;
void __vector_11 (void)
{

	counter++;
	if(counter==33){
	DIO_vidSetPortDirection(1,255);
	toggle_bit(PORTA,7);
	counter=0;
	}



}
	DIO_vidSetPortDirection(1,255);
	clr_bit(TIFR,0);
	set_bit(TIFR,1);
	set_bit(TCCR0,0);
	set_bit(TCCR0,1);
	clr_bit(TCCR0,2);
	set_bit(TCCR0,3);
	clr_bit(TCCR0,4);
	clr_bit(TCCR0,5);
	clr_bit(TCCR0,6);
	clr_bit(TCCR0,7);
	set_bit(TIMSK,0);
	clr_bit(TIMSK,1);
	set_bit(SREG,7);
	while(1)
	{

	}
// Timer with normal mode
	DIO_vidSetPortDirection(1,255);
	set_bit(TCCR0,0);
	clr_bit(TCCR0,1);
	set_bit(TCCR0,2);
	clr_bit(TCCR0,3);
	clr_bit(TCCR0,4);
	clr_bit(TCCR0,5);
	clr_bit(TCCR0,6);
	clr_bit(TCCR0,7);
	set_bit(TIMSK,0);
	clr_bit(TIMSK,1);
	set_bit(SREG,7);
	while(1)
	{

	}
// interrupt
	DIO_vidSetPortDirection(3,0b00000000);
	set_bit(PORTD,2);
	set_bit(SREG,7);
	set_bit(GICR,6);
	clr_bit(GICR,7);
	clr_bit(GICR,5);
	set_bit(MCUCR,1);
	clr_bit(MCUCR,0);
	while(1)
	{
		DIO_vidSetPortDirection(1,255);
		DIO_vidSetPortValue(1,0b00000000);
	}

 //press button and print number on LCD
	u8 i , value;
	u8 keyflag[16] = {0} ;

		LCD_vidInit() ;
		//print string
		//LCD_vidWriteString("Basma");
		keybad_vidinit() ;


		while (1)
		{

			for (i=1 ; i<17 ; i++)
			{
				value = keybad_u8GetButtonStatus(i);
				if (value == 1 && keyflag[i]==0 )
				{
					LCD_vidWriteNumber(i);
					keyflag[i]=1;
				}
				else if(value == 0)
				{
					keyflag[i]=0;
				}
			}
		}







//switches (transistor)
	DIO_vidSetPortDirection(4,255);
	while(1){

	DIO_vidSetPinValue(4,0,1);
	_delay_ms(1000);
	DIO_vidSetPinValue(4,0,0);
	_delay_ms(1000);
	}
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

//fun to check password
u8 WritePAssword(void)
{u8 i,k=0,j=0,p=0,value,result=0,button;
u8 keyflag[16] = {0} ;
u8 A[6]={0};
	LCD_vidWriteString("Welcome");
_delay_ms(1000);
LCD_vidWriteCommand(0x01);
LCD_vidWriteString("Enter Password");
LCD_vidSetPosition(1,1);
button=0;
while (1)
{
for (i=1 ; i<13 ; i++)
{
	value = keybad_u8GetButtonStatus(i);
	if (value == 1 && keyflag[i]==0 )
	{
		if(i<11)
		{
			LCD_vidWriteChar(0b00101010);
			A[j] = i-1;
			j++;
			keyflag[i]=1;
			button++;
		}
		else if(i==11)
		{
			LCD_vidWriteCommand(0x01);
			keyflag[i]=1;
			j=0;
		}
		else if(i==12)
		{

			keyflag[i]=1;

		if(j==6)
		{
		u8 B[6]={1,2,3,4,5,6};
		for(k=0; k<6;k++)
		{
			if(A[k]==B[k])
			{
				p++;
			}
		}
		if(p==6)
		{
			LCD_vidWriteCommand(0x01);
			LCD_vidWriteString("welcome");
			result= 0;

		}
		else
		{
			LCD_vidWriteCommand(0x01);
			LCD_vidWriteString("Error,try Again");
			_delay_ms(3000);
			LCD_vidWriteCommand(0x01);
			result = 1;

		}}
		else{ LCD_vidWriteCommand(0x01);
		LCD_vidWriteString("Error,try Again");
		_delay_ms(3000);
		LCD_vidWriteCommand(0x01);
		result= 1;}
		}

}
else if(value == 0)
{
	keyflag[i]=0;
}
}}
return result;*/
}

