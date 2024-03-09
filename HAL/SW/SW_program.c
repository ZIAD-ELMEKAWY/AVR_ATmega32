/*
 * SW_program.c
 *	Layer  : HAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created: 09/03/2024 01:38:37
 */ 

#include "SW_interface.h"

void SW_voidInit		 (SW_type SW_Config)
{
	DIO_enum_SetPinDirection(SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT);
	if (SW_Config.Pull_State == SW_INT_PULL_UP)
	{
		DIO_enum_SetPinVlaue(SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH);
	}
}

u8 SW_u8GetPressed	 (SW_type SW_Config)
{
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	if ((SW_Config.Pull_State == SW_INT_PULL_UP) || (SW_Config.Pull_State == SW_EXT_PULL_UP))
	{
		DIO_enum_GetPinValue(SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal);
		if (LOC_u8PinVal == 0)
		{
			LOC_u8Result = SW_PRESSED;
		}
		else
		{
			LOC_u8Result = SW_NOT_PRESSED;
		}
	} 
	else if (SW_Config.Pull_State == SW_EXT_PULL_DOWN)
	{
		DIO_enum_GetPinValue(SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal);
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