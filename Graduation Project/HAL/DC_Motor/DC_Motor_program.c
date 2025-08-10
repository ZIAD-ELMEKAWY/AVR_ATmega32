/*
 * @name 	DC_Motor_program.c
 * @date  	Created on: 23/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "DC_Motor_interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				DC_Motor_init
 * @brief
 * @argument
 * @return
 */
void DC_Motor_init 	(motor_t motor)
{
	if((motor.Port>= _PORTA_) && (motor.Port<= _PORTD_) )
	{
		if((motor.Pin >= PIN0) && (motor.Pin <= PIN7))
		{
			DIO_Std_SetPinDirection(motor.Port, motor.Pin , DIO_PIN_OUTPUT);
			DIO_Std_SetPinValue(motor.Port , motor.Pin , PIN_LOW);
		}
	}
}

/***
 * @name				DC_Motor_ON
 * @brief
 * @argument
 * @return
 */
void DC_Motor_ON 	(motor_t motor)
{
	if((motor.Port>= _PORTA_) && (motor.Port<= _PORTD_) )
	{
		if((motor.Pin >= PIN0) && (motor.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(motor.Port , motor.Pin , PIN_HIGH);
		}
	}
}

/***
 * @name				DC_Motor_OFF
 * @brief
 * @argument
 * @return
 */
void DC_Motor_OFF (motor_t motor)
{
	if((motor.Port >= _PORTA_) && (motor.Port<= _PORTD_) )
	{
		if((motor.Pin >= PIN0) && (motor.Pin <= PIN7))
		{
			DIO_Std_SetPinValue(motor.Port , motor.Pin , PIN_LOW);
		}
	}
}



