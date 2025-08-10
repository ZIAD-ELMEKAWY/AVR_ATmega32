/*
 * @name 	APP.h
 * @date  	Created on: 25/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

#ifndef APP_APP_H_
#define APP_APP_H_
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include <util/delay.h>
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/DC_Motor/DC_Motor_interface.h"
#include "../HAL/Buzzer/Buzzer_Interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */


/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */



/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void Application_Initialization(void);
void Light_Turn_ON (void);
void Light_Turn_OFF (void);
void Weather_Turn_ON (void);
void Weather_Turn_OFF (void);
void Motor_Turn_ON (void);
void Motor_Turn_OFF (void);
u8 Read_Temperature (void);
u8 Read_Light (void);
void SendSensors(u8 temp , u16 light);
void SendDataToEEPROM(u8 temp , u8 light);
void Control (u8 temp , u16 light , u8 UART_Receive);

#endif /* APP_APP_H_ */
