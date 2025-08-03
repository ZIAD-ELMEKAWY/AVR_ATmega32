/*
 * @name 	DC_Motor_interface.h
 * @date  	Created on: 23/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../DIO/DIO_Interface.h"
#include "DC_Motor_config.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */
typedef struct
{
	u8 Port ;
	u8 Pin;
}motor_t;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void DC_Motor_init 	(motor_t motor);
void DC_Motor_ON 	(motor_t motor);
void DC_Motor_OFF 	(motor_t motor);



#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
