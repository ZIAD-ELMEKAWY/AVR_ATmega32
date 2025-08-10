/*
 * @name 	APP.c
 * @date  	Created on: 25/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "APP.h"

/* <<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>  */
led_t led1 =
{
	.Port = _PORTB_ ,
	.Pin = PIN0
};

led_t led2 =
{
	.Port = _PORTB_ ,
	.Pin = PIN1
};

led_t led3 =
{
	.Port = _PORTB_ ,
	.Pin = PIN2
};
buz_t buz1 =
{
		.Port = _PORTB_ ,
		.Pin = PIN3
};
motor_t motor1 =
{
		.Port = _PORTB_ ,
		.Pin = PIN4
};
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Application_Initialization
 * @brief
 * @argument		void
 * @return				void
 */
void Application_Initialization(void)
{
	DIO_Std_SetPinDirection(_PORTA_ , PIN0 , DIO_PIN_INPUT);
	DIO_Std_SetPinDirection(_PORTA_ , PIN1 , DIO_PIN_INPUT);
	ADC_voidInit();
	USART_Init();
	TWI_voidInitMaster(0);

	LED_Void_Initialzation(led1);
	LED_Void_Initialzation(led2);
	LED_Void_Initialzation(led3);
	Buz_Void_Initialzation(buz1);
	DC_Motor_init(motor1);

}

/***
 * @name				Light_Turn_ON
 * @brief				Turn ON light
 * @argument		void
 * @return			void
 */
void Light_Turn_ON (void)
{
	LED_Void_Turn_ON(led1);
	LED_Void_Turn_ON(led2);
}

/***
 * @name				Light_Turn_OFF
 * @brief				Turn OFF light
 * @argument		void
 * @return			void
 */
void Light_Turn_OFF (void)
{
	LED_Void_Turn_OFF(led1);
	LED_Void_Turn_OFF(led2);
}

/***
 * @name				Read_Light
 * @brief				Read Light from LDR
 * @argument		void
 * @return			void
 */
u8 Read_Light (void)
{
	u16 RetValue = 0 ;
	u32 light = 0 ;
	DIO_Std_SetPinDirection(_PORTA_ , PIN1 , DIO_PIN_INPUT);
	ADC_u8GetResultSync(ADC_CHANNEL1 , &RetValue );
	RetValue = RetValue *( 5000 / 1024.0) ;
	light = ((f32)RetValue*10) ;

	return light ;
}

/***
 * @name				Read_Temperature
 * @brief				Read temperature from LM35
 * @argument		void
 * @return				void
 */
u8 Read_Temperature (void)
{
	u16 RetValue = 0 ;
	u32 temp = 0 ;
	DIO_Std_SetPinDirection(_PORTA_ , PIN0 , DIO_PIN_INPUT);
	 ADC_u8GetResultSync(ADC_CHANNEL0 , &RetValue );
	 RetValue = RetValue *( 5000 / 1024.0) ;
	 temp = ((f32)RetValue / 10.0) ;
	 return temp ;
}

void Control (u8 temp , u16 light , u8 UART_Receive)
{
	if (UART_Receive == '3')
	{
		Motor_Turn_ON();
	}
	else if (UART_Receive == '2')
	{
		Motor_Turn_OFF();
	}
	else if (UART_Receive == '1')
	{
		Light_Turn_ON();
	}
	else if (UART_Receive == '0')
	{
		Light_Turn_OFF();
	}
	if ((temp < 50) && (temp >= 40))
	{
		Motor_Turn_ON();
	}
	else if((temp >= 50) && (temp < 100))
	{
		Weather_Turn_ON();
	}
	else
	{
		Weather_Turn_OFF();
	}
	if((light  >= 0) && (light  <= 600))
	{
		Light_Turn_ON();
	}
	else if (light  > 600)
	{
		Light_Turn_OFF();
	}
}


void SendSensors(u8 temp , u16 light)
{
    u8 buffer[50];

    sprintf(buffer, "%d,%d,%d\n", temp, light, 50);
    USART_POLL_SendString(buffer); // Send string over UART
}

void SendDataToEEPROM(u8 temp , u8 light)
{
	static u8 counter =0  ;
	EEPROM_voidSendDataByte(counter , temp);
	EEPROM_voidSendDataByte(counter , light);
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Helper Functions >>>>>>>>>>>>>>>>>>>>>>>> */

void Weather_Turn_ON (void)
{
	Buz_Void_Turn_ON(buz1);
	LED_Void_Turn_ON(led3);
}
void Weather_Turn_OFF (void)
{
	Buz_Void_Turn_OFF(buz1);
	LED_Void_Turn_OFF(led3);
}
void Motor_Turn_ON (void)
{
	DC_Motor_ON(motor1);
}
void Motor_Turn_OFF (void)
{
	DC_Motor_OFF(motor1);
}


