/********************************************************************
* File : SEG_config.h
*
* Author  : Mohab Ahmed
* Created : 05-Feb-21
*
********************************************************************/

#ifndef SEG_CONFIG_H_
#define SEG_CONFIG_H_

#define SEG_MODE 				SEG_SINGLE				/* Choose from :
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

#define SEG_1_START_PIN  		1
#define SEG_2_START_PIN  		1						/* Choose from :
															0
															1
															2
															3
															4
															5
															6
															7
															8
															9
															10
															11
															12
															13
															14
															15 	   */



#elif (SEG_MODE==SEG_MULTIPLEXING)

#define SEG_1_PORT 				GPIO_ENUM_PORTA			/* Choose from :
															GPIO_ENUM_PORTA
															GPIO_ENUM_PORTB */

#define SEG_1_TYPE  			SEG_ANOD				/* Choose from :
															SEG_CATH
															SEG_ANOD */

#define SEG_1_START_PIN  		1						/* Choose from :
															0
															1
															2
															3
															4
															5
															6
															7
															8
															9
															10
															11
															12
															13
															14
															15 	   */

#define SEG_1_EN1  				GPIO_ENUM_PINB12
#define SEG_1_EN2  				GPIO_ENUM_PINB13

/* Choose from : for PORT A PINs        Choose from : for PORT B PINs        Choose from : for PORT B PINs
		GPIO_ENUM_PINA0                 	GPIO_ENUM_PINB0                  	 GPIO_ENUM_PINB13
		GPIO_ENUM_PINA1                 	GPIO_ENUM_PINB1                  	 GPIO_ENUM_PINB14
		GPIO_ENUM_PINA2                 	GPIO_ENUM_PINB2                  	 GPIO_ENUM_PINB15
		GPIO_ENUM_PINA3                 	GPIO_ENUM_PINB3
		GPIO_ENUM_PINA4                 	GPIO_ENUM_PINB4
		GPIO_ENUM_PINA5                 	GPIO_ENUM_PINB5
		GPIO_ENUM_PINA6                 	GPIO_ENUM_PINB6
		GPIO_ENUM_PINA7                 	GPIO_ENUM_PINB7
		GPIO_ENUM_PINA8                 	GPIO_ENUM_PINB8
		GPIO_ENUM_PINA9                 	GPIO_ENUM_PINB9
		GPIO_ENUM_PINA10                	GPIO_ENUM_PINB10
		GPIO_ENUM_PINA11                	GPIO_ENUM_PINB11
		GPIO_ENUM_PINA12                	GPIO_ENUM_PINB12
		GPIO_ENUM_PINA13                	GPIO_ENUM_PINB13
		GPIO_ENUM_PINA14                	GPIO_ENUM_PINB14
		GPIO_ENUM_PINA15 	            	GPIO_ENUM_PINB15 	*/

#endif

#endif /* SEG_CONFIG_H_ */
