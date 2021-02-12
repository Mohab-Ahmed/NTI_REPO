/*
 * EXTI_program.c
 *
 *  Created on: Feb 8, 2021
 *      Author: mohab
 */

#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*EXTI_FptrArray[EXTI_ENUM_TOTAL_LINES])(void)={NULLPTR};

void EXTI_voidInit(void)
{
	/* Select all edge modes for all lines */
	#if (EXTI_LINE0_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 0);
	#elif (EXTI_LINE0_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 0);
	#elif (EXTI_LINE0_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 0);
		SET_BIT(EXTI->FTSR , 0);
	#else
	#error "Wrong edge selected for LINE 0 !"
	#endif

	#if (EXTI_LINE1_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 1);
	#elif (EXTI_LINE1_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 1);
	#elif (EXTI_LINE1_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 1);
		SET_BIT(EXTI->FTSR , 1);
	#else
	#error "Wrong edge selected for LINE 1 !"
	#endif

	#if (EXTI_LINE2_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 2);
	#elif (EXTI_LINE2_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 2);
	#elif (EXTI_LINE2_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 2);
		SET_BIT(EXTI->FTSR , 2);
	#else
	#error "Wrong edge selected for LINE 2 !"
	#endif

	#if (EXTI_LINE3_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 3);
	#elif (EXTI_LINE3_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 3);
	#elif (EXTI_LINE3_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 3);
		SET_BIT(EXTI->FTSR , 3);
	#else
	#error "Wrong edge selected for LINE 3 !"
	#endif

	#if (EXTI_LINE4_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 4);
	#elif (EXTI_LINE4_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 4);
	#elif (EXTI_LINE4_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 4);
		SET_BIT(EXTI->FTSR , 4);
	#else
	#error "Wrong edge selected for LINE 4 !"
	#endif

	#if (EXTI_LINE5_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 5);
	#elif (EXTI_LINE5_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 5);
	#elif (EXTI_LINE5_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 5);
		SET_BIT(EXTI->FTSR , 5);
	#else
	#error "Wrong edge selected for LINE 5 !"
	#endif

	#if (EXTI_LINE6_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 6);
	#elif (EXTI_LINE6_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 6);
	#elif (EXTI_LINE6_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 6);
		SET_BIT(EXTI->FTSR , 6);
	#else
	#error "Wrong edge selected for LINE 6 !"
	#endif

	#if (EXTI_LINE7_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 7);
	#elif (EXTI_LINE7_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 7);
	#elif (EXTI_LINE7_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 7);
		SET_BIT(EXTI->FTSR , 7);
	#else
	#error "Wrong edge selected for LINE 7 !"
	#endif

	#if (EXTI_LINE8_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 8);
	#elif (EXTI_LINE8_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 8);
	#elif (EXTI_LINE8_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 8);
		SET_BIT(EXTI->FTSR , 8);
	#else
	#error "Wrong edge selected for LINE 8 !"
	#endif

	#if (EXTI_LINE9_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 9);
	#elif (EXTI_LINE9_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 9);
	#elif (EXTI_LINE9_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 9);
		SET_BIT(EXTI->FTSR , 9);
	#else
	#error "Wrong edge selected for LINE 9 !"
	#endif

	#if (EXTI_LINE10_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 10);
	#elif (EXTI_LINE10_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 10);
	#elif (EXTI_LINE10_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 10);
		SET_BIT(EXTI->FTSR , 10);
	#else
	#error "Wrong edge selected for LINE 10 !"
	#endif

	#if (EXTI_LINE11_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 11);
	#elif (EXTI_LINE11_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 11);
	#elif (EXTI_LINE11_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 11);
		SET_BIT(EXTI->FTSR , 11);
	#else
	#error "Wrong edge selected for LINE 11 !"
	#endif

	#if (EXTI_LINE12_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 12);
	#elif (EXTI_LINE12_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 12);
	#elif (EXTI_LINE12_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 12);
		SET_BIT(EXTI->FTSR , 12);
	#else
	#error "Wrong edge selected for LINE 12 !"
	#endif

	#if (EXTI_LINE13_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 13);
	#elif (EXTI_LINE13_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 13);
	#elif (EXTI_LINE13_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 13);
		SET_BIT(EXTI->FTSR , 13);
	#else
	#error "Wrong edge selected for LINE 13 !"
	#endif

	#if (EXTI_LINE14_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 14);
	#elif (EXTI_LINE14_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 14);
	#elif (EXTI_LINE14_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 14);
		SET_BIT(EXTI->FTSR , 14);
	#else
	#error "Wrong edge selected for LINE 14 !"
	#endif

	#if (EXTI_LINE15_EDGE==EXTI_RISING)
		SET_BIT(EXTI->RTSR , 15);
	#elif (EXTI_LINE15_EDGE==EXTI_FALLING)
		SET_BIT(EXTI->FTSR , 15);
	#elif (EXTI_LINE15_EDGE==EXTI_ANY_LOGIC_CHANGE)
		SET_BIT(EXTI->RTSR , 15);
		SET_BIT(EXTI->FTSR , 15);
	#else
	#error "Wrong edge selected for LINE 15 !"
	#endif

	/* Disable EXTI all lines */
	EXTI->IMR=0;
	/* Clear all pending bits */
	EXTI->PR=0xFFFFFFFF;
}

