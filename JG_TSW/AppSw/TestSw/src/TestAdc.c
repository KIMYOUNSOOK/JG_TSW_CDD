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
**          FILE  : TestApp.c
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
#include "Adc.h"

#include "TestDio.h"
#include "TestAdc.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    uint16 AN2_TEMP_RADI;
    uint16 AN3_TEMP_INLET;
    uint16 AN4_TEMP_PRA1;
    uint16 AN5_TEMP_PRA2;
    uint16 AN6_TEMP_HEAT;
    uint16 AN7_TEMP_SENSING1;
    
} GROUP0_T;

typedef struct
{
    uint16 AN21_ISO_NEG;

} ISO_NEG_T;

typedef struct
{
    uint16 AN20_ISO_POS;

} ISO_POS_T;

typedef struct
{
    uint16 AN8_TEMP_SENSING2;
    uint16 AN10_LIN_COMM_PWR;
    uint16 AN11_IG_KEY;
    uint16 AN12_BPLUS_LDC;
    uint16 AN13_CURRENT1; // High Voltage current sensing input 1
    uint16 AN14_CURRENT2; // High Voltage current sensing input 2
    uint16 AN15_RLY2_DIAG;

} GROUP1_T;

typedef struct
{
    uint16 AN16_RLY1_PRECHARGE;
    uint16 AN17_RLY1_DIAG;
    uint16 AN18_RLY_B_PLUS;
    uint16 AN19_PWR_C_SNR;
    uint16 AN22_VSUB_AD;

} GROUP2_T;

typedef struct
{
    uint16 AN24_ADRF1_3V3;
    uint16 AN25_ADRF2_3V3;
    uint16 AN26_INTERLOCK_INV;
    uint16 AN27_INTERLOCK_JB;
    uint16 AN28_INTERLOCK_AS;
    uint16 AN29_INTERLOCK_ICCU;
    uint16 AN30_INTERLOCK_OBC;
    uint16 AN31_ADC_IN;
} GROUP3_T;

typedef struct
{
    uint16 AN33_OPD_5V;
    uint16 AN34_LEVEL_SENSING1;
    uint16 AN35_LEVEL_SENSING2;

} GROUP8_T;

typedef struct
{
    GROUP0_T m_tG0; /* AdcHwUnit0 */
    GROUP1_T m_tG1; /* AdcHwUnit1 */
    GROUP2_T m_tG2; /* AdcHwUnit2 */
    GROUP3_T m_tG3; /* AdcHwUnit3 */
    GROUP8_T m_tG8; /* AdcHwUnit8 */

    ISO_POS_T m_tIsoPos;
    ISO_NEG_T m_tIsoNeg;

    uint32 m_n10msSeq;
    uint32 m_n8100msSeq;

} TESTADC_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void TestAdc_Group0Conv(void);
static void TestAdc_Group1Conv(void);
static void TestAdc_Group2Conv(void);
static void TestAdc_Group3Conv(void);
static void TestAdc_Group8Conv(void);
static void TestAdc_IsoPosConv(void);
static void TestAdc_IsoNegConv(void);


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
static TESTADC_INSTANCE_T l_tTestAdc_Inst;





/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestAdc_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestAdc_Init(void)
{
    memset(&l_tTestAdc_Inst, 0U, sizeof(TESTADC_INSTANCE_T));

    /* Initialize the result buffer pointer of Adc groups */
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_0, (uint16*)&l_tTestAdc_Inst.m_tG0);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_1, (uint16*)&l_tTestAdc_Inst.m_tG1);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_2, (uint16*)&l_tTestAdc_Inst.m_tG2);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_2_ISO_P, (uint16*)&l_tTestAdc_Inst.m_tIsoPos);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_2_ISO_N, (uint16*)&l_tTestAdc_Inst.m_tIsoNeg);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_3, (uint16*)&l_tTestAdc_Inst.m_tG3);
    Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_8, (uint16*)&l_tTestAdc_Inst.m_tG8);

    TestAdc_Group0Conv();
    TestAdc_Group1Conv();
    TestAdc_Group2Conv();
    TestAdc_Group3Conv();
    TestAdc_Group8Conv();
    TestAdc_IsoPosConv();
    TestAdc_IsoNegConv();

} /*End of TestAdc_Init */

