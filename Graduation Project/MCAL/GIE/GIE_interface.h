/*
 * @name 	GIE_interface.h
 * @date  	Created on: 23/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

#ifndef GIE_GIE_INTERFACE_H_
#define GIE_GIE_INTERFACE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../DIO/DIO_Interface.h"
#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"
#include "GIE_config.h"
#include "GIE_private.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<< Data Types  >>>>>>>>>>>>>>>>>>>>>>>  */
/**
 * @ref Mode_e
 */
typedef enum
{
	DISABLE = 0 ,
	ENABLE
}Mode_e;

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void GIE_Enable		(void) ;
void GIE_Disable 	(void);
void GIE_EnableDisable	(u8 mode);
#endif /* GIE_GIE_INTERFACE_H_ */
