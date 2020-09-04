/*
 * eeprom.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: dell
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void eeprom_init(void);
void eeprom_write_byte(u8 address, u8 data);
unsigned char eeprom_read_byte(u8 address);


#endif /* EEPROM_H_ */
