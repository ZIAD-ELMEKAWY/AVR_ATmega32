/*
 * @name 	TWI_config.h
 * @date  	Created on: 3/8/2025
 * @author  Ziad ELmekawy
 */

#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_

/* <<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */


/* <<<<<<<<<<<<<<<<<<<<<<<< Macro declaration >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#define F_CPU 8000000UL


/*
	$ Options :-
		1-PRESCALLER_BY_1
		2-PRESCALLER_BY_4
		3-PRESCALLER_BY_16
		4-PRESCALLER_BY_64
*/
#define TWI_PRESCALLER  PRESCALLER_BY_1


/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_Clock  400000UL
/* <<<<<<<<<<<<<<<<<<<<<<<< Macro function  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* <<<<<<<<<<<<<<<<<<<<<<<< Data types >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<<<<< API interface declaration >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

#endif /* MCAL_TWI_TWI_CONFIG_H_ */
