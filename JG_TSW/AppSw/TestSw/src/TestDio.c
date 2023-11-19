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
**          FILE  : TestDio.c
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
#include "Dio.h"
#include "TestDio.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    boolean m_bIg1;
    boolean m_bWuSolar;
    boolean m_bOpdSig;
    boolean m_bWuPressure;
    boolean m_bWuAcc;
    boolean m_bWuMCan;
#if 1 // CAN-IG, MCAN
    boolean m_bMcanErr;
#endif

} INPUT_T;

typedef struct
{
    boolean m_bVlinEn;
    boolean m_bPwrOff;
#if 1 // CAN-IG, MCAN
    boolean m_bMcanEn;
    boolean m_bMcanStb;
#endif
    boolean m_bRegWdi;
    boolean m_bIsoPosEn;
    boolean m_bIsoNegEn;
    boolean m_bRlyDiagSel0;
    boolean m_bRlyDiagSel1;
    boolean m_bRlyQcPlus;
    boolean m_bRlyMainMinus;
    boolean m_bRlyDiagEn;
    boolean m_bRlyPressure;
    boolean m_bRlyPrecharger;
    boolean m_bRly2QcMinus;
    boolean m_bRly2MainPlus;
    boolean m_bRly2WuExt2Res;
    boolean m_bRly2DiagEn;
    boolean m_bRly2Heat;
    boolean m_bRly2DiagSel0;
    boolean m_bRly2DiagSel1;
    boolean m_bMcuSmufsp;
    boolean m_bCurrent1SenEn;
    boolean m_bCurrent2SenEn;

    boolean m_bVgate1N;
    boolean m_bVgate1P;

} OUTPUT_T;

typedef struct
{
    INPUT_T m_tInput;
    OUTPUT_T m_tOutput;

} TESTDIO_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void _Read(void);
static void _Write(void);


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
TESTDIO_INSTANCE_T l_tTestDio_Inst;





/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestDio_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestDio_Init(void)
{
    memset(&l_tTestDio_Inst, 0U, sizeof(TESTDIO_INSTANCE_T));

    // Active High
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel1 = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel0 = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2Heat = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2MainPlus = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel0 = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyQcPlus = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyMainMinus = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagEn = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyPrecharger = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRlyPressure = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel1 = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagEn = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2QcMinus = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bRly2WuExt2Res = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bCurrent2SenEn = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bCurrent1SenEn = STD_LOW;
    l_tTestDio_Inst.m_tOutput.m_bMcuSmufsp = STD_LOW;
    
    _Write();

    l_tTestDio_Inst.m_tOutput.m_bPwrOff = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_PMIC_POWER_OFF,
        l_tTestDio_Inst.m_tOutput.m_bPwrOff);

    l_tTestDio_Inst.m_tOutput.m_bRegWdi = STD_HIGH;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_PMIC_WDI,
        l_tTestDio_Inst.m_tOutput.m_bRegWdi);

    l_tTestDio_Inst.m_tOutput.m_bVlinEn = STD_HIGH;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_VLIN_EN, 
        l_tTestDio_Inst.m_tOutput.m_bVlinEn);

    l_tTestDio_Inst.m_tOutput.m_bIsoPosEn = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_ISO_POS_EN,
        l_tTestDio_Inst.m_tOutput.m_bIsoPosEn);

    l_tTestDio_Inst.m_tOutput.m_bIsoNegEn = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_ISO_NEG_EN,
        l_tTestDio_Inst.m_tOutput.m_bIsoNegEn);

    l_tTestDio_Inst.m_tOutput.m_bVgate1N = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_VGATE1N,
        l_tTestDio_Inst.m_tOutput.m_bVgate1N);
        
    l_tTestDio_Inst.m_tOutput.m_bVgate1P = STD_LOW;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_VGATE1P,
        l_tTestDio_Inst.m_tOutput.m_bVgate1P);
        
    /* Read */
    _Read();

    /* Initialize the PortPinLevelValue   */

