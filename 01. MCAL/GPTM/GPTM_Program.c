/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPTM.c
 *        \brief  GPTM Driver
 *
 *      \details  The driver enable GPTM modes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "tm4c123gh6pm_registers.h"
#include "GPT.h"
#include "bit_cal.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TIMERA_ENABLE_BIT 0
#define TIMER_A 0
#define TIMER_B 1
#define TIMER_COUNTING_DIRECTION_DOWN 0


/**********************************************************************************************************************
*  LOCAL DATA 
*********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static GPT_REGS_CONFIG *GPT_ARR[12] = {GPT0_16_32_BIT_REGS, GPT1_16_32_BIT_REGS,
                                       GPT2_16_32_BIT_REGS, GPT3_16_32_BIT_REGS,
                                       GPT4_16_32_BIT_REGS, GPT5_16_32_BIT_REGS,
                                       GPT0_32_64_WIDE_BIT_REGS, GPT1_32_64_WIDE_BIT_REGS,
                                       GPT2_32_64_WIDE_BIT_REGS, GPT3_32_64_WIDE_BIT_REGS,
                                       GPT4_32_64_WIDE_BIT_REGS, GPT5_32_64_WIDE_BIT_REGS};

static u32 gTimer_Counter = 0;
																			 
/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL FUNCTIONS
*********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void MGPT_Init(const GPT_ConfigType *ConfigPtr)                                     
* \Description     : initialize GPTM 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
																			 
void MGPT_Init(const GPT_ConfigType *ConfigPtr)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMCTL &= ~(1 << TIMERA_ENABLE_BIT);

    GPT_ARR[ConfigPtr->Channel_ID]->GPTMCFG = ConfigPtr->PredefTimerType;

    GPT_ARR[ConfigPtr->Channel_ID]->GPTMT_A_B_MR[TIMER_A] |= ConfigPtr->Channel_Mode;
}

/******************************************************************************
* \Syntax          : void MGPT_StartTimer(const GPT_ConfigType *ConfigPtr, Gpt_ValueType TargetTime)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MGPT_StartTimer(const GPT_ConfigType *ConfigPtr, Gpt_ValueType TargetTime)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMT_A_B_ILR[TIMER_A] = TargetTime;
    gTimer_Counter = TargetTime;
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMCTL |= (1 << TIMERA_ENABLE_BIT);
}

/******************************************************************************
* \Syntax          : void MGPT_StopTimer(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MGPT_StopTimer(const GPT_ConfigType *ConfigPtr)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMCTL &= ~(1 << TIMERA_ENABLE_BIT);
    gTimer_Counter = 0;
}

/******************************************************************************
* \Syntax          : void MGPT_EnableNotification(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MGPT_EnableNotification(const GPT_ConfigType *ConfigPtr)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMIMR |= 1;
}

/******************************************************************************
* \Syntax          : void MGPT_DisableNotification(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MGPT_DisableNotification(const GPT_ConfigType *ConfigPtr)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMIMR &=~ (1);
}


/******************************************************************************
* \Syntax          : u8 MGPT_HasFinished(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


u8 MGPT_HasFinished(const GPT_ConfigType *ConfigPtr)
{
    return (check_bit(GPT_ARR[ConfigPtr->Channel_ID]->GPTMRIS, 0));
}

/******************************************************************************
* \Syntax          : u32 MGPT_GetTimeElapsed(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

u32 MGPT_GetTimeElapsed(const GPT_ConfigType *ConfigPtr)
{
    return (gTimer_Counter - GPT_ARR[ConfigPtr->Channel_ID]->GPTMT_A_B_V[TIMER_A]);
}

/******************************************************************************
* \Syntax          : u32 MGPT_ClearFlag(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MGPT_ClearFlag(const GPT_ConfigType *ConfigPtr)
{
    GPT_ARR[ConfigPtr->Channel_ID]->GPTMICR |= 1;
}

/******************************************************************************
* \Syntax          : u32 MGPT_GetTimeRemaining(const GPT_ConfigType *ConfigPtr)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

u32 MGPT_GetTimeRemaining(const GPT_ConfigType *ConfigPtr)
{
    return gTimer_Counter - MGPT_GetTimeElapsed(ConfigPtr);
}


/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/

