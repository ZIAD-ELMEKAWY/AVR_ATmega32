/*
 * @name 	SPI 
 * @date  	Created on: 31/7/2025
 * @author  Ziad Elmekawy
 */



#include <util/delay.h>
#include "LIB/Bit_MATH.h"
#include "LIB/Std_types.h"
#include "SPI/SPI_Interface.h"
#include "ADC/ADC_interface.h"
#include "DIO/DIO_Interface.h"

#define F_CPU		8000000UL

int main ()
{
	u16 ReturnValue = 0 ;
	u8 temp = 0 ;
	// Master SPI
	DIO_Std_SetPinDirection(_PORTB_ , PIN5 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(_PORTB_ , PIN6 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTB_ , PIN7 , DIO_PIN_OUTPUT);
	// Analog pin
	DIO_Std_SetPinDirection(_PORTA_ , PIN0 , DIO_PIN_INPUT);
	ADC_voidInit();
	// Initialization
	SPI_Init(SPI_MASTER_MODE);

	// Send data

	while(1)
	{
		ADC_u8GetResultSync( ADC_CHANNEL0 , &ReturnValue);
		ReturnValue = ReturnValue *( 5000 / 1024.0) ;
		temp = ((f32)ReturnValue / 10.0) ;
		SPI_DataSend((u8)temp);
		_delay_ms(500);
	}
	return 0 ;
}
