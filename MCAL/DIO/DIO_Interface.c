/*
 * @name 	DIO_Interface.c
 * @date  	Created on: ??þ/??þ/????
 * @author  Ziad Elmekawy
 */


#include "DIO_Interface.h"

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Pin Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/***
 * @name				DIO_Std_SetPinDirection
 * @brief				Sets the direction (input/output) of a specific digital pin.
 * @argument PortName	The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument PinNumber	The pin number within the port (e.g., PIN0 to PIN7).
 * @argument PinDirection The desired direction (DIO_PIN_INPUT or DIO_PIN_OUTPUT).
 * @return				Std_ReturnType indicating success (E_OK) or failure (E_NOK).
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
 * @brief				Sets the output value (high/low) of a specific digital pin.
 * @argument PortName	The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument PinNumber	The pin number within the port (e.g., PIN0 to PIN7).
 * @argument Value		The desired value (PIN_HIGH or PIN_LOW).
 * @return				Std_ReturnType indicating success (E_OK) or failure (E_NOK).
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
 * @brief				Reads the current value (high/low) of a specific digital pin.
 * @argument PortName	The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument PinNumber	The pin number within the port (e.g., PIN0 to PIN7).
 * @return				u8 representing the pin value (0 for low, 1 for high), or an undefined value if an error occurs.
 */
u8 DIO_Std_GetPinValue(u8 PortName , u8 PinNumber )
{
	u8 RetValue  =0  ;
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

/***
 * @name				DIO_Std_TogglePin
 * @brief				Toggles the output value of a specific digital pin.
 * @argument PortName	The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument PinNumber	The pin number within the port (e.g., PIN0 to PIN7).
 * @return				Std_ReturnType indicating success (E_OK) or failure (E_NOK).
 */
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
 * @name							DIO_Std_SetPortDirection
 * @brief							Sets the direction (input/output) for all pins of a specific port.
 * @argument PortName		The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument Direction		The 8-bit value representing the direction for each pin (1 for output, 0 for input).
 * @return	Std_ReturnType indicating success (E_OK) or failure (E_NOK).
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
 * @name							DIO_Std_SetPortValue
 * @brief							Sets the output value for all pins of a specific port.
 * @argument PortName		The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument Value			The 8-bit value to set for the port (1 for high, 0 for low on each pin).
 * @return							Std_ReturnType indicating success (E_OK) or failure (E_NOK).
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
 * @name							DIO_Std_GetPortValue
 * @brief							Reads the current input value of all pins of a specific port.
 * @argument PortName		The name of the port (e.g., _PORTA_, _PORTB_).
 * @return				u8 		representing the 8-bit port value, or an undefined value if an error occurs.
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
 * @name							DIO_Std_WriteHighNibbles
 * @brief							Writes a value to the higher nibble (bits 4-7) of a specific port, preserving the lower nibble.
 * @argument PortName		The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument Value			The 4-bit value to write to the high nibble.
 * @return	Std_ReturnType indicating success (E_OK) or failure (E_NOK).
 */
Std_ReturnType DIO_Std_WriteHighNibbles (u8 PortName , u8 Value)
{
    Std_ReturnType Ret = E_OK ;
    if((PortName >= _PORTA_) && (PortName <= _PORTD_))
    {
        switch(PortName)
        {
            case _PORTA_  : PORTA = (PORTA & 0x0F) | (Value << 4) ;  break ;
            case _PORTB_  : PORTB = (PORTB & 0x0F) | (Value << 4) ;  break ;
            case _PORTC_  : PORTC = (PORTC & 0x0F) | (Value << 4) ;  break ; // Corrected line for PC4-PC7
            case _PORTD_  : PORTD = (PORTD & 0x0F) | (Value << 4) ;  break ;
        }
    }
    else
    {
        Ret = E_NOK ;
    }
    return Ret ;
}

/***
 * @name							DIO_Std_WriteLowNibbles
 * @brief							Writes a value to the lower nibble (bits 0-3) of a specific port, preserving the higher nibble.
 * @argument PortName		The name of the port (e.g., _PORTA_, _PORTB_).
 * @argument Value			The 4-bit value to write to the low nibble.
 * @return	Std_ReturnType indicating success (E_OK) or failure (E_NOK).
 */
Std_ReturnType DIO_Std_WriteLowNibbles (u8 PortName , u8 Value)
{
    Std_ReturnType Ret = E_OK ;
        if((PortName >= _PORTA_) && (PortName <= _PORTD_))
        {
            switch(PortName)
            {
                case _PORTA_  : PORTA = (PORTA & 0xF0) | (Value & 0x0F) ;  break ;
                case _PORTB_  : PORTB = (PORTB & 0xF0) | (Value & 0x0F) ;  break ;
                case _PORTC_  : PORTC = (PORTC & 0xF0) | (Value & 0x0F) ;  break ;
                case _PORTD_  : PORTD = (PORTD & 0xF0) | (Value & 0x0F) ;  break ;
            }
        }
        else
        {
            Ret = E_NOK ;
        }
        return Ret ;
}

