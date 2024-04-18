/*
 * LCD_config.h
 * Layer   : HAL
 * SWC	   : LCD
 * Author  : Ziad
 * Created: 14/03/2024 12:38:38
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*********** Includes Section *******************/
#include "DIO_interface.h"

/*********** Macro Function Declaration Section *******************/
/**************** Macro Declaration Section ***********************/
#define CLCD_MODE  8

#define CLCD_DATA_PORT      DIO_PORTA

/* RS,RW,EN */
#define CLCD_CONTROL_PORT   DIO_PORTB
/* the importance of this thing to make your code more readable & change ports and pins easily */
#define CLCD_RS             DIO_PIN0
#define CLCD_RW             DIO_PIN1
#define CLCD_EN             DIO_PIN3
/************** Data Types Declaration Section ********************/

/*************** Function Declaration Section *********************/



#endif /* LCD_CONFIG_H_ */
