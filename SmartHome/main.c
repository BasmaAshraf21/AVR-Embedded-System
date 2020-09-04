#define FCPU 8000000
#define pass 4
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

int main (void)
{	 //smart home

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

			u64 password = 0;
			u16 done = 0;
			while(done == 0){
				LCD_vidWriteCommand(0x01);
				LCD_vidWriteString("Welcome");
				_delay_ms(3000);
				LCD_vidWriteCommand(0x01);
				LCD_vidWriteString("Enter Your Password");
				_delay_ms(3000);
			password = UART_Receiver();
			if(password == pass)
			{
				UART_Transmition('Welcome');
				UART_Transmition('e');
				done = 6;
				LCD_vidWriteCommand(0x01);
				LCD_vidWriteString("Welcome To SmartHome");
				_delay_ms(3000);
				LCD_vidWriteCommand(0x01);
			while(1)
			{

				value = UART_Receiver();
				if(value==1)
				{
				 DIO_vidSetPinValue(2,6,1);
				 LCD_vidWriteCommand(0x01);
				 LCD_vidWriteString("Light ON");
				 UART_Transmition('O');
				 UART_Transmition('N');
				}
				if(value==2)
				{
					DIO_vidSetPinValue(2,6,0);
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Light OFF");
					UART_Transmition('O');
					UART_Transmition('F');
					UART_Transmition('F');

				}
				if(value==3)
				{
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("Door Opens");
					OCR1A = 300;
					_delay_ms(1000);
					OCR1A = 1250;
					_delay_ms(1000);
					OCR1A = 2300;
					_delay_ms(1000);
					OCR1A = 1250;
					_delay_ms(1000);


				}


			}

			}
			else
				{
					UART_Transmition('try again');
					UART_Transmition('O');
					LCD_vidWriteCommand(0x01);
					LCD_vidWriteString("try again");
					_delay_ms(1000);
					LCD_vidWriteCommand(0x01);
				}
			}//end of pro
	}
