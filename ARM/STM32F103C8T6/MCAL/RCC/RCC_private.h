/*
 * RCC_private.h
 *
 *  Created on: Feb 2, 2021
 *      Author: mohab
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* RCC clock select in config.h */
#define	RCC_HSI					0
#define	RCC_HSE					1
#define	RCC_PLL					2

/* HSE clock source select in config.h */
#define	RCC_RC					0
#define	RCC_CRYSTAL				1

/* PLL clock source select in config.h */
#define RCC_HSI_DIVIDED_BY_2    0
#define RCC_HSE_DIVIDED_BY_2    1
#define RCC_HSE_FULL            2

/* PLL multiplier select in config.h */
#define RCC_PLL_MUL_2           0
#define RCC_PLL_MUL_3           1
#define RCC_PLL_MUL_4           2
#define RCC_PLL_MUL_5           3
#define RCC_PLL_MUL_6           4
#define RCC_PLL_MUL_7           5
#define RCC_PLL_MUL_8           6
#define RCC_PLL_MUL_9           7
#define RCC_PLL_MUL_10          8
#define RCC_PLL_MUL_11          9
#define RCC_PLL_MUL_12          10
#define RCC_PLL_MUL_13          11
#define RCC_PLL_MUL_14          12
#define RCC_PLL_MUL_15          13
#define RCC_PLL_MUL_16          14







/* Base Address for RCC */
#define RCC_BASE_ADD 		(0x40021000)

/* RCC Registers */
#define RCC_CR 				(*(volatile u32*)(RCC_BASE_ADD + 0x00 ))
#define RCC_CFGR 			(*(volatile u32*)(RCC_BASE_ADD + 0x04 ))
#define RCC_CIR				(*(volatile u32*)(RCC_BASE_ADD + 0x08 ))
#define RCC_APB2RSTR 		(*(volatile u32*)(RCC_BASE_ADD + 0x0C ))
#define RCC_APB1RSTR 		(*(volatile u32*)(RCC_BASE_ADD + 0x10 ))
#define RCC_AHBENR 			(*(volatile u32*)(RCC_BASE_ADD + 0x14 ))
#define RCC_APB2ENR 		(*(volatile u32*)(RCC_BASE_ADD + 0x18 ))
#define RCC_APB1ENR 		(*(volatile u32*)(RCC_BASE_ADD + 0x1C ))
#define RCC_BDCR 			(*(volatile u32*)(RCC_BASE_ADD + 0x20 ))
#define RCC_CSR 			(*(volatile u32*)(RCC_BASE_ADD + 0x24 ))

/* RCC_CR BITS */
#define HSION				0
#define HSIRDY				1
#define HSEON				16
#define HSERDY				17
#define HSEBYP				18
#define CSSON				19
#define PLLON				24
#define PLLRDY				25

/* RCC_CFGR BITS */
#define SW0					0
#define SW1					1
#define SWS0				2
#define SWS1				3
#define PLLSRC				16
#define PLLXTPRE			17
#define PLLMUL0				18

#endif /* RCC_PRIVATE_H_ */
