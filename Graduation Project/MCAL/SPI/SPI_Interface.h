/*
 * @name 	{file_name}
 * @date  	Created on: ??þ/??þ/????
 * @author  hp
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "SPI_Private.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define SPI_MASTER_MODE		0
#define SPI_SLAVE_MODE			1

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void SPI_Init	(u8 SPI_Mode);
u8 SPI_DataSendReceive (u8 data);

#endif /* SPI_SPI_INTERFACE_H_ */
