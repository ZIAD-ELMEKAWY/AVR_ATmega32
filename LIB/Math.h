/*
 * Math.h
 * Layer : LIB "Library"
 * Created: 06/03/2024 08:37:20
 *  Author: Ziad
 */ 


#ifndef MATH_H_
#define MATH_H_

#define SET_BIT(Reg,Bit)		Reg|=(1<<Bit)
#define GET_BIT(Reg,Bit)		Reg&=(1<<Bit)
#define TOGGLE_BIT(Reg,Bit)		Reg^=(1<<Bit)
#define CLR_BIT(Reg,Bit)		Reg&=(~(1<<Bit))

#define IS_BIT_SET(Reg,Bit)		(Reg&(1<<Bit))>>Bit
#define IS_BIT_CLR(Reg,Bit)		!((Reg&(1<<Bit))>>Bit)


#endif /* MATH_H_ */