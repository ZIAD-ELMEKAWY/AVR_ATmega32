/*
 * @name 	DIO_Private.h
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_



/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define _PORTA_		1
#define _PORTB_		2
#define _PORTC_		3
#define _PORTD_		4

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#define DIO_PIN_INPUT    		0
#define DIO_PIN_OUTPUT			1

#define DIO_PORT_OUTPUT		 0xFF
#define DIO_PORT_INPUT  		 0x00

#define PIN_LOW			0
#define PIN_HIGH		1

#define PORT_LOW			0b00000000
#define PORT_HIGH			0b11111111
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */



#endif /* DIO_PRIVATE_H_ */
