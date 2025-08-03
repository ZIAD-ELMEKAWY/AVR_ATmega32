/*
 * @name 	Relay_program.c
 * @date  	Created on: 23/7/2025
 * @author  Ziad ELmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Relay_interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Relay_VoidInit
 * @brief				Initializes a relay by setting its control pin as an output and ensuring it's initially off.
 * @argument port		The port name where the relay is connected (e.g., _PORTA_, _PORTB_).
 * @argument pin		The pin number within the port where the relay is connected (e.g., PIN0 to PIN7).
 * @return				void
 */
void Relay_Init (u8 port , u8 pin )
{
	if((port>= _PORTA_) && (port<= _PORTD_) )
	{
		if((pin >= PIN0) && (pin <= PIN7))
		{
			DIO_Std_SetPinDirection( port, pin , DIO_PIN_OUTPUT);
			DIO_Std_SetPinValue(port , pin , PIN_LOW);
		}
	}
}

/***
 * @name				Relay_ON
 * @brief				Turns on the relay by setting its control pin to a high value.
 * @argument port		The port name where the relay is connected (e.g., _PORTA_, _PORTB_).
 * @argument pin		The pin number within the port where the relay is connected (e.g., PIN0 to PIN7).
 * @return				void
 */
void Relay_ON	(u8 port , u8 pin )
{
	if((port>= _PORTA_) && (port<= _PORTD_) )
	{
		if((pin >= PIN0) && (pin <= PIN7))
		{
			DIO_Std_SetPinValue(port , pin , PIN_HIGH);
		}
	}
}

/***
 * @name				Relay_OFF
 * @brief				Turns off the relay by setting its control pin to a low value.
 * @argument port		The port name where the relay is connected (e.g., _PORTA_, _PORTB_).
 * @argument pin		The pin number within the port where the relay is connected (e.g., PIN0 to PIN7).
 * @return				void
 */
void Relay_OFF	(u8 port , u8 pin )
{
	if((port>= _PORTA_) && (port<= _PORTD_) )
	{
		if((pin >= PIN0) && (pin <= PIN7))
		{
			DIO_Std_SetPinValue(port , pin , PIN_LOW);
		}
	}
}
