/*
 * @name 	main.c
 * @date  	Created on: 22/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "DIO/DIO_Interface.h"

#define F_CPU	8000000UL


void main()
{
	DIO_Std_SetPinDirection(_PORTA_ , PIN7 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinValue(_PORTA_ , PIN7 , PIN_LOW);

	while(1)
	{
		DIO_Std_SetPinValue(_PORTA_ , PIN7 , PIN_HIGH);
		_delay_ms(1000);
		DIO_Std_SetPinValue(_PORTA_ , PIN7 , PIN_LOW);
		_delay_ms(1000);
	}
}