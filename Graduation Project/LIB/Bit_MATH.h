#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* <<<<<<<<<<<<<<<<<<<<<<<<<<< Includes >>>>>>>>>>>>>>>>>>>>>>>>>>>> */

/* <<<<<<<<<<<<<<<<<<<<< Macro Declaration >>>>>>>>>>>>>>>>>>>>>> */
#define SET_BIT(REG,BIT_NUM)  			(REG|=(1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM)  		(REG&=(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM)  	(REG^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)  			((REG>>BIT_NUM)&1)
/* <<<<<<<<<<<<<<<<<<<<< Macro Function   >>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */

/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */

#endif
