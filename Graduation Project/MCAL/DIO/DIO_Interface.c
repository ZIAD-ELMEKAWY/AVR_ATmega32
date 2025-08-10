/*
 * @name 	DIO_Interface.c
 * @date  	Created on: 17/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */


#include "DIO_Interface.h"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Pin Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/***
 * @name				DIO_Std_SetPinDirection
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_SetPinDirection(u8 PortName , u8 PinNumber , u8 PinDirection)
{
	Std_ReturnType Ret_Status = E_OK ;
	if((PortName >= _PORTA_ ) && (PortName <= _PORTD_))
	{
		if((PinNumber >= PIN0 ) && (PinNumber <= PIN7))
		{
			if(PinDirection == DIO_PIN_INPUT)
			{
				switch(PortName)
				{
					case _PORTA_ : CLEAR_BIT(DDRA , PinNumber);  break ;
					case _PORTB_  : CLEAR_BIT(DDRB , PinNumber);  break ;
					case _PORTC_  : CLEAR_BIT(DDRC , PinNumber);  break ;
					case _PORTD_  : CLEAR_BIT(DDRD , PinNumber);  break ;
				}
			}
			else if (PinDirection == DIO_PIN_OUTPUT)
			{
				switch(PortName)
				{
					case _PORTA_ : SET_BIT(DDRA , PinNumber);  break ;
					case _PORTB_  : SET_BIT(DDRB , PinNumber);  break ;
					case _PORTC_  : SET_BIT(DDRC , PinNumber);  break ;
					case _PORTD_  : SET_BIT(DDRD , PinNumber);  break ;
				}
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
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status;
}

/***
 * @name				DIO_Std_SetPinValue
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_SetPinValue(u8 PortName , u8 PinNumber , u8 Value)
{
	Std_ReturnType Ret_Status = E_OK ;
		if((PortName >= _PORTA_) && (PortName <= _PORTD_))
		{
			if((PinNumber >= PIN0 ) && (PinNumber <= PIN7))
			{
				if(Value == PIN_HIGH)
				{
					switch(PortName)
					{
						case _PORTA_ : SET_BIT(PORTA , PinNumber);  break ;
						case _PORTB_  : SET_BIT(PORTB , PinNumber);  break ;
						case _PORTC_  : SET_BIT(PORTC , PinNumber);  break ;
						case _PORTD_  : SET_BIT(PORTD , PinNumber);  break ;
					}
				}
				else if(Value == PIN_LOW)
				{
					switch(PortName)
					{
						case _PORTA_  : CLEAR_BIT(PORTA , PinNumber);  break ;
						case _PORTB_  : CLEAR_BIT(PORTB , PinNumber);  break ;
						case _PORTC_  : CLEAR_BIT(PORTC , PinNumber);  break ;
						case _PORTD_  : CLEAR_BIT(PORTD , PinNumber);  break ;
					}
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
		}
		else
		{
			Ret_Status = E_NOK ;
		}
		return Ret_Status ;
}

/***
 * @name				DIO_Std_GetPinValue
 * @brief
 * @argument
 * @return
 */
u8 DIO_Std_GetPinValue(u8 PortName , u8 PinNumber )
{
	Std_ReturnType RetValue  =0  ;
	if((PortName >= _PORTA_) && (PortName <= _PORTD_))
	{
		if((PinNumber >= PIN0 ) && (PinNumber <= PIN7))
		{
			switch(PortName)
			{
					case _PORTA_ : RetValue = GET_BIT(PINA , PinNumber);  break ;
					case _PORTB_  : RetValue = GET_BIT(PINB , PinNumber);  break ;
					case _PORTC_  : RetValue = GET_BIT(PINC , PinNumber);  break ;
					case _PORTD_  : RetValue = GET_BIT(PIND , PinNumber);  break ;
			}
		}
	}
	return RetValue ;
}

Std_ReturnType DIO_Std_TogglePin(u8 PortName , u8 PinNumber )
{
	Std_ReturnType Ret_Status = E_OK ;
	if((PortName >= _PORTA_) && (PortName <= _PORTD_))
	{
		if((PinNumber >= PIN0 ) && (PinNumber <= PIN7))
		{
			switch(PortName)
			{
				case _PORTA_ : TOGGLE_BIT(PORTA , PinNumber);  break ;
				case _PORTB_  : TOGGLE_BIT(PORTB , PinNumber);  break ;
				case _PORTC_  : TOGGLE_BIT(PORTC , PinNumber);  break ;
				case _PORTD_  : TOGGLE_BIT(PORTD , PinNumber);  break ;
			}
		}
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return Ret_Status ;
}


/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Port Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/***
 * @name				DIO_Std_SetPortDirection
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_SetPortDirection(u8 PortName ,  u8 Direction)
{
	Std_ReturnType Ret_Status = E_OK ;
			if((PortName >= _PORTA_) && (PortName <= _PORTD_))
			{
				switch(PortName)
				{
					case _PORTA_  : DDRA = Direction ;  break ;
					case _PORTB_  : DDRB = Direction ;  break ;
					case _PORTC_  : DDRC = Direction ;  break ;
					case _PORTD_  : DDRD = Direction ;  break ;
				}
			}
			else
			{
				Ret_Status = E_NOK ;
			}
			return Ret_Status ;
}

/***
 * @name				DIO_Std_SetPortValue
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_SetPortValue(u8 PortName ,  u8 Value)
{
	Std_ReturnType Ret_Status = E_OK ;
				if((PortName >= _PORTA_) && (PortName <= _PORTD_))
				{
					switch(PortName)
					{
						case _PORTA_  : PORTA = Value ;  break ;
						case _PORTB_  : PORTB = Value ;  break ;
						case _PORTC_  : PORTC = Value ;  break ;
						case _PORTD_  : PORTD = Value ;  break ;
					}
				}
				else
				{
					Ret_Status = E_NOK ;
				}
				return Ret_Status ;
}

/***
 * @name				DIO_Std_GetPortValue
 * @brief
 * @argument
 * @return
 */
u8 DIO_Std_GetPortValue(u8 PortName )
{
	 u8 RetValue = 0 ;
	if((PortName >= _PORTA_) && (PortName <= _PORTD_))
	{
		switch(PortName)
		{
			case _PORTA_ : RetValue = PINA ;  break ;
			case _PORTB_  : RetValue = PINB ;  break ;
			case _PORTC_  : RetValue = PINC ;  break ;
			case _PORTD_  : RetValue = PIND ;  break ;
		}
	}
	return RetValue ;
}

/***
 * @name				DIO_Std_WriteHighNibbles
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_WriteHighNibbles (u8 PortName , u8 Value)
{
	Std_ReturnType Ret = E_OK ;
	if((PortName >= _PORTA_) && (PortName <= _PORTD_))
	{
		switch(PortName)
		{
			case _PORTA_  : PORTA = 0x0f ;  PORTA |= Value ;  break ;
			case _PORTB_  : PORTB = 0x0f ;   PORTB |= Value ;  break ;
			case _PORTC_  : PORTC = 0x0f ;   PORTC |= Value ;  break ;
			case _PORTD_  : PORTD = 0x0f ;  PORTD |= Value ;  break ;
		}
	}
	else
	{
		Ret = E_NOK ;
	}
	return Ret ;
}

/***
 * @name				DIO_Std_WriteLowNibbles
 * @brief
 * @argument
 * @return
 */
Std_ReturnType DIO_Std_WriteLowNibbles (u8 PortName , u8 Value)
{
	Std_ReturnType Ret = E_OK ;
		if((PortName >= _PORTA_) && (PortName <= _PORTD_))
		{
			switch(PortName)
			{
				case _PORTA_  : PORTA = 0xf0 ;  PORTA |= Value ;  break ;
				case _PORTB_  : PORTB = 0xf0 ;   PORTB |= Value ;  break ;
				case _PORTC_  : PORTC = 0xf0 ;   PORTC |= Value ;  break ;
				case _PORTD_  : PORTD = 0xf0 ;  PORTD |= Value ;  break ;
			}
		}
		else
		{
			Ret = E_NOK ;
		}
		return Ret ;
}
