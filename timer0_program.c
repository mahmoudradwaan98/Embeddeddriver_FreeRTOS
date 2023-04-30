/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan        **********************/
/****************    Layer     : RTOS stack            *********************/
/****************    SWC       : Timer0                ********************/
/****************    version   : 1.0                   *******************/
/****************    Date      : 21-3-2023            *******************/
/***********************************************************************/
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "timer0_config.h"
#include "timer0_private.h"
#include "timer0_interface.h"
#include "timer0_register.h"

/* Global pointer to function to hold the callback function address */
static void(*Timer0_PVOverFlowCallBackFunc)(void) = NULL;
static void(*Timer0_PVCompMatchCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void){
	
	/*Initialize Waveform generation mode to work as normal mode*/
	
	//CLR_BIT(TCCR0,TCCR0_WGM00);
	//CLR_BIT(TCCR0,TCCR0_WGM01);
	
	/*Initialize Waveform generation mode to work as CTC mode*/
	
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);	
	
	/*set the required preload*/
	
	//TCNT0 = TIMER0_u8PRELOAD_VAL;
	
	/*set the required compare match value*/
	
	OCR0 = TIMER0_u8COMP_MATCH_VAL;
	
	/*Timer0 overflow interrupt enable*/
	
	SET_BIT(TIMSK,TIMSK_TOIE0);
	
	/*Timer0 compare match interrupt enable*/
	
	SET_BIT(TIMSK,TIMSK_OCIE0);
	
	/* set the required prescaler */
	
	TCCR0 &=TIMER0_PRESCALER_MASK;
	TCCR0 |=TIMER0_u8PRESCALER;
	
}
	
u8 TIMER0_u8OverFlowsetcallback(void(*copy_ptrvoidfunc)(void)){
	u8 Local_u8ErrorState = OK;
	if(copy_ptrvoidfunc!=NULL){
		Timer0_PVOverFlowCallBackFunc = copy_ptrvoidfunc;
	}
	else{
		Local_u8ErrorState = NULLPOINTER;
	}
	return Local_u8ErrorState;
}

u8 TIMER0_u8CompMatchsetcallback(void(*copy_ptrvoidfunc)(void)){
		u8 Local_u8ErrorState = OK;
	if(copy_ptrvoidfunc!=NULL){
		
		Timer0_PVCompMatchCallBackFunc = copy_ptrvoidfunc;
	}
	else{
		
		Local_u8ErrorState = NULLPOINTER;
	}
	return Local_u8ErrorState;
}	
	
void TIMER0_voidSetPreload(u8 Copy_u8preload){
	TCNT0 = Copy_u8preload;
}

/* timer 0 overflow ISR */
void __vector_11(void)     __attribute__((signal));
void __vector_11(void){
	
	if(Timer0_PVOverFlowCallBackFunc!=NULL){
		Timer0_PVOverFlowCallBackFunc();
	}
	else{
		//do nothing
	}
	
}

/* timer 0 compare match ISR */

void __vector_10(void)     __attribute__((signal));
void __vector_10(void) {
	
	if(Timer0_PVCompMatchCallBackFunc!=NULL){
		Timer0_PVCompMatchCallBackFunc();
	}
	else{
		//do nothing
	}
	
	
}

















