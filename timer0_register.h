/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : RTOS stack           **********************/
/****************    SWC       : Timer0               *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef Timer0_register_H_

 #define Timer0_register_H_ 

	#define TCCR0               *((volatile u8*)0x53)   /* Timer 0 control REGISTER */
	
	#define TCCR0_WGM00         6                        /* waveform generation mode Bit 0 */
	#define TCCR0_WGM01         3                       /* waveform generation mode Bit 1 */
	
	#define TCCR0_CS02          2                       /* prescaler Bit 2 */
	#define TCCR0_CS01          1                       /* prescaler Bit 1 */
	#define TCCR0_CS00          0                        /* prescaler Bit 0 */
	
	#define OCR0                *((volatile u8*)0x5C)  /* Output compare REGISTER 0 */
	
	#define TIMSK               *((volatile u8*)0x5C)  /* Timer Mask */
	
	#define TIMSK_OCIE0         1                       /* Output compare 0 Interrupt Enable */ 
	
    #define TCNT0               *((volatile u8*)0x52)

	#define TIMSK_TOIE0         0
	
	
#endif
