/*
 * @name 	USART_register.h
 * @date  	Created on: 30/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef MCAL_USART_USART_REGISTER_H_
#define MCAL_USART_USART_REGISTER_H_


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* --------- USART I/O Data Register – UDR ---------- */
#define UDR					*((volatile u8 *) 0x2C)
/* --------- USART Control and Status Register A – UCSRA ---------- */
#define UCSRA					*((volatile u8 *) 0x2B)
#define UCSRA_RXC		7
#define UCSRA_TXC		6
#define UCSRA_UDRE		5
#define UCSRA_FE			4
#define UCSRA_DOR		3
#define UCSRA_PE			2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0
/* --------- USART Control and Status Register B – UCSRB ---------- */
#define UCSRB					*((volatile u8 *) 0x2A)
#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE	5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2	2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0
/* --------- USART Control and Status Register C – UCSRC ---------- */
#define UCSRC_UBRRH    				*((volatile u8 *) 0X40)
#define UCSRC_UBRRH_URSEL		7
#define UCSRC_UBRRH_UMSEL		6
#define UCSRC_UBRRH_UPM1			5
#define UCSRC_UBRRH_UPM0			4
#define UCSRC_UBRRH_USBS			3
#define UCSRC_UBRRH_UCSZ1		2
#define UCSRC_UBRRH_UCSZ0		1
#define UCSRC_UBRRH_UCPOL		0
/* --------- USART Baud Rate Registers – UBRRL and UBRRH ---------- */
#define UBRRL           		*((volatile u8 *) 0X29)

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */


#endif /* MCAL_USART_USART_REGISTER_H_ */
