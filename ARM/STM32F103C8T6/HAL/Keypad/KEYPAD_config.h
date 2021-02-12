/********************************************************************
* File : KEYPAD_config.h
*
* Author  : Mohab Ahmed
* Created : 06-Feb-21
*
********************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_ROW_1_PIN			GPIO_ENUM_PINC13		//OUTPUTs
#define KEYPAD_ROW_2_PIN			GPIO_ENUM_PINC14
#define KEYPAD_ROW_3_PIN			GPIO_ENUM_PINC15
#define KEYPAD_ROW_4_PIN			GPIO_ENUM_PINA0

#define KEYPAD_COL_1_PIN			GPIO_ENUM_PINB0		//INPUTs
#define KEYPAD_COL_2_PIN			GPIO_ENUM_PINB1
#define KEYPAD_COL_3_PIN			GPIO_ENUM_PINB10
#define KEYPAD_COL_4_PIN			GPIO_ENUM_PINB11


/* Choose from : for PORT A PINs        Choose from : for PORT B PINs        Choose from : for PORT C PINs
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

#define KEYPAD_ROWS					4
#define KEYPAD_COLS					4

#endif /* KEYPAD_CONFIG_H_ */
