/*
 * @name 	KPD_Interface.h
 * @date  	Created on: 21/7/2025
 * @author  Ziad Elmakawy
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "KPD_Config.h"
#include "KPD_Private.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define NOT_PRESSED		0xff
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void KPD_voidInit		(void);
u8   KPD_u8GetPressed	(void);
u16 KPD_u16KPDNum		(void);
u8   KPD_u8GetNumPressed	(void);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
