/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "Timer1/Timer1_interface.h"
#include "ADC/ADC_interface.h"
#include "GIE/GIE_interface.h"

#define F_CPU	8000000UL

#define MOTOR_DIR_PIN1  PIN6
#define MOTOR_DIR_PIN2  PIN7
#define MOTOR_PORT      _PORTC_

int main()
{
	u16 RetValue = 400 ;
	DIO_Std_SetPinDirection(_PORTD_ , PIN5 , DIO_PIN_OUTPUT);     // PWM pin
	DIO_Std_SetPinDirection(MOTOR_PORT , MOTOR_DIR_PIN1 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(MOTOR_PORT , MOTOR_DIR_PIN2 , DIO_PIN_OUTPUT);

	ADC_voidInit();
	GIE_Enable();

	Timer1_SetTop(20000);
	Timer1_SetCTC_A_Value(RetValue);
	Timer1_Init();

	while(1)
	{
		// Forward Direction
		DIO_Std_SetPinValue(MOTOR_PORT, MOTOR_DIR_PIN1, PIN_HIGH);
		DIO_Std_SetPinValue(MOTOR_PORT, MOTOR_DIR_PIN2, PIN_LOW);

		for(u16 counter=400 ; counter<2600 ; counter+=10)
		{
			Timer1_SetCTC_A_Value((u8)counter);
			_delay_ms(500);
		}
		// Reverse Direction
		DIO_Std_SetPinValue(MOTOR_PORT, MOTOR_DIR_PIN1, PIN_LOW);
		DIO_Std_SetPinValue(MOTOR_PORT, MOTOR_DIR_PIN2, PIN_HIGH);

		for(u16 counter=2600 ; counter>400 ; counter-=10)
		{
			Timer1_SetCTC_A_Value((u8)counter);
			_delay_ms(1000);
		}
	}
	return 0 ;
}




