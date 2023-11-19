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
**          FILE  : TestGpt.c
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

 *  V1.0    202221028               -           First Implementation


*******************************************************************************/





/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>

#include "Gpt.h"

#if 0 // Using MCAL GPT Interrupt TIMER
#include "TestGpt.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define MAX_TIMER               (10)
#define INVALID_GPT_ID          (0)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef enum
{
    GPT_STATE_FREE,
    GPT_STATE_BUSY,
    
    MAX_GPT_STATE
    
} GPT_STATE;

typedef enum
{
    GPT_ACT_STOP,
    GPT_ACT_START,
    
    MAX_GPT_ACT
    
} GPT_ACTION;

typedef struct
{
    GPT_ACTION m_nAct; // 0:stop, 1:start
    uint8 m_nId;
    uint32 m_nPeriodUs;
    GPT_MODE_E m_nMode; // 0:none, 1:oneshot, 2:continue
    GPT_STATE m_nBusy;
    uint32 m_nTicks; // 10us
    uint32 m_nMeasTicks; // Measurement time, 1tick*10us
    gptTimerCallFunc m_func;

} TIMER_T;

typedef struct
{
    uint64 m_nTicks; // 1tick = 10us
    uint8 m_nActId;
    GPT_STATE m_nBusy;

    uint8 m_nTimer;
    TIMER_T m_tTimer[MAX_TIMER];

} TESTGPT_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static TESTGPT_INSTANCE_T l_tTestGpt_Inst;



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#if 1 /* MCAL notification functions */
/*******************************************************************************
** Function Name    : IoHwAb_GptNotification0
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 1ms
**
*******************************************************************************/
void IoHwAb_GptNotification0(void)
{
    TestGpt_Notification();

} /*End of IoHwAb_GptNotification0 */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification1
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 3ms => 1ms
**
*******************************************************************************/
void IoHwAb_GptNotification1(void)
{
    TestGpt_Task();

} /*End of IoHwAb_GptNotification1 */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification2
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 2.5ms => 800us
**
*******************************************************************************/
void IoHwAb_GptNotification2(void)
{

} /*End of IoHwAb_GptNotification2 */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification3
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 1ms
**
*******************************************************************************/
void IoHwAb_GptNotification3(void)
{

} /*End of IoHwAb_GptNotification3 */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification4
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 50ms
**
*******************************************************************************/
void IoHwAb_GptNotification4(void)
{

} /*End of IoHwAb_GptNotification3 */
#endif

/*******************************************************************************
** Function Name    : TestGpt_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_Init(void)
{
    memset(&l_tTestGpt_Inst, 0U, sizeof(TESTGPT_INSTANCE_T));

} /*End of TestGpt_Init */

/*******************************************************************************
** Function Name    : TestGpt_Notification
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_Notification(void)
{
    uint8 nTimer = 0U;

    l_tTestGpt_Inst.m_nTicks++;

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if((l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == 0) || 
            (l_tTestGpt_Inst.m_tTimer[nTimer].m_nAct == GPT_ACT_STOP))
        {
            continue;
        }

        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nBusy == GPT_STATE_FREE)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nTicks++;
        }
    }
    
}/*End of TestGpt_Notification */

/*******************************************************************************
** Function Name    : TestGpt_Enable
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_Enable(void)
{
    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1);

    // 1tick = 10us, for TestGpt_Notification
    /* Start timer for system tick generation */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, GPT_TASK_TICK);
    
    // 1tick = 10us, for TestGpt_Task
    /* Start timer for system tick generation */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_1, GPT_TASK_TICK);
    
}/*End of TestGpt_Enable */

/*******************************************************************************
** Function Name    : TestGpt_Disable
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_Disable(void)
{
    /* Stop timer for system tick */
    Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_2);
    
}/*End of TestGpt_Disable */

/*******************************************************************************
** Function Name    : TestGpt_Task
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_Task(void)
{
    uint8 nTimer = 0U;
    uint64 nSTime = 0U;

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if((l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == 0) || 
            (l_tTestGpt_Inst.m_tTimer[nTimer].m_nAct == GPT_ACT_STOP))
        {
            continue;
        }
        
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nTicks >= l_tTestGpt_Inst.m_tTimer[nTimer].m_nPeriodUs)
        {
            l_tTestGpt_Inst.m_nActId = l_tTestGpt_Inst.m_tTimer[nTimer].m_nId;
            l_tTestGpt_Inst.m_nBusy = GPT_STATE_BUSY;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nBusy = GPT_STATE_BUSY;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nTicks = 0;
            nSTime = l_tTestGpt_Inst.m_nTicks;
            
            if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode != GPT_NONE)
            {
                if(l_tTestGpt_Inst.m_tTimer[nTimer].m_func != (void *)0)
                {
                    l_tTestGpt_Inst.m_tTimer[nTimer].m_func(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId);
                }
    
                // If mode is oneshot
                if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode == GPT_ONESHOT)
                {
                    l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode = GPT_NONE;
                }
            }
            
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nMeasTicks = (uint32)(l_tTestGpt_Inst.m_nTicks - nSTime);
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nBusy = GPT_STATE_FREE;
            l_tTestGpt_Inst.m_nBusy = GPT_STATE_FREE;
        }
    }

} /*End of TestGpt_Task */

