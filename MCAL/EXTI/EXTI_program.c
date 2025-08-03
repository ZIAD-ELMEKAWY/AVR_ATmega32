/*
 * @name 	EXTI_program.c
 * @date  	Created on: 23/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "EXTI_interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				EXTI_VoidEnableDisable
 * @brief
 * @argument		u8 Ext_Int : @ref EXTI_INTNUM_e
 * 													- EXTI_INT_0
 * 													- EXTI_INT_1
 * 													- EXTI_INT_2
 * 							 u8 mode : @ref EXTI_Mode_e
 * 													- EXTI_ENABLE
 * 													- EXTI_DISABLE
 * @return			void
 */
void EXTI_VoidEnableDisable		(u8 Ext_Int , u8 mode )
{
	switch (Ext_Int)
	{
	case EXTI_INT_0 :
		if(EXTI_ENABLE == mode)
		{
			SET_BIT(GICR , GICR_INT0);
		}
		else if(EXTI_DISABLE == mode)
		{
			CLEAR_BIT(GICR , GICR_INT0);
		}
		break ;
	case EXTI_INT_1 :
		if(EXTI_ENABLE == mode)
		{
			SET_BIT(GICR , GICR_INT1);
		}
		else if(EXTI_DISABLE == mode)
		{
			CLEAR_BIT(GICR , GICR_INT1);
		}
		break ;
	case EXTI_INT_2 :
		if(EXTI_ENABLE == mode)
		{
			SET_BIT(GICR , GICR_INT2);
		}
		else if(EXTI_DISABLE == mode)
		{
			CLEAR_BIT(GICR , GICR_INT2);
		}
		break ;
	default : break ;
	}
}

/***
 * @name				EXTI_VoidSetSenstivity
 * @brief
 * @argument		u8 Ext_Int : @ref EXTI_INTNUM_e
 * 													=> EXTI_INT_0
 * 														 u8 senstivity : @ref EXTI_SENSTIVITY_e
 * 															- EXTI_LOW_LEVEL
 * 															- EXTI_ON_CHANGE
 * 															- EXTI_FALLING_EDGE
 * 															- EXTI_RISING_EDGE
 * 													=> EXTI_INT_1
 * 														 u8 senstivity : @ref EXTI_SENSTIVITY_e
 * 															- EXTI_LOW_LEVEL
 * 															- EXTI_ON_CHANGE
 * 															- EXTI_FALLING_EDGE
 * 															- EXTI_RISING_EDGE
 * 													=> EXTI_INT_2
 * 														 u8 senstivity : @ref EXTI_SENSTIVITY_e
 * 															- EXTI_FALLING_EDGE
 * 															- EXTI_RISING_EDGE
 * @return			void
 */
void EXTI_VoidSetSenstivity		(u8 Ext_Int , u8 senstivity )
{
	switch (Ext_Int)
	{
	case EXTI_INT_0 :
		switch(senstivity)
		{
		case EXTI_LOW_LEVEL :
			// ISC00 = 0 , ISC01 = 0
			CLEAR_BIT(MCUCR , MCUCR_ISC00);
			CLEAR_BIT(MCUCR , MCUCR_ISC01);
			break ;
		case EXTI_ON_CHANGE :
			// ISC00 = 1 , ISC01 = 0
			SET_BIT(MCUCR , MCUCR_ISC00);
			CLEAR_BIT(MCUCR , MCUCR_ISC01);
			break ;
		case EXTI_FALLING_EDGE :
			// ISC00 = 0 , ISC01 = 1
			CLEAR_BIT(MCUCR , MCUCR_ISC00);
			SET_BIT(MCUCR , MCUCR_ISC01);
			break ;
		case EXTI_RISING_EDGE:
			// ISC00 = 1 , ISC01 = 1
			SET_BIT(MCUCR , MCUCR_ISC00);
			SET_BIT(MCUCR , MCUCR_ISC01);
			break ;
		default : break ;
		}
		break ;
	case EXTI_INT_1 :
		switch(senstivity)
		{
		case EXTI_LOW_LEVEL :
			// ISC10 = 0 , ISC11 = 0
			CLEAR_BIT(MCUCR , MCUCR_ISC10);
			CLEAR_BIT(MCUCR , MCUCR_ISC11);
			break ;
		case EXTI_ON_CHANGE :
			// ISC10 = 1 , ISC11 = 0
			SET_BIT(MCUCR , MCUCR_ISC10);
			CLEAR_BIT(MCUCR , MCUCR_ISC11);
			break ;
		case EXTI_FALLING_EDGE :
			// ISC10 = 0 , ISC11 = 1
			CLEAR_BIT(MCUCR , MCUCR_ISC10);
			SET_BIT(MCUCR , MCUCR_ISC11);
			break ;
		case EXTI_RISING_EDGE:
			// ISC10 = 1 , ISC11 = 1
			SET_BIT(MCUCR , MCUCR_ISC10);
			SET_BIT(MCUCR , MCUCR_ISC11);
			break ;
		default : break ;
		}
	break ;
	case EXTI_INT_2 :
		switch(senstivity)
		{
		case EXTI_FALLING_EDGE :
			// ISC2 = 0
			CLEAR_BIT(MCUCSR , MCUCSR_ISC2);
			break ;
		case EXTI_RISING_EDGE:
			// ISC2 = 1
			SET_BIT(MCUCSR , MCUCSR_ISC2);
			break ;
		default : break ;
		}
		break ;
		default :
			break ;
	}
}



/***
 * @name				EXTI_Std_SetCallBack
 * @brief				Sets the callback function to be executed when a specific external interrupt occurs.
 * @argument Ext_Int	The external interrupt source (e.g., EXTI0, EXTI1, etc.).
 * @argument PrCallBackFun A pointer to the callback function that will be invoked upon interrupt.
 * @return				Std_ReturnType indicating success (E_OK) if the callback function is successfully set, or failure (E_NOK) if the provided function pointer is NULL.
 */
Std_ReturnType EXTI_Std_SetCallBack 				(u8 Ext_Int ,  void (*PrCallBackFun)(void))
{
	Std_ReturnType Ret_Status = E_OK ;
	if(PrCallBackFun != NULL)
	{
		// Logic to store the callback function pointer for the specified external interrupt
		// This part of the code is missing from the provided snippet but would typically involve
		// assigning PrCallBackFun to a global array or structure indexed by Ext_Int.
	}
	else
	{
		Ret_Status = E_NOK ;
	}
	return  Ret_Status ;
}
