/*
 * @File:   Std_types.h
 * @Author: Ziad Elmekawy
 *
 * @Date :  Created on 13 July, 2025, 10:57 ?
 */

#ifndef _STD_TYPES_H
#define	_STD_TYPES_H

/******************* includes *******************/
#include <stdio.h>

/*********** Data Type Declarations *************/
typedef unsigned char       u8 ;
typedef unsigned short int  u16;
typedef unsigned int  		u32;
typedef signed char   		s8 ;
typedef signed short int  	s16;
typedef signed int    		s32 ;
typedef float 		  		f32;
typedef double 		  		f64;
typedef u8           Std_ReturnType;

/************* Macro Declarations ***************/
#define STD_HIGH       0x01
#define STD_LOW        0x00


#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDEAL      0x00

#define E_OK             (Std_ReturnType)0x01;
#define E_NOK          (Std_ReturnType)0x00;

/* Func States  */
#define IDLE 			0
#define BUSY			1

/* My States  */
#define OK           	0
#define NOK          	1
#define NULL_POINTER 	2
#define BUSY_STATE	 	3
#define TIMEOUT_STATE   4

/* Macro Function Declarations */


/* Function Declarations */

#endif	/* _STD_TYPES_H */
