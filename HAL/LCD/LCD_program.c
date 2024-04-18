/*
 * LCD_program.c
 * Layer   : HAL
 * SWC	   : LCD
 * Author  : Ziad
 * Created: 14/03/2024 12:38:57
 */ 
/************************************************************************/
/* we write this driver by using #if #endif to consume less storage in memory */
/************************************************************************/
/*********** Includes Section *******************/
#include "LCD_interface.h"
/*********** Global variable Section *******************/
// ÒíÇÏ ÍÓä
u8 CLCD_u8ExtraChar_1[] = {
	0x00,0x00,0x15,0x11,0x11,0x1F,0x00,0x00,  //Char8 ÍÑÝ Çáäæä
	0x00,0x00,0x0E,0x0E,0x1F,0x00,0x00,0x00,  //Char7 ÍÑÝ ÇáÓíä
	0x00,0x00,0x07,0x01,0x1F,0x00,0x00,0x00,  //Char6  ÍÑÝ ÇáÍÇÁ
	0x00,0x01,0x01,0x01,0x0F,0x00,0x00,0x00,  //Char5 ÍÑÝ ÇáÏÇá
	0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,  //Char4  ÍÑÝ ÇáÇáÝ
	0x00,0x00,0x01,0x01,0x1F,0x05,0x00,0x00,  //Char3 ÍÑÝ ÇáíÇÁ
	0x00,0x01,0x00,0x01,0x02,0x04,0x18,0x00   //Char2 ÍÑÝ ÇáÒíä

};
/*********** Function Definition Section *******************/

void CLCD_VoidInit					(void			  )
{
	/*********************  8 BIT MODE  ***************************************/
	#if CLCD_MODE == 8
	_delay_ms(50);
	// All pins as output pins
	DIO_enum_SetPortDirection(CLCD_DATA_PORT    , DIO_PORT_OUTPUT);
	DIO_enum_SetPinDirection (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT);
	DIO_enum_SetPinDirection (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT);
	
	/* Return first cursor to the first position on the first line */
	CLCD_VoidSendCommand(lcd_Home);
	_delay_ms(1);
	/* Function Set command : 2 lines , 5*8 Font size */
	CLCD_VoidSendCommand(EIGHT_BITS);
	_delay_ms(1);
	/* Display & cursor (ON/OFF) Control */
	CLCD_VoidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1); 	
	/* Display clear */
	CLCD_voidClearScreen();
	/* Entry Mode Set */
	CLCD_VoidSendCommand(lcd_EntryMode);
	_delay_ms(1);
	/*********************  4 BIT MODE  ***************************************/
	#elif	CLCD_MODE==4
	
	#endif
	
}
/************************************************************************/
/* CLCD_VoidSendData this function send a character to LCD  */
/************************************************************************/
void CLCD_VoidSendData				(u16 Copy_u8Data	  )
{
	/*********************  8 BIT MODE  ***************************************/
	#if CLCD_MODE==8             // 8 bit = 8 pins of LCD
	DIO_enum_SetPortVlaue	(CLCD_DATA_PORT , Copy_u8Data);
	DIO_enum_SetPinVlaue	(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH);  // Send Data -> RS=1
	DIO_enum_SetPinVlaue	(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();
	/*********************  4 BIT MODE  ***************************************/
	#elif	CLCD_MODE==4		// 4 bit = 4 pins of LCD
	

	#endif
}

void CLCD_VoidSendCommand			(u8 Copy_u8Command)
{
	/*********************  8 BIT MODE  ***************************************/
	#if CLCD_MODE==8
	DIO_enum_SetPortVlaue	(CLCD_DATA_PORT , Copy_u8Command);
	DIO_enum_SetPinVlaue	(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW);  // Send Command -> RS=0
	DIO_enum_SetPinVlaue	(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();
	/*********************  4 BIT MODE  ***************************************/
	#elif	CLCD_MODE==4
	

	#endif
}

static void CLCD_voidSendFallingEdge(void		  )
{
	DIO_enum_SetPinVlaue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enum_SetPinVlaue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW);
	_delay_ms(1);
}

void CLCD_voidClearScreen			(void			  )
{
	CLCD_VoidSendCommand(lcd_Clear);
	_delay_ms(10);    /* wait more than 1.53 ms */
}

void CLCD_VoidSendString		(const u8 *Copy_u8ptrString	)
{
	u8 LOC_Iterator = 0 ;
	while(Copy_u8ptrString[LOC_Iterator] != '\0')
	{
		CLCD_VoidSendData(Copy_u8ptrString[LOC_Iterator]);
		LOC_Iterator++;
	}
}

void CLCD_VoidSetPosition		(u8 Copy_u8Row , u8 Copy_u8Column)
{
	u8 LOC_u8Data ;
	if ((Copy_u8Row<1) || (Copy_u8Row>2) || (Copy_u8Column<1) || (Copy_u8Column>16))
	{
		LOC_u8Data = CLCD_SETCURSOR ;   // first location 
	}
	else if (Copy_u8Row == CLCD_ROW_1)
	{
		LOC_u8Data = ((CLCD_SETCURSOR) + (Copy_u8Column - 1) );  // ROW -> 0x80 + (col-1)
	}
	else if (Copy_u8Row == CLCD_ROW_2)
	{
		LOC_u8Data = ((CLCD_SETCURSOR) + 64 +(Copy_u8Column - 1) );   // 64 for second Row
	}
	CLCD_VoidSendCommand (LOC_u8Data);
	_delay_ms(1);
}

void CLCD_VoidSendExtraChar		(u8 Copy_u8ROW , u8 Copy_u8Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	CLCD_VoidSendCommand(lcd_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < (sizeof(CLCD_u8ExtraChar_1) / sizeof(CLCD_u8ExtraChar_1[0])) ; LOC_Iterator++)
	{
		CLCD_VoidSendData(CLCD_u8ExtraChar_1[LOC_Iterator]);
	}
	// Back AC to DDRAM
	CLCD_VoidSetPosition(Copy_u8ROW , Copy_u8Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 8 ; LOC_Iterator++)
	{
		CLCD_VoidSendData(LOC_Iterator);
	}
}