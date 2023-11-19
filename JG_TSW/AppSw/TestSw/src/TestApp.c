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
**       PROJECT  : SVM_STANDLAONE_TC387                                             
**
**        AUTHOR  : YG.SON
**
**       VERSION  : V1.0
**
**      PLATFORM  : Infineon Aurix TC387                                         
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

 *  V1.0    20220225    YG.SON      -           First Implementation


*******************************************************************************/





/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <stdio.h>
#include <string.h>
//#include "Dio.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxScu_reg.h"
#if 1 // FREQ.SPREAD CONTROL
#include "IfxPms_reg.h"
#endif
#include "PmicM_Tlf35584.h"
#include "TestStm.h"
#if 0 // Using MCAL GPT Interrupt TIMER
#include "TestGpt.h"
#endif
#include "TestFls.h"
#include "TestAdc.h"
#include "TestDio.h"
#include "TestIcu.h"
//#include "TestCan.h"
#include "TestLin.h"
//#include "Cmic_Manager.h"
#include "Utils.h"
#include "TestApp.h"

#if 1 // @SURE - ADI-EXAMPLE
#include "adi_wil_example_functions.h"
#endif

#if 0 /* RSW */
#include "Dia.h"
#include "DiaSec.h"
#endif


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#if 1 // Using MCAL GPT Interrupt TIMER
typedef enum
{
    // 10us
    TASK_TICK_1MS   = 100U,
    TASK_TICK_5MS   = 500U,
    TASK_TICK_10MS  = 1000U,
    TASK_TICK_100MS = 10000U,

} TASK_TICK_E;

typedef enum
{
    TASK_STOP,
    TASK_START

} TASK_RUN_E;
#endif

typedef enum
{
    WAKEUP_SRC_DEFAULT_NONE = 0U,
    WAKEUP_SRC_IG_KEY,
    WAKEUP_SRC_RTC

} WAKEUP_SRC_E;

typedef struct
{
     /* Is power off mode, TRUE:Power off, FALSE:Power on */
    boolean m_bPowerOff;
    
    /* Power latch time, User define or default(5) */
    uint8 m_nLatchTime;

    /* Power latch count(100ms) */
    uint32 m_nLatchCnt;

} PWR_MODE_T;

typedef struct
{
    uint8 m_bInitDone;
    uint16 m_nTickCnt;
    uint32 m_nMsTickCnt;

#if 1 // Using MCAL GPT Interrupt TIMER
    TASK_RUN_E m_eTaskRun[5]; // 0:1ms, 1:5ms, 2:10ms, 3:100ms
#else
    /* Timer ID */
    uint8 m_nTimerId[5];
#endif

    /* Wakeup source enumeration */
    WAKEUP_SRC_E m_eWakeupSrc;

    /* Power on/off structure */
    PWR_MODE_T m_tPwrMode;

} TESTAPP_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if 1 // Using MCAL GPT Interrupt TIMER
static void _Task1ms(void);
static void _Task5ms(void);
static void _Task10ms(void);
static void _Task100ms(void);
#else
static void _Task10us(uint8 nId);
static void _Task1ms(uint8 nId);
static void _Task5ms(uint8 nId);
static void _Task10ms(uint8 nId);
static void _Task100ms(uint8 nId);
#endif
static void _ShutDownFromBoot(void);
static void _ShutDownFromNorm(void);
static void _ResetSoftware(void);


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
static TESTAPP_INSTANCE_T l_tTestApp_Inst;




/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#if 1 // @SURE - ADI-EXAMPLE
extern int adi_wil_example_Main(void);
#if 1 // Using MCAL GPT Interrupt TIMER
extern void Scheduler_1ms_Trigger(void);
extern void HalTmrIsr(void);
extern void HalTaskIsr(void);
extern void HalTaskCBIsr(void);
#endif
#endif

