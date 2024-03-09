/*
 * Seven_Seg_Using_GPIO.c
 *
 * Created: 05/03/2024 23:05:51
 * Author : ziad
 */ 

/************************************************************************/
/************************************************************************/
#include "Application.h"

int main(void)
{
	SW_type SW1 = {DIO_PORTB , DIO_PIN0 , SW_EXT_PULL_UP};
	SSD_Type SSD1 = {SSD_COMMON_CATHODE , SSD_PORTC , SSD_PORTC , SSD_PIN7};
	SSD_Type SSD2 = {SSD_COMMON_CATHODE , SSD_PORTD , SSD_PORTD , SSD_PIN7};
	SSD_voidInitialDataPort(SSD1);
	SSD_voidInitialDataPort(SSD2);
	SSD_voidEnable(SSD1);
	SW_voidInit(SW1);
	u8 I=0 ;
	u8 J=0 ;
	while (1) 
    {
		for (I=0 ; I<=9 ; I++)
		{
			SSD_Write(SSD_PORTC , I);
			for (J=0 ; J<=9 ; J++)
			{
				SSD_Write(SSD_PORTD , J);
				_delay_ms(100);
			}
		}
    }
}

