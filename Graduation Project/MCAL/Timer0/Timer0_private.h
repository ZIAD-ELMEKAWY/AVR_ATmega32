/*
 * @name 	Timer0_private.h
 * @date  	Created on: 27/7/2025
 * @author  Ziad Elmekawy
 */


#ifndef TIMER0_TIMER0_PRIVATE_H_
#define TIMER0_TIMER0_PRIVATE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define TCCR0						*((volatile u8 *) 0x53)
#define TCCR0_FOC0			7
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define TCNT0						*((volatile u8 *) 0x52)

#define OCR0						*((volatile u8 *) 0x5C)

#define TIMSK						*((volatile u8 *) 0x59)
#define TIMSK_OCIE2		7
#define TIMSK_TOIE2		6
#define TIMSK_TICIE1		5
#define TIMSK_OCIE1A		4
#define TIMSK_OCIE1B		3
#define TIMSK_TOIE1		2
#define TIMSK_OCIE0		1
#define TIMSK_TOIE0		0

#define TIFR							*((volatile u8 *) 0x58)
#define TIFR_OCF2				7
#define TIFR_TOV2				6
#define TIFR_ICF1				5
#define TIFR_OCF1A			4
#define TIFR_OCF1B			3
#define TIFR_TOV1				2
#define TIFR_OCF0				1
#define TIFR_TOV0				0

// TIMER0_Mode
#define NORMAL_MODE 			0
#define PWM_PHASE_MODE	1
#define CTC_MODE					2
#define FAST_PWM_MODE		3
// TIMER0_PRESCALER
#define PRESCALER_1 				0b001
#define PRESCALER_8 				0b010
#define PRESCALER_64 			0b011
#define PRESCALER_256 		0b100
#define PRESCALER_1024 		0b101
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif /* TIMER0_TIMER0_PRIVATE_H_ */
