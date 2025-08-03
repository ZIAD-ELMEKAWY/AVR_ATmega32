/*
 * @name 	ass_1_1.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include "DIO_Registers.h"
#include "Std_types.h"
#include "Bit_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"

#define F_CPU	8000000UL

void Application_Setup(void);
void Blink_LED (void);



void main()
{
	// Common Anode
	u8 Sev_Seg[10] = {
		    0b11000000, // 0
		    0b11111001, // 1
		    0b10100100, // 2
		    0b10110000, // 3
		    0b10011001, // 4
		    0b10010010, // 5
		    0b10000010, // 6
		    0b11111000, // 7
		    0b10000000, // 8
		    0b10010000  // 9
		};
	u8 iteration = 0 ;

	Application_Setup();
	DIO_Std_SetPortValue(_PORTB_ , Sev_Seg[0]) ;		// Set initial value which appear on 70-segment
	while(1)
	{
		if(DIO_Std_GetPinValue(_PORTC_ , PIN1) == PIN_LOW)
		{
			DIO_Std_SetPortValue(_PORTB_ , Sev_Seg[iteration]) ;
			iteration++;
			if(iteration == 10)
			{
					iteration = 0 ;
			}
		}
		if(DIO_Std_GetPinValue(_PORTC_ , PIN0) == PIN_LOW)
		{
			if(iteration > 0)
			{
				iteration--;
				DIO_Std_SetPortValue(_PORTB_ , Sev_Seg[iteration]) ;
			}
			else
			{
				iteration =0 ;
			}
		}
		_delay_ms(220);

	}
}

void Application_Setup(void)
{
	// Set Port B as output for seven segment common Anode
	DIO_Std_SetPortDirection(_PORTB_  , DIO_PORT_OUTPUT) ;
	// Set pin 0 as Input pull up switch
	DIO_Std_SetPinDirection(_PORTC_  , PIN0 ,DIO_PIN_INPUT) ;
	DIO_Std_SetPinValue(_PORTC_ , PIN0 , PIN_HIGH);
	// Set pin 1 as Input pull up switch
	DIO_Std_SetPinDirection(_PORTC_  , PIN1 ,DIO_PIN_INPUT) ;
	DIO_Std_SetPinValue(_PORTC_ , PIN1 , PIN_HIGH);
}


