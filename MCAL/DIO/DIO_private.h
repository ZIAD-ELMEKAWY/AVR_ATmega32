﻿/*
 * DIO_private.h
 * Layer   : MCAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created : 06/03/2024 05:36:44 م
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#include "Std_Types.h"

/******** GROUP A *******************/
#define PORTA_Register	*((volatile u8*)0x3B) 
#define DDRA_Register	*((volatile u8*)0x3A)
#define PINA_Register	*((volatile u8*)0x39)

/******** GROUP B ******************/
#define PORTB_Register	*((volatile u8*)0x38)
#define DDRB_Register	*((volatile u8*)0x37)
#define PINB_Register	*((volatile u8*)0x36)

/******** GROUP C ******************/
#define PORTC_Register	*((volatile u8*)0x35)
#define DDRC_Register	*((volatile u8*)0x34)
#define PINC_Register	*((volatile u8*)0x33)

/******** GROUP D ******************/
#define PORTD_Register	*((volatile u8*)0x32)
#define DDRD_Register	*((volatile u8*)0x31)
#define PIND_Register	*((volatile u8*)0x30)


#endif /* DIO_PRIVATE_H_ */
