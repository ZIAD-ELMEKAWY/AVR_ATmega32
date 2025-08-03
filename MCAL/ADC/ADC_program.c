/*
 * @name 	ADC_program.c
 * @date  	Created on: 24/7/2025
 * @author  Ziad Elmekawy
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
//=====================================================================================================================
/*Global pointer to carry the conversion result in the Asynchronous execution*/
static u16 * ADC_pu16AsynchConversionResult = NULL;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_pvNotificationFunc)(void)= NULL;

/*Global flag for the ADC ISR State*/
static u8 ADC_u8ISRState ;

/*Global pointer to carry the chain Channel*/
static u8 * ADC_pu8ChainChannel ;

/*Global variable to carry the chain size*/
static u8 ADC_u8ChainSize ;

/*Global variable to indicate for the current ADC Chain*/
static u8 ADC_u8Index ;

/*Global flag for the ADC Busy State*/
static u8 ADC_u8State= IDLE ;

//=====================================================================================================================
/**
 * @brief Initializes the ADC peripheral with predefined settings:
 *        - Selects voltage reference (AREF, AVCC, or Internal 2.56V)
 *        - Sets result adjustment (Left/Right)
 *        - Sets the ADC clock prescaler
 *        - Enables/disables ADC and ADC interrupt according to configuration
 *
 * @param void
 * @return void
 */
void ADC_voidInit(void)
{
	/*Select the voltage reference*/
	#if ADC_VREF == AREF
		CLR_BIT(ADMUX , ADMUX_REFS0) ;
		CLR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == AVCC
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		CLEAR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == INTERNAL_2_56
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		SET_BIT(ADMUX , ADMUX_REFS1) ;

	#else
		#error "Wrong ADC_VREF config"

	#endif


	/*Set Left Adjust Result*/
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
			CLEAR_BIT(ADMUX , ADMUX_ADLAR) ;

	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
			SET_BIT(ADMUX , ADMUX_ADLAR) ;

	#else
		#error "Wrong ADC_ADJUSTMENT config"

	#endif

	/*Set Prescaler Value*/
	ADSAR &= ADC_PRE_MASK ;
	ADSAR |= ADC_PRESCALLER ;

	/* ENABLE The Peripheral & Interrupt  */

	/*Enable ADC Peripheral*/
	#if ADC_STATUS == ADC_DISABLE
		CLR_BIT(ADSAR , ADSAR_ADEN) ;
	#elif ADC_STATUS == ADC_ENABLE
		SET_BIT(ADSAR , ADSAR_ADEN) ;
	#else
	#error "Wrong ADC_STATUS config"
	#endif

	/*Enable ADC Interrupt*/
	#if INT_STATUS == INT_DISABLE
		CLR_BIT(ADSAR , ADSAR_ADIE) ;
	#elif INT_STATUS == INT_ENABLE
		SET_BIT(ADSAR , ADSAR_ADIE) ;
	#else
	#error "Wrong INT_STATUS config"
	#endif

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Enables the ADC peripheral by setting the ADEN bit.
 *
 * @param void
 * @return void
 */
void ADC_voidEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADEN) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Disables the ADC peripheral by clearing the ADEN bit.
 *
 * @param void
 * @return void
 */
void ADC_voidDisable (void)
{
	CLEAR_BIT(ADSAR , ADSAR_ADEN) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Enables the ADC interrupt by setting the ADIE bit.
 *
 * @param void
 * @return void
 */
void ADC_voidInterruptEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADIE) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Disables the ADC interrupt by clearing the ADIE bit.
 *
 * @param void
 * @return void
 */
void ADC_voidInterruptDisable (void)
{
	CLEAR_BIT(ADSAR , ADSAR_ADIE) ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Sets the ADC clock prescaler to control conversion speed.
 *
 * @param Copy_u8Prescaler Value from 0 to 7 representing prescaler settings.
 * @return u8 Error state: OK if valid, else unchanged.
 */
u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_u8Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADSAR &= ADC_PRE_MASK ;
		ADSAR |= Copy_u8Prescaler ;
	}

	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Performs synchronous ADC conversion on a specific channel.
 *        - Waits (blocking) until the conversion completes or timeout occurs.
 *        - Stores the result in provided pointer.
 *
 * @param Copy_u8Channel ADC channel to read from (0 to 7).
 * @param Copy_pu16Result Pointer to store the conversion result.
 * @return u8 Error state: OK, TIMEOUT_STATE, NULL_POINTER, or BUSY_STATE.
 */