#if 1 // Using MCAL GPT Interrupt TIMER
/*******************************************************************************
** Function Name    : TestApp_GptNotification
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
    uint16 nTickCnt = 0U;
    uint32 nMsTickCnt = 0U;

    // set 1tick=10us
    nTickCnt = l_tTestApp_Inst.m_nTickCnt++;
    //CmicM_SetSysTick(nTickCnt);

    if ((nTickCnt / TASK_TICK_1MS) &&
        ((nTickCnt % TASK_TICK_1MS) == 0))
    {
        // set 1tick=1ms
        nMsTickCnt = l_tTestApp_Inst.m_nMsTickCnt++;
        //CmicM_SetMsSysTick(nMsTickCnt);

        l_tTestApp_Inst.m_eTaskRun[0] = TASK_START;
#if (CMIC_CONF_ONLY_SPI_TEST) // for SPI test
        l_tTestApp_Inst.m_eTaskRun[4] = TASK_START;
#endif
    }

    if ((nTickCnt / TASK_TICK_5MS) &&
        ((nTickCnt % TASK_TICK_5MS) == 0))
    {
        l_tTestApp_Inst.m_eTaskRun[1] = TASK_START;
    }

    if ((nTickCnt / TASK_TICK_10MS) &&
        ((nTickCnt % TASK_TICK_10MS) == 0))
    {
        l_tTestApp_Inst.m_eTaskRun[2] = TASK_START;
    }

    if ((nTickCnt / TASK_TICK_100MS) &&
        ((nTickCnt % TASK_TICK_100MS) == 0))
    {
        l_tTestApp_Inst.m_nTickCnt = 0;
        l_tTestApp_Inst.m_eTaskRun[3] = TASK_START;
    }

#if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        return;
    }
#endif

    TestApp_RunTask();
    
#if (CMIC_CONF_ONLY_SPI_TEST) // for SPI test
    if(l_tTestApp_Inst.m_eTaskRun[4] == TASK_START)
    {
        static uint8 m_n3MsTickCnt = 0;
        extern void Test_Spi_Hal_0(void);
        extern void Test_Spi_Hal_1(void);

        m_n3MsTickCnt++;
        if((m_n3MsTickCnt%20) == 0) // 20ms
        {
            Test_Spi_Hal_1(); // CMIC2
            m_n3MsTickCnt = 0;
        }
        else if((m_n3MsTickCnt%10) == 0) // 10ms
        {
            Test_Spi_Hal_0(); // CMIC1
        }

        l_tTestApp_Inst.m_eTaskRun[4] = TASK_STOP;
    }
#endif

} /*End of TestApp_GptNotification */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification1
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 3ms
**
*******************************************************************************/
void IoHwAb_GptNotification1(void)
{
#if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        return;
    }
#endif

#if 1 // @SURE - ADI-EXAMPLE
    HalTmrIsr();
#endif

} /*End of IoHwAb_GptNotification1 */

/*******************************************************************************
** Function Name    : IoHwAb_GptNotification2
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1tick = 2.5ms
**
*******************************************************************************/
void IoHwAb_GptNotification2(void)
{
#if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        return;
    }
#endif
    
#if 1 // @SURE - ADI-EXAMPLE
    HalTaskIsr();
#endif

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
#if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        return;
    }
#endif
    
#if 1 // @SURE - ADI-EXAMPLE
    Scheduler_1ms_Trigger();
#endif

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
#if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        return;
    }
#endif
    
#if 1 // @SURE - ADI-EXAMPLE
    HalTaskCBIsr();
#endif

} /*End of IoHwAb_GptNotification4 */
#endif

