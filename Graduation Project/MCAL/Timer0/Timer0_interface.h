/*
 * @name 	Timer0_interface.h
 * @date  	Created on: 27/7/2025
 * @author  Ziad Elmekawy
 */


#ifndef TIMER0_TIMER0_INTERFACE_H_
#define TIMER0_TIMER0_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Timer0_config.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */
typedef enum
{
	TIMER0_INT_DISABLE =0  ,
	TIMER0_INT_ENABLE
}TIMER0_INT_e;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void Timer0_Init (void);
void Timer0_DeInit (void);
void Timer0_SetTimerValue (u8 value);
void Timer0_SetCTCTimerValue (u8 value);
void Timer0_OVIntEnableDisable   (u8 Copy_u8TIMER0_INT_e);
void Timer0_CTCIntEnableDisable (u8 Copy_u8TIMER0_INT_e);

u8 Timer0_SetOVCallBack	(void (* pvCallBackFun)(void));
u8 Timer0_SetCTCCallBack	(void (* pvCallBackFun)(void));
#endif /* TIMER0_TIMER0_INTERFACE_H_ */
