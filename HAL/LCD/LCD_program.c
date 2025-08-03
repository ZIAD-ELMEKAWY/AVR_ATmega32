/*
 * @name 	LCD_Program.c
 * @date  	Created on: 20/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "LCD_Interface.h"


/* <<<<<<<<<<<<<<<<<<<<<<< Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
// “Ì«œ Õ”‰
u8 LCD_u8ExtraChar_1[] = {
	0x00,0x00,0x15,0x11,0x11,0x1F,0x00,0x00,  //Char8 Õ—› «·‰Ê‰
	0x00,0x00,0x0E,0x0E,0x1F,0x00,0x00,0x00,  //Char7 Õ—› «·”Ì‰
	0x00,0x00,0x07,0x01,0x1F,0x00,0x00,0x00,  //Char6  Õ—› «·Õ«¡
	0x00,0x01,0x01,0x01,0x0F,0x00,0x00,0x00,  //Char5 Õ—› «·œ«·
	0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,  //Char4  Õ—› «·«·›
	0x00,0x00,0x01,0x01,0x1F,0x05,0x00,0x00,  //Char3 Õ—› «·Ì«¡
	0x00,0x01,0x00,0x01,0x02,0x04,0x18,0x00   //Char2 Õ—› «·“Ì‰

};
 u8 UpperCase[] = {
		 0b11111, 0b00011, 0b00010, 0b00010, 0b00100 , 0b00100, 0b01000, 0b11000, 0b10000, 0b11111
 };

 u8 LowerCase[] = {
		 0b00000,
		 0b00000,
		 0b00000,
		 0b01110,
		 0b00010,
		 0b00100,
		 0b01110,
		 0b00000,
		 0b00000
 };

/* <<<<<<<<<<<<<<<<< User Interface Definition >>>>>>>>>>>>>>> */
/***
 * @name				LCD_VoidInit
 * @brief				Initializes the LCD module for either 4-bit or 8-bit mode operation.
 * @argument			void
 * @return				void
 */
void LCD_VoidInit						(void	 )
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#if LCD_MODE == 4
	_delay_ms(50);
	DIO_Std_SetPinDirection (LCD_DATA_PORT , PIN4 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_DATA_PORT , PIN5 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_DATA_PORT , PIN6 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_DATA_PORT , PIN7 , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_CONTROL_PORT , LCD_RS , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_CONTROL_PORT , LCD_EN , DIO_PIN_OUTPUT);

	/* Return first cursor to the first position on the first line */
	LCD_VoidSendCommand(LCD_Home);
	_delay_ms(30);
	// 4 Bit Mode
	LCD_VoidSendCommand(0x28);
	_delay_ms(2);
	/* Display & cursor (ON/OFF) Control */
	LCD_VoidSendCommand(LCD_DisplayOn_CursorOff);
	_delay_ms(2);
	/* Display clear */
	LCD_voidClearScreen();
	/* Entry Mode Set */
	LCD_VoidSendCommand(LCD_EntryMode);
	_delay_ms(2);

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#elif LCD_MODE == 8
	_delay_ms(50);
	// All pins as output pins
	DIO_Std_SetPortDirection(LCD_DATA_PORT    , DIO_PORT_OUTPUT);
	DIO_Std_SetPinDirection (LCD_CONTROL_PORT , LCD_RS , DIO_PIN_OUTPUT);
	DIO_Std_SetPinDirection (LCD_CONTROL_PORT , LCD_EN , DIO_PIN_OUTPUT);

	/* Return first cursor to the first position on the first line */
	LCD_VoidSendCommand(LCD_Home);
	_delay_ms(2);
	/* Function Set command : 2 lines , 5*8 Font size */
	LCD_VoidSendCommand(0x38);
	_delay_ms(2);
	/* Display & cursor (ON/OFF) Control */
	LCD_VoidSendCommand(LCD_DisplayOn_CursorOff);
	_delay_ms(2);
	/* Display clear */
	LCD_voidClearScreen();
	/* Entry Mode Set */
	LCD_VoidSendCommand(LCD_EntryMode);
	_delay_ms(2);
#endif
}


/***
 * @name				LCD_VoidSendCommand
 * @brief				Sends a command byte to the LCD module.
 * @argument command	The 8-bit command to be sent to the LCD.
 * @return				void
 */
void LCD_VoidSendCommand(u8 command)
{
#if LCD_MODE == 4
	DIO_Std_SetPinValue(LCD_CONTROL_PORT , LCD_RS , PIN_LOW);
	// Send the most 4 bits of data to high nibbles
	DIO_Std_WriteHighNibbles(LCD_DATA_PORT , (command>>4));
	LCD_voidSendFallingEdge();
	// Send the least 4 bits of data to high nibbles
	DIO_Std_WriteHighNibbles(LCD_DATA_PORT , command);
	LCD_voidSendFallingEdge();
#elif LCD_MODE == 8
	DIO_Std_SetPortValue(LCD_DATA_PORT , command);
	DIO_Std_SetPinValue	(LCD_CONTROL_PORT , LCD_RS , PIN_LOW);  // Send Command -> RS=0
	LCD_voidSendFallingEdge();
#endif
	_delay_ms(1);
}

