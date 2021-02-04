/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: mohab
 */

#include "STDTYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"


void GPIO_voidSetPinDirection(GPIO_EnumPort_type Copy_EnumPortID, GPIO_EnumPin_type Copy_EnumPinID, GPIO_EnumPinMode_type Copy_EnumMode)
{
	/* Range Check */
	if ( (Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS) && (Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS) )
	{
		switch (Copy_EnumPortID)
		{
		case GPIO_ENUM_PORTA:
			/* LOW PORT */
			if (Copy_EnumPinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOA_CRL &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOA_CRL |=( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_EnumPinID-=8;
				GPIOA_CRH &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOA_CRH |= ( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
			}
		break;
		case GPIO_ENUM_PORTB:
			/* LOW PORT */
			if (Copy_EnumPinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOB_CRL &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOB_CRL |=( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_EnumPinID-=8;
				GPIOB_CRH &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOB_CRH |= ( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
			}
		break;
		case GPIO_ENUM_PORTC:
			/* LOW PORT */
			if (Copy_EnumPinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOC_CRL &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOC_CRL |= ( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_EnumPinID-=8;
				GPIOC_CRH &=~( ((u32)0b1111)<<(Copy_EnumPinID*4) );
				GPIOC_CRH |= ( ((u32)Copy_EnumMode)<<(Copy_EnumPinID*4) );
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

void GPIO_voidSetPinValue(GPIO_EnumPort_type Copy_EnumPortID, GPIO_EnumPin_type Copy_EnumPinID, GPIO_EnumPinMode_type Copy_EnumValue)
{
	/* Range Check */
	if ( (Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS) && (Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS) )
	{
		switch (Copy_EnumPortID)
		{
			case GPIO_ENUM_PORTA:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOA_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOA_BRR=(1<<Copy_EnumPinID);	break;
					default: /* Error */ break;
				}
			break;
			case GPIO_ENUM_PORTB:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOB_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOB_BRR=(1<<Copy_EnumPinID);	break;
					default: /* Error */ break;
				}
			break;
			case GPIO_ENUM_PORTC:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOC_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOC_BRR=(1<<Copy_EnumPinID);	break;
					default: /* Error */ break;
				}
			break;
			default: /* Error */ break;
		}
	}
}

u8 GPIO_u8GetPinValue(GPIO_EnumPort_type Copy_EnumPortID, GPIO_EnumPin_type Copy_EnumPinID)
{
	/* Local value to return the answer and init it to anything but ur answers */
	u8 Local_u8Value=5;
	/* Range Check */
	if ( (Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS) && (Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS) )
	{
		switch (Copy_EnumPortID)
		{
			case GPIO_ENUM_PORTA:	Local_u8Value=GET_BIT(GPIOA_IDR,Copy_EnumPinID);	break;
			case GPIO_ENUM_PORTB:	Local_u8Value=GET_BIT(GPIOB_IDR,Copy_EnumPinID);	break;
			case GPIO_ENUM_PORTC:	Local_u8Value=GET_BIT(GPIOC_IDR,Copy_EnumPinID);	break;
			default: /* Error */ break;
		}
	}
	else
	{
		/* Error */
	}
	return Local_u8Value;
}

void GPIO_voidSetPortDirection(GPIO_EnumPort_type Copy_EnumPortID, GPIO_EnumPinMode_type Copy_EnumMode)
{
	GPIO_EnumPin_type Local_EnumPin=GPIO_ENUM_PIN0;
	for ( ; Local_EnumPin < GPIO_ENUM_TOTAL_PINS; Local_EnumPin++)
	{
		GPIO_voidSetPinDirection(Copy_EnumPortID, Local_EnumPin, Copy_EnumMode);
	}
}

void GPIO_voidSetPortValue(GPIO_EnumPort_type Copy_EnumPortID, GPIO_EnumPinMode_type Copy_EnumValue)
{
	GPIO_EnumPin_type Local_EnumPin=0;
	for ( ; Local_EnumPin < GPIO_ENUM_TOTAL_PINS; Local_EnumPin++)
	{
		GPIO_voidSetPinValue(Copy_EnumPortID, Local_EnumPin, Copy_EnumValue);
	}
}
