/*
 * @name 	SPI 
 * @date  	Created on: 31/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "LIB/Bit_MATH.h"
#include "LIB/Std_types.h"
#include "SPI/SPI_Interface.h"
#include "DIO/DIO_Interface.h"
#include "DC_Motor/DC_Motor_interface.h"

#define F_CPU		8000000UL

motor_t motor1 =
{
		.Port = _PORTC_ ,
		.Pin = PIN0
};

int main ()
{
	u8 data = 0 ;
	// Slave
	// Set pins
	DIO_Std_SetPinDirection(_PORTB_ , PIN6 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(_PORTB_ , PIN4 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTB_ , PIN5 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTB_ , PIN7 , DIO_PIN_INPUT);
	// Initialization
	SPI_Init(SPI_SLAVE_MODE);
	// Motor Initialization
	DC_Motor_init(motor1);
	LCD_VoidInit();

	while(1)
	{
		data = SPI_SlaveReceive();
		if ((data % 2 ) == 0)
		{
			data *= 2   ;
		}
		else
		{
			data = (data *2 ) +1 ;
		}
		if (data >= 26)
		{
			DC_Motor_ON(motor1);
		}
		else
		{
			DC_Motor_OFF(motor1);
		}
	}
	return 0 ;
}
