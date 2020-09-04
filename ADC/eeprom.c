/*
 * eeprom.c
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
void eeprom_init(void)
{
	i2c_init_master();
}

void eeprom_write_byte(u8 address, u8 data)
{
    i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 );
	i2c_write_byte(address);
	i2c_write_byte(data);
	i2c_stop();
    return;
}

u8 eeprom_read_byte(u8 address)
{
	u8 data;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0x50 );
    i2c_write_byte(address);
	i2c_repeated_start();
	i2c_send_slave_address_with_read_req( 0x50 );
	data = i2c_read_byte();
	i2c_stop();
    return data;
}

