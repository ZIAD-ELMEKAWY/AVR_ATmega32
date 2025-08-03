/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "HAL/LCD/LCD_Interface.h"

#define F_CPU	8000000UL

void LCD_VoidSendUpperCaeChar		(u8 ROW , u8 Column);
void LCD_VoidSendLowerCaeChar		(u8 ROW , u8 Column);

 u8 UpperCase[] = {
		 0b11111, 0b00011, 0b00010, 0b00010, 0b00100 , 0b00100, 0b01000, 0b11000, 0b10000, 0b11111
 };

 u8 LowerCase[] = {
		 0b00000,
		 0b00000,
		 0b00000,
		 0b01110,
		 0b00010,
		 0b00100,
		 0b01110,
		 0b00000,
		 0b00000
 };


void main()
{
	LCD_VoidInit();
	u8 Cursor = 0 ;
	LCD_VoidSendString("UpperCase : ");
	LCD_VoidSendUpperCaeChar(1,12);
	LCD_VoidSetPosition(2,1);
	LCD_VoidSendString("LowerCase : ");
	LCD_VoidSendLowerCaeChar(2,12);
	while(1)
	{

	}
}

/***
 * @name				LCD_VoidSendUpperCaeChar
 * @brief
 * @argument
 * @return
 */
void LCD_VoidSendUpperCaeChar		(u8 ROW , u8 Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	LCD_VoidSendCommand(LCD_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(UpperCase[LOC_Iterator]);
	}
	// Back AC to DDRAM
	LCD_VoidSetPosition(ROW , Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LOC_Iterator);
	}
}

/***
 * @name				LCD_VoidSendLowerCaeChar
 * @brief
 * @argument
 * @return
 */
void LCD_VoidSendLowerCaeChar		(u8 ROW , u8 Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	LCD_VoidSendCommand(LCD_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LowerCase[LOC_Iterator]);
	}
	// Back AC to DDRAM
	LCD_VoidSetPosition(ROW , Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LOC_Iterator);
	}
}
