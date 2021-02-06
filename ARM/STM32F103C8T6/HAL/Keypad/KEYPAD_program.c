/********************************************************************
* File : KEYPAD_program.c
*
* Author  : Mohab Ahmed
* Created : 06-Feb-21
*
********************************************************************/

#include "BIT_MATH.h"
#include "STDTYPES.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "GPIO_interface.h"



static const u8 KEYPAD_Au8keys[KEYPAD_ROWS][KEYPAD_COLS]={ 		{'1','2','3','/'},
																{'4','5','6','*'},
																{'7','8','9','-'},
																{'c','0','=','+'} };

static const u8 KEYPAD_Au8keysHEX[KEYPAD_ROWS][KEYPAD_COLS]={  	{'1','2','3','A'},
																{'4','5','6','B'},
																{'7','8','9','E'},
																{'c','0','=','F'} };


u8 KEYPAD_u8GetKey(void)
{
	u8 Local_u8Key=KEYPAD_NO_KEY;


	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_HIGH);

	/* ROW 1 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[0][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[0][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[0][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[0][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_HIGH);


	/* ROW 2 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[1][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[1][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[1][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[1][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_HIGH);


	/* ROW 3 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[2][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[2][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[2][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[2][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_HIGH);


	/* ROW 4 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[3][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[3][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[3][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keys[3][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_HIGH);

	return Local_u8Key;
}





u8 KEYPAD_u8GetKeyHEX(void)
{
	u8 Local_u8Key=KEYPAD_NO_KEY;


	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_HIGH);
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_HIGH);

	/* ROW 1 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[0][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[0][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[0][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[0][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_ENUM_HIGH);


	/* ROW 2 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[1][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[1][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[1][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[1][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_ENUM_HIGH);


	/* ROW 3 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[2][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[2][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[2][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[2][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_ENUM_HIGH);


	/* ROW 4 check all COLUMNS */
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_LOW);
	if (!GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[3][0];
		while(GPIO_u8GetPinValue(KEYPAD_COL_1_PORT, KEYPAD_COL_1_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[3][1];
		while(GPIO_u8GetPinValue(KEYPAD_COL_2_PORT, KEYPAD_COL_2_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[3][2];
		while(GPIO_u8GetPinValue(KEYPAD_COL_3_PORT, KEYPAD_COL_3_PIN));
	}
	else if (!GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN))
	{
		Local_u8Key=KEYPAD_Au8keysHEX[3][3];
		while(GPIO_u8GetPinValue(KEYPAD_COL_4_PORT, KEYPAD_COL_4_PIN));
	}
	GPIO_voidSetPinValue(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_ENUM_HIGH);

	return Local_u8Key;
}
