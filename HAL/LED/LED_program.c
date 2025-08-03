/*
 * @name 	LED_Program.c
 * @date  	Created on: 19/7/2025
 * @author  Ziad Elmekawy
 */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "LED_Interface.h"

/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				LED_Initialzation
 * @brief				Initializes an LED by setting its corresponding pin as an output.
 * @argument led		A structure `led_t` containing the port and pin information for the LED.
 * @return				Std_ReturnType indicating success (E_OK) if initialization is successful, or failure (E_NOK) if the provided port or pin is invalid.
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
 * @brief				Turns on the LED by setting its corresponding pin to a high value.
 * @argument led		A structure `led_t` containing the port and pin information for the LED.
 * @return				Std_ReturnType indicating success (E_OK) if the LED is turned on successfully, or failure (E_NOK) if the provided port or pin is invalid.
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
 * @brief				Turns off the LED by setting its corresponding pin to a low value.
 * @argument led		A structure `led_t` containing the port and pin information for the LED.
 * @return				Std_ReturnType indicating success (E_OK) if the LED is turned off successfully, or failure (E_NOK) if the provided port or pin is invalid.
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
 * @brief				Toggles the state (ON/OFF) of the LED's corresponding pin.
 * @argument led		A structure `led_t` containing the port and pin information for the LED.
 * @return				Std_ReturnType indicating success (E_OK) if the LED state is toggled successfully, or failure (E_NOK) if the provided port or pin is invalid.
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
