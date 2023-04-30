/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : RTOS stack           **********************/
/****************    SWC       : RTOS                 *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include"GIE_interface.h"
#include "timer0_interface.h"

#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"

/* Global array of tasks in system */

task_t SystemTasks[TASK_NUM]={{NULL}};

void RTOS_voidStart(void)
{
	
	TIMER0_u8CompMatchsetcallback(&voidSchduler);
	
	GIE_voidEnable();
	
	TIMER0_voidInit();

}
	
void RTOS_voidCreateTask(u8 copy_u8priority,u16 copy_u16periodicity,void(*copy_PVTaskFunc)(void))
{
	
	SystemTasks[copy_u8priority].periodicity = copy_u16periodicity;
	SystemTasks[copy_u8priority].TaskFunc = copy_PVTaskFunc;
	SystemTasks[copy_u8priority].Task_State = TASK_RESUMED; // INIT task state
}

static void voidSchduler(void){
	
	static u16 Local_u16TickCounter = 0;
	u8 Local_u8TaskCounter;
	Local_u16TickCounter++;

    /* loop on all tasks to check their periodicity*/

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{

		if(SystemTasks[Local_u8TaskCounter].Task_State==TASK_RESUMED)
		{
			if((Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].periodicity)==0)
			{

				if(SystemTasks[Local_u8TaskCounter].TaskFunc!=NULL)
				{

					SystemTasks[Local_u8TaskCounter].TaskFunc();
				}
				else
				{
					// Do Nothing
				}

			}
		}
		else {

			/* Task is suspended*/
		}


	}

}

void RTOS_SuspendTask(u8 copy_u8priority)
{

	SystemTasks[copy_u8priority].Task_State=TASK_SUSPENDED;

}

void RTOS_ResumeTask(u8 copy_u8priority)
{

	SystemTasks[copy_u8priority].Task_State=TASK_RESUMED;

}


void RTOS_DeleteTask(u8 copy_u8priority)
{
	SystemTasks[copy_u8priority].TaskFunc=NULL;
}







