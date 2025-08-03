/*
 * @name 	Buzzer_Interface.h
 * @date  	Created on: 19/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../DIO/DIO_Interface.h"
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
}buz_t;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
Std_ReturnType Buz_Void_Initialzation 	(buz_t buz) ;
Std_ReturnType Buz_Void_Turn_ON  		(buz_t buz) ;
Std_ReturnType Buz_Void_Turn_OFF 	(buz_t buz) ;
Std_ReturnType Buz_Void_Toglle        	(buz_t buz) ;

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
