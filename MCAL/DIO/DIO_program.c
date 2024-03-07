/*
 * DIO_program.c
 * Layer   : MCAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created : 06/03/2024 05:36:44 م
 */

/*********** Includes Section *******************/
#include "DIO_interface.h" 
#include "DIO_private.h"
#include "DIO_config.h"

/*********** Global variable Section ********************/

/*********** Function Definition Section *******************/
DIO_ErrorStatus DIO_enum_SetPinDirection  (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 Copy_u8_Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if ((Copy_u8PORT <= DIO_PORTD ) && (Copy_u8PiN <= DIO_PIN7))
	{
		if (Copy_u8_Direction == DIO_PIN_OUTPUT)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA : SET_BIT(DDRA_Register , Copy_u8PiN); break;
				case DIO_PORTB : SET_BIT(DDRB_Register , Copy_u8PiN); break;
				case DIO_PORTC : SET_BIT(DDRC_Register , Copy_u8PiN); break;
				case DIO_PORTD : SET_BIT(DDRD_Register , Copy_u8PiN); break;
			}
		}
		else if (Copy_u8_Direction == DIO_PIN_INPUT)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA : CLR_BIT(DDRA_Register , Copy_u8PiN); break;
				case DIO_PORTB : CLR_BIT(DDRB_Register , Copy_u8PiN); break;
				case DIO_PORTC : CLR_BIT(DDRC_Register , Copy_u8PiN); break;
				case DIO_PORTD : CLR_BIT(DDRD_Register , Copy_u8PiN); break;
			}
		}
		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enum_SetPinVlaue      (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 Copy_u8_Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PiN <= DIO_PIN7))
	{
		if (Copy_u8_Value == DIO_PIN_HIGH)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA : SET_BIT(PORTA_Register , Copy_u8PiN); break;
				case DIO_PORTB : SET_BIT(PORTB_Register , Copy_u8PiN); break;
				case DIO_PORTC : SET_BIT(PORTC_Register , Copy_u8PiN); break;
				case DIO_PORTD : SET_BIT(PORTD_Register , Copy_u8PiN); break;
			}
		}
		else if (Copy_u8_Value == DIO_PIN_LOW)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA : CLR_BIT(PORTA_Register , Copy_u8PiN); break;
				case DIO_PORTB : CLR_BIT(PORTB_Register , Copy_u8PiN); break;
				case DIO_PORTC : CLR_BIT(PORTC_Register , Copy_u8PiN); break;
				case DIO_PORTD : CLR_BIT(PORTD_Register , Copy_u8PiN); break;
			}
		}
		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enum_GetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 *Copy_PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PiN <= DIO_PIN7))
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : *Copy_PtrData = GET_BIT(PINA_Register , Copy_u8PiN); break;
			case DIO_PORTB : *Copy_PtrData = GET_BIT(PINB_Register , Copy_u8PiN); break;
			case DIO_PORTC : *Copy_PtrData = GET_BIT(PINC_Register , Copy_u8PiN); break;
			case DIO_PORTD : *Copy_PtrData = GET_BIT(PIND_Register , Copy_u8PiN); break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
}

DIO_ErrorStatus DIO_enum_TogglePinValue   (u8 Copy_u8PORT , u8 Copy_u8PiN)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if ((Copy_u8PORT <= DIO_PORTD ) && (Copy_u8PiN <= DIO_PIN7))
	{
		switch (DIO_PORTD)
		{
			case DIO_PORTA : TOGGLE_BIT(PORTA_Register , Copy_u8PiN); break;
			case DIO_PORTB : TOGGLE_BIT(PORTB_Register , Copy_u8PiN); break;
			case DIO_PORTC : TOGGLE_BIT(PORTC_Register , Copy_u8PiN); break;
			case DIO_PORTD : TOGGLE_BIT(PORTD_Register , Copy_u8PiN); break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
}

DIO_ErrorStatus DIO_enum_SetPortDirection (u8 Copy_u8PORT ,  u8 Copy_u8_Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : DDRA_Register = Copy_u8_Direction ; break;
			case DIO_PORTB : DDRB_Register = Copy_u8_Direction ; break;
			case DIO_PORTC : DDRC_Register = Copy_u8_Direction ; break;
			case DIO_PORTD : DDRD_Register = Copy_u8_Direction ; break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
}

DIO_ErrorStatus DIO_enum_SetPortVlaue     (u8 Copy_u8PORT , u8 Copy_u8_Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : PORTA_Register = Copy_u8_Value ; break;
			case DIO_PORTB : PORTB_Register = Copy_u8_Value ; break;
			case DIO_PORTC : PORTC_Register = Copy_u8_Value ; break;
			case DIO_PORTD : PORTD_Register = Copy_u8_Value ; break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
	
}

DIO_ErrorStatus DIO_enum_GetPortValue     (u8 Copy_u8PORT , u8 *Copy_PtrData )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : *Copy_PtrData = PINA_Register ; break;
			case DIO_PORTB : *Copy_PtrData = PINB_Register ; break;
			case DIO_PORTC : *Copy_PtrData = PINC_Register ; break;
			case DIO_PORTD : *Copy_PtrData = PIND_Register ; break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
}

DIO_ErrorStatus DIO_enum_TogglePortValue  (u8 Copy_u8PORT )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : PORTA_Register = ~PORTA_Register ; break;
			case DIO_PORTB : PORTB_Register = ~PORTB_Register ; break;
			case DIO_PORTC : PORTC_Register = ~PORTC_Register ; break;
			case DIO_PORTD : PORTD_Register = ~PORTD_Register ; break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK ;
	}
	return LOC_enumState ;
}
