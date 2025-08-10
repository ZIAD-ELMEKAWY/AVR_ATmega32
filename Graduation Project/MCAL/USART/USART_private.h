/*
 * @name 	USART_private.h
 * @date  	Created on: 30/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
/* --------------------------- USART Mode ------------------------------ */
#define ASYNCHRONOUS	0
#define SYNCHRONOUS		1
/* ------------------ USART Speed in asynchronous -------------------- */
#define USART_X1		0
#define USART_X2		1
/* ------------------ Set Multi-Processor Communication mode ------------------ */
#define DISABLE			0
#define ENABLE			1
/* ------------------ Even and Odd parity mode ------------------ */
#define EVEN_PARITY			2
#define ODD_PARITY			3
/* ---------------------------------- Set Stop bit ---------------------------------- */
#define STOP_BIT_1			0
#define STOP_BIT_2			1
/* ---------------------------------- Data Size ---------------------------------- */
#define DATA_SIZE_5_BIT		                    0
#define DATA_SIZE_6_BIT		                    1
#define DATA_SIZE_7_BIT		                    2
#define DATA_SIZE_8_BIT		                    3
#define DATA_SIZE_9_BIT		                    4
/* ---------------------------------- Frame Size ---------------------------------- */
#define FRAME_SIZE_8BIT		0b011
/* ---------------------------------- Baud Rate ---------------------------------- */
#define BAUD_RATE_9600			51
/* ------------ Set Clock Polarity (for SYNCHRONOUS mode only) -------------*/
#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1

#define UBRRL_MAX								256

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */


#endif /* MCAL_USART_USART_PRIVATE_H_ */
