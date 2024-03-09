/*
 * Seven_Seg_Using_GPIO.c
 *
 * Created: 05/03/2024 23:05:51
 * Author : ziad
 */ 

/************************************************************************/
/* Three LEDs are connected to PORTX (X : A , B , C , D)   */
/* First  LED toggle after one second  */
/* Second LED toggle after two second  */
/* Third LED toggle after Three second */
/************************************************************************/
#include "Application.h"

int main(void)
{
	LED_Type LED1 = {LED_PORTA , LED_PIN0 , ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTA , LED_PIN1 , ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTA , LED_PIN2 , ACTIVE_HIGH};
	
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);
	
	s8 Count = 1;
	while (1) 
    {
		if ((Count % 1) == 0)
		{
			LED_voidToggle(LED1);
		}
		if ((Count % 2) == 0)
		{
			LED_voidToggle(LED2);
		}
		if ((Count % 3) == 0)
		{
			LED_voidToggle(LED3);
		}
		Count++ ;
		_delay_ms(500);
    }
}
