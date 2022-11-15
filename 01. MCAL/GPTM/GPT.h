/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *  Description:  header file for IntCrtl Module
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************/
typedef enum
{
    CHANNEL_ID_0,
    CHANNEL_ID_1,
    CHANNEL_ID_2,
    CHANNEL_ID_3,
    CHANNEL_ID_4,
    CHANNEL_ID_5,
    CHANNEL_ID_6,
    CHANNEL_ID_7,
    CHANNEL_ID_8,
    CHANNEL_ID_9,
    CHANNEL_ID_10,
    CHANNEL_ID_11
} Gpt_ChannelID;

typedef enum
{
    GPT_MODE_ONE_SHOT = 1,
    GPT_MODE_PERIODIC, 
} Gpt_ModeType;


typedef u32 Gpt_ValueType;

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 4,
    GPT_PREDEF_TIMER_1US_24BIT = 4,
    GPT_PREDEF_TIMER_1US_32BIT = 0
} Gpt_PredefTimerType;

typedef struct
{
    Gpt_ChannelID Channel_ID;
    Gpt_ModeType Channel_Mode;
	  Gpt_PredefTimerType PredefTimerType;

} GPT_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void MGPT_Init(const GPT_ConfigType *ConfigPtr);

void MGPT_StartTimer(const GPT_ConfigType *ConfigPtr, Gpt_ValueType TargetTime);

void MGPT_StopTimer(const GPT_ConfigType *ConfigPtr);

void MGPT_EnableNotification(const GPT_ConfigType *ConfigPtr);

void MGPT_DisableNotification(const GPT_ConfigType *ConfigPtr);

u8 MGPT_HasFinished(const GPT_ConfigType *ConfigPtr);

u32 MGPT_GetTimeElapsed(const GPT_ConfigType *ConfigPtr);

u32 MGPT_GetTimeRemaining(const GPT_ConfigType *ConfigPtr);

void MGPT_ClearFlag(const GPT_ConfigType *ConfigPtr);


#endif /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
 