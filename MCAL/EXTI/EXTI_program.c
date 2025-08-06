/*
 * @name 	EXTI_program.c
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "../LIB/Bit_MATH.h"
#include "../LIB/Std_types.h"

void (*EXTI_pvInt0Func)(void) = NULL;

void EXTI_voidEnableDisable(u8 copy_u8_EXTI_INTNum_e,u8 copy_u8EXTI_MODE_e)
{
	switch(copy_u8_EXTI_INTNum_e)
	{
	case EXTI_INT0:
		if(EXTI_ENABLE==copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR,GICR_INT0);
		}
		else if(EXTI_DISABLE==copy_u8EXTI_MODE_e)
		{
			CLEAR_BIT(GICR,GICR_INT0);
		}
		break;
	case EXTI_INT1:
		if(EXTI_ENABLE==copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR,GICR_INT1);
		}
		else if(EXTI_DISABLE==copy_u8EXTI_MODE_e)
		{
			CLEAR_BIT(GICR,GICR_INT1);
		}
		break;
	case EXTI_INT2:
		if(EXTI_ENABLE==copy_u8EXTI_MODE_e)
		{
			SET_BIT(GICR,GICR_INT2);
		}
		else if(EXTI_DISABLE==copy_u8EXTI_MODE_e)
		{
			CLEAR_BIT(GICR,GICR_INT2);
		}
		break;

	}

}



void EXTI_voidSetSenstivity(u8 copy_u8_EXTI_INTNum_e,u8 copy_EXTI_SENSTIVITY_e)
{
	switch(copy_u8_EXTI_INTNum_e)
	{
	case EXTI_INT0:
		switch(copy_EXTI_SENSTIVITY_e)
		{
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLEAR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLEAR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		}
		break;
		case EXTI_INT1:
			switch(copy_EXTI_SENSTIVITY_e)
			{
			case EXTI_LOW_LEVEL:
				CLEAR_BIT(MCUCR,MCUCR_ISC10);
				CLEAR_BIT(MCUCR,MCUCR_ISC00);
				break;
			case EXTI_ON_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLEAR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case EXTI_FALLING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC11);
				CLEAR_BIT(MCUCR,MCUCR_ISC10);
				break;
			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}

			break;
			case EXTI_INT2:
				switch(copy_EXTI_SENSTIVITY_e)
				{
				case EXTI_FALLING_EDGE:
					CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				}
				break;

	}

}



u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*ISR of INT0*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}



