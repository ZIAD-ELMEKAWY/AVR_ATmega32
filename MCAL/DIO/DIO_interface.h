/*
 * DIO_interface.h
 * Layer   : MCAL
 * SWC	   : GPIO 
 * Author  : Ziad
 * Created : 06/03/2024 05:36:44 م
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*********** Includes Section ********************/
#include "Math.h"
#include "Std_Types.h"
/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT  0x00

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORT_HIGH 1
#define DIO_PORT_LOW  0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
/************** Data Types Declaration Section ********************/
typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;

/*************** Function Declaration Section *********************/
// Pin
DIO_ErrorStatus DIO_enum_SetPinDirection  (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 Copy_u8_Direction);
DIO_ErrorStatus DIO_enum_SetPinVlaue      (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 Copy_u8_Value);
DIO_ErrorStatus DIO_enum_GetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PiN , u8 *Copy_PtrData);
DIO_ErrorStatus DIO_enum_TogglePinValue   (u8 Copy_u8PORT , u8 Copy_u8PiN);
// Port
DIO_ErrorStatus DIO_enum_SetPortDirection (u8 Copy_u8PORT ,  u8 Copy_u8_Direction);
DIO_ErrorStatus DIO_enum_SetPortVlaue     (u8 Copy_u8PORT , u8 Copy_u8_Value);
DIO_ErrorStatus DIO_enum_GetPortValue     (u8 Copy_u8PORT , u8 *Copy_PtrData );
DIO_ErrorStatus DIO_enum_TogglePortValue  (u8 Copy_u8PORT );

#endif /* DIO_INTERFACE_H_ */
