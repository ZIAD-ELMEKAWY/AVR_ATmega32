/*
 * Layer   : MCAL
 * SWC	   : GPIO
 * Author  : Ziad
 * Created: 07/03/2024 22:04:18
 */ 

/*********** Includes Section *******************/
#include "SSD_interface.h"
#include "DIO_interface.h"
/*********** Global variable Section *******************/
static u8 Local_u8SSDCATHODENumbers[10] = SSD_COMM_CATHODE_NUMBER_ARR ;
static u8 Local_u8SSDANODENumbers[10]   = SSD_COMM_ANODE_NUMBER_ARR ;
/*********** Function Definition Section *******************/
void SSD_voidInitialDataPort (SSD_Type Copy_StructConfig) 
{
	DIO_enum_SetPortDirection(Copy_StructConfig.Data_Port , SSD_PORT_OUTPUT);
}
void SSD_voidEnable			 (SSD_Type Copy_StructConfig) 
{
	if (Copy_StructConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enum_SetPinDirection(Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT);
		DIO_enum_SetPinVlaue(Copy_StructConfig.Data_Port , Copy_StructConfig.EnablePin , DIO_PIN_LOW);
	}
	else if (Copy_StructConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enum_SetPinDirection(Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT);
		DIO_enum_SetPinVlaue(Copy_StructConfig.Data_Port , Copy_StructConfig.EnablePin , DIO_PIN_HIGH);
	}
}
void SSD_voidDisable		 (SSD_Type Copy_StructConfig) 
{
	if (Copy_StructConfig.Type == SSD_COMMON_CATHODE)
	{
		DIO_enum_SetPinDirection(Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT);
		DIO_enum_SetPinVlaue(Copy_StructConfig.Data_Port , Copy_StructConfig.EnablePin , DIO_PIN_HIGH);
	}
	else if (Copy_StructConfig.Type == SSD_COMMON_ANODE)
	{
		DIO_enum_SetPinDirection(Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT);
		DIO_enum_SetPinVlaue(Copy_StructConfig.Data_Port , Copy_StructConfig.EnablePin , DIO_PIN_LOW);
	}
}
void SSD_voidSendNumber		 (SSD_Type Copy_StructConfig , u8 Copy_u8Number) 
{
	if (Copy_StructConfig.Type = SSD_COMMON_CATHODE)
	{
		DIO_enum_SetPortVlaue(Copy_StructConfig.Data_Port , Local_u8SSDCATHODENumbers[Copy_u8Number]);
	}
	else if (Copy_StructConfig.Type = SSD_COMMON_ANODE)
	{
		DIO_enum_SetPortVlaue(Copy_StructConfig.Data_Port , ~(Local_u8SSDCATHODENumbers[Copy_u8Number]));
	}
}
void SSD_Write (u8 PortName , u8 Copy_u8Number)
{
	DIO_enum_SetPortVlaue(PortName , Local_u8SSDCATHODENumbers[Copy_u8Number]);
}