/***
 * @name				LCD_VoidSendData
 * @brief				Sends a data byte (character) to the LCD module to be displayed.
 * @argument Data		The 8-bit data (ASCII character) to be displayed on the LCD.
 * @return				void
 */
void LCD_VoidSendData			(u8 Data )
{
#if LCD_MODE == 4
	DIO_Std_SetPinValue(LCD_CONTROL_PORT , LCD_RS , PIN_HIGH);
	LCD_voidSendFallingEdge();
	// Send the most 4 bits of data to high nibbles
	DIO_Std_WriteHighNibbles(LCD_DATA_PORT , (Data>>4));
	LCD_voidSendFallingEdge();
	// Send the least 4 bits of data to high nibbles
	DIO_Std_WriteHighNibbles(LCD_DATA_PORT , Data);
	LCD_voidSendFallingEdge();
#elif LCD_MODE == 8
	DIO_Std_SetPortValue	(LCD_DATA_PORT , Data);
	DIO_Std_SetPinValue	(LCD_CONTROL_PORT , LCD_RS , PIN_HIGH);  // Send Data -> RS=1
	LCD_voidSendFallingEdge();
#endif
	_delay_ms(1);
}

/***
 * @name				LCD_voidSendFallingEdge
 * @brief				Generates a falling edge on the Enable (EN) pin of the LCD, which latches the data/command.
 * @argument			void
 * @return				void
 */
static void LCD_voidSendFallingEdge(void		  )
{
	DIO_Std_SetPinValue(LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);
	_delay_ms(1);
	DIO_Std_SetPinValue(LCD_CONTROL_PORT , LCD_EN , PIN_LOW);
}

/***
 * @name				LCD_voidClearScreen
 * @brief				Clears the entire LCD display and returns the cursor to the home position.
 * @argument			void
 * @return				void
 */
void LCD_voidClearScreen			(void			  )
{
	LCD_VoidSendCommand(LCD_Clear);
	_delay_ms(10);    /* wait more than 1.53 ms */
}

/***
 * @name				LCD_VoidSendString
 * @brief				Sends a null-terminated string to the LCD for display.
 * @argument ptrString	A pointer to the constant character array (string) to be displayed.
 * @return				void
 */
void LCD_VoidSendString		(const u8 *ptrString	)
{
	u8 LOC_Iterator = 0 ;
	while(ptrString[LOC_Iterator] != '\0')
	{
		LCD_VoidSendData(ptrString[LOC_Iterator]);
		LOC_Iterator++;
	}
}

/***
 * @name				LCD_VoidSetPosition
 * @brief				Sets the cursor position on the LCD display to a specified row and column.
 * @argument Row		The desired row number (typically 1 or 2).
 * @argument Column	The desired column number (typically 1 to 16).
 * @return				void
 */
void LCD_VoidSetPosition		(u8 Row , u8 Column)
{
	u8 LOC_u8Data ;
	if ((Row<1) || (Row>2) || (Column<1) || (Column>16))
	{
		LOC_u8Data = LCD_SETCURSOR ;   // first location
	}
	else if (Row == LCD_ROW_1)
	{
		LOC_u8Data = ((LCD_SETCURSOR) + (Column - 1) );  // ROW -> 0x80 + (col-1)
	}
	else if (Row == LCD_ROW_2)
	{
		LOC_u8Data = ((LCD_SETCURSOR) + 64 +(Column - 1) );   // 64 for second Row
	}
	LCD_VoidSendCommand (LOC_u8Data);
	_delay_ms(1);
}

/***
 * @name				LCD_VoidSendExtraChar
 * @brief				Sends custom characters defined in `LCD_u8ExtraChar_1` to the LCD's CGRAM and then displays them at a specified position.
 * @argument ROW		The row where the custom characters should be displayed.
 * @argument Column	The starting column where the custom characters should be displayed.
 * @return				void
 */
void LCD_VoidSendExtraChar		(u8 ROW , u8 Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	LCD_VoidSendCommand(LCD_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < (sizeof(LCD_u8ExtraChar_1) / sizeof(LCD_u8ExtraChar_1[0])) ; LOC_Iterator++)
	{
		LCD_VoidSendData(LCD_u8ExtraChar_1[LOC_Iterator]);
	}
	// Back AC to DDRAM
	LCD_VoidSetPosition(ROW , Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 8 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LOC_Iterator);
	}
}

