/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : RTOS stack           **********************/
/****************    SWC       : Timer0               *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef TIMER0_interface_H_

 #define TIMER0_interface_H_
 
	void TIMER0_voidInit(void);
	
	u8 TIMER0_u8OverFlowsetcallback(void(*copy_ptrvoidfunc)(void));
	
	u8 TIMER0_u8CompMatchsetcallback(void(*copy_ptrvoidfunc)(void));
	
	void TIMER0_voidSetPreload(u8 Copy_u8preload);
	
	
	
	
		
#endif