/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include "DIO_Registers.h"
#include "Std_types.h"
#include "Bit_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"

#define F_CPU	8000000UL

void Application_Setup(void);
void Blink_LED (void);



void main()
{
	Application_Setup();
	while(1)
	{
		Blink_LED();
	}
}

void Application_Setup(void)
{
	DIO_Std_SetPortDirection(_PORTA_  , DIO_PORT_INPUT) ;
	DIO_Std_SetPortDirection(_PORTD_  , DIO_PORT_OUTPUT) ;
	DIO_Std_SetPortValue(_PORTD_ , PORT_HIGH);
}


void Blink_LED(void)
{
	// led 1
	if(DIO_Std_GetPinValue(_PORTA_ , PIN0 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN0 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN0 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN0 , PIN_HIGH);
	}
	// led 2
	if(DIO_Std_GetPinValue(_PORTA_ , PIN1 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN1 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN1 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN1 , PIN_HIGH);
	}
	// led 3
	if(DIO_Std_GetPinValue(_PORTA_ , PIN2 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN2 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN2 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN2 , PIN_HIGH);
	}
	// led 4
	if(DIO_Std_GetPinValue(_PORTA_ , PIN3 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN3 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN3 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN3 , PIN_HIGH);
	}
	// led 5
	if(DIO_Std_GetPinValue(_PORTA_ , PIN4 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN4 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN4 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN4 , PIN_HIGH);
	}
	// led 6
	if(DIO_Std_GetPinValue(_PORTA_ , PIN5 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN5 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN5 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN5 , PIN_HIGH);
	}
	// led 7
	if(DIO_Std_GetPinValue(_PORTA_ , PIN6 ) == PIN_LOW)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN6 , PIN_LOW);
	}
	else if(DIO_Std_GetPinValue(_PORTA_ , PIN6 ) == PIN_HIGH)
	{
		DIO_Std_SetPinValue(_PORTD_ , PIN6 , PIN_HIGH);
	}
}