/*******************************************************************************
** Function Name    : TestAdc_10ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestAdc_10ms(void)
{
    switch (l_tTestAdc_Inst.m_n10msSeq)
    {
        case 0U:
            break;
        case 1U:
            break;
        case 2U:
            TestAdc_Group0Conv();
            break;
        case 3U:
            TestAdc_Group1Conv();
            break;
        case 4U:
            TestAdc_Group2Conv();
            break;
        case 5U:
            TestAdc_Group3Conv();
            break;
        case 6U:
            TestAdc_Group8Conv();
            break;
        case 7U:
            break;
    }

    l_tTestAdc_Inst.m_n10msSeq ++;
    l_tTestAdc_Inst.m_n10msSeq %= 8U;

} /*End of TestAdc_10ms */

/*******************************************************************************
** Function Name    : TestAdc_100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestAdc_100ms(void)
{
    if(l_tTestAdc_Inst.m_n8100msSeq == 1U)
    {
        TestDio_SetIsoNegEn(STD_HIGH);
    }
    else if(l_tTestAdc_Inst.m_n8100msSeq == 46U)  /* After 4.5s */
    {
        /* Start ADC conversion of IsoLow */
        TestAdc_IsoNegConv();
    }
    else if(l_tTestAdc_Inst.m_n8100msSeq == 47U)
    {
        TestDio_SetIsoNegEn(STD_LOW);
        TestAdc_IsoNegConv();
    }
    else if(l_tTestAdc_Inst.m_n8100msSeq == 48U)
    {
        TestDio_SetIsoPosEn(STD_HIGH);
    }
    else if(l_tTestAdc_Inst.m_n8100msSeq == 93U)  /* After 4.5s */
    {
        /* Start ADC conversion of IsoHigh */
        TestAdc_IsoPosConv();
    }
    else if(l_tTestAdc_Inst.m_n8100msSeq == 94U)
    {
        TestDio_SetIsoPosEn(STD_LOW);
        TestAdc_IsoPosConv();

        l_tTestAdc_Inst.m_n8100msSeq = 0U;
    }
    else
    {
        /*  Do Nothing */
    }

    
    l_tTestAdc_Inst.m_n8100msSeq++;
    //l_tTestAdc_Inst.m_n10msSeq %= 95U;

} /*End of TestAdc_100ms */

