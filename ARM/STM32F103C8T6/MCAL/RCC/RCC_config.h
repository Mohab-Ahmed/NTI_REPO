/*
 * RCC_config.h
 *
 *  Created on: Feb 2, 2021
 *      Author: mohab
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#define CLK_TYPE 				RCC_HSI					 /* Choose from :
															RCC_HSI
															RCC_HSE
															RCC_PLL */

#if (CLK_TYPE==RCC_HSE)
#define RCC_HSE_SOURCE 			RCC_RC					 /* Choose from :
															RCC_RC
															RCC_CRYSTAL */

#elif (CLK_TYPE==RCC_PLL)
#define RCC_PLL_SOURCE 			RCC_HSE_FULL	 /* Choose from :
															 RCC_HSI_DIVIDED_BY_2
															 RCC_HSE_DIVIDED_BY_2
															 RCC_HSE_FULL */

#define RCC_PLL_MULTI 			RCC_PLL_MUL_2		 	/* Choose from :
															 RCC_PLL_MUL_2
															 RCC_PLL_MUL_3
															 RCC_PLL_MUL_4
															 RCC_PLL_MUL_5
															 RCC_PLL_MUL_6
															 RCC_PLL_MUL_7
															 RCC_PLL_MUL_8
															 RCC_PLL_MUL_9
															 RCC_PLL_MUL_10
															 RCC_PLL_MUL_11
															 RCC_PLL_MUL_12
															 RCC_PLL_MUL_13
															 RCC_PLL_MUL_14
															 RCC_PLL_MUL_15
															 RCC_PLL_MUL_16 */

#endif

#endif /* RCC_CONFIG_H_ */
