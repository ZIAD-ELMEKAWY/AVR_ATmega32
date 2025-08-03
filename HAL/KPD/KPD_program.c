/*
 * @name 	KPD_Program.c
 * @date  	Created on: 21/7/2025
 * @author  Ziad Elmakawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include  "KPD_Interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<< Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
u8 KPD_u8Buttons[4][4]= {	{ '7'   , '8'   ,  '9'  , '/'},	// Row 1
											{ '4'   , '5'   ,  '6'  , '*'},	// Row 2
											{ '1'   , '2'   ,  '3'  , '-'},	// Row 3
											{ '#'    , '0'   ,  '='  , '+'}	// Row 4
};
/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				KPD_VoidInit
 * @brief				Initializes the keypad by setting the direction and initial value for its row and column pins.
 * @argument			void
 * @return				void
 */
void KPD_VoidInit (void)
{
	// Coll Output
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL1 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL2 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL3 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL4 , DIO_PIN_OUTPUT);
	// Col Pull up
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL1 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL2 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL3 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL4 , PIN_HIGH);
	// Row input
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW1 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW2 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW3 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW4 , DIO_PIN_INPUT);
	// Row Pull up
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW1 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW2 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW3 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW4 , PIN_HIGH);
}

/***
 * @name				KPD_u8GetPressed
 * @brief				Scans the keypad to detect which button is pressed and returns its corresponding character.
 * @argument			void
 * @return				u8 representing the character of the pressed button, or NOT_PRESSED if no button is pressed.
 */
u8	 KPD_u8GetPressed	(void)
{
	u8 LOC_u8ReturnData = NOT_PRESSED ;
	u8 LOC_u8GetPressed ;
	u8 LOC_u8Row = 0 ;
	u8 LOC_u8Col = 0 ;
	for (LOC_u8Col = (0+KPD_COL_INIT) ; LOC_u8Col < (KPD_COL_END+1) ; LOC_u8Col++)
	{
		DIO_Std_SetPinValue(KPD_PORT , LOC_u8Col , PIN_LOW);
		for (LOC_u8Row = (0+KPD_ROW_INIT) ; LOC_u8Row < (KPD_ROW_END+1) ; LOC_u8Row++)
		{
			LOC_u8GetPressed = DIO_Std_GetPinValue(KPD_PORT , LOC_u8Row );
			if (LOC_u8GetPressed == 0)
			{
				_delay_ms(10);   // For bouncing
				LOC_u8GetPressed = DIO_Std_GetPinValue(KPD_PORT , LOC_u8Row );  //to make sure the button is pressed only
				if (LOC_u8GetPressed == 0)
				{
					LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT] ;
				}
				LOC_u8GetPressed = DIO_Std_GetPinValue(KPD_PORT , LOC_u8Row );
				/* stay here if the button is pressed */
				while(PIN_LOW == LOC_u8GetPressed)
				{
					LOC_u8GetPressed = DIO_Std_GetPinValue(KPD_PORT , LOC_u8Row );
				}
				break;
			}
		}
		DIO_Std_SetPinValue(KPD_PORT , LOC_u8Col , PIN_HIGH);
	}
	return LOC_u8ReturnData ;
}


/***
 * @name				KPD_u16KPDNum
 * @brief				Accumulates pressed numeric keys from the keypad into a multi-digit number.
 * @argument			void
 * @return				u16 representing the accumulated number from pressed numeric keys.
 */
u16  KPD_u16KPDNum		(void)
{
		static u16 Num = 0 ;
		if (KPD_u8GetPressed() < 10) // Assuming KPD_u8GetPressed returns the numeric value directly for digits
		{
			Num *= 10 ;
			Num += KPD_u8GetPressed();
		}
		return Num ;
}


/***
 * @name				KPD_u8GetNumPressed
 * @brief				(Potentially an alternative or incomplete function) Attempts to get a pressed numeric key.
 * @argument			void
 * @return				u8 representing the numeric value of the pressed key, or 0 if no numeric key is pressed or an error occurs.
 */
u8	 KPD_u8GetNumPressed	(void)
{
	u8 Loc_Ret = 0;
	u8 Port = KPD_PORT ;
	Port = 0xF1 ;
	_delay_ms(1);
	if ((PIN0 & 0b00010000)) { Loc_Ret=1; }
	if ((PIN0 & 0b00100000)) { Loc_Ret=2; }
	if ((PIN0 & 0b01000000)) { Loc_Ret=3; }

	Port = 0xF2 ;
	_delay_ms(1);
	if ((PIN0 & 0b00010000)) { Loc_Ret=4; }
	if ((PIN0 & 0b00100000)) { Loc_Ret=5; }
	if ((PIN0 & 0b01000000)) { Loc_Ret=6; }

	Port = 0xF4 ;
	_delay_ms(1);
	if ((PIN0 & 0b00010000)) { Loc_Ret=7; }
	if ((PIN0 & 0b00100000)) { Loc_Ret=8; }
	if ((PIN0 & 0b01000000)) { Loc_Ret=9; }

	Port = 0xF8 ;
	_delay_ms(1);
	if ((PIN0 & 0b00100000)) { Loc_Ret=0; }
	return Loc_Ret ;
}
