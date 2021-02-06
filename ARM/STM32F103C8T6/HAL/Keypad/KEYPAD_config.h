/********************************************************************
* File : KEYPAD_config.h
*
* Author  : Mohab Ahmed
* Created : 06-Feb-21
*
********************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_ROW_1_PIN			GPIO_ENUM_PIN13		//OUTPUTs
#define KEYPAD_ROW_1_PORT			GPIO_ENUM_PORTC
#define KEYPAD_ROW_2_PIN			GPIO_ENUM_PIN14
#define KEYPAD_ROW_2_PORT			GPIO_ENUM_PORTC
#define KEYPAD_ROW_3_PIN			GPIO_ENUM_PIN15
#define KEYPAD_ROW_3_PORT			GPIO_ENUM_PORTC
#define KEYPAD_ROW_4_PIN			GPIO_ENUM_PIN0
#define KEYPAD_ROW_4_PORT			GPIO_ENUM_PORTA

#define KEYPAD_COL_1_PIN			GPIO_ENUM_PIN0		//INPUTs
#define KEYPAD_COL_1_PORT			GPIO_ENUM_PORTB
#define KEYPAD_COL_2_PIN			GPIO_ENUM_PIN1
#define KEYPAD_COL_2_PORT			GPIO_ENUM_PORTB
#define KEYPAD_COL_3_PIN			GPIO_ENUM_PIN10
#define KEYPAD_COL_3_PORT			GPIO_ENUM_PORTB
#define KEYPAD_COL_4_PIN			GPIO_ENUM_PIN11
#define KEYPAD_COL_4_PORT			GPIO_ENUM_PORTB


/* Choose from : for PORTs			Choose from : for PINs
	GPIO_ENUM_PORTA	                	GPIO_ENUM_PIN0
	GPIO_ENUM_PORTB                 	GPIO_ENUM_PIN1
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
#define KEYPAD_ROWS					4
#define KEYPAD_COLS					4

#endif /* KEYPAD_CONFIG_H_ */
