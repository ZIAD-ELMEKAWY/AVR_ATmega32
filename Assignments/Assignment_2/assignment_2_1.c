/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "HAL/LCD/LCD_Interface.h"

#define F_CPU	8000000UL

void Sinusoidal_string(void) ;

void main()
{
	LCD_VoidInit();
	u8 Cursor = 0 ;

	while(1)
	{
		LCD_voidClearScreen();
		Sinusoidal_string();
		
		_delay_ms(500);
	}
}

void Sinusoidal_string (void)
{
	LCD_VoidSetPosition(1 , 1) ;
			LCD_VoidSendData('Z');
			LCD_VoidSetPosition(2 , 2) ;
			LCD_VoidSendData('I');
			LCD_VoidSetPosition(1 , 3) ;
			LCD_VoidSendData('A');
			LCD_VoidSetPosition(2 , 4) ;
			LCD_VoidSendData('D');
			LCD_VoidSetPosition(1 , 5) ;

			LCD_VoidSetPosition(2 , 6) ;
			LCD_VoidSendData('E');
			LCD_VoidSetPosition(1 , 7) ;
			LCD_VoidSendData('L');
			LCD_VoidSetPosition(2 , 8) ;
			LCD_VoidSendData('M');
			LCD_VoidSetPosition(1 , 9) ;
			LCD_VoidSendData('E');
			LCD_VoidSetPosition(2 , 10) ;
			LCD_VoidSendData('K');
			LCD_VoidSetPosition(1 , 11) ;
			LCD_VoidSendData('A');
			LCD_VoidSetPosition(2 , 12) ;
			LCD_VoidSendData('W');
			LCD_VoidSetPosition(1 , 13) ;
			LCD_VoidSendData('Y');
}
