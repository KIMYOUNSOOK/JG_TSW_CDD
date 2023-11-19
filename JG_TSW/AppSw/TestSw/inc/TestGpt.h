/*******************************************************************************
**                                                                            **
** Copyright (C) Hyundai Mobis                                                **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Hyundai Mobis  **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**
**          FILE  : TestGpt.h
**
**       PROJECT  :                                              
**
**        AUTHOR  :
**
**       VERSION  :
**
**      PLATFORM  : Infineon Aurix 387                                         
**
**   DESCRIPTION  : 
**
*******************************************************************************/


/*******************************************************************************
**  Revision History                                                          **
********************************************************************************
 *  ----------------------------------------------------------------------------
 *  Version Date        Author      Change Id   Description
 *  ----------------------------------------------------------------------------

 *  V1.0    20221028                -           First Implementation


*******************************************************************************/





#ifndef TESTGPT_H
#define TESTGPT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"


#if 0 // Using MCAL GPT Interrupt TIMER
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
// 100000000 (1sec)
// 10000000 (100ms)
// 1000000 (10ms)
// 100000 (1ms)
// 10000 (100us)
// 1000 (10us)
// 100 (1us)
#define GPT_TASK_TICK         (1000) // 10us


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef void (*gptTimerCallFunc)(uint8 nId);


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
typedef enum
{
    GPT_NONE,
    GPT_ONESHOT,
    GPT_CONTINUE,

    MAX_GPT_MODE
    
}GPT_MODE_E;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void
    TestGpt_Init(void);
extern void
    TestGpt_Notification(void);
extern void
    TestGpt_Enable(void);
extern void
    TestGpt_Disable(void);
extern void 
    TestGpt_Task(void);
extern uint8 
    TestGpt_RegTimer(uint32 nPeriodUs, uint8 nMode, gptTimerCallFunc func);
extern void
    TestGpt_ClrTimer(uint8 nId);
extern void
    TestGpt_StartTimer(uint8 nId);
extern void
    TestGpt_StopTimer(uint8 nId);
extern void
    TestGpt_SetMode(uint8 nId, uint8 nMode);
extern void
    TestGpt_SetPeriod(uint8 nId, uint32 nPeriod);

#endif

#endif /* TESTGPT_H */