#if 1 // FREQ.SPREAD CONTROL
#if 0
/*******************************************************************************
** Function Name    : _PMS_EVRSDCTRL0
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void PMS_EVRSDCTRL0(uint32 nPMS_EVRSDCTRL0)
{
    static uint32 tempPMS_EVRSDCTRL0 = 0x30390001;
    unsigned short safetyWdtPassword;
    /* AP32344_TC3xx_SMPS_regulator_v1_3.pdf (page 19)
        Frequency Spread Threshold(freq_spread_mode_i)
        this bit field defines the additional frequency spread to the nominal
        EVRC regulator swithcing frequency during operation. A random number of
        swithcing clock cycles are added to both TON and TOFF repsectively.
        where SDSWPRDNOM is the Nominal Switching period without spreading = TON + TOFF + 18
        Ifx_PMS_EVRSDCTRL0_Bits
        {
            SDFREQSPRD:16 = 0001 => A
            SDFREQ:12     = 0039
            NGOFF:1       = LOW
            PGOFF:1       = TRISTATE
            UP:1          = No effect
            LCK:1         = Unlock
        }
    */
    if(tempPMS_EVRSDCTRL0 == nPMS_EVRSDCTRL0)
    {
        return;
    }

    tempPMS_EVRSDCTRL0 = nPMS_EVRSDCTRL0;
    safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
    Ifx_Ssw_clearSafetyEndinit(safetyWdtPassword);
    PMS_EVRSDCTRL0.U = nPMS_EVRSDCTRL0; // 0x30390001 => 0x3039000A
    Ifx_Ssw_setSafetyEndinit(safetyWdtPassword);
    
} /*End of _PMS_EVRSDCTRL0 */
#endif

/*******************************************************************************
** Function Name    : _PMS_EVRSD_ChangeSpreadFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : Change Spread Frequency
**
*******************************************************************************/
void PMS_EVRSD_ChangeSpreadFrequency(uint8 nFreqMode, uint8 nFreqSpread)
{
    static uint8 tempFreqMode = 0xff;
    static uint8 tempnFreqSpread = 0xff;
    unsigned short safetyWdtPassword;

    if(!l_tTestApp_Inst.m_bInitDone)
    {
        return;
    }

    if(nFreqSpread > 0xA)
    {
        nFreqSpread = 0xA;
    }
    
    if(tempFreqMode == nFreqMode)
    {
        if(tempnFreqSpread == nFreqSpread)
        {
            return;
        }
        
        tempnFreqSpread = nFreqSpread;
    }

    tempFreqMode = nFreqMode;

    safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
    Ifx_Ssw_clearSafetyEndinit(safetyWdtPassword);
    PMS_EVRSDCOEFF6.U = 0x00873802;
    PMS_EVRSDCOEFF7.U = 0x0000D066;
    PMS_EVRSDCOEFF8.U = 0x00073802;
    PMS_EVRSDCOEFF9.U = 0x00009826;
    PMS_EVRSDCTRL7.U = 0x000000C9;
    
    if(nFreqMode == 1) // 0.8Mhz
    {
        PMS_EVRSDCTRL0.U = 0x307C0001;
    }
    else // 1.8Mhz
    {
        PMS_EVRSDCTRL0.U = 0x30360001;
    }

    PMS_EVRSDCTRL1.U = 0x0B690708;
    PMS_EVRSDCTRL8.U = 0x0121048E;
    PMS_EVRSDCTRL0.B.UP = 1;
    Delay(20);
    while(1)
    {
        if(!PMS_EVRSDCTRL0.B.UP)
        {
            break;
        }
    }

    if(nFreqMode == 1) // 0.8Mhz
    {
        PMS_EVRSDCOEFF0.U = 0x34087336;
    }
    else // 1.8Mhz
    {
        PMS_EVRSDCOEFF0.U = 0x350873B6;
        PMS_EVRSDCOEFF1.U = 0x02946C46;
    }
    
    PMS_EVRSDCTRL0.B.UP = 1;
    Delay(20);
    while(1)
    {
        if(!PMS_EVRSDCTRL0.B.UP)
        {
            break;
        }
    }

    if(nFreqMode == 1) // 0.8Mhz
    {
        //PMS_EVRSDCTRL0.U = 0x307c0002;
        PMS_EVRSDCTRL0.U = 0x307C0000 | nFreqSpread;
        PMS_EVRSDCOEFF0.U = 0x34087236;
        PMS_EVRSDCOEFF1.U = 0x02946C46;
    }
    else // 1.8Mhz
    {
        //PMS_EVRSDCTRL0.U = 0x30360002;
        PMS_EVRSDCTRL0.U = 0x30360000 | nFreqSpread;
    }
    
    PMS_EVRSDCTRL2.U = 0x0036033B;
    PMS_EVRSDCTRL3.U = 0x0B690810;
    PMS_EVRSDCOEFF2.U = 0x3408710E;
    PMS_EVRSDCOEFF3.U = 0x02946C44;
    PMS_EVRSDCTRL4.U = 0x00360009;
    PMS_EVRSDCTRL5.U = 0x0B690808;
    PMS_EVRSDCTRL6.U = 0x00231C94;
    PMS_EVRSDCOEFF4.U = 0x1B0822B6;
    PMS_EVRSDCOEFF5.U = 0x02946C46;
    PMS_EVRSDCTRL9.U = 0x00000434;
    PMS_EVRSDCTRL10.U = 0x00005A82;
    PMS_EVRSDCTRL11.U = 0x12070909;
    PMS_EVRSDCTRL0.B.UP = 1;
    while(1)
    {
        if(!PMS_EVRSDCTRL0.B.UP)
        {
            break;
        }
    }

    while(1)
    {
        if(PMS_EVRSTAT.B.SDVOK)
        {
            break;
        }
    }

    Ifx_Ssw_setSafetyEndinit(safetyWdtPassword);
    
} /*End of _PMS_EVRSD_ChangeSpreadFrequency */
#endif

