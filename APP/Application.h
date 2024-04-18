/*
 * Application.h
 *
 * Created: 07/03/2024 19:53:35
 *  Author: Ziad
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
/************************** Include Section **********************/
#define  F_CPU 8000000UL       // 8000000UL = 8 Million Instruction Per Second (MIPS)
#include <util/delay.h>
#include <avr/io.h>
#include <math.h>
#include "DIO_interface.h"
#include "DIO_private.h"
#include "LED/LED_interface.h"
#include "SSD/SSD_interface.h"
#include "SW/SW_interface.h"
#include "LCD/LCD_interface.h"
#include "KPD/KPD_interface.h"
/******************* Macro Function Section ************************/
/******************* Function Declaration Section ******************/
void APP_voidInit (void) ;
u16	 APP_ChartoInt (u8 ch);
u8 get_num(u8 ch) ;
void disp_num(u16 numb); //displays number on LCD
void LCD_u8WriteNum( f64 real_num ) ;
void APP_voidInitZero (u8 a,u8 b);
void APP_voidStandSys (u8 APP_pressFunc);				// Standard_System
void APP_voidScienSys (u8 APP_pressFunc , s32 Value);	// Scientific_System
void APP_voidProgSys  (u8 APP_pressFunc);				// Programmable_System
void Decimal_to_binary (u8 DEC_BIN_Var) ;
void APP_voidInfix_To_Postfix_System (u8 APP_pressFunc);
#endif /* APPLICATION_H_ */