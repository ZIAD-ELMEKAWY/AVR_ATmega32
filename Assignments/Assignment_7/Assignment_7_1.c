/*
 * @name 	main.c
 * @date  	Created on: 17/7/2025
 * @author  Ziad Elmekawy
 */


#include <util/delay.h>
#include "HAL/DC_Motor/DC_Motor_interface.h"
#include "Timer0/Timer0_interface.h"
#include "GIE/GIE_interface.h"

#define F_CPU	8000000UL

motor_t motor1 =
{
	.Port = _PORTB_ ,
	.Pin = PIN0
};
motor_t motor2 =
{
	.Port = _PORTB_ ,
	.Pin = PIN1
};

void Motor (void);

int main()
{
	GIE_Enable();
	DC_Motor_init(motor1);
	DC_Motor_init(motor2);
	Timer0_Init();


	Timer0_SetTimerValue(0);
	Timer0_SetCallBack(Motor);
	Timer0_OVIntEnableDisable(TIMER0_INT_ENABLE);
	while(1)
	{

	}
	return 0 ;
}



void Motor (void)
{
	static u16 counter = 0 ;
	++counter;
	if((counter>=0) && (counter<2440))
	{
		DC_Motor_ON(motor1);
		DC_Motor_OFF(motor2);
	}
	else if((counter>=2441) && (counter<3904))
	{
		DC_Motor_OFF(motor1);
		DC_Motor_ON(motor2);
	}
	else if((counter>=3904) && (counter<=6344))
	{
		DC_Motor_OFF(motor1);
		DC_Motor_OFF(motor2);

	}
	if (counter == 6344)
	{
		counter = 0 ;
	}
}
