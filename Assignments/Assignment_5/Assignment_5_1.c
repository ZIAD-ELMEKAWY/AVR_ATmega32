/*
 * @name 	main.c
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>

#include "DIO/DIO_Interface.h"
#include "DIO/DIO_Private.h"
#include "EXTI/EXTI_interface.h"
#include "GIE/GIE_interface.h"
#include "HAL/LED/LED_Interface.h"
#include "LIB/Std_types.h"

#define F_CPU	8000000UL


void ToggleMotor (void );

void main()
{
	// PIN Config
	//  - Interrupt
	DIO_Std_SetPinDirection(_PORTD_ , PIN2 , DIO_PIN_INPUT);
	DIO_Std_SetPinValue(_PORTD_ , PIN2 , PIN_HIGH);
	//  - Motor
	DIO_Std_SetPinDirection(_PORTA_ , PIN0 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinValue(_PORTA_ , PIN0 , PIN_HIGH);

	// PIN Interrupt Config
	EXTI_VoidSetSenstivity(EXTI_INT_0 , EXTI_FALLING_EDGE);
	EXTI_VoidEnableDisable(EXTI_INT_0 , ENABLE);
	GIE_Enable();
	// ISR function


	while(1)
	{

	}
}

void ToggleMotor (void )
{
	static u8 flag = 1 ;
	if(flag == 1)
	{
		DIO_Std_SetPinValue(_PORTA_ , PIN0 , PIN_HIGH);
		flag =0 ;
	}
	else
	{
		DIO_Std_SetPinValue(_PORTA_ , PIN0 , PIN_LOW);
		flag =1 ;
	}
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	ToggleMotor();
}