/*******************************************************************************
** Function Name    : TestApp_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestApp_Init(void)
{
    memset(&l_tTestApp_Inst, 0U, sizeof(TESTAPP_INSTANCE_T));

#if 0 // using STM
    TestStm_Init();
#endif
#if 1 // Using MCAL GPT Interrupt TIMER
#else
    TestGpt_Init();
    TestGpt_Enable();
    /* Register Timer function */
    l_tTestApp_Inst.m_nTimerId[0] = TestGpt_RegTimer(10,     GPT_CONTINUE, _Task10us);
    l_tTestApp_Inst.m_nTimerId[1] = TestGpt_RegTimer(1000,   GPT_CONTINUE, _Task1ms);
    l_tTestApp_Inst.m_nTimerId[2] = TestGpt_RegTimer(5000,   GPT_CONTINUE, _Task5ms);
    l_tTestApp_Inst.m_nTimerId[3] = TestGpt_RegTimer(10000,  GPT_CONTINUE, _Task10ms);
    l_tTestApp_Inst.m_nTimerId[4] = TestGpt_RegTimer(100000, GPT_CONTINUE, _Task100ms);
#endif

#if 0 // test for HSM enable
    #if 0
    TestFls_Erase(DFLASH_BLOCK_0_BASE + DFLASH_BLOCK_SIZE*2);
    TestFls_Erase(DFLASH_BLOCK_0_BASE + DFLASH_BLOCK_SIZE*3);
    RswExec_HsmEnable();
    #endif
    RswExec_SwapEnable_Erase();
    //RswExec_SwapEnable_Case3_1();
    //RswExec_SwapEnable_Case3_2();
#endif

    PmicM_Tlf35584_Init();
    TLF35584_ABIST();

#if 1 // FREQ.SPREAD CONTROL
    TLF35584_SetBckFreSpread(0xFF);
#endif
    
    TestFls_Init();
    TestDio_Init();
    TestAdc_Init();
    TestIcu_Init();
//    TestCan_Init();
    TestLin_Init();

    _ShutDownFromBoot();

    /* CMIC Initialization */
    CmicM_Init();

#if 1 // Using MCAL GPT Interrupt TIMER
#else
    /* Start Timer function */
#if (CMIC_CONF_ONLY_ADI_WIL_RUN)
    // Only ADI WIL EXAMPLE RUN
#else
    TestGpt_StartTimer(l_tTestApp_Inst.m_nTimerId[0]); // 10us
    TestGpt_StartTimer(l_tTestApp_Inst.m_nTimerId[1]); // 1ms
    TestGpt_StartTimer(l_tTestApp_Inst.m_nTimerId[2]); // 5ms
    TestGpt_StartTimer(l_tTestApp_Inst.m_nTimerId[3]); // 10ms
    TestGpt_StartTimer(l_tTestApp_Inst.m_nTimerId[4]); // 100ms
