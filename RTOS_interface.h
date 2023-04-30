/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : RTOS stack           **********************/
/****************    SWC       : RTOS                 *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/



#ifndef RTOS_interface_H_

 #define RTOS_interface_H_
 
	void RTOS_voidStart(void);
	
	void RTOS_voidCreateTask(u8 copy_u8priority,u16 copy_u16periodicity,void(*copy_PVTaskFunc)(void));

	void RTOS_SuspendTask(u8 copy_u8priority);

	void RTOS_ResumeTask(u8 copy_u8priority);

	void RTOS_DeleteTask(u8 copy_u8priority);

#endif
