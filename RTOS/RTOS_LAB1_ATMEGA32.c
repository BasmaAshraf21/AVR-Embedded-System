/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 1/27/2014 12:22:11 AM
 *  Author: Islam
 */ 

#include"macros1.h"
#include"types.h"
#include"registers.h"
#include"DIO.h"
#include"LCD.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "lcd_4bit.h"
#include "semphr.h"
#include"macros.h"

#include <util/delay.h>

/* Define Tasks Priorities */
#define  TASK1_PRIORITY (3)
#define  TASK2_PRIORITY (2)

xSemaphoreHandle mutex1 ;

/*tasks codes prototypes */
 void task1_code(void*pvParamter);
 void task2_code(void*pvParamter);

int main(void)
{
	/*Create tasks*/
	LCD_vidInit();
	xTaskCreate(task1_code,NULL,450,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,NULL,configMINIMAL_STACK_SIZE,NULL,TASK1_PRIORITY,NULL);
	mutex1 = xSemaphoreCreateRecursiveMutex();
	/*start Scheduler */
	vTaskStartScheduler();

	return 0;
    
}

/*Task1 Code */
 void task1_code(void*pvParamter)
{
	
	for (;;)
	{
		// LED On
		unsigned char y = xSemaphoreTakeRecursive(mutex1,100);
		if(y==1){
		LCD_vidSetPosition(0,0);
		LCD_vidWriteString("Hello");
		}
		xSemaphoreGiveRecursive(mutex1);

	}
		
}

/*Task 2 Code*/
 void task2_code(void*pvParamter)
{
	while(1)
	{
		// LED Off
		unsigned char x = xSemaphoreTakeRecursive(mutex1,100);
		if(x==1){
		LCD_vidSetPosition(1,0);
		LCD_vidWriteString("Welcome");
		}
		xSemaphoreGiveRecursive(mutex1);
	}
}