#endif
#endif

    l_tTestApp_Inst.m_bInitDone = 1;
    
#if 1 // FREQ.SPREAD CONTROL
    PMS_EVRSD_ChangeSpreadFrequency(1, 0xA);
#endif

#if 0
    #if (CMIC_CONF_TEST_FORCED_SUBMCU_RUN)
        // Forced SUB-MCU RUN
    #else
    #if 1 // @SURE - ADI-EXAMPLE
        #if !(CMIC_CONF_ONLY_ADI_WIL_RUN)
        Delay_ms(100); // when booting, wait min 100ms for authority checking
        #if (CMIC_CONF_MCU_AURIX)
        if(TestCan_GetAuthority() == CMIC_AUTHORITY_SUB)
        {
            CmicM_SetAuthority(CMIC_AUTHORITY_SUB, 0);
        }
        #endif
        #endif
        /* Analog Device WBMS */
        (void)adi_wil_example_Main();
    #endif
    #endif
#endif
} /*End of TestApp_Init */

#if 1 // Using MCAL GPT Interrupt TIMER
/*******************************************************************************
** Function Name    : TestApp_RunTask
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestApp_RunTask(void)
{
    if (l_tTestApp_Inst.m_eTaskRun[0] == TASK_START)
    {
        _Task1ms();
        l_tTestApp_Inst.m_eTaskRun[0] = TASK_STOP;
    }

    if (l_tTestApp_Inst.m_eTaskRun[1] == TASK_START)
    {
        _Task5ms();
        l_tTestApp_Inst.m_eTaskRun[1] = TASK_STOP;
    }

    if (l_tTestApp_Inst.m_eTaskRun[2] == TASK_START)
    {
        _Task10ms();
        l_tTestApp_Inst.m_eTaskRun[2] = TASK_STOP;
    }
    
    if (l_tTestApp_Inst.m_eTaskRun[3] == TASK_START)
    {
        _Task100ms();
        l_tTestApp_Inst.m_eTaskRun[3] = TASK_STOP;
    }

} /*End of TestApp_RunTask */
#endif

/*******************************************************************************
** Function Name    : TestApp_GetTick
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint16 TestApp_GetTick(void)
{
    return l_tTestApp_Inst.m_nTickCnt;

} /*End of TestApp_GetTick */

/*******************************************************************************
** Function Name    : TestApp_GetMsTick
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint32 TestApp_GetMsTick(void)
{
    return l_tTestApp_Inst.m_nMsTickCnt;

} /*End of TestApp_GetTick */

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
#if 1 // Using MCAL GPT Interrupt TIMER
/*******************************************************************************
** Function Name    : _Task1ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task1ms(void)
{
#if 0    
    if(TestCan_GetEnable())
    {
#if 1 // @SURE - ADI-EXAMPLE
        if(!adi_example_is_boot_end()) return;
#endif
        CmicM_Handler();
    }
#endif
} /* End of _Task1ms() */

/*******************************************************************************
** Function Name    : _Task5ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task5ms(void)
{
#if 0
    if(TestCan_GetEnable())
    {
        TestCan_10ms();
    }

#if 0 /* RSW */
    CAN_CheckRswMsg();
    DIA_vMainTask();
    DiaSec_vMainTask();
#endif
#endif
} /* End of _Task5ms() */

/*******************************************************************************
** Function Name    : _Task10ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task10ms(void)
{
    if(TestLin_GetEnable())
    {
        TestLin_10ms();
    }
 #if 0       
    if(TestCan_GetEnable())
    {
        TestAdc_10ms();
    }
#endif
} /* End of _Task10ms() */

