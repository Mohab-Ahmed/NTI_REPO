/*
 * NVIC_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: mohab
 */

#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"

/* Group offset to be used in priority function */
#if (NUM_GROUPS_AND_SUB==GROUPS_16_SUB_0)
#define GROUP_OFFSET			0
#elif (NUM_GROUPS_AND_SUB==GROUPS_8_SUB_2)
#define GROUP_OFFSET			1
#elif (NUM_GROUPS_AND_SUB==GROUPS_4_SUB_4)
#define GROUP_OFFSET			2
#elif (NUM_GROUPS_AND_SUB==GROUPS_2_SUB_8)
#define GROUP_OFFSET			3
#elif (NUM_GROUPS_AND_SUB==GROUPS_0_SUB_16)
#define GROUP_OFFSET			4
#endif

void NVIC_voidInit(void)
{
	/* Number of Groups and Sub Groups  SCB */
	#ifndef			SCB_AIRCR
	#define 		SCB_AIRCR 			(*(volatile u32*)(0xE000ED00 + 0x0C))
	#endif
	SCB_AIRCR = NUM_GROUPS_AND_SUB;
}

void NVIC_voidEnableInterrupt(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum)
{
	if(Copy_EnumInterruptNum < 32)
	{
		NVIC_ISER0 = ( 1 << Copy_EnumInterruptNum );
	}
	else if (Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		Copy_EnumInterruptNum -= 32;
		NVIC_ISER1 = ( 1 << Copy_EnumInterruptNum );
	}
	else
	{
		/* Error */
	}
}

void NVIC_voidDisableInterrupt(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum)
{
	if(Copy_EnumInterruptNum < 32)
	{
		NVIC_ICER0 = ( 1 << Copy_EnumInterruptNum );
	}
	else if (Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		Copy_EnumInterruptNum -= 32;
		NVIC_ICER1 = ( 1 << Copy_EnumInterruptNum );
	}
	else
	{
		/* Error */
	}
}

void NVIC_voidSetPendingFlag(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum)
{
	if(Copy_EnumInterruptNum < 32)
	{
		NVIC_ISPR0 = ( 1 << Copy_EnumInterruptNum );
	}
	else if (Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		Copy_EnumInterruptNum -= 32;
		NVIC_ISPR1 = ( 1 << Copy_EnumInterruptNum );
	}
	else
	{
		/* Error */
	}
}

void NVIC_voidClearPendingFlag(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum)
{
	if(Copy_EnumInterruptNum < 32)
	{
		NVIC_ICPR0 = ( 1 << Copy_EnumInterruptNum );
	}
	else if (Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		Copy_EnumInterruptNum -= 32;
		NVIC_ICPR1 = ( 1 << Copy_EnumInterruptNum );
	}
	else
	{
		/* Error */
	}
}

u8	 NVIC_u8GetActiveFlag(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum)
{
	u8 Local_u8Active = 0xFF;		//initialized to a meaningless value
	if(Copy_EnumInterruptNum < 32)
	{
		Local_u8Active = GET_BIT(NVIC_IABR0,Copy_EnumInterruptNum);
	}
	else if (Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		Copy_EnumInterruptNum -= 32;
		Local_u8Active = GET_BIT(NVIC_IABR1,Copy_EnumInterruptNum);
	}
	else
	{
		/* Error */
	}
	return Local_u8Active;
}

void NVIC_voidSetPriority(NVIC_EnumPeripheralPosition_type Copy_EnumInterruptNum , NVIC_EnumPriorityGroupNum_type Copy_EnumGroupPriority, NVIC_EnumPrioritySubNum_type Copy_EnumGSubPriority)
{
	if(Copy_EnumInterruptNum < NVIC_ENUM_TOTAL_PERIPHERALS)
	{
		/* Bits From 4 : 7 */
		NVIC_IPR[Copy_EnumInterruptNum] = ( ( (Copy_EnumGroupPriority<<GROUP_OFFSET)|(Copy_EnumGSubPriority>>GROUP_OFFSET) ) <<4);
	}
	else
	{
		/* Error */
	}
}
