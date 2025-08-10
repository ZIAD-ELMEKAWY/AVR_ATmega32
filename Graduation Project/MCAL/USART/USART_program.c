/*
 * @name 	USART_program.c
 * @date  	Created on: 30/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_register.h"


/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
// ********************************* Polling *************************************
/***
 * @name				USART_Init
 * @brief				This Function initialize USART
 * @argument
 * @return
 */
void USART_Init	(void)
{
	u8 Local_UCSRC = 0 ;	// 0000 0000
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_URSEL);	// 1000 0000

	// select USART Mode
#if USART_MDOE == ASYNCHRONOUS
	CLEAR_BIT( Local_UCSRC , UCSRC_UBRRH_UMSEL);	// 1000 0000
#elif USART_MDOE == SYNCHRONOUS
	SET_BIT( Local_UCSRC , UCSRC_UBRRH_UMSEL);
#else
	#warning "Wrong USART_MODE configuration"
#endif
	// select USART  Parity Mode
#if USART_PARITY_MODE == ODD_PARITY
	SET_BIT( Local_UCSRC , UCSRC_UBRRH_UPM0);
	SET_BIT( Local_UCSRC , UCSRC_UBRRH_UPM1);
#elif USART_PARITY_MODE == EVEN_PARITY
	SET_BIT( Local_UCSRC , UCSRC_UBRRH_UPM1);		// 1010 0000
	CLEAR_BIT( Local_UCSRC , UCSRC_UBRRH_UPM0);
	#else
	#warning "Wrong USART_PARITY_MODE configuration"
#endif
	// select USART  Stop Bit
#if USART_STOP_MODE == STOP_BIT_1
	CLEAR_BIT( Local_UCSRC , UCSRC_UBRRH_USBS);
#elif USART_STOP_MODE == STOP_BIT_2
	SET_BIT( Local_UCSRC , UCSRC_UBRRH_USBS);
#else
	#warning "Wrong USART_STOP_MODE configuration"
#endif
	// Select 8-bit mode ==> set character size to 8 bit
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UCSZ0);
	SET_BIT(Local_UCSRC , UCSRC_UBRRH_UCSZ1);


	// Equal register with local variable
	UCSRC_UBRRH = Local_UCSRC ;
	// Set Baud Rate to 9600 , if you need to change it see data shit
	UBRRL = BAUD_RATE_9600 ;
	// Receiver Enable
	SET_BIT(UCSRB , UCSRB_RXEN);
	// Transmitter Enable
	SET_BIT(UCSRB , UCSRB_TXEN);

}

/***
 * @name				USART_POLL_SendData
 * @brief				This Function transmit data on USART ==> Send one byte (8-bit) of data
 * @argument
 * @return
 */
void USART_POLL_SendData	(const u8 data)
{
	while ((GET_BIT(UCSRA , UCSRA_UDRE)) == 0);
	UDR = data ;
}

/***
 * @name				USART_POLL_SendString
 * @brief				This Function transmit string on USART
 * @argument
 * @return
 */
void USART_POLL_SendString	(const u8* data)
{
	while(*data != '\0')
	{
		USART_POLL_SendData(*data);
		data++ ;
	}
}

/***
 * @name				USART_POLL_ReceiveData
 * @brief				This Function receive data from USART
 * @argument
 * @return
 */
void USART_POLL_ReceiveData		(u8 *data)
{
	while ((GET_BIT(UCSRA , UCSRA_RXC)) == 0);
	* data = UDR ;
}

/***
 * @name				USART_POLL_ReceiveString
 * @brief				This Function receive data from USART
 * @argument
 * @return
 */
void USART_POLL_ReceiveString		(u8 counter ,u8 *data)
{
	u8 i = 0 ;
	for (i = 0 ; i<counter ; i++)
	{
		 USART_POLL_ReceiveData(data[i]) ;
	}
}

// ********************************* Interrupt *************************************
/***
 * @name				USART_INT_SendData
 * @brief				This Function receive data from USART
 * @argument
 * @return
 */
void USART_INT_SendData				(const u8 data)
{

}

/***
 * @name				USART_INT_SendString
 * @brief				This Function receive data from USART
 * @argument
 * @return
 */
void USART_INT_SendString			(const u8* data)
{

}

/***
 * @name				USART_INT_ReceiveData
 * @brief				This Function receive data from USART
 * @argument
 * @return
 */
void USART_INT_ReceiveData			(u8 *data)
{

}