#if 1 // CAN-IG, MCAN
    /* MCAN Enable Low => High */
    TestDio_CtrlMcanEn(STD_LOW);

    /* MCAN Standby Low */
    TestDio_CtrlMcanStandby(STD_LOW);
#endif

} /*End of TestDio_Init */

/*******************************************************************************
** Function Name    : TestDio_100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestDio_100ms(void)
{
    _Write();
    _Read();

} /*End of DioHal_100ms */

/*******************************************************************************
** Function Name    : TestDio_SetValue
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
void TestDio_SetValue(const uint8 *pData)
{
    if (pData == NULL)
        return;

    l_tTestDio_Inst.m_tOutput.m_bPwrOff         = (pData[0] & 0x01U) >> 0U;
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel1    = (pData[0] & 0x02U) >> 1U;
    l_tTestDio_Inst.m_tOutput.m_bRlyQcPlus      = (pData[0] & 0x04U) >> 2U;
    l_tTestDio_Inst.m_tOutput.m_bRlyMainMinus   = (pData[0] & 0x08U) >> 3U;
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagEn      = (pData[0] & 0x10U) >> 4U;
    l_tTestDio_Inst.m_tOutput.m_bRlyPrecharger  = (pData[0] & 0x20U) >> 5U;
    l_tTestDio_Inst.m_tOutput.m_bRlyPressure    = (pData[0] & 0x40U) >> 6U;
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel0    = (pData[0] & 0x80U) >> 7U;
    
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagEn     = (pData[1] & 0x01U) >> 0U;
    l_tTestDio_Inst.m_tOutput.m_bRly2Heat       = (pData[1] & 0x02U) >> 1U;
    l_tTestDio_Inst.m_tOutput.m_bRly2MainPlus   = (pData[1] & 0x04U) >> 2U;
    l_tTestDio_Inst.m_tOutput.m_bRly2QcMinus    = (pData[1] & 0x08U) >> 3U;
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel0   = (pData[1] & 0x10U) >> 4U;
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel1   = (pData[1] & 0x20U) >> 5U;
    l_tTestDio_Inst.m_tOutput.m_bRly2WuExt2Res  = (pData[1] & 0x40U) >> 6U;
    l_tTestDio_Inst.m_tOutput.m_bMcuSmufsp      = (pData[1] & 0x80U) >> 7U;
    
    l_tTestDio_Inst.m_tOutput.m_bCurrent1SenEn  = (pData[2] & 0x01U) >> 0U;
    l_tTestDio_Inst.m_tOutput.m_bCurrent2SenEn  = (pData[2] & 0x02U) >> 1U;

} /*End of TestDio_SetValue */

/*******************************************************************************
** Function Name    : TestDio_GetValue
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
void TestDio_GetValue(uint8 *pData)
{
    if (pData == NULL)
        return;

    /* Input Direction DIO */
    pData[0] = 
        (l_tTestDio_Inst.m_tInput.m_bWuMCan             << 7U) |
        (l_tTestDio_Inst.m_tInput.m_bWuAcc              << 6U) |
        (l_tTestDio_Inst.m_tInput.m_bWuPressure         << 5U) |    
        (l_tTestDio_Inst.m_tInput.m_bIg1                << 4U) |
        (l_tTestDio_Inst.m_tInput.m_bWuSolar            << 3U) |
        (l_tTestDio_Inst.m_tInput.m_bOpdSig             << 2U) |
#if 1 // CAN-IG, MCAN
        (l_tTestDio_Inst.m_tInput.m_bMcanErr            << 1U);
