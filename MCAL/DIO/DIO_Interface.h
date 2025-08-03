/*
 * @name 	DIO.Interface.H
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "DIO_Private.h"
#include "DIO_Registers.h"
#include "../LIB/Std_types.h"
#include "../LIB/Bit_MATH.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
/*------------- Pin Functions -------------- */
Std_ReturnType DIO_Std_SetPinDirection(u8 PortName , u8 PinNumber , u8 Direction);
Std_ReturnType DIO_Std_SetPinValue(u8 PortName , u8 PinNumber , u8 Value);
Std_ReturnType DIO_Std_TogglePin(u8 PortName , u8 PinNumber );
u8 DIO_Std_GetPinValue(u8 PortName , u8 PinNumber );
/*------------- Port Functions ------------ */
Std_ReturnType DIO_Std_SetPortDirection(u8 PortName ,  u8 Direction);
Std_ReturnType DIO_Std_SetPortValue(u8 PortName , u8 Value);
u8 DIO_Std_GetPortValue(u8 PortName );
/* ------------- Nibble Functions ------------ */
Std_ReturnType DIO_Std_WriteHighNibbles (u8 PortName , u8 Value);
Std_ReturnType DIO_Std_WriteLowNibbles (u8 PortName , u8 Value);


#endif /* DIO_INTERFACE_H_ */
