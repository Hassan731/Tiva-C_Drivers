/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_Ctrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *********************************************************************************************************************/
#ifndef SYS_CTRL_CFG_H
#define SYS_CTRL_CFG_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SYS_Ctrl_types.h"
#include "platform_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
    -MOSC_MAIN_OSCILLATOR_16_MHZ
    -PIOSC_PRECISION_INTERNAL_OSCILLATOR
    -PIOSC_4_PRECISION_INTERNALL_OSCILLATOR
    -LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR
*/
#define CLOCK_SOURCE    MOSC_MAIN_OSCILLATOR_16_MHZ
/*
    Available options:
    CRYSTAL_VALUE_4_MHz
    CRYSTAL_VALUE_4_096_MHz 
    CRYSTAL_VALUE_4_9152_MHz 
    CRYSTAL_VALUE_5_MHz_USB
    CRYSTAL_VALUE_5_12_MHz
    CRYSTAL_VALUE_6_MHz_USB
    CRYSTAL_VALUE_6_144_MHz
    CRYSTAL_VALUE_7_3728_MHz
    CRYSTAL_VALUE_8_MHz_USB
    CRYSTAL_VALUE_8_192_MHz
    CRYSTAL_VALUE_10_MHz_USB
    CRYSTAL_VALUE_12_MHz_USB
    CRYSTAL_VALUE_12_288_MHz
    CRYSTAL_VALUE_13_56_MHz
    CRYSTAL_VALUE_14_31818_MHz
    CRYSTAL_VALUE_16_MHz_USB
    CRYSTAL_VALUE_16_384_MHz
    CRYSTAL_VALUE_18_MHz_USB
    CRYSTAL_VALUE_20_MHz_USB
    CRYSTAL_VALUE_24_MHz_USB
    CRYSTAL_VALUE_25_MHz_USB
*/
#define CRYSTAL_VALUE       CRYSTAL_VALUE_16_MHz_USB
/*
    Available options:
    -RUN_MODE_CLOCK_CONTROL RCC
    -DEEP_SLEEP_MODE_CONTROL
*/
#define SLEEP_MODE_CONTROL   RUN_MODE_CLOCK_CONTROL

/*
    options:
        -ENABLE
        -DISABLE
*/
#define DIVIDER_STATE   ENABLE
#define PLL_STATE   ENABLE

#if DIVIDER_STATE == ENABLE
/*
    Available options:
    -SYSDIV_DIVISOR1__RESERVED
    -SYSDIV_DIVISOR2_RESERVED
    -SYSDIV_DIVISOR3_66_O_67MHZ
    -SYSDIV_DIVISOR4_50MHZ
    -SYSDIV_DIVISOR5_40MHZ
    -SYSDIV_DIVISOR6_33_O_33MHZ
    -SYSDIV_DIVISOR7_28_O_57MHZ
    -SYSDIV_DIVISOR8_25MHZ
    -SYSDIV_DIVISOR9_22_O_22MHZ
    -SYSDIV_DIVISOR10_20MHZ
    -SYSDIV_DIVISOR11_18_O_18MHZ
    -SYSDIV_DIVISOR12_16_O_67MHZ
    -SYSDIV_DIVISOR13_15_O_38MHZ
    -SYSDIV_DIVISOR14_14_O_29MHZ
    -SYSDIV_DIVISOR15_13_O_33MHZ
    -SYSDIV_DIVISOR16_12_O_5MHZ
*/
#define SSDIV_DIVISOR       SYSDIV_DIVISOR16_12_O_5MHZ
#endif

/*
    Available options:
    -DISABLE
    -ENABLE
*/
#define PWM_CLOCK_DIVISOR_STATE     DISABLE

#if PWM_CLOCK_DIVISOR_STATE == ENABLE

/*
    options:
    -PWM_CLOCK_DIVISOR_2
    -PWM_CLOCK_DIVISOR_4
    -PWM_CLOCK_DIVISOR_8
    -PWM_CLOCK_DIVISOR_16
    -PWM_CLOCK_DIVISOR_32
    -PWM_CLOCK_DIVISOR_64
*/
#define PWM_CLOCK_DIVISOR   PWM_CLOCK_DIVISOR_2
#endif
#endif  /* SCB_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SYS_Ctrl_Cfg.h
 *********************************************************************************************************************/