/***
 * @name				LCD_VoidSendUpperCaeChar
 * @brief				Sends custom uppercase characters (defined in `UpperCase`) to the LCD's CGRAM and then displays them at a specified position.
 * @argument ROW		The row where the custom character should be displayed.
 * @argument Column	The starting column where the custom character should be displayed.
 * @return				void
 */
void LCD_VoidSendUpperCaeChar		(u8 ROW , u8 Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	LCD_VoidSendCommand(LCD_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(UpperCase[LOC_Iterator]);
	}
	// Back AC to DDRAM
	LCD_VoidSetPosition(ROW , Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LOC_Iterator);
	}
}

/***
 * @name				LCD_VoidSendLowerCaeChar
 * @brief				Sends custom lowercase characters (defined in `LowerCase`) to the LCD's CGRAM and then displays them at a specified position.
 * @argument ROW		The row where the custom character should be displayed.
 * @argument Column	The starting column where the custom character should be displayed.
 * @return				void
 */
void LCD_VoidSendLowerCaeChar		(u8 ROW , u8 Column)
{
	u8 LOC_Iterator = 0 ;
	// Go to CGRAM
	LCD_VoidSendCommand(LCD_CGRAM);       //Make AC refers to the first address at CGRAM
	// Draw character in CGRAM
	for (LOC_Iterator = 0 ; LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LowerCase[LOC_Iterator]);
	}
	// Back AC to DDRAM
	LCD_VoidSetPosition(ROW , Column);
	// Send character address
	for (LOC_Iterator = 0 ;  LOC_Iterator < 1 ; LOC_Iterator++)
	{
		LCD_VoidSendData(LOC_Iterator);
	}
}

/***
 * @name				LCD_VoidSendNumber
 * @brief				Displays an unsigned 32-bit integer number on the LCD.
 * @argument Data		The unsigned 32-bit integer to be displayed.
 * @return				void
 */
void LCD_VoidSendNumber		(u32 Data )
{
	u32 LOC_f64Reversed = 1 ;

	if( Data == 0 )
	{
		LCD_VoidSendData('0');
	}
	else
	{
		while( Data != 0 )
		{
			LOC_f64Reversed = ( LOC_f64Reversed * 10 ) + ( Data % 10 );
			Data /= 10 ;
		}
		while( LOC_f64Reversed != 1 )
		{
			LCD_VoidSendData( ( LOC_f64Reversed % 10 ) + 48 );
			LOC_f64Reversed /= 10 ;
		}
	}
}

/***
 * @name				LCD_voidSendSignedIntegerNumber
 * @brief				Displays a signed floating-point number as an integer on the LCD.
 * @argument number	The floating-point number to be displayed as a signed integer.
 * @return				void
 */
void LCD_voidSendSignedIntegerNumber(f64 number)
{
	f64 rest_number = 0;

	if(number < 0)
	{
		rest_number = number * (-1);
	}
	else if(number == 0)
	{
		LCD_VoidSendData('0');
		return;
	}
	else
	{
		rest_number = number;
	}


	u8 *ptr = (u8 *)malloc(20*sizeof(u8)); // This is not necessary, or I do not know how to use it optimally.

	//u8 ptr[20];

	u8 modelus_num = 0;

	u8 index = 0;

	while(rest_number != 0)
	{
		modelus_num = (u32)rest_number % 10;

		ptr[index] = modelus_num;
		index++;

		rest_number /= 10;
	}

	if(number < 0)
	{
		LCD_VoidSendData('-');
	}

	for(s8 i = index - 1 ; i >= 0 ; i--)
	{
		LCD_VoidSendData(ptr[i] + '0');
	}

	free(ptr);
}

/***
 * @name				LCD_voidSendDoubleNumber
 * @brief				Displays a double-precision floating-point number on the LCD with a specified number of digits after the decimal point.
 * @argument number	The floating-point number to be displayed.
 * @argument No_DigitsAfterDecimal The number of digits to display after the decimal point.
 * @return				void
 */
void LCD_voidSendDoubleNumber(f64 number , u8 No_DigitsAfterDecimal)
{
	// Dividing a decimal number into an integer and a decimal part
	f64 int_part =(f64) number;

	// Print integer part
	LCD_voidSendSignedIntegerNumber(int_part);

	if(number < 0)
	{
		number *= -1;
	}

	f64 decimal_part = number - int_part;


	// Print decimal point
	LCD_VoidSendData('.');

	if(No_DigitsAfterDecimal == 0)
	{
		LCD_VoidSendData('0');
	}
	else
	{
		for(u8 i = 0 ; i < No_DigitsAfterDecimal ; i++)
		{
			decimal_part *= 10;
		}

		//decimal_part *= pow(10 , No_DigitsAfterDecimal);   // Error
		//decimal_part *= (10 ^ No_DigitsAfterDecimal);      // Logical Error

		f64 decimal_part_cast_to_int = (f64)decimal_part;

		LCD_voidSendSignedIntegerNumber(decimal_part_cast_to_int);
	}


}
