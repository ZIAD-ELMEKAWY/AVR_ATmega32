/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "HAL/LED/LED_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"

#define F_CPU	8000000UL

led_t led_1 =
{
	.Port = _PORTA_ ,
	.Pin = PIN0
};
led_t led_2 =
{
	.Port = _PORTA_ ,
	.Pin = PIN1
};
led_t led_3 =
{
	.Port = _PORTA_ ,
	.Pin = PIN2
};
led_t led_4 =
{
	.Port = _PORTA_ ,
	.Pin = PIN3
};
led_t led_5 =
{
	.Port = _PORTA_ ,
	.Pin = PIN4
};
led_t led_6 =
{
	.Port = _PORTA_ ,
	.Pin = PIN5
};
led_t led_7 =
{
	.Port = _PORTA_ ,
	.Pin = PIN6
};
led_t led_8 =
{
	.Port = _PORTA_ ,
	.Pin = PIN7
};

void main()
{
	u8 Press = 0 ;
	LCD_VoidInit();
	KPD_VoidInit();
	LED_Void_Initialzation(led_1);
	LED_Void_Initialzation(led_2);
	LED_Void_Initialzation(led_3);
	LED_Void_Initialzation(led_4);
	LED_Void_Initialzation(led_5);
	LED_Void_Initialzation(led_6);
	LED_Void_Initialzation(led_7);

	LCD_voidClearScreen();
	LCD_VoidSetPosition(1 , 4) ;
	LCD_VoidSendString("Welcome to");
	LCD_VoidSetPosition(2 , 6) ;
	LCD_VoidSendString("My Home");
	_delay_ms(1000);
	LCD_voidClearScreen();
	while(1)
	{

		Press =KPD_u8GetPressed();
		if(Press != NOT_PRESSED)
		{
			switch(Press)
			{
			case '0':
				DIO_Std_SetPortValue(_PORTA_ , 0);
				break ;
			case '1':
				DIO_Std_SetPortValue(_PORTA_ , 1);
				break ;
			case '2':
				DIO_Std_SetPortValue(_PORTA_ , 2);
				break ;
			case '3':
				DIO_Std_SetPortValue(_PORTA_ , 3);
				break ;
			case '4':
				DIO_Std_SetPortValue(_PORTA_  , 4);
				break ;
			case '5':
				DIO_Std_SetPortValue(_PORTA_ , 5);
				break ;
			case '6':
				DIO_Std_SetPortValue(_PORTA_ , 6);
				break ;
			case '7':
				DIO_Std_SetPortValue(_PORTA_ , 7);
				break ;
			case '8':
				DIO_Std_SetPortValue(_PORTA_ , 8);
				break ;
			case '9':
				DIO_Std_SetPortValue(_PORTA_ , 9);
				break ;
			default :
				DIO_Std_SetPortValue(_PORTA_ , 11);
			}
		}

	}
}

