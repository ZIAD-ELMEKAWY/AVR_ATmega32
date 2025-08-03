/*
 * @name 	Relay_interface.h
 * @date  	Created on: 23/7/2025
 * @author  Ziad ELmekawy
 */

#ifndef HAL_RELAY_RELAY_INTERFACE_H_
#define HAL_RELAY_RELAY_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Relay_config.h"
#include "../../DIO/DIO_Interface.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void Relay_Init 		(u8 port , u8 pin );
void Relay_ON		(u8 port , u8 pin );
void Relay_OFF		(u8 port , u8 pin );

#endif /* HAL_RELAY_RELAY_INTERFACE_H_ */
