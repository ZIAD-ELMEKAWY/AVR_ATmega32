/*
 * @name 	EXTI_interface.h
 * @date  	Created on: 23/7/2025
 * @author  	Ziad Elmekawy
 */


#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../DIO/DIO_Interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<< Data Types  >>>>>>>>>>>>>>>>>>>>>>>  */
typedef enum
{
	EXTI_INT0=0,
	EXTI_INT1,
	EXTI_INT2,
}EXTI_INTNUM_e;

typedef enum
{
	EXTI_DISABLE=0,
	EXTI_ENABLE,
}EXTI_MODE_e;

typedef enum
{
	EXTI_LOW_LEVEL=0,
	EXTI_ON_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE,

}EXTI_SENSTIVITY_e;
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));
void EXTI_voidEnableDisable(u8 copy_u8_EXTI_INTNum_e,u8 copy_u8EXTI_MODE_e);
void EXTI_voidSetSenstivity(u8 copy_u8_EXTI_INTNum_e,u8 copy_EXTI_SENSTIVITY_e);
#endif /* EXTI_EXTI_INTERFACE_H_ */

