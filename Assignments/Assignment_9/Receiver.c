/*
 * @name 		main.c
 * @Subject	UART
 * @date  		Created on: 30/7/2025
 * @author  	Ziad Elmekawy
 */


#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/USART/USART_interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"

#include "LIB/Bit_MATH.h"
#include "LIB/Std_types.h"


#define F_CPU		8000000UL


int main()
{
	u8 received_compare_value = 0;
	u8 ctc_value = 0 ;
	// USART pin configuration
	DIO_Std_SetPinDirection(_PORTD_ , PIN0 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTD_ , PIN1 , DIO_PIN_OUTPUT);
	// Timer0 pin configuration
	DIO_Std_SetPinDirection(_PORTB_ , PIN3 , DIO_PIN_OUTPUT);
	//  Initialization
	USART_Init();
	GIE_Enable();
	TIMER0_voidInit();
	TIMER0_voidSetCTCTimerValue(ctc_value);
	while(1)
	{
		USART_POLL_ReceiveData(&received_compare_value);
		if ((received_compare_value >= '0' )&& (received_compare_value <= '9'))
		{
			switch (received_compare_value) {
			case '0':
				TIMER0_voidSetCTCTimerValue(0);
				break;
			case '1':
				TIMER0_voidSetCTCTimerValue(30);
				break;
			case '2':
				TIMER0_voidSetCTCTimerValue(60);
				break;
			case '3':
				TIMER0_voidSetCTCTimerValue(90);
				break;
			case '4':
				TIMER0_voidSetCTCTimerValue(120);
				break;
			case '5':
				TIMER0_voidSetCTCTimerValue(150);
				break;
			case '6':
				TIMER0_voidSetCTCTimerValue(180);
				break;
			case '7':
				TIMER0_voidSetCTCTimerValue(210);
				break;
			case '8':
				TIMER0_voidSetCTCTimerValue(230);
				break;
			case '9':
				TIMER0_voidSetCTCTimerValue(255);
				break;
			default:
					break;
			}

		}
		else
		{
			TIMER0_voidSetCTCTimerValue(0);
		}

	}
	return 0 ;
}
