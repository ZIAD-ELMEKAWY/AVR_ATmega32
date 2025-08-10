/*
 * @name 	GIE_program.c
 * @date  	Created on: 23/7/2025
 * @folder   Graduation Project
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "GIE_interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				GIE_Enable
 * @brief				Enable General Interrupt
 * @argument		void
 * @return			void
 */
void GIE_Enable		(void)
{
	SET_BIT(SREG , SREG_I);
}

/***
 * @name				GIE_Disable
 * @brief				Disable General Interrupt
 * @argument		void
 * @return			void
 */
void GIE_Disable 	(void)
{
	CLEAR_BIT(SREG , SREG_I);
}

/***
 * @name				GIE_EnableDisable
 * @brief				Enable / Disable General Interrupt
 * @argument		mode @ref Mode_e
 * @return			void
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
