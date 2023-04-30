/*
 * app.c
 *
 *  Created on: Mar 21, 2023
 *      Author: User
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include"PORT_interface.h"
#include"DIO_interface.h"

#include"RTOS_interface.h"

void led1(void);
void led2(void);
void led3(void);

void main(void)
{


	PORT_voidInit();

	/* system tick is 1ms inside (ISR) = 1000 tick from you */

	RTOS_voidCreateTask(0,1000,&led1);
	RTOS_voidCreateTask(1,2000,&led1);
	RTOS_voidCreateTask(2,3000,&led1);

	RTOS_voidStart();
	while(1)
	{



	}

}

void led1(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN0,Local_u8LedState);
}

void led2(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN1,Local_u8LedState);

}

void led3(void)
{
	static u8 Local_u8LedState = 0;
	TOGGLE_BIT(Local_u8LedState,0);
	DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN2,Local_u8LedState);

}