#endif

    /* Output Direction DIO */
    pData[1] = 
        (l_tTestDio_Inst.m_tOutput.m_bVlinEn            << 7U) |
        (l_tTestDio_Inst.m_tOutput.m_bPwrOff            << 6U) |
        (l_tTestDio_Inst.m_tOutput.m_bRegWdi            << 5U) |
        (l_tTestDio_Inst.m_tOutput.m_bIsoPosEn          << 4U) |
        (l_tTestDio_Inst.m_tOutput.m_bIsoNegEn          << 3U) |
        (l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel0      << 2U) |
        (l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel1      << 1U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyQcPlus         << 0U);
        
    pData[2] = 
        (l_tTestDio_Inst.m_tOutput.m_bRly2QcMinus       << 7U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyMainMinus      << 6U) |
        (l_tTestDio_Inst.m_tOutput.m_bRly2MainPlus      << 5U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyDiagEn         << 4U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyPressure       << 3U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyPrecharger     << 2U) |
        (l_tTestDio_Inst.m_tOutput.m_bRly2WuExt2Res     << 1U) |
        (l_tTestDio_Inst.m_tOutput.m_bRly2DiagEn        << 0U);
        
    pData[3] =
#if 1 // CAN-IG, MCAN, CANdb
        (l_tTestDio_Inst.m_tOutput.m_bMcanStb           << 7U) |
        (l_tTestDio_Inst.m_tOutput.m_bMcanEn            << 6U) |
#endif
        (l_tTestDio_Inst.m_tOutput.m_bRly2Heat          << 5U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel0       << 4U) |
        (l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel1       << 3U) |
        (l_tTestDio_Inst.m_tOutput.m_bMcuSmufsp         << 2U) |
        (l_tTestDio_Inst.m_tOutput.m_bCurrent1SenEn     << 1U) |
        (l_tTestDio_Inst.m_tOutput.m_bCurrent2SenEn     << 0U);

} /*End of TestDio_GetValue */

/*******************************************************************************
** Function Name    : TestDio_GetIg1
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
boolean TestDio_GetIg1(void)
{
    l_tTestDio_Inst.m_tInput.m_bIg1 = Dio_ReadChannel(DioConf_DioChannel_DioChannel_IG1_WUP);
    return l_tTestDio_Inst.m_tInput.m_bIg1;

} /*End of TestDio_GetIg1 */

/*******************************************************************************
** Function Name    : TestDio_GetAccWup
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
boolean TestDio_GetAccWup(void)
{
    l_tTestDio_Inst.m_tInput.m_bWuAcc = Dio_ReadChannel(DioConf_DioChannel_DioChannel_ACC_WUP);
    return l_tTestDio_Inst.m_tInput.m_bWuAcc;

} /*End of DioHal_GetAccWup */

/*******************************************************************************
** Function Name    : TestDio_GetSolarWup
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
boolean TestDio_GetSolarWup(void)
{
    l_tTestDio_Inst.m_tInput.m_bWuSolar = Dio_ReadChannel(DioConf_DioChannel_DioChannel_SOLAR_WUP);
    return l_tTestDio_Inst.m_tInput.m_bWuSolar;

} /*End of DioHal_GetLdcWup */

/*******************************************************************************
** Function Name    : TestDio_GetPressureWup
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
boolean TestDio_GetPressureWup(void)
{
    l_tTestDio_Inst.m_tInput.m_bWuPressure = Dio_ReadChannel(DioConf_DioChannel_DioChannel_PRESSURE_WUP);
    return l_tTestDio_Inst.m_tInput.m_bWuPressure;

} /*End of DioHal_GetLdcWup */

/*******************************************************************************
** Function Name    : TestDio_GetMCanWup
**
** Return Value     : None
**
** Parameter        : #1(uint8 *)pData
**
** Description      : None
**
*******************************************************************************/
boolean TestDio_GetMCanWup(void)
{
    l_tTestDio_Inst.m_tInput.m_bWuMCan = Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCAN_WUP);
    return l_tTestDio_Inst.m_tInput.m_bWuMCan;

} /*End of TestDio_GetMCanWup */

