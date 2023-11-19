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
**          FILE  : TestIcu.c
**
**       PROJECT  : BMS_STANDLAONE_TC375                                             
**
**        AUTHOR  : Hyun Kang
**
**       VERSION  : V1.0
**
**      PLATFORM  : Infineon Aurix 375TP                                         
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

 *  V1.0    20211105    YG.SON      -           First Implementation


*******************************************************************************/





/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>
#include "Icu_17_TimerIp.h"
#include "TestIcu.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    uint32 m_nPressurePeriod;
    uint16 m_nPressureDuty;
    uint32 m_nCrashPeriod;
    uint16 m_nCrashDuty;

} TESTICU_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void _DutyCycle(void);


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
TESTICU_INSTANCE_T l_tTestIcu_Inst;





/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestIcu_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestIcu_Init(void)
{
    memset(&l_tTestIcu_Inst, 0x00, sizeof(TESTICU_INSTANCE_T));

    Icu_17_TimerIp_StartSignalMeasurement(IcuConf_IcuChannel_IcuChannel_CRASH);
    Icu_17_TimerIp_StartSignalMeasurement(IcuConf_IcuChannel_IcuChannel_PRESSURE);

} /*End of TestIcu_Init */


/*******************************************************************************
** Function Name    : TestIcu_100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestIcu_100ms(void)
{
    _DutyCycle();

} /*End of TestIcu_100ms */

/*******************************************************************************
** Function Name    : TestIcu_GetValue
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestIcu_GetValue(uint8 *pData)
{
    if (pData == NULL)
        return;

    /* Pressure */
    pData[0] = (l_tTestIcu_Inst.m_nPressureDuty & 0x00FFU)  >> 0U;
    pData[1] = (l_tTestIcu_Inst.m_nPressureDuty & 0xFF00U)  >> 8U;

    /* Crash */
    pData[2] = (l_tTestIcu_Inst.m_nCrashDuty & 0x00FFU)     >> 0U;
    pData[3] = (l_tTestIcu_Inst.m_nCrashDuty & 0xFF00U)     >> 8U;

} /*End of TestIcu_100ms */





/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/


/*******************************************************************************
** Function Name    : _DutyCycle
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _DutyCycle(void)
{
    Icu_17_TimerIp_DutyCycleType tPressureDutyCycle, tCrashDutyCycle;

    uint32 nActiveTime;
    uint32 nPeriodTime;

    Icu_17_TimerIp_GetDutyCycleValues(IcuConf_IcuChannel_IcuChannel_CRASH, &tCrashDutyCycle);
    nActiveTime = (uint32)(tCrashDutyCycle.ActiveTime);
    nPeriodTime = (uint32)(tCrashDutyCycle.PeriodTime);
    l_tTestIcu_Inst.m_nCrashPeriod = nPeriodTime;
    l_tTestIcu_Inst.m_nCrashDuty = (uint16)(nActiveTime * 1000U / nPeriodTime);

    Icu_17_TimerIp_GetDutyCycleValues(IcuConf_IcuChannel_IcuChannel_PRESSURE, &tPressureDutyCycle);
    nActiveTime = (uint32)(tPressureDutyCycle.ActiveTime);
    nPeriodTime = (uint32)(tPressureDutyCycle.PeriodTime);
    l_tTestIcu_Inst.m_nPressurePeriod = nPeriodTime;
    l_tTestIcu_Inst.m_nPressureDuty = (uint16)(nActiveTime * 1000U / nPeriodTime);

} /*End of _DutyCycle */


