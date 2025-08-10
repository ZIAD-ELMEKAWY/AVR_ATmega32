/*
 * @name 	{file_name}
 * @date  	Created on: ??þ/??þ/????
 * @author  hp
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"

#define EEPROM_FIXED_ADDRESS		0b01010000


void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
