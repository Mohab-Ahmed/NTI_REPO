/********************************************************************
* File : SEG_program.c
*
* Author  : Mohab Ahmed
* Created : 05-Feb-21
*
********************************************************************/

#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "SEG_private.h"
#include "SEG_config.h"
#include "SEG_interface.h"
#include "GPIO_interface.h"


#define DELAY_TIME_MS_MULTIPLEXING		10

static u8 SEG_Au8AnodeDEC[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
static u8 SEG_Au8AnodeHEX[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};


#if (SEG_MODE==SEG_SINGLE)						/********************** If SINGLE segments **********************/


void SEG_voidDisplayDEC(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num)
{
	/* Range Check */
	if (Copy_EnumSegNumber<SEG_ENUM_TOTAL )
	{
		switch (Copy_EnumSegNumber)
		{
			case SEG_ENUM_ONE:
			if (SEG_1_TYPE==SEG_ANOD)
			{
				GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_1_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_1_START_PIN ) );
			}
			else
			{
				GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_1_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_1_START_PIN ) );
			}
			break;
			case SEG_ENUM_TWO:
			if (SEG_2_TYPE==SEG_ANOD)
			{
				GPIO_voidSETPortValue(SEG_2_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_2_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_2_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_2_START_PIN ) );
			}
			else
			{
				GPIO_voidSETPortValue(SEG_2_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_2_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_2_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_2_START_PIN ) );
			}
			break;
			default: /* Error */ break;
		}
	}
	else
	{
		/* Error */
	}
}


void SEG_voidDisplayHEX(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num)
{
	/* Range Check */
	if (Copy_EnumSegNumber<SEG_ENUM_TOTAL )
	{
		switch (Copy_EnumSegNumber)
		{
			case SEG_ENUM_ONE:
			if (SEG_1_TYPE==SEG_ANOD)
			{
				GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_1_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_1_START_PIN ) );
			}
			else
			{
				GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_1_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_1_START_PIN ) );
			}
			break;
			case SEG_ENUM_TWO:
			if (SEG_2_TYPE==SEG_ANOD)
			{
				GPIO_voidSETPortValue(SEG_2_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_2_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_2_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_2_START_PIN ) );
			}
			else
			{
				GPIO_voidSETPortValue(SEG_2_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_2_START_PIN ) );
				GPIO_voidCLRPortValue(SEG_2_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_2_START_PIN ) );
			}
			default: /* Error */ break;
		}
	}
	else
	{
		/* Error */
	}
}

#elif (SEG_MODE==SEG_MULTIPLEXING)					/********************** If Multiplexing **********************/

static void Delay_ms(u32 Copy_u32Time)
{
	for (u32 i = 0; i < Copy_u32Time; i++)
	{
		for (u16 j = 0; j < 565; j++)
		{
			asm("NOP");
		}
	}
}

void SEG_voidDisplayDEC(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num)
{
	/* Range Check */
	if (Copy_EnumSegNumber<SEG_ENUM_TOTAL )
	{
		if (SEG_1_TYPE==SEG_ANOD)
		{
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_HIGH);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_LOW);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_LOW);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_HIGH);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num/10]  & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num/10]) & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
		}
		else
		{
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_LOW);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_HIGH);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num%10]) & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num%10]  & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_HIGH);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_LOW);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeDEC[Copy_u8Num/10]) & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeDEC[Copy_u8Num/10]  & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
		}
	}
	else
	{
		/* Error */
	}
}


void SEG_voidDisplayHEX(SEG_EnumNumber_type Copy_EnumSegNumber, u8 Copy_u8Num)
{
	/* Range Check */
	if (Copy_EnumSegNumber<SEG_ENUM_TOTAL )
	{
		if (SEG_1_TYPE==SEG_ANOD)
		{
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_HIGH);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_LOW);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_LOW);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_HIGH);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num/16]  & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num/16]) & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
		}
		else
		{
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_LOW);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_HIGH);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num%16]) & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num%16]  & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
			GPIO_voidSetPinValue(SEG_1_EN1, GPIO_ENUM_HIGH);
			GPIO_voidSetPinValue(SEG_1_EN2, GPIO_ENUM_LOW);
			GPIO_voidSETPortValue(SEG_1_PORT, (  ( (u16)(~SEG_Au8AnodeHEX[Copy_u8Num/16]) & 0x00FF ) << SEG_1_START_PIN ) );
			GPIO_voidCLRPortValue(SEG_1_PORT, (  ( (u16)  SEG_Au8AnodeHEX[Copy_u8Num/16]  & 0x00FF ) << SEG_1_START_PIN ) );
			Delay_ms(DELAY_TIME_MS_MULTIPLEXING);
		}
	else
	{
		/* Error */
	}
}

#endif
