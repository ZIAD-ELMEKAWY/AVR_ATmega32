/*
 * @name 	TWI_interface.h
 * @date  	Created on: 3/8/2025
 * @author  Ziad ELmekawy
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_
/* <<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "TWI_config.h"
#include "TWI_private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"

/* <<<<<<<<<<<<<<<<<<<<<<<< Macro declaration >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* Error Status fot TWI */
typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,



}TWI_ErrStatus;

/*Set master address to 0 if master will not be addressed*/
void TWI_voidInitMaster(u8 Copy_u8Address);

void TWI_voidInitSlave(u8 Copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8* Copy_pu8DataByte);


void TWI_SendStopCondition(void);

#endif 				/*MCAL_TWI_TWI_INTERFACE_H_*/
