/*
 * LED_interface.h
 *	Layer  : HAL
 * SWC	   : GPIO
 * Author  : Ziad
 */ 

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
/*********** Includes Section *******************/
#include "Math.h"
#include "Std_Types.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
#define ACTIVE_HIGH		1
#define ACTIVE_LOW		0

//PIN
#define LED_PIN0	0
#define LED_PIN1	1
#define LED_PIN2	2
#define LED_PIN3	3
#define LED_PIN4	4
#define LED_PIN5	5
#define LED_PIN6	6
#define LED_PIN7	7

//PORT
#define LED_PORTA	0
#define LED_PORTB	1
#define LED_PORTC	2
#define LED_PORTD	3



/************** Data Types Declaration Section ********************/
typedef struct  
{
	u8 Port			;
	u8 Pin			;
	u8 Active_State ;
}LED_Type;

typedef enum
{
	LED_NOK,
	LED_OK
}LED_ErrorStatus;

/*************** Function Declaration Section *********************/
void LED_voidInit	 (LED_Type LED_Configuration);
void LED_voidOn		 (LED_Type LED_Configuration);
void LED_voidOff	 (LED_Type LED_Configuration);
void LED_voidToggle	 (LED_Type LED_Configuration);

#endif /* LED_INTERFACE_H_ */