#include "DIO_Interface.h"
#include "std_types.h"
#include "bit_cal.h"
#include "GPT.h"
#include "SYS_Ctrl.h"
#include "IntCtrl_Cfg.h"



															/* Set the Configurations */

static const GPT_ConfigType TIMER_0 = {CHANNEL_ID_0, GPT_MODE_PERIODIC,GPT_PREDEF_TIMER_1US_32BIT};
static const GPT_ConfigType TIMER_1 = {CHANNEL_ID_1, GPT_MODE_PERIODIC,GPT_PREDEF_TIMER_1US_32BIT};


															/* prototype for function */

void Time_by_Seconds(u8 On, u8 Off);
void Timer_0A_On_Led(void);
void Timer_1A_Off_Led(void);

															/* entry point of program */
int main(void)
{
	/* Initialize all drivers */
	
	MDIO_Init();
	SYSCTRL_Init();
  SYSCTRL_RCC_MODE(GPIO_16_32, MODULE_0);
  SYSCTRL_RCC_MODE(GPIO_16_32, MODULE_1);
	MGPT_Init(&TIMER_0);
  MGPT_Init(&TIMER_1);
	IntCrtl_Init();

    
	/* set pin direction */
	
	MDIO_SetPinDirection(PORTF, PINF2, OUTPUT);
	MDIO_SetPinDirection(PORTF, PINF0, INPUT);
	MDIO_SetPinDirection(PORTF, PINF4, INPUT);


	/* call function to take time */
	/* enter the time by seconds */
	
	
	/* Control blinking of an LED */
	
	while (1)
  {
		if( (MDIO_ReadPin(PORTF, PINF0) == 1) && (MDIO_ReadPin(PORTF, PINF4) == 1))
		{
			Time_by_Seconds(1, 1);
		}
		else if ( (MDIO_ReadPin(PORTF, PINF0) == 1) && (MDIO_ReadPin(PORTF, PINF4) == 0))
		{
			Time_by_Seconds(1, 2);
		}
		else if ( (MDIO_ReadPin(PORTF, PINF0) == 0) && (MDIO_ReadPin(PORTF, PINF4) == 1))
		{
			Time_by_Seconds(2, 1);
		}
		else if ( (MDIO_ReadPin(PORTF, PINF0) == 0) && (MDIO_ReadPin(PORTF, PINF4) == 0))
		{
			Time_by_Seconds(4, 4);
		}
		else
		{
			Time_by_Seconds(0, 0);
		}
		
		Timer_0A_On_Led();
    Timer_1A_Off_Led();
  }
	
	return 0;
}


 u32 Time_On = 0;  
 u32 Time_Off = 0; 

															/* Function to calculate time by seconds */

void Time_by_Seconds(u8 On, u8 Off)
{
    Time_On = (On *1) / (0.0000000625);
    Time_Off = (Off *1) / (0.0000000625);
}


void Timer_0A_On_Led()
{
    MGPT_ClearFlag(&TIMER_0);
    MDIO_WritePin(PORTF, PINF2, HIGH);
    MGPT_StartTimer(&TIMER_0, Time_On);


	while (MGPT_HasFinished(&TIMER_0)==0)//polling
    {  }
    MGPT_StopTimer(&TIMER_0);
    MGPT_ClearFlag(&TIMER_0); 
}



void Timer_1A_Off_Led()
{
    MGPT_ClearFlag(&TIMER_1); 
    MDIO_WritePin(PORTF, PINF2, LOW);
    MGPT_StartTimer(&TIMER_1, Time_Off);

    while (MGPT_HasFinished(&TIMER_1) ==0)//polling
    {  } 
    MGPT_StopTimer(&TIMER_1);
    MGPT_ClearFlag(&TIMER_1); 
}




