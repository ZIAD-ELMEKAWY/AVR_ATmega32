/*
 * KPD_program.c
 *
 * Created: 18/03/2024 02:25:47
 *  Author: hp
 */ 

/*********** Includes Section *******************/
#include "KPD_interface.h"
/*********** Global variable Section *******************/
u8 KPD_u8Buttons[4][4]= {	{ '7'   , '8'   ,  '9'  , '/'},	// Row 1
							{ '4'   , '5'   ,  '6'  , '*'},	// Row 2
							{ '1'   , '2'   ,  '3'  , '-'},	// Row 3
							{ '?'   , '0'   ,  '='  , '+'}	};	// Row 4
/*********** Function Definition Section *******************/
void KPD_voidInit	(void )
{
	DIO_enumConnectPullup	(KPD_PORT , KPD_ROW1 , DIO_PIN_HIGH);
	DIO_enumConnectPullup	(KPD_PORT , KPD_ROW2 , DIO_PIN_HIGH);
	DIO_enumConnectPullup	(KPD_PORT , KPD_ROW3 , DIO_PIN_HIGH);
	DIO_enumConnectPullup	(KPD_PORT , KPD_ROW4 , DIO_PIN_HIGH);
	
	DIO_enum_SetPinDirection(KPD_PORT , KPD_COL1 , DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(KPD_PORT , KPD_COL2 , DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(KPD_PORT , KPD_COL3 , DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection(KPD_PORT , KPD_COL4 , DIO_PIN_OUTPUT);
	DIO_enum_SetPinVlaue	(KPD_PORT , KPD_COL1 , DIO_PIN_HIGH);
	DIO_enum_SetPinVlaue	(KPD_PORT , KPD_COL2 , DIO_PIN_HIGH);
	DIO_enum_SetPinVlaue	(KPD_PORT , KPD_COL3 , DIO_PIN_HIGH);
	DIO_enum_SetPinVlaue	(KPD_PORT , KPD_COL4 , DIO_PIN_HIGH);
}

u8	 KPD_u8GetPressed	(void)
{
	u8 LOC_u8ReturnData = NOT_PRESSED ;
	u8 LOC_u8GetPressed ;
	u8 LOC_u8Row = 0 ;
	u8 LOC_u8Col = 0 ;
	for (LOC_u8Col = (0+KPD_COL_INIT) ; LOC_u8Col < (KPD_COL_END+1) ; LOC_u8Col++)
	{
		DIO_enum_SetPinVlaue(KPD_PORT , LOC_u8Col , DIO_PIN_LOW);
		for (LOC_u8Row = (0+KPD_ROW_INIT) ; LOC_u8Row < (KPD_ROW_END+1) ; LOC_u8Row++)
		{
			DIO_enum_GetPinValue(KPD_PORT , LOC_u8Row , &LOC_u8GetPressed);
			if (LOC_u8GetPressed == 0)
			{
				_delay_ms(10);   // For bouncing
				DIO_enum_GetPinValue(KPD_PORT , LOC_u8Row , &LOC_u8GetPressed);  //to make sure the button is pressed only
				if (LOC_u8GetPressed == 0)
				{
					LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT] ;
				}
				DIO_enum_GetPinValue(KPD_PORT , LOC_u8Row , &LOC_u8GetPressed);
				/* stay here if the button is pressed */
				while(DIO_PIN_LOW == LOC_u8GetPressed)
				{
					DIO_enum_GetPinValue(KPD_PORT , LOC_u8Row , &LOC_u8GetPressed);
				}
				break;
			}
		}
		DIO_enum_SetPinVlaue(KPD_PORT , LOC_u8Col , DIO_PIN_HIGH);
	}
	return LOC_u8ReturnData ;
}

u16  KPD_u16KPDNum		(void)
{
		static u16 Num = 0 ;
		if (KPD_u8GetPressed() < 10)
		{
			Num *= 10 ;
			Num += KPD_u8GetPressed();
		}
		return Num ;
}

u8	 KPD_u8GetNumPressed	(void)
{
	u8 Loc_Ret = 0; 
	u8 Port = KPD_PORT ;
	Port = 0xF1 ;
	_delay_ms(1);
	if ((DIO_PIN0 & 0b00010000)) { Loc_Ret=1; }
	if ((DIO_PIN0 & 0b00100000)) { Loc_Ret=2; }
	if ((DIO_PIN0 & 0b01000000)) { Loc_Ret=3; }
		
	Port = 0xF2 ;
	_delay_ms(1);
	if ((DIO_PIN0 & 0b00010000)) { Loc_Ret=4; }
	if ((DIO_PIN0 & 0b00100000)) { Loc_Ret=5; }
	if ((DIO_PIN0 & 0b01000000)) { Loc_Ret=6; }
		
	Port = 0xF4 ;
	_delay_ms(1);
	if ((DIO_PIN0 & 0b00010000)) { Loc_Ret=7; }
	if ((DIO_PIN0 & 0b00100000)) { Loc_Ret=8; }
	if ((DIO_PIN0 & 0b01000000)) { Loc_Ret=9; }
		
	Port = 0xF8 ;
	_delay_ms(1);
	if ((DIO_PIN0 & 0b00100000)) { Loc_Ret=0; }
	return Loc_Ret ;
}