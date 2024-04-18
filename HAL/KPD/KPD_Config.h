/*
 * KPD_config.h
 *
 * Created: 18/03/2024 02:26:17
 *  Author: hp
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/*********** Includes Section *******************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "DIO_interface.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
#define KPD_ROW_INIT	DIO_PIN0
#define KPD_ROW_END		DIO_PIN3
#define KPD_COL_INIT	DIO_PIN4
#define KPD_COL_END		DIO_PIN7

#define KPD_PORT		DIO_PORTC

#define KPD_ROW1		DIO_PIN0
#define KPD_ROW2		DIO_PIN1
#define KPD_ROW3		DIO_PIN2
#define KPD_ROW4		DIO_PIN3

#define KPD_COL1		DIO_PIN4
#define KPD_COL2		DIO_PIN5
#define KPD_COL3		DIO_PIN6
#define KPD_COL4		DIO_PIN7

/************** Data Types Declaration Section ********************/

/************** Variable Section ********************/

/*************** Function Declaration Section *********************/



#endif /* KPD_CONFIG_H_ */
