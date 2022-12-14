/*********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_CTRL_Types.h
 *       Module:  -
 *  Description:  <Write File DESCRIPTION here>
 *********************************************************************************************************************/
#ifndef SYS_CTRL_TYPES_H
#define SYS_CTRL_TYPES_H
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MOSC_MAIN_OSCILLATOR_16_MHZ 0
#define PIOSC_PRECISION_INTERNAL_OSCILLATOR 1
#define PIOSC_4_PRECISION_INTERNALL_OSCILLATOR 2
#define LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR 3
#define RUN_MODE_CLOCK_CONTROL 0
#define DEEP_SLEEP_MODE_CONTROL 1

typedef enum
{
    CRYSTAL_VALUE_4_MHz = 6,
    CRYSTAL_VALUE_4_096_MHz,
    CRYSTAL_VALUE_4_9152_MHz,
    CRYSTAL_VALUE_5_MHz_USB,
    CRYSTAL_VALUE_5_12_MHz,
    CRYSTAL_VALUE_6_MHz_USB,
    CRYSTAL_VALUE_6_144_MHz,
    CRYSTAL_VALUE_7_3728_MHz,
    CRYSTAL_VALUE_8_MHz_USB,
    CRYSTAL_VALUE_8_192_MHz,
    CRYSTAL_VALUE_10_MHz_USB,
    CRYSTAL_VALUE_12_MHz_USB,
    CRYSTAL_VALUE_12_288_MHz,
    CRYSTAL_VALUE_13_56_MHz,
    CRYSTAL_VALUE_14_31818_MHz,
    CRYSTAL_VALUE_16_MHz_USB,
    CRYSTAL_VALUE_16_384_MHz,
    CRYSTAL_VALUE_18_MHz_USB,
    CRYSTAL_VALUE_20_MHz_USB,
    CRYSTAL_VALUE_24_MHz_USB,
    CRYSTAL_VALUE_25_MHz_USB
} CRYSTAL_VALUE_CONFIG;

typedef enum
{
    SYSDIV_DIVISOR1__RESERVED,
    SYSDIV_DIVISOR2_RESERVED,
    SYSDIV_DIVISOR3_66_O_67MHZ,
    SYSDIV_DIVISOR4_50MHZ,
    SYSDIV_DIVISOR5_40MHZ,
    SYSDIV_DIVISOR6_33_O_33MHZ,
    SYSDIV_DIVISOR7_28_O_57MHZ,
    SYSDIV_DIVISOR8_25MHZ,
    SYSDIV_DIVISOR9_22_O_22MHZ,
    SYSDIV_DIVISOR10_20MHZ,
    SYSDIV_DIVISOR11_18_O_18MHZ,
    SYSDIV_DIVISOR12_16_O_67MHZ,
    SYSDIV_DIVISOR13_15_O_38MHZ,
    SYSDIV_DIVISOR14_14_O_29MHZ,
    SYSDIV_DIVISOR15_13_O_33MHZ,
    SYSDIV_DIVISOR16_12_O_5MHZ
} SYSDIV_DIVISOR;

typedef enum
{
    PWM_CLOCK_DIVISOR_2,
    PWM_CLOCK_DIVISOR_4,
    PWM_CLOCK_DIVISOR_8,
    PWM_CLOCK_DIVISOR_16,
    PWM_CLOCK_DIVISOR_32,
    PWM_CLOCK_DIVISOR_64
} PWM_CLOCK_DIVISOR_config;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
typedef enum
{
    WATCH_DOG_TIMER,
    GPIO_16_32,
    GPIO,
    MICRO_DIRECT_MEMORY_ACCESS,
    HIB = 5,
    UART,
    SSI,
    I2C,
    USB_SCB = 10,
    CAN = 13,
    ADC,
    ACMP,
    PWM,
    QEI,
    EEPROM = 22,
    WTIMER_32_64
} MODULE_NAME;

typedef enum
{
    MODULE_0,
    MODULE_1,
    MODULE_2,
    MODULE_3,
    MODULE_4,
    MODULE_5,
    MODULE_6,
    MODULE_7
} MODULE_INDEX;

#endif /* SYS_CTRL_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: SYS_CTRL_Types.h
 *********************************************************************************************************************/
