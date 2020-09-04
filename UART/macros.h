/*
 * macros.h
 *
 *  Created on: ??�/??�/????
 *      Author: dell
 */

#ifndef MACROS_H_
#define MACROS_H_

#define set_bit(data,bit) data |= (1<<bit)
#define clr_bit(data,bit) data &= ~(1<<bit)
#define toggle_bit(data,bit) data ^= (1<<bit)
#define get_bit(data,bit) ((data>>bit)&1)


#endif /* MACROS_H_ */