void EXTI_voidEnableLine(EXTI_EnumLine_type Copy_EnumLine)
{
	/* Range check */
	if (Copy_EnumLine<EXTI_ENUM_TOTAL_LINES)
	{
		SET_BIT(EXTI->IMR , Copy_EnumLine);
	}
	else
	{
		/* error */
	}
}

void EXTI_voidDisableLine(EXTI_EnumLine_type Copy_EnumLine)
{
	/* Range check */
	if (Copy_EnumLine<EXTI_ENUM_TOTAL_LINES)
	{
		CLR_BIT(EXTI->IMR , Copy_EnumLine);
	}
	else
	{
		/* error */
	}
}

void EXTI_voidTriggerEdge(EXTI_EnumLine_type Copy_EnumLine, u8 Copy_u8EdgeMode)
{
	/* Range check */
	if (Copy_EnumLine<EXTI_ENUM_TOTAL_LINES)
	{
		/* Clear both registers b4 applying any change */
		CLR_BIT(EXTI->FTSR , Copy_EnumLine);
		CLR_BIT(EXTI->RTSR , Copy_EnumLine);
		switch (Copy_u8EdgeMode)
		{
			case EXTI_RISING 			: SET_BIT(EXTI->RTSR , Copy_EnumLine); break;
			case EXTI_FALLING			: SET_BIT(EXTI->FTSR , Copy_EnumLine); break;
			case EXTI_ANY_LOGIC_CHANGE	: SET_BIT(EXTI->RTSR , Copy_EnumLine);
										  SET_BIT(EXTI->FTSR , Copy_EnumLine); break;
			default: /* error */ break;
		}
	}
	else
	{
		/* error */
	}
}

void EXTI_voidSetSoftwareInterrupt(EXTI_EnumLine_type Copy_EnumLine)
{
	/* Range check */
	if (Copy_EnumLine<EXTI_ENUM_TOTAL_LINES)
	{
		SET_BIT(EXTI->SWIER,Copy_EnumLine);
	}
	else
	{
		/* error */
	}
}

void EXTI_voidClearPendingFlag(EXTI_EnumLine_type Copy_EnumLine)
{
	/* Range check */
	if (Copy_EnumLine<EXTI_ENUM_TOTAL_LINES)
	{
		SET_BIT(EXTI->PR , Copy_EnumLine);
	}
	else
	{
		/* error */
	}
}

void EXTI_voidSetCallBack(EXTI_EnumLine_type Copy_EnumLine, void (*ptr)(void))
{
	EXTI_FptrArray[Copy_EnumLine]=ptr;
}
/*
void EXTI0_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE0])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE0]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE0);
	}
}
*/
void EXTI1_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE1])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE1]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE1);
	}
}

void EXTI2_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE2])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE2]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE2);
	}
}

void EXTI3_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE3])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE3]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE3);
	}
}

void EXTI4_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE4])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE4]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE4);
	}
}

void EXTI9_5_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE5])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE5]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE5);
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE6])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE6]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE6);
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE7])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE7]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE7);
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE8])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE8]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE8);
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE9])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE9]();
		EXTI_voidClearPendingFlag(EXTI_ENUM_LINE9);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE10])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE10]();
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE11])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE11]();
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE12])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE12]();
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE13])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE13]();
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE14])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE14]();
	}
	else if (NULLPTR!=EXTI_FptrArray[EXTI_ENUM_LINE15])
	{
		EXTI_FptrArray[EXTI_ENUM_LINE15]();
	}
}

