/*
 * STK_program.c
 *
 *  Created on: Feb 9, 2021
 *      Author: mohab
 */


#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "STK_config.h"
#include "STK_interface.h"
#include "STK_private.h"

static void (*STK_Fptr)(void) = NULLPTR;
static u8 STK_u8IntervalMode;

void STK_voidInit(void)
{
	/* STK CLK */
	#if STK_PRESCALLER	==	STK_AHB_DIV_BY_8
	/* AHB clock divided by 8 */
	STK -> CTRL = 0x00000000;
	#elif STK_PRESCALLER	==	STK_AHB
	/* STK Clock = AHB Clock */
	STK -> CTRL = 0x00000004;
	#else
		#error "Wrong Choice of SysTick CLK!"
	#endif

}

void STK_voidSetBusyWait_us(u32 Copy_u32us)
{
	/* Max value the timer can hold is 2^24=16777216/1000 */
	if (Copy_u32us<16777216)
	{
		/* Load Value */
		STK->VAL = 0;
		STK->LOAD = Copy_u32us;
		/* Enable timer */
		SET_BIT(STK->CTRL,ENABLE);
		/* Wait for flag, doing No operation */
		while(GET_BIT(STK->CTRL,COUNT_FLAG)==0)
		{
			asm("NOP");
		}
		/* Stop timer */
		CLR_BIT(STK->CTRL,ENABLE);
		STK->LOAD = 0;
		STK->VAL = 0;
	}
	else
	{
		/* Error */
	}
}

void STK_voidSetBusyWait_ms(u32 Copy_u32ms)
{
	u32 Local_u32NumRepeat=1;
	u32 Local_u32NumReminder=0;
	u32 i=0;
	/* Max value the timer can hold is 2^24=16777216/1000 to convert to ms = 16777 */
	if (Copy_u32ms>16777)
	{
		Local_u32NumRepeat=Copy_u32ms/16777;
		Local_u32NumReminder=Copy_u32ms%16777;
		Copy_u32ms=16777;
	}
	/* To convert to us since our CLK give use 1 count per 1 us */
	Copy_u32ms*=1000;
	/* Load Value */
	STK->VAL = 0;
	STK->LOAD = Copy_u32ms;
	/* Enable timer */
	SET_BIT(STK->CTRL,ENABLE);
	for (i = 0; i < Local_u32NumRepeat; i++)
	{
		/* Wait for flag, doing No operation */
		while(GET_BIT(STK->CTRL,COUNT_FLAG)==0)
		{
			asm("NOP");
		}
		/* Zeroing the flag */
		CLR_BIT(STK->CTRL,COUNT_FLAG);
	}
	/* Stop timer */
	CLR_BIT(STK->CTRL,ENABLE);
	STK->LOAD = 0;
	STK->VAL = 0;
	/* Check reminder if greater than 0 */
	if (Local_u32NumReminder>0)
	{
		Local_u32NumReminder*=1000;
		STK->LOAD = Local_u32NumReminder;
		SET_BIT(STK->CTRL,ENABLE);
		while(GET_BIT(STK->CTRL,COUNT_FLAG)==0)
		{
			asm("NOP");
		}
		CLR_BIT(STK->CTRL,ENABLE);
		STK->LOAD = 0;
		STK->VAL = 0;
	}
}

void STK_voidIntervalSingle_ms(u16 Copy_u16ms, void (*ptr)(void))
{
	/* Load Value */
	STK->VAL = 0;
	STK->LOAD = (u32)Copy_u16ms*1000;
	/* Set function pointer */
	STK_Fptr=ptr;
	/* Enable interrupts */
	SET_BIT(STK->CTRL,TICKINT);
	/* Set interrupts Mode */
	STK_u8IntervalMode=STK_SINGLE_INTERVAL;
	/* Enable timer */
	SET_BIT(STK->CTRL,ENABLE);
}

void STK_voidIntervalPeriodic_ms(u16 Copy_u16ms, void (*ptr)(void))
{
	/* Load Value */
	STK->VAL = 0;
	STK->LOAD = (u32)Copy_u16ms*1000;
	/* Set function pointer */
	STK_Fptr=ptr;
	/* Enable interrupts */
	SET_BIT(STK->CTRL,TICKINT);
	/* Set interrupts Mode */
	STK_u8IntervalMode=STK_PERIODIC_INTERVAL;
	/* Enable timer */
	SET_BIT(STK->CTRL,ENABLE);
}

void STK_voidStopInterval(void)
{
	/* Stop Timer */
	CLR_BIT( STK -> CTRL , ENABLE );
}

void STK_voidEnableSTK(void)
{
	/* Enable Timer */
	SET_BIT( STK -> CTRL , ENABLE );
}

u32 STK_u32GetCounts(void)
{
	u32 Local_u32Counts = 0;
	Local_u32Counts = (STK -> LOAD) - (STK -> VAL);
	return Local_u32Counts;
}

u32 STK_u32GetRemainingTime(void)
{
	u32 Local_u32Remaining = 0;
	Local_u32Remaining = STK -> VAL;
	return Local_u32Remaining;
}

void SysTick_Handler(void)
{
	if(STK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		/* Disable Interrupt */
		CLR_BIT( STK -> CTRL , TICKINT );
		/*		Stop Timer			*/
		CLR_BIT( STK -> CTRL , ENABLE );
		STK -> LOAD = 0;
		STK -> VAL = 0;
	}
	/* Call the desired function */
	STK_Fptr();
}
