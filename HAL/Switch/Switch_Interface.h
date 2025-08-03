/*
 * @name 	Switch_Interface.h
 * @date  	Created on: 19/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../DIO/DIO_Interface.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define SW_PRESSED	    1
#define SW_NOT_PRESSED  0

#define SW_INT_PULL_UP		0
#define SW_EXT_PULL_UP		1
#define SW_EXT_PULL_DOWN	2
#define SW_FLOATING			3
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */
typedef struct
{
	u8 Port ;
	u8 Pin;
	u8 Pull_State ;
}switch_t;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void Switch_VoidInit (switch_t sw);
u8   SW_u8GetPressed	 (switch_t sw);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
