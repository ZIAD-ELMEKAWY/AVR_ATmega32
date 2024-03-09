/*
 * Layer   : MCAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created: 07/03/2024 22:03:58
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/*********** Includes Section *******************/
#include "SSD_Private.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
//Pin
#define SSD_PIN0	0
#define SSD_PIN1	1
#define SSD_PIN2	2
#define SSD_PIN3	3
#define SSD_PIN4	4
#define SSD_PIN5	5
#define SSD_PIN6	6
#define SSD_PIN7	7
//Port
#define SSD_PORTA	0
#define SSD_PORTB	1
#define SSD_PORTC	2
#define SSD_PORTD	3

#define SSD_COMMON_CATHODE	 0
#define SSD_COMMON_ANODE	 1

#define SSD_PORT_OUTPUT		0xFF
#define SSD_PORT_INPUT		0x00

/************** Data Types Declaration Section ********************/
typedef struct
{ 
	u8 Type		 ;		// SSD COMMON CATHODE or SSD COMMON ANODE
	u8 Data_Port ;		// SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePort;      // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePin ;      // SSD_PIN0 to SSD_PIN7
}SSD_Type;
/*************** Function Declaration Section *********************/
void SSD_voidInitialDataPort (SSD_Type Copy_StructConfig) ;
void SSD_voidEnable			 (SSD_Type Copy_StructConfig) ;
void SSD_voidDisable		 (SSD_Type Copy_StructConfig) ;
void SSD_voidSendNumber		 (SSD_Type Copy_StructConfig , u8 Copy_u8Number) ;
void SSD_Write				 (u8 PortName, u8 Copy_u8Number);

#endif /* SSD_INTERFACE_H_ */