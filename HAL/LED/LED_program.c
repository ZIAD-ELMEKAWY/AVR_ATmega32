/*
 * LED_program.c
 *	Layer  : HAL
 * SWC	   : GPIO
 * Author  : Ziad
 */ 

/*********** Includes Section *******************/
#include "LED_interface.h"          // Includes Library.h
#include "DIO_interface.h"
/*********** Global variable Section *******************/

/*********** Function Definition Section *******************/
void LED_voidInit	 (LED_Type LED_Configuration)
{
	DIO_enum_SetPinDirection(LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_OUTPUT);
}
void LED_voidOn		 (LED_Type LED_Configuration)
{
	if (LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enum_SetPinVlaue(LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH);
	}
	else
	{
		DIO_enum_SetPinVlaue(LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW);
	}
}
void LED_voidOff		 (LED_Type LED_Configuration)
{
	if (LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_enum_SetPinVlaue(LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW);
	}
	else
	{
		DIO_enum_SetPinVlaue(LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH);
	}
}
void LED_voidToggle	 (LED_Type LED_Configuration)
{
	DIO_enum_TogglePinValue(LED_Configuration.Port , LED_Configuration.Pin);
}

// LED_ErrorStatus LED_LOC_enumState = LED_OK ;

//return LED_LOC_enumState;