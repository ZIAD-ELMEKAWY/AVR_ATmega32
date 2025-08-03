/*
 * @name 	Switch_Program.c
 * @date  	Created on: 19/7/2025
 * @author  Ziad Elmekawy
 */

#include "Switch_Interface.h"



/***
 * @name				Switch_Init
 * @brief				Initializes a switch by setting its corresponding pin as an input and configuring its pull-up state if internal pull-up is desired.
 * @argument sw		A structure `switch_t` containing the port, pin, and pull-state information for the switch.
 * @return				void
 */
void Switch_VoidInit (switch_t sw)
{
	DIO_Std_SetPinDirection(sw.Port , sw.Pin , DIO_PIN_INPUT);
		if (sw.Pull_State == SW_INT_PULL_UP)
		{
			DIO_Std_SetPinValue(sw.Port , sw.Pin , PIN_HIGH);
		}
}

/***
 * @name				SW_u8GetPressed
 * @brief				Reads the state of a switch and determines if it is pressed based on its pull-up/pull-down configuration.
 * @argument sw		A structure `switch_t` containing the port, pin, and pull-state information for the switch.
 * @return				u8 indicating whether the switch is pressed (SW_PRESSED) or not pressed (SW_NOT_PRESSED).
 */
u8   SW_u8GetPressed	 (switch_t sw)
{
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	if ((sw.Pull_State == SW_INT_PULL_UP) || (sw.Pull_State == SW_EXT_PULL_UP))
	{
		LOC_u8PinVal = DIO_Std_GetPinValue(sw.Port , sw.Pin );
		if (LOC_u8PinVal == 0)
		{
			LOC_u8Result = SW_PRESSED;
		}
		else
		{
			LOC_u8Result = SW_NOT_PRESSED;
		}
	}
	else if (sw.Pull_State == SW_EXT_PULL_DOWN)
	{
		LOC_u8PinVal = DIO_Std_GetPinValue(sw.Port , sw.Pin );
		if (LOC_u8PinVal == 0)
		{
			LOC_u8Result = SW_NOT_PRESSED;
		}
		else
		{
			LOC_u8Result = SW_PRESSED;
		}
	}
	return LOC_u8Result ;
}
