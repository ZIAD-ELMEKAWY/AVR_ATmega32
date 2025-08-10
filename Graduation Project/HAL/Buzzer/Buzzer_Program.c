/*
 * @name 	Buzzer_Program.c
 * @date  	Created on: 19/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Buzzer_Interface.h"

/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				buz_Initialzation
 * @brief
 * @argument
 * @return
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
 * @brief
 * @argument
 * @return
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
 * @brief
 * @argument
 * @return
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
 * @brief
 * @argument
 * @return
 */
Std_ReturnType Buz_Void_Toglle        (buz_t buz)
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

