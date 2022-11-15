/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  SysTick Timer Driver

 *      \details  The Driver Configure The 24-bit SysTick 
                  
 *             
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "bit_cal.h"
#include "SysTick.h"
#include "tm4c123gh6pm_registers.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/* Declaring a pointer to function For Callback Function */
void (*ISR_CALLBACK) (void);

/* Declaring Global variables */
u8  num_of_OV, rem_ticks;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

void SetTaskPeriodic(u32 time_ms, void (*copy_ptr)(void))
{
	// Declaring Variables
	u32 Total_Ticks;
	
	// Declaring a variable to hold Tick Time
	u8 tick_time;
	
	// put the address of the callback function in a Global pinter to function to call it in the ISR
	ISR_CALLBACK = copy_ptr;
	
	// Calculate Tick Time
	tick_time = 1 / ( 25000000 / 1000000);							// Result will be in micro-second
	
	Total_Ticks = ( time_ms * 1000 ) / tick_time; 					// Total Ticks for timer
	
	num_of_OV = Total_Ticks / 16777216;								// number of overflows needed to reach the time desired
		
	rem_ticks = Total_Ticks % 16777216;								// reminder ticks after overflows needed to reach the time desired
		
		
	if(rem_ticks != 0)
	{
		SYSTICK_RELOAD_REG = rem_ticks;								// if the remainder of overflows needed isn't zero, put the reminder ticks in counter register to be counted
		num_of_OV++;
	}
	
	// Load timer
	SYSTICK_RELOAD_REG = 0x00FFFFFF;
	
	SysTick_StartTimer();

}




/******************************************************************************
* \Syntax          : void TIMER0A_Handler()      
* \Description     : Timer0A_Hanler                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                     
*******************************************************************************/
void SysTick_Handler()
{
	  // Initialize a counter for overflows 
	static u32 counter;
	counter++;
	
	if(counter == num_of_OV)
	{
		// Call the function to be executed
		ISR_CALLBACK();
	
		counter = 0;
		SYSTICK_RELOAD_REG = rem_ticks;
	}
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void SysTick_Init(uint32 Ticks)       
* \Description     : SysTick Initialization                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Ticks : Upper bound Ticks                    
* \Parameters (out): None                                                      
* \Return value:   : None                               
*******************************************************************************/
void SysTick_Init(void)
{  
	// Make sure timer is not working
	clear_bit(SYSTICK_CTRL_REG, 0);
	
	// Enable Interrupt in Systick    /* note that you should enable it in NVIC too */
	set_bit(SYSTICK_CTRL_REG, 1);
	
	// Enable systick interrupt in NVIC
	set_bit(NVIC_EN0_REG, 15);  
	
	
	// SysTick works on system clock
	set_bit(SYSTICK_CTRL_REG, 2);
	
	// Making sure load register is empty at first
	SYSTICK_RELOAD_REG = 0;
	
	// Clear the count register
	SYSTICK_CURRENT_REG = 0;
	
}


/******************************************************************************
* \Syntax          : SysTick_StopTimer()       
* \Description     : Clear and Stop SysTick Timer                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                     
*******************************************************************************/

void SysTick_StartTimer(void) 
{
	set_bit(SYSTICK_CTRL_REG, 0);
   
}

void SysTick_StopTimer(void) 
{
   clear_bit(SYSTICK_CTRL_REG, 0);
}


/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