/*******************************************************************************
** Function Name    : TestDio_SetPwrOff
**
** Return Value     : None
**
** Parameter        : #1(uint8)bLevel
**
** Description      : None
**
*******************************************************************************/
void TestDio_SetPwrOff(boolean bLevel)
{
    l_tTestDio_Inst.m_tOutput.m_bPwrOff = bLevel;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_PMIC_POWER_OFF,
        l_tTestDio_Inst.m_tOutput.m_bPwrOff);

} /*End of TestDio_SetPwrOff */

#if 1 // CAN-IG, MCAN
/*******************************************************************************
** Function Name    : TestDio_CtrlMcanEn
**
** Return Value     : None
**
** Parameter        : #1(uint8)bLevel
**
** Description      : None
**
*******************************************************************************/
void TestDio_CtrlMcanEn(boolean bLevel)
{
    l_tTestDio_Inst.m_tOutput.m_bMcanEn = bLevel;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_MCAN_EN, 
        l_tTestDio_Inst.m_tOutput.m_bMcanEn);

} /*End of TestDio_CtrlMcanEn */

/*******************************************************************************
** Function Name    : TestDio_CtrlMcanStandby
**
** Return Value     : None
**
** Parameter        : #1(uint8)bLevel
**
** Description      : None
**
*******************************************************************************/
void TestDio_CtrlMcanStandby(boolean bLevel)
{
    l_tTestDio_Inst.m_tOutput.m_bMcanStb = bLevel;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_MCAN_STB_N, 
        l_tTestDio_Inst.m_tOutput.m_bMcanStb);

} /*End of TestDio_CtrlMcanStandby */
#endif

/*******************************************************************************
** Function Name    : TestDio_SetIsoPosEn
**
** Return Value     : None
**
** Parameter        : #1(uint8)bLevel
**
** Description      : None
**
*******************************************************************************/
void TestDio_SetIsoPosEn(boolean bLevel)
{
    l_tTestDio_Inst.m_tOutput.m_bIsoPosEn = bLevel;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_ISO_POS_EN,
        l_tTestDio_Inst.m_tOutput.m_bIsoPosEn);

} /*End of TestDio_SetIsoPosEn */

/*******************************************************************************
** Function Name    : TestDio_SetIsoNegEn
**
** Return Value     : None
**
** Parameter        : #1(uint8)bLevel
**
** Description      : None
**
*******************************************************************************/
void TestDio_SetIsoNegEn(boolean bLevel)
{
    l_tTestDio_Inst.m_tOutput.m_bIsoNegEn = bLevel;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_ISO_NEG_EN,
        l_tTestDio_Inst.m_tOutput.m_bIsoNegEn);

} /*End of TestDio_SetIsoNegEn */




/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
/*******************************************************************************
** Function Name    : _Read
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Read(void)
{
    /* Input */
    l_tTestDio_Inst.m_tInput.m_bIg1 =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_IG1_WUP);
    l_tTestDio_Inst.m_tInput.m_bWuSolar =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_SOLAR_WUP);
    l_tTestDio_Inst.m_tInput.m_bOpdSig =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_OPD_SIGNAL);
    l_tTestDio_Inst.m_tInput.m_bWuPressure =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_PRESSURE_WUP);
    l_tTestDio_Inst.m_tInput.m_bWuAcc =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_ACC_WUP);
    l_tTestDio_Inst.m_tInput.m_bWuMCan =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCAN_WUP);
    l_tTestDio_Inst.m_tInput.m_bMcanErr =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCAN_ERR_N);

    /* Output */
    l_tTestDio_Inst.m_tOutput.m_bVlinEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_VLIN_EN);
    l_tTestDio_Inst.m_tOutput.m_bPwrOff =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_PMIC_POWER_OFF);
#if 1 // CAN-IG, MCAN
    l_tTestDio_Inst.m_tOutput.m_bMcanEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCAN_EN);
    l_tTestDio_Inst.m_tOutput.m_bMcanStb =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCAN_STB_N);
