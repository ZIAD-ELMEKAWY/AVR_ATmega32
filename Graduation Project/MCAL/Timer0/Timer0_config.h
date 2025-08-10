/*
 * @name 	Timer0_config.h
 * @date  	Created on: 27/7/2025
 * @author  Ziad Elmekawy
 */


#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Timer0_private.h"
#include "../../LIB/Bit_MATH.h"
#include "../../LIB/Std_types.h"
#include "../DIO/DIO_Interface.h"
/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
/*
 * ***** Options TIMER0_MODE
 * 1.  NORMAL_MODE
 * 2. PWM_PHASE_MODE
 * 3. CTC_MODE
 * 4. FAST_PWM_MODE
 */
#define TIMER0_MODE 		FAST_PWM_MODE
/*
 * ***** Options TIMER0_PRESCALER
 * 1.  PRESCALER_1
 * 2. PRESCALER_8
 * 3. PRESCALER_64
 * 4. PRESCALER_256
 * 5. PRESCALER_1024
 */
#define TIMER0_PRESCALER		PRESCALER_8
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif /* TIMER0_TIMER0_CONFIG_H_ */
