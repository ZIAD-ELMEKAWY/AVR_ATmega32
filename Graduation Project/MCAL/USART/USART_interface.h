/*
 * @name 	USART_interface.h
 * @date  	Created on: 30/7/2025
 * @author  Ziad Elmekawy
 */


#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
// Polling
void USART_Init								(void);
void USART_POLL_SendData			(const u8 data);
void USART_POLL_SendString			(const u8* data);
void USART_POLL_ReceiveData		(u8 *data);
void USART_POLL_ReceiveString		(u8 counter ,u8 *data);
// Interrupt
void USART_INT_SendData				(const u8 data);
void USART_INT_SendString			(const u8* data);
void USART_INT_ReceiveData			(u8 *data);


#endif /* MCAL_USART_USART_INTERFACE_H_ */