#endif
    l_tTestDio_Inst.m_tOutput.m_bRegWdi =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_PMIC_WDI);
    l_tTestDio_Inst.m_tOutput.m_bIsoPosEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_ISO_POS_EN);
    l_tTestDio_Inst.m_tOutput.m_bIsoNegEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_ISO_NEG_EN);
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel0 =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_SEL0);
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel1 =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_SEL1);
    l_tTestDio_Inst.m_tOutput.m_bRlyQcPlus =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_QC_PLUS);
    l_tTestDio_Inst.m_tOutput.m_bRlyMainMinus =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_MAIN_MINUS);
    l_tTestDio_Inst.m_tOutput.m_bRlyDiagEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_EN);
    l_tTestDio_Inst.m_tOutput.m_bRlyPressure =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_PRESSURE);
    l_tTestDio_Inst.m_tOutput.m_bRlyPrecharger =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY_PRECHAGER);
    l_tTestDio_Inst.m_tOutput.m_bRly2QcMinus =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_QC_MINUS);
    l_tTestDio_Inst.m_tOutput.m_bRly2MainPlus =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_MAIN_PLUS);
    l_tTestDio_Inst.m_tOutput.m_bRly2WuExt2Res =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_WUP_EXT2_RES);
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_EN);
    l_tTestDio_Inst.m_tOutput.m_bRly2Heat =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_HEAT);
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel0 =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_SEL0);
    l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel1 =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_SEL1);
    l_tTestDio_Inst.m_tOutput.m_bMcuSmufsp =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_MCU_SMUFSP);
    l_tTestDio_Inst.m_tOutput.m_bCurrent1SenEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_CURRENT1_SEN_EN);
    l_tTestDio_Inst.m_tOutput.m_bCurrent2SenEn =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_CURRENT2_SEN_EN);

    l_tTestDio_Inst.m_tOutput.m_bVgate1N =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_VGATE1N);
    l_tTestDio_Inst.m_tOutput.m_bVgate1P =
        Dio_ReadChannel(DioConf_DioChannel_DioChannel_VGATE1P);

} /*End of InputRead */

/*******************************************************************************
** Function Name    : _Write
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Write(void)
{
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_SEL0,
        l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel0);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_SEL1,
        l_tTestDio_Inst.m_tOutput.m_bRlyDiagSel1);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_QC_PLUS,
        l_tTestDio_Inst.m_tOutput.m_bRlyQcPlus);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_QC_MINUS,
        l_tTestDio_Inst.m_tOutput.m_bRly2QcMinus);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_MAIN_MINUS,
        l_tTestDio_Inst.m_tOutput.m_bRlyMainMinus);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_MAIN_PLUS,
        l_tTestDio_Inst.m_tOutput.m_bRly2MainPlus);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_DIAG_EN,
        l_tTestDio_Inst.m_tOutput.m_bRlyDiagEn);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_PRESSURE,
        l_tTestDio_Inst.m_tOutput.m_bRlyPressure);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY_PRECHAGER,
        l_tTestDio_Inst.m_tOutput.m_bRlyPrecharger);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_WUP_EXT2_RES,
        l_tTestDio_Inst.m_tOutput.m_bRly2WuExt2Res);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_EN,
        l_tTestDio_Inst.m_tOutput.m_bRly2DiagEn);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_HEAT,
        l_tTestDio_Inst.m_tOutput.m_bRly2Heat);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_SEL0,
        l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel0);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_RLY2_DIAG_SEL1,
        l_tTestDio_Inst.m_tOutput.m_bRly2DiagSel1);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_MCU_SMUFSP,
        l_tTestDio_Inst.m_tOutput.m_bMcuSmufsp);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_CURRENT1_SEN_EN,
        l_tTestDio_Inst.m_tOutput.m_bCurrent1SenEn);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_CURRENT2_SEN_EN,
        l_tTestDio_Inst.m_tOutput.m_bCurrent2SenEn);

} /*End of _Write */



