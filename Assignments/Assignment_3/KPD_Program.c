/*
 * @name 	KPD_Program.c
 * @date  	Created on: 21/7/2025
 * @author  Ziad Elmakawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include  "KPD_Interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<< Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
u8 KPD_u8Buttons[3][3]= {	{ '7'   , '8'   ,  '9'  , '/'},	// Row 1
		{ '4'   , '5'   ,  '6'  , '*'},	// Row 2
		{ '1'   , '2'   ,  '3'  , '-'},	// Row 3
		{ '#'   , '0'   ,  '='  , '+'}	// Row 4
};
/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				KPD_VoidInit
 * @brief
 * @argument
 * @return
 */
void KPD_VoidInit (void)
{
	// Coll Output
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL1 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL2 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_COL3 , DIO_PIN_OUTPUT);
	// Col Pull up
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL1 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL2 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_COL3 , PIN_HIGH);
	// Row input
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW1 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW2 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(KPD_PORT , KPD_ROW3 , DIO_PIN_INPUT);
	// Row Pull up
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW1 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW2 , PIN_HIGH);
	DIO_Std_SetPinValue(KPD_PORT , KPD_ROW3 , PIN_HIGH);
}

/***
 * @name				KPD_u8GetPressed
 * @brief
 * @argument
 * @return
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




