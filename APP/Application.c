/*
 * application.c
 *
 * Created: 18/03/2024 17:46:07
 *  Author: hp
 */ 


/************************** Include Section **********************/
#include "Application.h"

/******************** Global Variable Section ********************/
u8 Str_Error[] = {"Error"};
u8 KPD_OPERA  = 0 ;
u8 count_1  = 0 ;
u8 count_2	= 0 ;
u8 var1		= 0 ;
u8 var2		= 0 ;
f32 res		= 0 ;
	
/********************** Function Definition Section **************/
void APP_voidInit()
{
	CLCD_VoidInit();
	KPD_voidInit();
	EXTI_voidInit();
	u8 Str1[] = "Ziad";
	u8 Str2[] = "Calculator";
	CLCD_VoidSetPosition(1 , 7);
	CLCD_VoidSendString(Str1);
	CLCD_VoidSetPosition(2 , 4);
	CLCD_VoidSendString(Str2);
	_delay_ms(150);
	CLCD_voidClearScreen();
	CLCD_VoidSetPosition(1 , 3);
	CLCD_VoidSendString("Programmable");
	CLCD_VoidSetPosition(2 , 6);
	CLCD_VoidSendString("System");
	_delay_ms(100);
	CLCD_voidClearScreen();
}

u16	 APP_ChartoInt (u8 ch)
{
	u16 x = ch - '0' ;
	return x ;
}

void disp_num(u16 numb)					//displays number on LCD
{
	u8 UnitDigit = 0;					 //It will contain unit digit of numb
	u8 TenthDigit = 0;					//It will contain 10th position digit of numb

	if(numb<0) {
		numb = -1*numb;					// Make number positive
		CLCD_VoidSendData('-');			// Display a negative sign on LCD
	}
	TenthDigit = (numb/10);				// Find out Tenth Digit

	if( TenthDigit != 0)                 // If it is zero, then don’t display
	CLCD_VoidSendData(TenthDigit+0x30);  // Make Char of TenthDigit and then display it on LCD
	UnitDigit = numb - TenthDigit*10;
	CLCD_VoidSendData(UnitDigit+0x30);  // Make Char of UnitDigit and then display it on LCD
}

void LCD_u8WriteNum( f64 real_num )
{
	s64 int_num, int_num_cpy = 1;	// integer part
	u8 ch;
	u8 signFlag = FALSE;
	u64 dec_num;				// decimal part
	u8 dec_places = 3;			// number of decimal places in dec_num
	u8 r = 0;					// rounded place
	u8 count = 0;				// written chars

	signFlag = ( real_num < 0)? TRUE : FALSE;		// detect minus sign
	real_num *= (f64) (signFlag)? -1.0 : 1.0 ;			// absolute value
	int_num = (f64) real_num;						// store integer part
	real_num -= (f64) int_num;							// delete integer part from real_num

	// store decimal part:
	while( dec_places-- > 0 )
	{ real_num *= 10.0 ; }
	dec_num = (u64) real_num;
	real_num -= (s64) real_num;
	real_num *= 10.0;
	r = (u8) real_num;
	dec_num += (r >= 5)? 1 : 0;

	if( signFlag )
	{
		CLCD_VoidSendData( '-' );
		count++;
	}

	if( !int_num )
	{
		CLCD_VoidSendData( '0' );
		count++;
	}
	// storing the integer part reversed:
	while( int_num != 0 )
	{
		int_num_cpy *= 10;
		int_num_cpy += int_num % 10;
		int_num /= 10;
	}
	// displaying the integer part:
	while( int_num_cpy != 1 )
	{
		ch = int_num_cpy % 10 + '0';
		CLCD_VoidSendData( ch );
		count++;
		int_num_cpy /= 10;
	}
	// displaying the decimal part:
	if( dec_num )
	{
		u64 dec_num_cpy = 0;
		while( dec_num != 0 )
		{
			dec_num_cpy *= 10;
			dec_num_cpy += dec_num % 10;
			dec_num /= 10;
		}
		CLCD_VoidSendData( '.' );
		count++;
		while( dec_num_cpy != 0 )
		{
			ch = dec_num_cpy % 10 + '0';
			CLCD_VoidSendData( ch );
			count++;
			dec_num_cpy /= 10;
		}
	}
	//return count;
}

