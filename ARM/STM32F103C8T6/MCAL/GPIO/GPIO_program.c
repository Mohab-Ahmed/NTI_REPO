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


void GPIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode)
{
	/* Range Check */
	if ( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch (Copy_u8PortID)
		{
		case GPIO_U8_PORTA:
			/* LOW PORT */
			if (Copy_u8PinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOA_CRL &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOA_CRL |=( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_u8PinID-=8;
				GPIOA_CRH &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOA_CRH |= ( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
		break;
		case GPIO_U8_PORTB:
			/* LOW PORT */
			if (Copy_u8PinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOB_CRL &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOB_CRL |=( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_u8PinID-=8;
				GPIOB_CRH &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOB_CRH |= ( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
		break;
		case GPIO_U8_PORTC:
			/* LOW PORT */
			if (Copy_u8PinID<8)
			{
				/* Bit masking means clear the bit/s then assign them */
				GPIOC_CRL &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOC_CRL |= ( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
			/* HIGH PORT */
			else
			{
				Copy_u8PinID-=8;
				GPIOC_CRH &=~( ((u32)0b1111)<<(Copy_u8PinID*4) );
				GPIOC_CRH |= ( ((u32)Copy_u8Mode)<<(Copy_u8PinID*4) );
			}
		break;
		}
	}
	else
	{
		/* Error */
	}
}

void GPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	/* Range Check */
	if ( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch (Copy_u8PortID)
		{
			case GPIO_U8_PORTA:
				switch (Copy_u8Value)
				{
					case GPIO_U8_HIGH:	SET_BIT(GPIOA_ODR,Copy_u8PinID);	break;
					case GPIO_U8_LOW:	CLR_BIT(GPIOA_ODR,Copy_u8PinID);	break;
					default: /* Error */ break;
				}
			break;
			case GPIO_U8_PORTB:
				switch (Copy_u8Value)
				{
					case GPIO_U8_HIGH:	SET_BIT(GPIOB_ODR,Copy_u8PinID);	break;
					case GPIO_U8_LOW:	CLR_BIT(GPIOB_ODR,Copy_u8PinID);	break;
					default: /* Error */ break;
				}
			break;
			case GPIO_U8_PORTC:
				switch (Copy_u8Value)
				{
					case GPIO_U8_HIGH:	SET_BIT(GPIOC_ODR,Copy_u8PinID);	break;
					case GPIO_U8_LOW:	CLR_BIT(GPIOC_ODR,Copy_u8PinID);	break;
					default: /* Error */ break;
				}
			break;
		}
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	/* Local value to return the answer and init it to anything but ur answers */
	u8 Local_u8Value=5;
	/* Range Check */
	if ( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch (Copy_u8PortID)
		{
			case GPIO_U8_PORTA:	Local_u8Value=GET_BIT(GPIOA_IDR,Copy_u8PinID);	break;
			case GPIO_U8_PORTB:	Local_u8Value=GET_BIT(GPIOB_IDR,Copy_u8PinID);	break;
			case GPIO_U8_PORTC:	Local_u8Value=GET_BIT(GPIOC_IDR,Copy_u8PinID);	break;
		}
	}
	else
	{
		/* Error */
	}
	return Local_u8Value;
}

void GPIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Mode)
{
	u8 Local_u8Pins=0;
	for (Local_u8Pins = 0; Local_u8Pins < 16; Local_u8Pins++)
	{
		GPIO_voidSetPinDirection(Copy_u8PortID, Local_u8Pins, Copy_u8Mode);
	}
}

void GPIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	u8 Local_u8Pins=0;
	for (Local_u8Pins = 0; Local_u8Pins < 16; Local_u8Pins++)
	{
		GPIO_voidSetPinValue(Copy_u8PortID, Local_u8Pins, Copy_u8Value);
	}
}

