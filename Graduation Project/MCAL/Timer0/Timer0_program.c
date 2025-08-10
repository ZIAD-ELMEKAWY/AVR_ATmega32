/*
 * @name 	Timer0_program.c
 * @date  	Created on: 27/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "Timer0_interface.h"


static void (* Global_pvOVIntFun)(void);
static void (* Global_pcCTCIntFun)(void);
/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer0 Initialization function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Timer0_Init
 * @brief				Initializes Timer0 according to the configured mode (Normal, PWM Phase Correct, CTC, or Fast PWM) and sets the prescaler.
 * @argument			void
 * @return				void
 */
void Timer0_Init (void)
{
	/********************************* Check Mode ***********************/
#if TIMER0_MODE == NORMAL_MODE
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER0_MODE == PWM_PHASE_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER0_MODE == CTC_MODE
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);
#elif TIMER0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);
	//Clear on compare Set on Top -> to make timer0 PWM
	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);
#else
#error "Invalid Timer0 Mode"
#endif
	// Set prescaler
	TCCR0 &= 0b11111000 ;
	TCCR0 |= TIMER0_PRESCALER ;
}

/***
 * @name				Timer0_DeInit
 * @brief				De-initializes Timer0 by resetting its control register (TCCR0) to zero, effectively stopping the timer.
 * @argument			void
 * @return				void
 */
void Timer0_DeInit (void)
{
	TCCR0 = 0 ;
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Timer0 Set value function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Timer0_SetTimerValue
 * @brief				Sets the initial value of the Timer0 counter register (TCNT0).
 * @argument value		The 8-bit value to load into TCNT0 (0-255).
 * @return				void
 */
void Timer0_SetTimerValue (u8 value)
{
	if ((value >= 0) && (value <= 255))
	{
		TCNT0 = value ;
	}
	else
	{
		// Handle error or do nothing for invalid value
	}
}

/***
 * @name				Timer0_CTCTimerValue
 * @brief				Sets the Output Compare Register (OCR0) value for Clear Timer on Compare Match (CTC) mode.
 * @argument value		The 8-bit value to load into OCR0 (0-255).
 * @return				void
 */
void Timer0_SetCTCTimerValue (u8 value)
{
	OCR0 = value;
}
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Interrupt enable disable function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Timer0_OVIntEnableDisable
 * @brief				Enables or disables the Timer0 Overflow Interrupt.
 * @argument Copy_u8TIMER0_INT_e Specifies whether to enable (TIMER0_INT_ENABLE) or disable (TIMER0_INT_DISABLE) the interrupt.
 * @return				void
 */
void Timer0_OVIntEnableDisable   (u8 Copy_u8TIMER0_INT_e)
{
	if(TIMER0_INT_ENABLE == Copy_u8TIMER0_INT_e)
	{
		SET_BIT(TIMSK , TIMSK_TOIE0);
	}
	else if(TIMER0_INT_DISABLE == Copy_u8TIMER0_INT_e) // Corrected condition
	{
		CLEAR_BIT(TIMSK , TIMSK_TOIE0);
	}
}

/***
 * @name				Timer0_CTCIntEnableDisable
 * @brief				Enables or disables the Timer0 Output Compare Match Interrupt.
 * @argument Copy_u8TIMER0_INT_e Specifies whether to enable (TIMER0_INT_ENABLE) or disable (TIMER0_INT_DISABLE) the interrupt.
 * @return				void
 */
void Timer0_CTCIntEnableDisable (u8 Copy_u8TIMER0_INT_e)
{
	if(TIMER0_INT_ENABLE == Copy_u8TIMER0_INT_e)
	{
		SET_BIT(TIMSK , TIMSK_OCIE0);
	}
	else if(TIMER0_INT_DISABLE == Copy_u8TIMER0_INT_e) // Corrected condition
	{
		CLEAR_BIT(TIMSK , TIMSK_OCIE0);
	}
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Call Back function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				Timer0_SetOVCallBack
 * @brief				Sets the callback function to be executed when a Timer0 Overflow Interrupt occurs.
 * @argument pvCallBackFun A pointer to the callback function.
 * @return				u8 indicating success (OK) or failure (NOK) if the provided function pointer is NULL.
 */
u8 Timer0_SetOVCallBack	(void (* pvCallBackFun)(void))
{
	u8 LOC_Status = OK ;
	if (NULL != pvCallBackFun)
	{
		Global_pvOVIntFun = pvCallBackFun ;
	}
	else
	{
		LOC_Status = NOK ;
	}
	return OK; // Should return LOC_Status
}

/***
 * @name				Timer0_SetCTCCallBack
 * @brief				Sets the callback function to be executed when a Timer0 Output Compare Match Interrupt occurs.
 * @argument pvCallBackFun A pointer to the callback function.
 * @return				u8 indicating success (OK) or failure (NOK) if the provided function pointer is NULL.
 */
u8 Timer0_SetCTCCallBack	(void (* pvCallBackFun)(void))
{
	u8 LOC_Status = OK ;
	if (NULL != pvCallBackFun)
	{
		Global_pcCTCIntFun = pvCallBackFun ;
	}
	else
	{
		LOC_Status = NOK ;
	}
	return OK; // Should return LOC_Status
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ISR function >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
// Over flow ISR
void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	Global_pvOVIntFun();
}

// CTC ISR
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	Global_pcCTCIntFun();
}
