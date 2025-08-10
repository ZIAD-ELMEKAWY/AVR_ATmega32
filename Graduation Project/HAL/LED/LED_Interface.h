/*
 * @name 	LED_Interface.h
 * @date  	Created on: 19/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../MCAL/DIO/DIO_Interface.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define ACTIVE_HIGH		1
#define ACTIVE_LOW		0
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */
typedef struct
{
	u8 Port ;
	u8 Pin;
	u8 Status ;
}led_t;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
Std_ReturnType LED_Void_Initialzation (led_t led) ;
Std_ReturnType LED_Void_Turn_ON  (led_t led) ;
Std_ReturnType LED_Void_Turn_OFF (led_t led) ;
Std_ReturnType LED_Void_Toggle        (led_t led) ;
#endif /* HAL_LED_LED_INTERFACE_H_ */
