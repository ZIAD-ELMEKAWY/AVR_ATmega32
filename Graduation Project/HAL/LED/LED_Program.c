/*
 * @name 	LED_Program.c
 * @date  	Created on: 19/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "LED_Interface.h"

/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				LED_Initialzation
 * @brief
 * @argument
 * @return
 */
Std_ReturnType LED_Void_Initialzation (led_t led)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((led.Port >= _PORTA_) && (led.Port <= _PORTD_))
	{
		if((led.Pin >= PIN0) && (led.Pin <= PIN7))
		{
			DIO_Std_SetPinDirection(led.Port , led.Pin , DIO_PIN_OUTPUT);
		}
		else
		{
			Ret_Status = E_NOK ;
		}
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status ;
}

/***
 * @name				LED_Turn_ON
 * @brief
 * @argument
 * @return
 */
Std_ReturnType LED_Void_Turn_ON  (led_t led)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((led.Port >= _PORTA_) && (led.Port <= _PORTD_))
	{
		if((led.Pin >= PIN0) && (led.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(led.Port , led.Pin , PIN_HIGH);
		}
		else
		{
			Ret_Status = E_NOK ;
		}
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status ;
}

/***
 * @name				LED_Turn_OFF
 * @brief
 * @argument
 * @return
 */
Std_ReturnType LED_Void_Turn_OFF (led_t led)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((led.Port >= _PORTA_) && (led.Port <= _PORTD_))
	{
		if((led.Pin >= PIN0) && (led.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(led.Port , led.Pin , PIN_LOW);
		}
		else
		{
			Ret_Status = E_NOK ;
		}
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status ;
}

/***
 * @name				LED_Toglle
 * @brief
 * @argument
 * @return
 */
Std_ReturnType LED_Void_Toggle        (led_t led)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((led.Port >= _PORTA_) && (led.Port <= _PORTD_))
	{
		if((led.Pin >= PIN0) && (led.Pin <= PIN7))
		{
			DIO_Std_TogglePin(led.Port , led.Pin );
		}
		else
		{
			Ret_Status = E_NOK ;
		}
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status ;
}


