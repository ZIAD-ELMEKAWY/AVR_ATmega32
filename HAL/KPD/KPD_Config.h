/*
 * @name 	KPD_Config.h
 * @date  	Created on: 21/7/2025
 * @author  Ziad Elmakawy
 */
#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../DIO/DIO_Interface.h"
#include <util/delay.h>
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define KPD_ROW_INIT		PIN0
#define KPD_ROW_END		PIN3
#define KPD_COL_INIT		PIN4
#define KPD_COL_END		PIN7

#define KPD_PORT		_PORTD_

#define KPD_ROW1		PIN0
#define KPD_ROW2		PIN1
#define KPD_ROW3		PIN2
#define KPD_ROW4		PIN3

#define KPD_COL1		PIN4
#define KPD_COL2		PIN5
#define KPD_COL3		PIN6
#define KPD_COL4		PIN7
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */


#endif /* HAL_KPD_KPD_CONFIG_H_ */
