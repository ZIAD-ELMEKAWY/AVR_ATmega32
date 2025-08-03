/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "ADC/ADC_interface.h"
#include "HAL/LED/LED_Interface.h"

#define F_CPU	8000000UL

led_t led1 =
{
	.Port = _PORTD_ ,
	.Pin = PIN0
};

led_t led2 =
{
	.Port = _PORTD_ ,
	.Pin = PIN1
};

led_t led3 =
{
	.Port = _PORTD_ ,
	.Pin = PIN2
};



int main()
{
	u16 ReturnValue = 0 ;
	DIO_Std_SetPinDirection(_PORTA_ , PIN0 , DIO_PIN_INPUT);
	ADC_voidInit();
	LED_Void_Initialzation(led1);
	LED_Void_Initialzation(led2);
	LED_Void_Initialzation(led3);

	while(1)
	{
		ADC_u8GetResultSync( ADC_CHANNEL0 , &ReturnValue);
		ReturnValue = ReturnValue *( 5000 / 1024.0) ;
		if((ReturnValue > 0) && (ReturnValue <= 200))
		{
			LED_Void_Turn_ON(led1);
			LED_Void_Turn_OFF(led2);
			LED_Void_Turn_OFF(led3);
		}
		else if((ReturnValue > 200) && (ReturnValue <= 600))
		{
			LED_Void_Turn_ON(led1);
			LED_Void_Turn_ON(led2);
			LED_Void_Turn_OFF(led3);
		}
		else if(ReturnValue > 600)
		{
			LED_Void_Turn_ON(led1);
			LED_Void_Turn_ON(led2);
			LED_Void_Turn_ON(led3);
		}
		else
		{
			LED_Void_Turn_OFF(led3);
			LED_Void_Turn_OFF(led2);
			LED_Void_Turn_OFF(led1);
		}
	}
	return 0 ;
}

