/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SYS_Ctrl.c
 *        \brief
 *
 *      \details
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "bit_cal.h"
#include "platform_types.h"
#include "tm4c123gh6pm_registers.h"
#include "SYS_Ctrl_types.h"
#include "SYS_Ctrl_Cfg.h"
#include "SYS_Ctrl.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void SYSCTRL_Init(void)
{
#if CLOCK_SOURCE == MOSC_MAIN_OSCILLATOR_16_MHZ
	
    SYS_CTRL_RCC_REG->B.MOSCDIS = 0;
    SYS_CTRL_RCC_REG->R = 0x000000000;
    SYS_CTRL_RCC_REG->B.OSCSRC = 0;
	


    SYS_CTRL_RCC_REG->B.XTAL = CRYSTAL_VALUE;

  
    SYS_CTRL_MOSCCTL_REG |= 1;

  
    SYS_CTRL_MOSCCTL_REG &= ~(1 << 2);

#elif CLOCK_SOURCE == PIOSC_PRECISION_INTERNAL_OSCILLATOR
    SYS_CTRL_RCC_REG->B.OSCSRC = 1;
#elif CLOCK_SOURCE == PIOSC_4_PRECISION_INTERNALL_OSCILLATOR
    SYS_CTRL_RCC_REG->B.OSCSRC = 2;
#elif CLOCK_SOURCE == LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR
    SYS_CTRL_RCC_REG->B.OSCSRC = 3;
#endif

#if PLL_STATE == ENABLE

    SYS_CTRL_RCC_REG->B.PWRDN = 0;
    SYS_CTRL_RCC_REG->B.BYPASS = 0;

#elif PLL_STATE == DISABLE

    SYS_CTRL_RCC_REG->B.BYPASS = 1;
    SYS_CTRL_RCC_REG->B.PWRDN = 1;

#endif

    SYS_CTRL_RCC_REG->B.USESYSDIV = DIVIDER_STATE;
    SYS_CTRL_RCC_REG->B.SYSDIV = SSDIV_DIVISOR;

    SYS_CTRL_RCC_REG->B.ACG = SLEEP_MODE_CONTROL;
		
		
}

void SYSCTRL_RCC_MODE(MODULE_NAME name, MODULE_INDEX index)
{
    SYS_CTRL_REGS->SYS_CTRL_RCC[name] |= (1 << index);
}

/**********************************************************************************************************************
 *  END OF FILE: SYS_Ctrl.c
 *********************************************************************************************************************/
