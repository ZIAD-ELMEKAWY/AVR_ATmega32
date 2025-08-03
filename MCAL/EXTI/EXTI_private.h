/*
 * @name 	EXTI_private.h
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
// ----------------- External Interrupt Registers -----------------
#define GICR				*((volatile u8 *)0x5B)
#define GIFR				*((volatile u8 *)0x5A)
#define MCUCR			*((volatile u8 *)0x55)
#define MCUCSR		*((volatile u8 *)0x54)

// ----------------- MCUCR : Micro Controller Unit Control Register PINS -----------------
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

// ----------------- MCUCSR : MCU Control and StatusRegister PINS -----------------
#define MCUCSR_ISC2	6

// ----------------- GICR : General Interrupt Control Register PINS  -----------------
#define GICR_INT2			5
#define GICR_INT0			6
#define GICR_INT1			7

// ----------------- GIFR : General Interrupt Flag Register PINS -----------------
#define GIFR_INTF2			5
#define GIFR_INTF0			6
#define GIFR_INTF1			7

/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<< Data Types  >>>>>>>>>>>>>>>>>>>>>>>  */


/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif /* EXTI_EXTI_PRIVATE_H_ */