u8 ADC_u8GetResultSync (u8 Copy_u8Channel , u16 * Copy_pu16Result)
{
	u8 Local_u8ErrorState = OK ;
	u32 Local_u32TimeoutCounter = 0 ;
	if (Copy_pu16Result != NULL)
	{
		if (ADC_u8State == IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = BUSY ;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*Waiting until the conversion is complete*/
			while (((GET_BIT(ADSAR , ADSAR_ADIF)) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
			{
				Local_u32TimeoutCounter++ ;
			}
			if (Local_u32TimeoutCounter == ADC_TIMEOUT)
			{
				Local_u8ErrorState = TIMEOUT_STATE ;
			}
			else
			{
				/*Clear the interrupt flag*/
				SET_BIT(ADSAR , ADSAR_ADIF) ;

				/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					*Copy_pu16Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*Copy_pu16Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
			}

			/*ADC is IDLE*/
			ADC_u8State = IDLE ;
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}


	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Starts an asynchronous ADC conversion on a specific channel.
 *        - The result and completion notification are handled via callback and global pointer.
 *
 * @param Copy_u8Channel ADC channel to read from.
 * @param Copy_pu16Result Pointer to store conversion result.
 * @param Copy_pvNotificationFunc Function to be called when conversion completes.
 * @return u8 Error state: OK, NULL_POINTER, or BUSY_STATE.
 */
u8 ADC_u8StartConversionAsynch (u8 Copy_u8Channel , u16 * Copy_pu16Result , void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK ;

	if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_u8State == IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = BUSY ;

			/*Set ISR State*/
			ADC_u8ISRState = SINGLE_CHANNEL_ASYNCH ;

			/*Initialize the global result pointer*/
			ADC_pu16AsynchConversionResult = Copy_pu16Result;

			/*Initialize the global notification function pointer*/
			ADC_pvNotificationFunc= Copy_pvNotificationFunc;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Starts an asynchronous chain conversion on multiple ADC channels.
 *        - Converts each channel in order and stores results in an array.
 *        - Calls the notification function after all conversions complete.
 *
 * @param Copy_Chain Pointer to a Chain_t struct containing:
 *        - Channel list
 *        - Result array
 *        - Size of chain
 *        - Notification function
 * @return u8 Error state: OK, NULL_POINTER, or BUSY_STATE.
 */
u8 ADC_u8StartChainAsynch (Chain_t * Copy_Chain)
{
	u8 Local_u8ErrorState = OK ;

	if ((Copy_Chain != NULL) && (Copy_Chain->Channel != NULL) && (Copy_Chain->NotificationFunc != NULL) && (Copy_Chain->Result))
	{
		if (ADC_u8State == IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = BUSY ;

			/*Set ISR State*/
			ADC_u8ISRState = CHAIN_CHANNEL_ASYNCH ;

			/*Assign the ADC data globally*/
			ADC_pu16AsynchConversionResult = Copy_Chain->Result ;
			ADC_pu8ChainChannel = Copy_Chain->Channel ;
			ADC_u8ChainSize = Copy_Chain->Size ;
			ADC_pvNotificationFunc = Copy_Chain->NotificationFunc ;

			/*Set Index to first element*/
			ADC_u8Index = 0 ;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_pu8ChainChannel[ADC_u8Index] ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/* ISR for ADC conversion complete */
/**
 * @brief ADC Conversion Complete ISR.
 *        - Handles both single and chain asynchronous conversions.
 *        - Stores result, updates index, and calls user notification function.
 *        - Disables interrupt after conversion(s) finish.
 *
 * @param void
 * @return void
 */
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
	if (ADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
	{
		/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					* ADC_pu16AsynchConversionResult = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*ADC_pu16AsynchConversionResult = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif

		/*ADC is IDLE*/
		ADC_u8State = IDLE ;

		/*Call Notification Function*/
		ADC_pvNotificationFunc() ;

		/*Disable the Conversion Complete Interrupt*/
		CLEAR_BIT(ADSAR , ADSAR_ADIE) ;
	}
	else
	{
		/*Return Conversion Result*/
		#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
			*ADC_pu16AsynchConversionResult = (ADCL|(ADCH << 8))  ;

		#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
			*ADC_pu16AsynchConversionResult = ADCH ;
		#else
			#error "Wrong ADC_ADJUSTMENT config"

		#endif

		/*Increment Data index of the chain*/
		ADC_u8Index++ ;

		if (ADC_u8Index == ADC_u8ChainSize)
		{
			/*ADC is IDLE*/
			ADC_u8State = IDLE ;

			/*Call Notification Function*/
			ADC_pvNotificationFunc() ;

			/*Disable the Conversion Complete Interrupt*/
			CLEAR_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_pu8ChainChannel[ADC_u8Index] ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
