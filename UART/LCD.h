/*
 * LCD_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#ifndef LCD_H_
#define LCD_H_



void LCD_vidWriteChar(u8 data);
void LCD_vidWriteCommand(u8 command);
void LCD_vidInit(void);
void LCD_vidWriteString(u8*ptr);
void LCD_vidWriteNumber(u32 number);
void LCD_vidSetPosition(u8 row , u8 colum);

#endif /* LCD_H_ */
