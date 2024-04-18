/*
 * KPD_interface.h
 *
 * Created: 18/03/2024 02:26:03
 *  Author: hp
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/*********** Includes Section *******************/
#include "KPD_config.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
#define NOT_PRESSED		0xff
/************** Data Types Declaration Section ********************/

/*************** Function Declaration Section *********************/
void KPD_voidInit		(void);
u8	 KPD_u8GetPressed	(void);
u16  KPD_u16KPDNum		(void);
u8	 KPD_u8GetNumPressed	(void);
#endif /* KPD_INTERFACE_H_ */