/********************************************************************
* File : KEYPAD_interface.h
*
* Author  : Mohab Ahmed
* Created : 06-Feb-21
*
********************************************************************/

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KEYPAD_NO_KEY				0

/******************
 * Brief  : Return the Key pressed.
 *
 *
 *
 * Argument : void.
 *
 * Return	: unsigned char.
 *****************/
u8 KEYPAD_u8GetKey(void);

/******************
 * Brief  : Return the Key pressed in HEX mode.
 *
 *
 *
 * Argument : void.
 *
 * Return	: unsigned char.
 *****************/
u8 KEYPAD_u8GetKeyHEX(void);

#endif /* KEYPAD_INTERFACE_H_ */
