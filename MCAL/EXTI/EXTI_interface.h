/*
 * @name 	EXTI_interface.h
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
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
/**
 * @ref 	EXTI_INTNUM_e
 */
typedef enum
{
	EXTI_INT_0 = 0 ,
	EXTI_INT_1 ,
	EXTI_INT_2
}EXTI_INTNUM_e;

/**
 * @ref 	EXTI_Mode_e
 */
typedef enum
{
	EXTI_DISABLE = 0 ,
	EXTI_ENABLE
}EXTI_Mode_e;

/**
 * @ref EXTI_SENSTIVITY_e
 */
typedef enum
{
	EXTI_LOW_LEVEL = 0 ,
	EXTI_ON_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
}EXTI_SENSTIVITY_e;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void EXTI_VoidEnableDisable		(u8 Ext_Int , u8 mode );
void EXTI_VoidSetSenstivity		(u8 Ext_Int , u8 senstivity );
Std_ReturnType EXTI_Std_SetCallBack 				(u8 Ext_Int ,  void (*PrCallBackFun)(void));

#endif /* EXTI_EXTI_INTERFACE_H_ */
