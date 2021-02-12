/*
 * EXTI_interface.h
 *
 *  Created on: Feb 8, 2021
 *      Author: mohab
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum{
	/* PORT A */
	EXTI_ENUM_LINE0=0,
	EXTI_ENUM_LINE1,
	EXTI_ENUM_LINE2,
	EXTI_ENUM_LINE3,
	EXTI_ENUM_LINE4,
	EXTI_ENUM_LINE5,
	EXTI_ENUM_LINE6,
	EXTI_ENUM_LINE7,
	EXTI_ENUM_LINE8,
	EXTI_ENUM_LINE9,
	EXTI_ENUM_LINE10,
	EXTI_ENUM_LINE11,
	EXTI_ENUM_LINE12,
	EXTI_ENUM_LINE13,
	EXTI_ENUM_LINE14,
	EXTI_ENUM_LINE15,
	EXTI_ENUM_TOTAL_LINES
}EXTI_EnumLine_type;


#define	EXTI_RISING				1
#define	EXTI_FALLING			2
#define	EXTI_ANY_LOGIC_CHANGE	3

void EXTI_voidInit(void);
void EXTI_voidEnableLine(EXTI_EnumLine_type Copy_EnumLine);
void EXTI_voidDisableLine(EXTI_EnumLine_type Copy_EnumLine);
void EXTI_voidTriggerEdge(EXTI_EnumLine_type Copy_EnumLine, u8 Copy_u8EdgeMode);
void EXTI_voidSetSoftwareInterrupt(EXTI_EnumLine_type Copy_EnumLine);
void EXTI_voidClearPendingFlag(EXTI_EnumLine_type Copy_EnumLine);
void EXTI_voidSetCallBack(EXTI_EnumLine_type Copy_EnumLine, void (*ptr)(void));


#endif /* EXTI_INTERFACE_H_ */