/*******************************************************************************
** Function Name    : _Task100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task100ms(void)
{
    uint16 nIgKeyAdc = 0U;
#if 0
    if(TestCan_GetEnable())
    {
        TestAdc_100ms();
        TestDio_100ms();
        TestIcu_100ms();
        TestCan_100ms();
        
        PmicM_Tlf35584_MainFunction_100ms();
    }

    if(TestLin_GetEnable())
    {
        TestLin_100ms();
    }

#if 1 // CAN-IG, MCAN
    if (TestDio_GetIg1() ||
        TestDio_GetSolarWup() ||
        TestDio_GetPressureWup() ||
        /*TestDio_GetMCanWup() ||*/
        TestDio_GetAccWup())
    {
        TestDio_CtrlMcanStandby(STD_HIGH);
    }
    else
    {
        TestDio_CtrlMcanStandby(STD_LOW);
    }
#endif

    nIgKeyAdc = TestAdc_GetValue(TESTADC_CH_AN11);
    if (nIgKeyAdc <= TESTADC_LEVEL_IG_ON/*3FF=1023*/ || l_tTestApp_Inst.m_tPwrMode.m_bPowerOff)
    {
        _ShutDownFromNorm();
    }
#endif
} /* End of _Task100ms() */
#else
/*******************************************************************************
** Function Name    : _Task10us
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task10us(uint8 nId)
{
    l_tTestApp_Inst.m_nTickCnt ++;

    // set 1tick=1ms
    CmicM_SetSysTick(l_tTestApp_Inst.m_nTickCnt);

} /* End of _Task10us() */

/*******************************************************************************
** Function Name    : _Task1ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task1ms(uint8 nId)
{
    if(TestCan_GetEnable())
    {
#if 1 // @SURE - ADI-EXAMPLE
        if(!adi_example_is_boot_end()) return;
#endif
        CmicM_Handler();
    }
    
} /* End of _Task1ms() */

/*******************************************************************************
** Function Name    : _Task5ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task5ms(uint8 nId)
{
    if(TestCan_GetEnable())
    {
        TestCan_10ms();
    }
    
#if 0 /* RSW */
    CAN_CheckRswMsg();
    DIA_vMainTask();
    DiaSec_vMainTask();
#endif
    
} /* End of _Task5ms() */

/*******************************************************************************
** Function Name    : _Task10ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task10ms(uint8 nId)
{
    if(TestLin_GetEnable())
    {
        TestLin_10ms();
    }
    
    if(TestCan_GetEnable())
    {
        TestAdc_10ms();
    }

} /* End of _Task10ms() */

/*******************************************************************************
** Function Name    : _Task100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Task100ms(uint8 nId)
{
    uint16 nIgKeyAdc = 0U;

    l_tTestApp_Inst.m_nTickCnt = 0U;

    if(TestCan_GetEnable())
    {
        TestAdc_100ms();
        TestDio_100ms();
        TestIcu_100ms();
        TestCan_100ms();
        
        PmicM_Tlf35584_MainFunction_100ms();
    }

    if(TestLin_GetEnable())
    {
        TestLin_100ms();
    }

#if 1 // CAN-IG, MCAN
    if (TestDio_GetIg1() ||
        TestDio_GetSolarWup() ||
        TestDio_GetPressureWup() ||
        /*TestDio_GetMCanWup() ||*/
        TestDio_GetAccWup())
    {
        TestDio_CtrlMcanStandby(STD_HIGH);
    }
    else
    {
        TestDio_CtrlMcanStandby(STD_LOW);
    }
#else
    if (!TestDio_GetIg1())
    {
        TestDio_CtrlMcanStandby(STD_LOW);
    }
#endif

    nIgKeyAdc = TestAdc_GetValue(TESTADC_CH_AN11);
    if (nIgKeyAdc <= TESTADC_LEVEL_IG_ON/*3FF=1023*/ || l_tTestApp_Inst.m_tPwrMode.m_bPowerOff)
    {
        _ShutDownFromNorm();
    }

} /* End of _Task100ms() */
#endif