/*******************************************************************************
** Function Name    : TestAdc_GetValue
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint16 TestAdc_GetValue(TESTADC_CH_E eChannel)
{
    switch (eChannel)
    {
        /* Group0(AdcHwUnit0) */
        case TESTADC_CH_AN2:
            return l_tTestAdc_Inst.m_tG0.AN2_TEMP_RADI;

        case TESTADC_CH_AN3:
            return l_tTestAdc_Inst.m_tG0.AN3_TEMP_INLET;

        case TESTADC_CH_AN4:
            return l_tTestAdc_Inst.m_tG0.AN4_TEMP_PRA1;

        case TESTADC_CH_AN5:
            return l_tTestAdc_Inst.m_tG0.AN5_TEMP_PRA2;

        case TESTADC_CH_AN6:
            return l_tTestAdc_Inst.m_tG0.AN6_TEMP_HEAT;

        case TESTADC_CH_AN7:
            return l_tTestAdc_Inst.m_tG0.AN7_TEMP_SENSING1;


        /* Group1(AdcHwUnit1) */
        case TESTADC_CH_AN8:
            return l_tTestAdc_Inst.m_tG1.AN8_TEMP_SENSING2;

        case TESTADC_CH_AN10:
            return l_tTestAdc_Inst.m_tG1.AN10_LIN_COMM_PWR;

        case TESTADC_CH_AN11:
            return l_tTestAdc_Inst.m_tG1.AN11_IG_KEY;

        case TESTADC_CH_AN12:
            return l_tTestAdc_Inst.m_tG1.AN12_BPLUS_LDC;

        case TESTADC_CH_AN13:
            return l_tTestAdc_Inst.m_tG1.AN13_CURRENT1;

        case TESTADC_CH_AN14:
            return l_tTestAdc_Inst.m_tG1.AN14_CURRENT2;

        case TESTADC_CH_AN15:
            return l_tTestAdc_Inst.m_tG1.AN15_RLY2_DIAG;


        /* Group2(AdcHwUnit2) */
        case TESTADC_CH_AN16:
            return l_tTestAdc_Inst.m_tG2.AN16_RLY1_PRECHARGE;

        case TESTADC_CH_AN17:
            return l_tTestAdc_Inst.m_tG2.AN17_RLY1_DIAG;

        case TESTADC_CH_AN18:
            return l_tTestAdc_Inst.m_tG2.AN18_RLY_B_PLUS;

        case TESTADC_CH_AN19:
            return l_tTestAdc_Inst.m_tG2.AN19_PWR_C_SNR;

        case TESTADC_CH_AN20:
            return l_tTestAdc_Inst.m_tIsoPos.AN20_ISO_POS;
        
        case TESTADC_CH_AN21:
            return l_tTestAdc_Inst.m_tIsoNeg.AN21_ISO_NEG;
    
        case TESTADC_CH_AN22:
            return l_tTestAdc_Inst.m_tG2.AN22_VSUB_AD;


        /* Group3(AdcHwUnit3) */
        case TESTADC_CH_AN24:
            return l_tTestAdc_Inst.m_tG3.AN24_ADRF1_3V3;

        case TESTADC_CH_AN25:
            return l_tTestAdc_Inst.m_tG3.AN25_ADRF2_3V3;

        case TESTADC_CH_AN26:
            return l_tTestAdc_Inst.m_tG3.AN26_INTERLOCK_INV; // PR_INTERLOCK

        case TESTADC_CH_AN27:
            return l_tTestAdc_Inst.m_tG3.AN27_INTERLOCK_JB;

        case TESTADC_CH_AN28:
            return l_tTestAdc_Inst.m_tG3.AN28_INTERLOCK_AS;

        case TESTADC_CH_AN29:
            return l_tTestAdc_Inst.m_tG3.AN29_INTERLOCK_ICCU;

        case TESTADC_CH_AN30:
            return l_tTestAdc_Inst.m_tG3.AN30_INTERLOCK_OBC; // FR_INTERLOCK

        case TESTADC_CH_AN31:
            return l_tTestAdc_Inst.m_tG3.AN31_ADC_IN;

        /* Group8(AdcHwUnit8) */
        case TESTADC_CH_AN33:
            return l_tTestAdc_Inst.m_tG8.AN33_OPD_5V;

        case TESTADC_CH_AN34:
            return l_tTestAdc_Inst.m_tG8.AN34_LEVEL_SENSING1;
            
        case TESTADC_CH_AN35:
            return l_tTestAdc_Inst.m_tG8.AN35_LEVEL_SENSING2;
    }

    return 0;

} /*End of TestAdc_GetValue */






/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestAdc_Group0Conv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_Group0Conv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_0);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_0);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_Group0Conv */

/*******************************************************************************
** Function Name    : TestAdc_Group1Conv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_Group1Conv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_1);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_1);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_Group1Conv */

/*******************************************************************************
** Function Name    : TestAdc_Group2Conv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_Group2Conv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_2);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_2);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_Group2Conv */

/*******************************************************************************
** Function Name    : TestAdc_Group3Conv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_Group3Conv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_3);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_3);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_Group3Conv */

/*******************************************************************************
** Function Name    : TestAdc_Group8Conv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_Group8Conv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_8);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_8);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_Group8Conv */

/*******************************************************************************
** Function Name    : TestAdc_IsoPosConv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_IsoPosConv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_2_ISO_P);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_2_ISO_P);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_IsoPosConv */

/*******************************************************************************
** Function Name    : TestAdc_IsoNegConv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void TestAdc_IsoNegConv(void)
{
    Adc_StatusType AdcStatus;
    Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup_2_ISO_N);
    do
    {
        AdcStatus = Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_2_ISO_N);
    }
    while (AdcStatus != ADC_STREAM_COMPLETED);

} /*End of TestAdc_IsoNegConv */


