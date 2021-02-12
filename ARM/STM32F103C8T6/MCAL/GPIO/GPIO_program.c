/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: mohab
 */

#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


void GPIO_voidSetPinDirection(GPIO_EnumPin_type Copy_EnumPinID, GPIO_EnumPinMode_type Copy_EnumMode)
{
	/* Range Check */
	if ( Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS )
	{
		GPIO_EnumPort_type Local_EnumPortID=GPIO_ENUM_PORTA+(Copy_EnumPinID/16);
		Copy_EnumPinID%=16;
		switch (Local_EnumPortID)
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

void GPIO_voidSetPinValue(GPIO_EnumPin_type Copy_EnumPinID, GPIO_EnumPinValue_type Copy_EnumValue)
{
	/* Range Check */
	if ( Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS )
	{
		GPIO_EnumPort_type Local_EnumPortID=GPIO_ENUM_PORTA+(Copy_EnumPinID/16);
		Copy_EnumPinID%=16;
		switch (Local_EnumPortID)
		{
			case GPIO_ENUM_PORTA:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOA_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOA_BRR=(1<<Copy_EnumPinID);	break;
				}
			break;
			case GPIO_ENUM_PORTB:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOB_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOB_BRR=(1<<Copy_EnumPinID);	break;
				}
			break;
			case GPIO_ENUM_PORTC:
				switch (Copy_EnumValue)
				{
					case GPIO_ENUM_HIGH:	GPIOC_BSRR=(1<<Copy_EnumPinID);	break;
					case GPIO_ENUM_LOW:		GPIOC_BRR=(1<<Copy_EnumPinID);	break;
				}
			break;
			default: /* Error */ break;
		}
	}
}

u8 GPIO_u8GetPinValue(GPIO_EnumPin_type Copy_EnumPinID)
{
	/* Local value to return the answer and init it to anything but ur answers */
	u8 Local_u8Value=5;
	/* Range Check */
	if ( Copy_EnumPinID<GPIO_ENUM_TOTAL_PINS )
	{
		GPIO_EnumPort_type Local_EnumPortID=GPIO_ENUM_PORTA+(Copy_EnumPinID/16);
		Copy_EnumPinID%=16;
		switch (Local_EnumPortID)
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
	/* Range Check */
	if ( Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS )
	{
		GPIO_EnumPin_type Local_EnumPin=(GPIO_PORT_PINS*Copy_EnumPortID);
		u8 Local_u8PinMax=(Local_EnumPin+GPIO_PORT_PINS);
		for ( ; Local_EnumPin < Local_u8PinMax; Local_EnumPin++)
		{
			GPIO_voidSetPinDirection(Local_EnumPin, Copy_EnumMode);
		}
	}
}

void GPIO_voidSETPortValue(GPIO_EnumPort_type Copy_EnumPortID, u16 Copy_u16Value)
{
	/* Range Check */
	if (Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS)
	{
		switch (Copy_EnumPortID)
		{
			case GPIO_ENUM_PORTA:	GPIOA_BSRR=Copy_u16Value;	break;
			case GPIO_ENUM_PORTB:	GPIOB_BSRR=Copy_u16Value;	break;
			case GPIO_ENUM_PORTC:	GPIOC_BSRR=Copy_u16Value;	break;
			default: /* Error */ break;
		}
	}
	else
	{
		/* Error */
	}
}

void GPIO_voidCLRPortValue(GPIO_EnumPort_type Copy_EnumPortID, u16 Copy_u16Value)
{
	/* Range Check */
	if (Copy_EnumPortID<GPIO_ENUM_TOTAL_PORTS)
	{
		switch (Copy_EnumPortID)
		{
			case GPIO_ENUM_PORTA:	GPIOA_BRR=Copy_u16Value;	break;
			case GPIO_ENUM_PORTB:	GPIOB_BRR=Copy_u16Value;	break;
			case GPIO_ENUM_PORTC:	GPIOC_BRR=Copy_u16Value;	break;
			default: /* Error */ break;
		}
	}
	else
	{
		/* Error */
	}
}
