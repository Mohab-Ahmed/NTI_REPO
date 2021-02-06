/********************************************************************
* File : SEG_interface.h
*
* Author  : Mohab Ahmed
* Created : 05-Feb-21
*
********************************************************************/

#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

typedef enum{
	SEG_ENUM_ONE=0,
	SEG_ENUM_TWO,
	SEG_ENUM_TOTAL
}SEG_EnumNumber_type;

/******************
 * Brief  : Display a number in decimal on the segment chosen.
 *
 *
 *
 * Argument : A number.
 *
 * Return	: void.
 *****************/
void SEG_voidDisplayDEC(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num);

/******************
 * Brief  : Display a number in Hexadecimal on the segment chosen.
 *
 *
 *
 * Argument : A number.
 *
 * Return	: void.
 *****************/
void SEG_voidDisplayHEX(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num);

#endif /* SEG_INTERFACE_H_ */