/*******************************************************************************
** Function Name    : TestGpt_RegTimer
**
** Return Value     : None
**
** Parameter        : None
**
** Description      :
**
*******************************************************************************/
uint8 TestGpt_RegTimer(uint32 nPeriodUs, uint8 nMode, gptTimerCallFunc func)
{
    uint8 nTimer = 0U;

    if(l_tTestGpt_Inst.m_nTimer > MAX_TIMER)
    {
        return INVALID_GPT_ID;
    }
    
    if(TestGpt_RegTimer < 10) // 10us
    {
        return INVALID_GPT_ID;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == 0)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nId = (uint8)(nTimer + 1);
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nPeriodUs = (nPeriodUs/10);
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode = nMode;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_func = func;
            
            l_tTestGpt_Inst.m_nTimer++;
            
            return l_tTestGpt_Inst.m_tTimer[nTimer].m_nId;
        }
    }
    
    return INVALID_GPT_ID;
    
} /*End of TestGpt_RegTimer */

/*******************************************************************************
** Function Name    : TestGpt_ClrTimer
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_ClrTimer(uint8 nId)
{
    uint8 nTimer = 0U;

    if((nId == INVALID_GPT_ID) || (nId > MAX_TIMER))
    {
        return;
    }

    if(l_tTestGpt_Inst.m_nTimer == 0)
    {
        return;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == nId)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nId = 0;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nPeriodUs = 0;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode = GPT_NONE;
            l_tTestGpt_Inst.m_tTimer[nTimer].m_func = (void *)0;
            l_tTestGpt_Inst.m_nTimer--;
            return;
        }
    }
    
} /*End of TestGpt_ClrTimer */

/*******************************************************************************
** Function Name    : TestGpt_StartTimer
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_StartTimer(uint8 nId)
{
    uint8 nTimer = 0U;
    
    if((nId == INVALID_GPT_ID) || (nId > MAX_TIMER))
    {
        return;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == nId)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nAct = GPT_ACT_START;
            return;
        }
    }
    
} /*End of TestGpt_StartTimer */

/*******************************************************************************
** Function Name    : TestGpt_StopTimer
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_StopTimer(uint8 nId)
{
    uint32 nTimer = 0U;
    
    if((nId == INVALID_GPT_ID) || (nId > MAX_TIMER))
    {
        return;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == nId)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nAct = GPT_ACT_STOP;
            return;
        }
    }
    
} /*End of TestGpt_StopTimer */

/*******************************************************************************
** Function Name    : TestGpt_SetMode
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_SetMode(uint8 nId, uint8 nMode)
{
    uint32 nTimer = 0U;

    if((nId == INVALID_GPT_ID) || (nId > MAX_TIMER))
    {
        return;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == nId)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nMode = nMode;
            return;
        }
    }
    
} /*End of TestGpt_SetMode */

/*******************************************************************************
** Function Name    : TestGpt_SetPeriod
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestGpt_SetPeriod(uint8 nId, uint32 nPeriodUs)
{
    uint32 nTimer = 0U;

    if((nId == INVALID_GPT_ID) || (nId > MAX_TIMER))
    {
        return;
    }

    if(nPeriodUs < 10) // 10us
    {
        return;
    }

    for(nTimer = 0; nTimer < MAX_TIMER; nTimer++)
    {
        if(l_tTestGpt_Inst.m_tTimer[nTimer].m_nId == nId)
        {
            l_tTestGpt_Inst.m_tTimer[nTimer].m_nPeriodUs = (nPeriodUs/10);
            return;
        }
    }
    
} /*End of TestGpt_SetPeriod */

/*******************************************************************************
** Function Name    : TestGpt_GetTimestampMs
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 100000tick=1ms
**
*******************************************************************************/
uint32 TestGpt_GetTimestampMs(void)
{
    // 1tick = 10us
    uint32 iNow = (uint32)(l_tTestGpt_Inst.m_nTicks / 100000);

    return iNow;
    
} /*End of TestGpt_GetTimestampMs */

/*******************************************************************************
** Function Name    : TestGpt_GetTimestampUs
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick=10us
**
*******************************************************************************/
uint64 TestGpt_GetTimestampUs(void)
{
    // 1tick = 10us
    uint64 iNow = l_tTestGpt_Inst.m_nTicks;

    return iNow;
    
} /*End of TestGpt_GetTimestampMs */

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/

#endif

