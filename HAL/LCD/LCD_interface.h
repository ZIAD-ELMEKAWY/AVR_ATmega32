/*
 * @name 	LCD_Interface.h
 * @date  	Created on: 20/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawys
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "LCD_Config.h"
#include "LCD_Private.h"
#include <util/delay.h>
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/********/
#if   LCD_MODE == 4
#define FOUR_BITS                     0x28          //4 bits mode initialization
#elif LCD_MODE == 8
#define EIGHT_BITS                    0x38          //8 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
#endif
/********/

#define LCD_DisplayOn_CursorOff       	0x0c          // display on, cursor off, don't blink character
#define LCD_DisplayOn_CursorOn        	0x0e          // display on, cursor on, don't blink character
#define LCD_DisplayOff_CursorOff     	0x08          // turn display off
#define LCD_Clear                     				0x01          //replace all characters with ASCII 'space'
#define LCD_EntryMode                 			0x06          // shift cursor from left to right on read/write
#define LCD_Home                      				0x02          // return cursor to first position on first line
#define LCD_CGRAM                    			 	0x40          // the first Place/Address at CGRAM
#define LCD_FunctionReset             		0x30          // reset the LCD
#define LCD_SETCURSOR						0x80    // first address for cursor


// Columns and rows
#define LCD_ROW_1		1
#define LCD_ROW_2		2

#define	LCD_COL_1		1
#define	LCD_COL_2		2
#define	LCD_COL_3		3
#define	LCD_COL_4		4
#define	LCD_COL_5		5
#define	LCD_COL_6		6
#define	LCD_COL_7		7
#define	LCD_COL_8		8
#define	LCD_COL_9		9
#define	LCD_COL_10		10
#define	LCD_COL_11		11
#define	LCD_COL_12		12
#define	LCD_COL_13		13
#define	LCD_COL_14		14
#define	LCD_COL_15		15
#define	LCD_COL_16		16

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void LCD_VoidInit						(void	 );
void LCD_VoidSendData			(u8 Data );
void LCD_VoidSendNumber		(u32 number );
void LCD_VoidSendCommand		(u8 command );
void LCD_voidClearScreen			(void	 );
void LCD_VoidSendString			(const u8 *ptrString );
void LCD_VoidSetPosition			(u8 Row , u8 Column);
void LCD_VoidSendExtraChar	(u8 ROW , u8 Column);
void LCD_VoidSendUpperCaeChar		(u8 ROW , u8 Column);
void LCD_VoidSendLowerCaeChar		(u8 ROW , u8 Column);
void LCD_voidSendDoubleNumber(f64 number , u8 No_DigitsAfterDecimal);
void LCD_voidSendSignedIntegerNumber(f64 number);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
