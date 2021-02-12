/*
 * STK_private.h
 *
 *  Created on: Feb 9, 2021
 *      Author: mohab
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_type;

#define STK 	 				((STK_type*)0xE000E010)

/* CTRL BITS */
#define ENABLE					0
#define TICKINT					1
#define CLKSOURCE				2
#define COUNT_FLAG				16

#define STK_AHB_DIV_BY_8 		2
#define STK_AHB					4

#define STK_SINGLE_INTERVAL		1
#define STK_PERIODIC_INTERVAL	3

#endif /* STK_PRIVATE_H_ */