/*******************************************************************************
** Function Name    : _ResetSoftware
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _ResetSoftware(void)
{
    Ifx_SCU_WDTCPU *watchdog = &MODULE_SCU.WDTCPU[0];
    uint16 nCpuPassword = 0, password = 0;
    Ifx_SCU_RSTCON Rstcon;
    uint8          resetConfig = 2; /* Default 2 - Application reset, 1 - System reset */

    /* Get the CPU EndInit password */
    nCpuPassword = Ifx_Ssw_getCpuWatchdogPassword(watchdog);
    
    /* Configure the request trigger in the Reset Configuration Register */
    password = Ifx_Ssw_getSafetyWatchdogPasswordInline();
    Rstcon.U = MODULE_SCU.RSTCON.U;

    Rstcon.B.SW = resetConfig;

    Ifx_Ssw_clearSafetyEndinitInline(password);

    MODULE_SCU.RSTCON.U = Rstcon.U;
    Ifx_Ssw_setCpuEndinitInline(watchdog, password);
    
    /* Clear CPU EndInit protection to write in the SWRSTCON register of SCU */
    Ifx_Ssw_clearCpuEndinit(watchdog, nCpuPassword);
    
    /* Trigger a software reset based on the configuration of RSTCON register */
    MODULE_SCU.SWRSTCON.B.SWRSTREQ = 1;
    while(1) {};
    
    /* The following instructions are not executed if a SW reset occurs */
    /* Set CPU EndInit protection */
    //Ifx_Ssw_setCpuEndinit(watchdog, nCpuPassword);
    
}

/*******************************************************************************
** Function Name    : _ShutDownFromBoot
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _ShutDownFromBoot(void)
{
    uint16 nIgKey = 0U;
    nIgKey = TestAdc_GetValue(TESTADC_CH_AN11);

    if (nIgKey > TESTADC_LEVEL_IG_ON) /* 0x03FF(1023) = 1.25V, Low threshold */
    {
        l_tTestApp_Inst.m_eWakeupSrc = WAKEUP_SRC_IG_KEY;
#if 1 // CAN-IG, MCAN
        TestDio_CtrlMcanEn(STD_HIGH);
        TestDio_CtrlMcanStandby(STD_HIGH);
#endif
    }
    else
    {
        tWakeupSt tWakeup = DEFAULT_VAL;
        PmicM_Tlf35584_ReadWakeupStatus(&tWakeup);
        if (tWakeup == BY_WAKEUP_TIMER)
        {
            l_tTestApp_Inst.m_eWakeupSrc = WAKEUP_SRC_RTC;

#if 1 // CAN-IG, MCAN
            TestDio_CtrlMcanEn(STD_HIGH);
            TestDio_CtrlMcanStandby(STD_HIGH);
#endif

            /* Clear wakeup status of TLF35584 */
            PmicM_Tlf35584_ClearWakeupStatus();
        }
        else
        {
          //  TestCan_SetEnable(FALSE);
            TestLin_SetEnable(FALSE); /* LIN Message Disable */
            
            l_tTestApp_Inst.m_eWakeupSrc = WAKEUP_SRC_DEFAULT_NONE;

#if 1 // CAN-IG, MCAN
            TestDio_CtrlMcanEn(STD_HIGH);
            TestDio_CtrlMcanStandby(STD_HIGH);
#endif

            /* Clear wakeup status of TLF35584 */
            PmicM_Tlf35584_ClearWakeupStatus();

#if 1 // CAN-IG, MCAN
            TestDio_CtrlMcanEn(STD_HIGH);
            TestDio_CtrlMcanStandby(STD_LOW);
#endif

            /* Power-Off because there is no valid wake-up source */
            TestDio_SetPwrOff(STD_HIGH);
            
            PmicM_Tlf35584_Go_To_State(PMICM_STANDBY);

            DISABLE();
            while (TRUE) { }
        }
    }

} /* End of _Task100ms() */

