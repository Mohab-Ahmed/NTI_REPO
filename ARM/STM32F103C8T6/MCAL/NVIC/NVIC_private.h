/*
 * NVIC_private.h
 *
 *  Created on: Feb 7, 2021
 *      Author: mohab
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADD 			(0xE000E100)

/* NVIC Registers */
#define NVIC_ISER0 				(*(volatile u32*)(NVIC_BASE_ADD + 0x000 ))
#define NVIC_ISER1 				(*(volatile u32*)(NVIC_BASE_ADD + 0x004 ))

#define NVIC_ICER0				(*(volatile u32*)(NVIC_BASE_ADD + 0x080 ))
#define NVIC_ICER1 				(*(volatile u32*)(NVIC_BASE_ADD + 0x084 ))

#define NVIC_ISPR0 				(*(volatile u32*)(NVIC_BASE_ADD + 0x100 ))
#define NVIC_ISPR1 				(*(volatile u32*)(NVIC_BASE_ADD + 0x104 ))

#define NVIC_ICPR0 				(*(volatile u32*)(NVIC_BASE_ADD + 0x180 ))
#define NVIC_ICPR1 				(*(volatile u32*)(NVIC_BASE_ADD + 0x184 ))

#define NVIC_IABR0 				(*(volatile u32*)(NVIC_BASE_ADD + 0x200 ))
#define NVIC_IABR1 				(*(volatile u32*)(NVIC_BASE_ADD + 0x204 ))

#define NVIC_IPR 				((volatile u8*)(NVIC_BASE_ADD + 0x300 ))


#define GROUPS_16_SUB_0			(0x05FA0300)		//0x05FA is the key that must be written with the grouping u will do.
#define GROUPS_8_SUB_2			(0x05FA0400)
#define GROUPS_4_SUB_4			(0x05FA0500)
#define GROUPS_2_SUB_8			(0x05FA0600)
#define GROUPS_0_SUB_16			(0x05FA0700)

#endif /* NVIC_PRIVATE_H_ */
