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
#include "HAL/KPD/KPD_Interface.h"

#include "LIB/Bit_MATH.h"
#include "LIB/Std_types.h"


#define F_CPU		8000000UL



int main()
{
	u8 RetValue = 0 ;
	// USART pin configuration
	DIO_Std_SetPinDirection(_PORTD_ , PIN0 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTD_ , PIN1 , DIO_PIN_OUTPUT);
	// KPD Initialization
	KPD_VoidInit();
	USART_Init();
	while(1)
	{
		RetValue = KPD_u8GetPressed();
		if ((RetValue >= '0' )&& (RetValue <= '9'))
		{
			USART_POLL_SendData(RetValue);
		}


	}
	return 0 ;
}