/* <<<<<<<<<<<<<<<< convert unsigned char into int >>>>>>>>>>>>>>>> */
u8 get_num(u8 ch) 
{
	u8 num = 0;
	switch(ch)
	{
		case '0': num = 0; break;
		case '1': num = 1; break;
		case '2': num = 2; break;
		case '3': num = 3; break;
		case '4': num = 4; break;
		case '5': num = 5; break;
		case '6': num = 6; break;
		case '7': num = 7; break;
		case '8': num = 8; break;
		case '9': num = 9; break;
	}
	return num;
}

void APP_voidInitZero (u8 a,u8 b)
{
	a = b = 0 ;
}

/* <<<<<<<<<<<<<<<<<<<<<<< Standard_System >>>>>>>>>>>>>>>>>>>>>>> */
void APP_voidStandSys (u8 APP_pressFunc)
{
	u8 LOC_Press = APP_pressFunc ;
	CLCD_VoidSendData(LOC_Press);		// To display any Pressed
	if ((LOC_Press=='+') || (LOC_Press =='-') ||  (LOC_Press =='/') || (LOC_Press =='*'))
	{
		KPD_OPERA  = LOC_Press;
	}
	else if ((LOC_Press >= '0') && (LOC_Press <= '9'))
	{
		if (var1 == 0 )
		{
			var1 = get_num(LOC_Press);
		}
		else
		{
			var2 = get_num(LOC_Press);
		}
	}
	
	// To display the result on Screen (CLCD) from Keypad
	if (LOC_Press == '=')
	{
		switch (KPD_OPERA)
		{
			// Add Operation
			case '+':
			res = (var1 + var2);
			CLCD_VoidSetPosition(2 , 1);
			LCD_u8WriteNum(res);
			break;
			// Subtract operation
			case '-':
			res = (var1 - var2);
			CLCD_VoidSetPosition(2 , 1);
			LCD_u8WriteNum(res);
			break;
			// Multiply operation
			case '*':
			res = (var1 * var2);
			CLCD_VoidSetPosition(2 , 1);
			disp_num(res);
			break;
			// Division Operation
			case '/':
			if (var2 == 0)
			{
				CLCD_voidClearScreen();
				CLCD_VoidSendString(Str_Error);
				_delay_ms(100);
				CLCD_voidClearScreen();
			}
			else
			{
				res = (var1 / var2);
				CLCD_VoidSetPosition(2 , 1);
				LCD_u8WriteNum(res);
			}
			break;
			default:
			CLCD_voidClearScreen();
			CLCD_VoidSendString(Str_Error);
			_delay_ms(150);
			APP_voidInitZero(var1,var2);
			CLCD_voidClearScreen();
			break;
		}
	}
	// To clear Screen (CLCD) from Keypad
	if (LOC_Press == '?')
	{
		CLCD_voidClearScreen();
		var1 = var2 = 0 ;
	}
}

