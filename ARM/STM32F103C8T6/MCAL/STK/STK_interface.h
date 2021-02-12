/*
 * STK_Interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: mohab
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void STK_voidInit(void);
void STK_voidSetBusyWait_us(u32 Copy_u32us);	//polling on flag. aka our own delay function
void STK_voidSetBusyWait_ms(u32 Copy_u32ms);
void STK_voidIntervalSingle_ms(u16 Copy_u16ms, void (*ptr)(void));
void STK_voidIntervalPeriodic_ms(u16 Copy_u16ms, void (*ptr)(void));
void STK_voidStopInterval(void);
void STK_voidEnableSTK(void);
u32  STK_u32GetTime(void);
u32  STK_u32RemainingTime(void);

#endif /* STK_INTERFACE_H_ */
