#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
/**
 * @brief Sets a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to set (0-indexed).
 */
#define SET_BIT(REG,BIT_NUM)  			(REG|=(1<<BIT_NUM))
/**
 * @brief Clears a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to clear (0-indexed).
 */
#define CLEAR_BIT(REG,BIT_NUM)  		(REG&=(~(1<<BIT_NUM)))
/**
 * @brief Toggles a specific bit in a register.
 * @param REG The register to modify.
 * @param BIT_NUM The bit number to toggle (0-indexed).
 */
#define TOGGLE_BIT(REG,BIT_NUM)  	(REG^=(1<<BIT_NUM))
/**
 * @brief Gets the value of a specific bit in a register.
 * @param REG The register to read from.
 * @param BIT_NUM The bit number to get (0-indexed).
 * @return The value of the bit (0 or 1).
 */
#define GET_BIT(REG,BIT_NUM)  			((REG>>BIT_NUM)&1)
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif
