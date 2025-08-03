/*
 * @name 	GIE_program.c
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "GIE_interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				GIE_Enable
 * @brief				Enables global interrupts by setting the Global Interrupt Enable bit (I-bit) in the Status Register (SREG).
 * @argument		void
 * @return				void
 */
void GIE_Enable		(void)
{
	SET_BIT(SREG , SREG_I);
}

/***
 * @name				GIE_Disable
 * @brief				Disables global interrupts by clearing the Global Interrupt Enable bit (I-bit) in the Status Register (SREG).
 * @argument		void
 * @return				void
 */
void GIE_Disable 	(void)
{
	CLEAR_BIT(SREG , SREG_I);
}

/***
 * @name				GIE_EnableDisable
 * @brief				Enables or disables global interrupts based on the provided mode.
 * @argument		mode @ref Mode_e: Specifies whether to ENABLE or DISABLE global interrupts.
 * @return				void
 */
void GIE_EnableDisable	(u8 mode)
{
	if(ENABLE == mode)
	{
		SET_BIT(SREG , SREG_I);
	}
	else if(DISABLE == mode)
	{
		CLEAR_BIT(SREG , SREG_I);
	}
}
