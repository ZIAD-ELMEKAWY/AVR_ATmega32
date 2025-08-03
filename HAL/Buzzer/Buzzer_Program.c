/*
 * @name 	Buzzer_Program.c
 * @date  	Created on: 19/7/2025
 * @author  Ziad Elmekawy
 */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Buzzer_Interface.h"

/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				buz_Initialzation
 * @brief				Initializes a buzzer by setting its corresponding pin as an output.
 * @argument buz		A structure `buz_t` containing the port and pin information for the buzzer.
 * @return				Std_ReturnType indicating success (E_OK) if initialization is successful, or failure (E_NOK) if the provided port or pin is invalid.
 */
Std_ReturnType Buz_Void_Initialzation (buz_t buz)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((buz.Port >= _PORTA_) && (buz.Port <= _PORTD_))
	{
		if((buz.Pin >= PIN0) && (buz.Pin <= PIN7))
		{
			DIO_Std_SetPinDirection(buz.Port , buz.Pin , DIO_PIN_OUTPUT);
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
 * @name				buz_Turn_ON
 * @brief				Turns on the buzzer by setting its corresponding pin to a high value.
 * @argument buz		A structure `buz_t` containing the port and pin information for the buzzer.
 * @return				Std_ReturnType indicating success (E_OK) if the buzzer is turned on successfully, or failure (E_NOK) if the provided port or pin is invalid.
 */
Std_ReturnType Buz_Void_Turn_ON  (buz_t buz)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((buz.Port >= _PORTA_) && (buz.Port <= _PORTD_))
	{
		if((buz.Pin >= PIN0) && (buz.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(buz.Port , buz.Pin , PIN_HIGH);
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
 * @name				buz_Turn_OFF
 * @brief				Turns off the buzzer by setting its corresponding pin to a low value.
 * @argument buz		A structure `buz_t` containing the port and pin information for the buzzer.
 * @return				Std_ReturnType indicating success (E_OK) if the buzzer is turned off successfully, or failure (E_NOK) if the provided port or pin is invalid.
 */
Std_ReturnType Buz_Void_Turn_OFF (buz_t buz)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((buz.Port >= _PORTA_) && (buz.Port <= _PORTD_))
	{
		if((buz.Pin >= PIN0) && (buz.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(buz.Port , buz.Pin , PIN_LOW);
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
 * @name				buz_Toglle
 * @brief				Toggles the state (ON/OFF) of the buzzer's corresponding pin.
 * @argument buz		A structure `buz_t` containing the port and pin information for the buzzer.
 * @return				Std_ReturnType indicating success (E_OK) if the buzzer state is toggled successfully, or failure (E_NOK) if the provided port or pin is invalid.
 */
Std_ReturnType Buz_Void_Toglle     (buz_t buz)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((buz.Port >= _PORTA_) && (buz.Port <= _PORTD_))
	{
		if((buz.Pin >= PIN0) && (buz.Pin <= PIN7))
		{
			DIO_Std_TogglePin(buz.Port , buz.Pin );
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
