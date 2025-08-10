/*
 * @name 	{file_name}
 * @date  	Created on: ??þ/??þ/????
 * @author  hp
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define SPDR          			*((volatile u8*)0x2F)

#define SPSR         			*((volatile u8*)0x2E)
#define SPSR_SPIF			7
#define SPSR_WCOL		6
#define SPSR_SPI2X		0

#define SPCR          		*((volatile u8*)0x2D)
#define SPCR_SPIE		7
#define SPCR_SPE		6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL		3
#define SPCR_CPHA		2
#define SPCR_SPR1		1
#define SPCR_SPR0		0


/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif /* SPI_SPI_PRIVATE_H_ */
