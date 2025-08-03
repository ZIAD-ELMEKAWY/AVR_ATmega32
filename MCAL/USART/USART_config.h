/*
 * @name 	USART_config.h
 * @date  	Created on: 30/7/2025
 * @author  Ziad Elmekawy
 */


#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "USART_private.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
/*
 * Options
 * 		1. ASYNCHRONOUS
 * 		2. SYNCHRONOUS
 */
#define USART_MODE		ASYNCHRONOUS

/*
 * Options
 * 		1. EVEN_PARITY
 * 		2. ODD_PARITY
 */
#define USART_PARITY_MODE		EVEN_PARITY

/*
 * Options
 * 		1. STOP_BIT_1
 * 		2. STOP_BIT_2
 */
#define USART_STOP_MODE		STOP_BIT_1

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif /* MCAL_USART_USART_CONFIG_H_ */
