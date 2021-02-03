/*
 * RCC_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: mohab
 */


#include "STDTYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

#define TIMEOUT 				10000


void RCC_voidInit(void)
{
	u32 Local_u32TimeOut=0;
	#if (CLK_TYPE==RCC_HSI)
		/* HSI ON */
		SET_BIT(RCC_CR,HSION);
		/* Wait on HSI to be ready with polling and timeout */
		while(0==GET_BIT(RCC_CR,HSIRDY) && Local_u32TimeOut<TIMEOUT)
		{
			Local_u32TimeOut++;
		}
	#elif (CLK_TYPE==RCC_HSE)
		/* HSE ON */
		SET_BIT(RCC_CR,HSEON);
		/* System clock switch */
		SET_BIT(RCC_CFGR,SW0);
		CLR_BIT(RCC_CFGR,SW1);
		/* HSE bypass */
		#if (RCC_HSE_SOURCE==RCC_CRYSTAL)
			CLR_BIT(RCC_CR,HSEBYP);
		#elif (RCC_HSE_SOURCE==RCC_RC)
			SET_BIT(RCC_CR,HSEBYP);
		#endif
		/* Wait on HSE to be ready with polling and timeout */
		while(0==GET_BIT(RCC_CR,HSERDY) && Local_u32TimeOut<TIMEOUT)
		{
			Local_u32TimeOut++;
		}
		Local_u32TimeOut=0;
		/* Wait on System clock switch status bit 0 with polling and timeout */
		while(0==GET_BIT(RCC_CFGR,SWS0) && Local_u32TimeOut<TIMEOUT)
		{
			Local_u32TimeOut++;
		}
		Local_u32TimeOut=0;
		/* Wait on System clock switch status bit 1 with polling and timeout */
		while(1==GET_BIT(RCC_CFGR,SWS1) && Local_u32TimeOut<TIMEOUT)
		{
			Local_u32TimeOut++;
		}
	#elif (CLK_TYPE==RCC_PLL)
		/* PLL source select */
		#if (RCC_PLL_SOURCE==RCC_HSI_DIVIDED_BY_2)
			CLR_BIT(RCC_CFGR,PLLSRC);
		#elif (RCC_PLL_SOURCE==RCC_HSE_DIVIDED_BY_2)
			SET_BIT(RCC_CFGR,PLLSRC);
			SET_BIT(RCC_CFGR,PLLXTPRE);
		#elif (RCC_PLL_SOURCE==RCC_HSE_FULL)
			SET_BIT(RCC_CFGR,PLLSRC);
			CLR_BIT(RCC_CFGR,PLLXTPRE);
		#endif
		/* PLL multiplier select */
		RCC_CFGR&=~( ((u32)0b1111)<<PLLMUL0 );
		RCC_CFGR|= ( ((u32)RCC_PLL_MULTI)<<PLLMUL0 );
		/* PLL ON */
		SET_BIT(RCC_CR,PLLON);
		/* Wait on PLL to be ready with polling and timeout */
		while(0==GET_BIT(RCC_CR,PLLRDY) && Local_u32TimeOut<TIMEOUT)
		{
			Local_u32TimeOut++;
		}
	#else
		#error "Wrong clock selected!"
	#endif
}
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/* Range Check */
	if (Copy_u8PeripheralID<32)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB : 	SET_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1: 	SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID); 	break;
			case RCC_APB2: 	SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID); 	break;
			default: 	/* Error */ 	break;
		}
	}
	else
	{
		/* Error */
	}
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/* Range Check */
	if (Copy_u8PeripheralID<32)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB : 	CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1: 	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID); 	break;
			case RCC_APB2: 	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID); 	break;
			default: 	/* Error */ 	break;
		}
	}
	else
	{
		/* Error */
	}
}
