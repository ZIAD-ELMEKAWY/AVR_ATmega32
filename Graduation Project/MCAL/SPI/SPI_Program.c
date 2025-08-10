/*
 * @name 	{file_name}
 * @date  	Created on: ??þ/??þ/????
 * @author  hp
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
void SPI_Init	(u8 SPI_Mode)
{
	if (SPI_Mode  == SPI_MASTER_MODE)
	{
		// Set in master mode
		SET_BIT(SPCR , SPCR_MSTR);
		// Clock parity ==> Rising
		CLEAR_BIT(SPCR , SPCR_CPOL);
		// Clock phase ==> sample
		CLEAR_BIT(SPCR , SPCR_CPHA);
		// Set Clock Pre-scaler -->
		SET_BIT(SPCR , SPCR_SPR0);
		SET_BIT(SPCR , SPCR_SPR1);
		SET_BIT(SPSR , SPSR_SPI2X);
		// SPI Enable
		SET_BIT(SPCR , SPCR_SPE);
	}
	else if (SPI_Mode  == SPI_SLAVE_MODE)
	{
		// Set in Slave mode
		CLEAR_BIT(SPCR , SPCR_MSTR);
		// SPI Enable
		SET_BIT(SPCR , SPCR_SPE);
	}
	else { /* Nothing */ }

}


u8 SPI_DataSendReceive (u8 data)
{
	SPDR = data ;
	while(GET_BIT(SPSR , SPSR_SPIF) == 0 );
	return SPDR ;

}
