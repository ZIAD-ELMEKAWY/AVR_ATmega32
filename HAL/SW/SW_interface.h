/*
 * interface.h
 *	Layer  : HAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created: 09/03/2024 01:35:07
 */ 


#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_


/*********** Includes Section *******************/
#include "Math.h"
#include "Std_Types.h"
#include "DIO_interface.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
#define SW_PRESSED	    1
#define SW_NOT_PRESSED  0

#define SW_INT_PULL_UP		0
#define SW_EXT_PULL_UP		1
#define SW_EXT_PULL_DOWN	2
#define SW_FLOATING			3
/************** Data Types Declaration Section ********************/
typedef struct 
{
	u8 Port		  ;
	u8 Pin		  ;
	u8 Pull_State ;
}SW_type;
/*************** Function Declaration Section *********************/
void SW_voidInit		 (SW_type SW_Config);
u8   SW_u8GetPressed	 (SW_type SW_Config);


#endif /* SW_INTERFACE_H_ */