/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "HAL/LCD/LCD_Interface.h"

#define F_CPU	8000000UL

void main()
{
	LCD_VoidInit();
	u8 Cursor = 0 ;

	while(1)
	{
		LCD_voidClearScreen();
		LCD_VoidSetPosition(1 , Cursor) ;
		LCD_VoidSendString("Ziad Elmekawy");
		Cursor++ ;
		if(Cursor == 16)
		{
			Cursor =0 ;
		}
		_delay_ms(500);
	}
}

