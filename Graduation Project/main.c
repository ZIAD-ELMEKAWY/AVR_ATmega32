/*
 * @name 	  main.c
 * @date  	Created on: 17/7/2025
 * @folder  Graduation Project
 * @author  Ziad Elmekawy
 */


#include "APP/APP.h"

#define F_CPU	8000000UL

u8 RetValue =0  ;
u8 temp = 0 ;
u16 light  = 0 ;

int main()
{

	Application_Initialization();
	while(1)
	{
		temp = Read_Temperature();
		light = Read_Light();
		SendSensors(temp , light);
		USART_POLL_ReceiveData(&RetValue);
		Control(temp , light , RetValue);


	}
	return 0 ;
}