/*******************************************************************************
** Function Name    : _ShutDownFromNorm
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _ShutDownFromNorm(void)
{
    PWR_MODE_T *pPwrMode = &l_tTestApp_Inst.m_tPwrMode;
    uint16 nIgKeyAdc = 0U;
    uint32 nUserPwrLatchCnt = 0U;
    
    if (pPwrMode->m_nLatchCnt == 0U)
    {
        pPwrMode->m_bPowerOff = TRUE;
    }
    
    pPwrMode->m_nLatchCnt ++;

    /* Initial value setting of Power Latch Time */
    switch (l_tTestApp_Inst.m_eWakeupSrc)
    {
        case WAKEUP_SRC_IG_KEY:
            //TestCan_SetEnable(FALSE); /* CAN Message Disable, Move to under Pos1 & Pos2 & Pos3 */
            //TestLin_SetEnable(FALSE); /* LIN Message Disable */
           // nUserPwrLatchCnt = TestCan_GetPwrLatchTime() * 10U;
            if (nUserPwrLatchCnt == 0U)
            {
                /* Default Power Latch Time : 3sec */
                nUserPwrLatchCnt = 3U * 10U;
            }
            else
            {
                /* User Power Latch Time */
              //  pPwrMode->m_nLatchTime = TestCan_GetPwrLatchTime();
            }
            break;
    
        case WAKEUP_SRC_RTC:
            /* Wakeup source is RTC : Power Latch Time 5sec */
            nUserPwrLatchCnt = 5U * 10U;
            break;
    
        default:
            break;
    }

    nIgKeyAdc = TestAdc_GetValue(TESTADC_CH_AN11);

    /* Check whether key_iginition is alive again */
    if (nIgKeyAdc > TESTADC_LEVEL_IG_ON)
    {
        // Pos1
        if(l_tTestApp_Inst.m_eWakeupSrc == WAKEUP_SRC_IG_KEY)
        {
         //   TestCan_SetEnable(FALSE); /* CAN Message Disable */
            TestLin_SetEnable(FALSE); /* LIN Message Disable */
        }
        
#if 1 // CAN-IG, MCAN
        TestDio_CtrlMcanEn(STD_HIGH);
        TestDio_CtrlMcanStandby(STD_HIGH);
#endif

        DISABLE();
        
        /* Trigger SW Reset */
        _ResetSoftware();
    }
    else
    {

        
        if(pPwrMode->m_nLatchCnt >= 2)
        {
            // Pos2
            if(l_tTestApp_Inst.m_eWakeupSrc == WAKEUP_SRC_IG_KEY)
            {
                //TestCan_SetEnable(FALSE); /* CAN Message Disable */
                //TestLin_SetEnable(FALSE); /* LIN Message Disable */
            }
        }
        
        /* after Power Latch Time */
        if (pPwrMode->m_nLatchCnt >= nUserPwrLatchCnt)
        {
            switch (l_tTestApp_Inst.m_eWakeupSrc)
            {
                case WAKEUP_SRC_IG_KEY:
                 //   if (TestCan_GetRtcOnOff())
                    {
                        /* Wake-up Timer Enable, Wake timer unit = 10ms */
                        PmicM_Tlf35584_WakeupTimerEnable(STD_ON);
                    }
                   // else
                    {
                        /* Wake-up Timer Disable, Wake timer unit = 10ms */
                        PmicM_Tlf35584_WakeupTimerEnable(STD_OFF);
                    }
                    break;

                case WAKEUP_SRC_RTC:
                    /* Clear RTC mode regardless of user request */
                    /* Wake-up Timer Disable, Wake timer unit = 10ms */
                    PmicM_Tlf35584_WakeupTimerEnable(STD_OFF);
                    break;

                default:
                    /* Do nothing */
                    break;
            }

           // CmicM_HvTerminate1();
           // CmicM_HvTerminate2();

#if 1 // CAN-IG, MCAN
            TestDio_CtrlMcanStandby(STD_LOW);
#endif
            // Pos3
            if(l_tTestApp_Inst.m_eWakeupSrc == WAKEUP_SRC_IG_KEY)
            {
                Delay(30000U);
             //   TestCan_SetEnable(FALSE); /* CAN Message Disable */
                TestLin_SetEnable(FALSE); /* LIN Message Disable */
            }

            //Delay(20000U);

            PmicM_Tlf35584_Go_To_State(PMICM_STANDBY);

            DISABLE();
            while(TRUE) { }

        }
    }

} /* End of _ShutDownFromNorm() */
