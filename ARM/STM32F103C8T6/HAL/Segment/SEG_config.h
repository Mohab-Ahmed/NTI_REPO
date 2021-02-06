/********************************************************************
* File : SEG_config.h
*
* Author  : Mohab Ahmed
* Created : 05-Feb-21
*
********************************************************************/

#ifndef SEG_CONFIG_H_
#define SEG_CONFIG_H_

#define SEG_MODE 				SEG_MULTIPLEXING				/* Choose from :
															SEG_SINGLE
															SEG_MULTIPLEXING */


#if (SEG_MODE==SEG_SINGLE)


#define SEG_1_PORT 				GPIO_ENUM_PORTA			/* Choose from :
															GPIO_ENUM_PORTA
															GPIO_ENUM_PORTB */

#define SEG_1_TYPE  			SEG_ANOD				/* Choose from :
															SEG_CATH
															SEG_ANOD */

#define SEG_2_PORT	 			GPIO_ENUM_PORTB			/* Choose from :
															GPIO_ENUM_PORTA
															GPIO_ENUM_PORTB */

#define SEG_2_TYPE  			SEG_ANOD				/* Choose from :
															SEG_CATH
															SEG_ANOD */

#define SEG_1_START_PIN  		GPIO_ENUM_PIN1
#define SEG_2_START_PIN  		GPIO_ENUM_PIN1			/* Choose from :
															GPIO_ENUM_PIN0
															GPIO_ENUM_PIN1
															GPIO_ENUM_PIN2
															GPIO_ENUM_PIN3
															GPIO_ENUM_PIN4
															GPIO_ENUM_PIN5
															GPIO_ENUM_PIN6
															GPIO_ENUM_PIN7
															GPIO_ENUM_PIN8
															GPIO_ENUM_PIN9
															GPIO_ENUM_PIN10
															GPIO_ENUM_PIN11
															GPIO_ENUM_PIN12
															GPIO_ENUM_PIN13
															GPIO_ENUM_PIN14
															GPIO_ENUM_PIN15 */

#elif (SEG_MODE==SEG_MULTIPLEXING)

#define SEG_1_PORT 				GPIO_ENUM_PORTA
#define SEG_1_EN1_PORT 			GPIO_ENUM_PORTB
#define SEG_1_EN2_PORT 			GPIO_ENUM_PORTB			/* Choose from :
															GPIO_ENUM_PORTA
															GPIO_ENUM_PORTB */

#define SEG_1_TYPE  			SEG_ANOD				/* Choose from :
															SEG_CATH
															SEG_ANOD */

#define SEG_1_START_PIN  		GPIO_ENUM_PIN1
#define SEG_1_EN1  				GPIO_ENUM_PIN12
#define SEG_1_EN2  				GPIO_ENUM_PIN13			/* Choose from :
															GPIO_ENUM_PIN0
															GPIO_ENUM_PIN1
															GPIO_ENUM_PIN2
															GPIO_ENUM_PIN3
															GPIO_ENUM_PIN4
															GPIO_ENUM_PIN5
															GPIO_ENUM_PIN6
															GPIO_ENUM_PIN7
															GPIO_ENUM_PIN8
															GPIO_ENUM_PIN9
															GPIO_ENUM_PIN10
															GPIO_ENUM_PIN11
															GPIO_ENUM_PIN12
															GPIO_ENUM_PIN13
															GPIO_ENUM_PIN14
															GPIO_ENUM_PIN15 */

#endif

#endif /* SEG_CONFIG_H_ */