/* <<<<<<<<<<<<<<<<<<<<<< Scientific_System >>>>>>>>>>>>>>>>>>>>>> */
void APP_voidScienSys (u8 APP_pressFunc , s32 Value)
{
	static u8 LOC_OPERA = 0 ;
	s32 Final_RES = 0 ;
	if ((APP_pressFunc=='C'))
	{
		LOC_OPERA = 'c';
	}
	else if ((APP_pressFunc=='S'))
	{
		LOC_OPERA = 's';
	}
	else if ((APP_pressFunc=='E'))
	{
		LOC_OPERA = 'e';
	}
	else if ((APP_pressFunc=='L'))
	{
		LOC_OPERA = 'l';
	}
	
	if (APP_pressFunc== '=')
	{
		switch(LOC_OPERA)
		{
			case 'c':
			Final_RES = cos(Value);
			break;
			case  's':
			Final_RES = sin(Value);
			break;
			case 'e':
			Final_RES = exp(Value);
			break;
			case 'l':
			Final_RES = log(Value);
			break;
		}
		CLCD_VoidSetPosition(2,1);
		CLCD_VoidSendData(Final_RES);
	}
}
/* <<<<<<<<<<<<<<<<<<<<<< Programmable_System >>>>>>>>>>>>>>>>>>>>>> */
void APP_voidProgSys  (u8 APP_pressFunc)
{	
	static u8 LOC_Opera = 0 ;
	static u8 LOC_Var1  = 0 ;
	static u8 LOC_Var2  = 0 ;
	static u32 res = 0 ;
	if ((APP_pressFunc >= '0') && (APP_pressFunc <= '9'))
	{
		CLCD_VoidSendData(APP_pressFunc);
		if (LOC_Var1 == 0)
		{
			LOC_Var1 = get_num(APP_pressFunc);
		}
		else
		{
			LOC_Var2 = get_num(APP_pressFunc);
		}
	}
	else if (APP_pressFunc=='>')
	{
		LOC_Opera = '>';
	}
	else if (APP_pressFunc=='<')
	{
		LOC_Opera = '<';
	}
	else if (APP_pressFunc=='&')
	{
		LOC_Opera = '&';
	}
	else if (APP_pressFunc=='|')
	{
		LOC_Opera = '|';
	}
	else if (APP_pressFunc=='!')
	{
		LOC_Opera = '!';
	}
	else if (APP_pressFunc=='B')
	{
		LOC_Opera = 'B';
	}
	else if (APP_pressFunc=='H')
	{
		LOC_Opera = 'H';
	}
	else if (APP_pressFunc == '=')
	{
		switch(LOC_Opera)
		{
			case '>':
			res = (LOC_Var1 >> LOC_Var2);
			break;
			case '<':
			res = (LOC_Var1 << LOC_Var2);
			break;
			case '&':
			res = (LOC_Var1 & LOC_Var2);
			break;
			case '|':
			res = (LOC_Var1 | LOC_Var2);
			break;
			case 'B':
			Decimal_to_binary(LOC_Var1);
			break;
			case 'H':
			res = (LOC_Var1 >> LOC_Var2);
			break;
		}
		CLCD_VoidSetPosition(2 , 1 );
		LCD_u8WriteNum(res);
	}
	else if (APP_pressFunc == '?')
	{
		CLCD_voidClearScreen();
		LOC_Var1 = LOC_Var2 = LOC_Opera = 0 ;
	}
}

void Decimal_to_binary (u8 DEC_BIN_Var)
{
	static u8 counter = 0 ;
	u8 res = 0 ;
	CLCD_VoidSetPosition(1,1);
	CLCD_VoidSendString("BIN :");
	do
	{
		CLCD_VoidSetPosition(2,counter);
		res = (DEC_BIN_Var%2) ;
		CLCD_VoidSendData(res);
		DEC_BIN_Var = DEC_BIN_Var/2;
		counter++;
	}while(counter<8);
}

/* <<<<<<<<<<<<<<<<<<<< Infix_To_Postfix_System >>>>>>>>>>>>>>>>>>> */
void APP_voidInfix_To_Postfix_System (u8 APP_pressFunc)
{
	u8 count =0 ;
	u8 countarr =0 ;
	u8 arr[3];
	u8 LOC_Press = APP_pressFunc ;
	//CLCD_VoidSendData(LOC_Press);		// To display any Pressed
	if ((LOC_Press>= '0') && (LOC_Press<= '9'))
	{
		arr[countarr] = LOC_Press ;
		CLCD_VoidSetPosition(2 , 4);
		CLCD_VoidSendData(arr[countarr]);
		countarr++;
	}
	if ((LOC_Press=='+') || (LOC_Press =='-') ||  (LOC_Press =='/') || (LOC_Press =='*'))
	{
		arr[2] = LOC_Press;
		CLCD_VoidSetPosition(1 , 4);
		CLCD_VoidSendData(arr[2]);
	}
	if (LOC_Press == '=')
	{
		CLCD_VoidSetPosition(2 , 0);
		for (count = 0 ;count<= 2 ; count++)
		{
			disp_num(arr[count]);
		}
	}
	if (LOC_Press == '?')
	{
		CLCD_voidClearScreen();
	}
}
