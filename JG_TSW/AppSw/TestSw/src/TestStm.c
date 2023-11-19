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
**          FILE  : TestStm.c
**
**       PROJECT  :                                              
**
**        AUTHOR  :
**
**       VERSION  :
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

 *  V1.0    20220225                -           First Implementation


*******************************************************************************/





/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>

#include "Ifx_cfg.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"
#include "Mcu_Cfg.h"

#if 0 // using STM
#include "TestStm.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define BSP_DEFAULT_TIMER       &MODULE_STM0   /* Which BSP_DEFAULT_TIMER timer to use */
#define BSP_MODULE_SCU          &MODULE_SCU

#define TICK_1US                (1000000)
#define TICK_10US               (100000)
#define TICK_100US              (10000)
#define TICK_1000US             (1000)
#define TICK_1MS                (1000)
#define TICK_10MS               (100)
#define TICK_100MS              (10)

#define IFXSCU_EVR_OSC_FREQUENCY         (100000000.0)

#ifndef IFX_CFG_SCU_SYSCLK_FREQUENCY
#    define IFX_CFG_SCU_SYSCLK_FREQUENCY 20000000     /**< \brief Default External SysClk pin frequency */
#endif

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/** Clock selection  */
typedef enum
{
    IfxScu_CCUCON0_CLKSEL_fBack = 0,
    IfxScu_CCUCON0_CLKSEL_fPll  = 1
} IfxScu_CCUCON0_CLKSEL;

typedef enum
{
    IfxScuCcu_Fsource_0 = 0,      /**< \brief fSource0  */
    IfxScuCcu_Fsource_1,          /**< \brief fSource1  */
    IfxScuCcu_Fsource_2           /**< \brief fSource2  */
} IfxScuCcu_Fsource;

/** \brief SysPll & Per Pll input clock selection.
 * SYSPLLCON0.B.INSEL
 */
typedef enum
{
    IfxScuCcu_PllInputClockSelection_fOsc1   = 0, /**< \brief Backup clock select */
    IfxScuCcu_PllInputClockSelection_fOsc0   = 1, /**< \brief fOsc0 or XTAL clock select */
    IfxScuCcu_PllInputClockSelection_fSysclk = 2  /**< \brief fOsc1 */
} IfxScuCcu_PllInputClockSelection;

typedef struct
{
    uint32 m_n1MsTicks;
    uint32 m_n1UsTicks;
    uint32 m_n10UsTicks;

} TESTTIMER_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static float32 TestTimer_GetEvrFrequency(void);
static float32 TestTimer_GetOscFrequency(void);
static float32 TestTimer_GetPllFrequency(void);
static float32 TestTimer_GetPerPllFrequency1(void);
static float32 TestTimer_GetPerPllFrequency2(void);
static float32 TestTimer_GetStmFrequency(void);
static uint64 TestTimer_GetStm(Ifx_STM *stm);


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
static TESTTIMER_INSTANCE_T l_tTestTimer_Inst;



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestStm_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestStm_Init(void)
{
    memset(&l_tTestTimer_Inst, 0U, sizeof(TESTTIMER_INSTANCE_T));

    l_tTestTimer_Inst.m_n1MsTicks = (uint32)TestStm_GetStmTicksFromUs(BSP_DEFAULT_TIMER, TICK_1MS);
    l_tTestTimer_Inst.m_n1UsTicks = (uint32)TestStm_GetStmTicksFromUs(BSP_DEFAULT_TIMER, TICK_1US);
    l_tTestTimer_Inst.m_n10UsTicks = (uint32)TestStm_GetStmTicksFromUs(BSP_DEFAULT_TIMER, TICK_10US);

} /*End of TestStm_Init */

/*******************************************************************************
** Function Name    : TestStm_GetStmTicksFromUs
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
sint32 TestStm_GetStmTicksFromUs(Ifx_STM *stm, uint32 us)
{
    sint32 freq = (sint32)TestTimer_GetStmFrequency();
    return (sint32)(freq / us);
}

/*******************************************************************************
** Function Name    : TestStm_GetTimestampMs
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint32 TestStm_GetTimestampMs(void)
{
    /* read current value of BSP_DEFAULT_TIMER (BSP_DEFAULT_TIMER is 64-bit timer) and 
        divide to convert to milliseconds */
    uint64 iNow = TestTimer_GetStm(BSP_DEFAULT_TIMER) / (uint64)l_tTestTimer_Inst.m_n1MsTicks;
    return (uint32)iNow;
}

/*******************************************************************************
** Function Name    : TestStm_GetTimestampUs
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint64 TestStm_GetTimestampUs(void)
{
    /* read current value of BSP_DEFAULT_TIMER (BSP_DEFAULT_TIMER is 64-bit timer) and 
        divide to convert to milliseconds */
    uint64 iNow = TestTimer_GetStm(BSP_DEFAULT_TIMER) / (uint64)l_tTestTimer_Inst.m_n1UsTicks;
    return iNow;
}

/*******************************************************************************
** Function Name    : TestStm_GetTimestamp10Us
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint64 TestStm_GetTimestamp10Us(void)
{
    /* read current value of BSP_DEFAULT_TIMER (BSP_DEFAULT_TIMER is 64-bit timer) and 
        divide to convert to milliseconds */
    uint64 iNow = TestTimer_GetStm(BSP_DEFAULT_TIMER) / (uint64)l_tTestTimer_Inst.m_n10UsTicks;
    return iNow;
}

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/

/*******************************************************************************
** Function Name    : TestTimer_GetEvrFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetEvrFrequency(void)
{
    return IFXSCU_EVR_OSC_FREQUENCY;
}

/*******************************************************************************
** Function Name    : TestTimer_GetOscFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetOscFrequency(void)
{
    float32 freq;

    if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fOsc1)
    {
        freq = IFXSCU_EVR_OSC_FREQUENCY;
    }
    else if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fOsc0)
    {
        freq = (float32)IFX_CFG_SCU_XTAL_FREQUENCY;
    }
    else if (SCU_SYSPLLCON0.B.INSEL == IfxScuCcu_PllInputClockSelection_fSysclk)
    {
        freq = IFX_CFG_SCU_SYSCLK_FREQUENCY;
    }
    else
    {
        /* Reserved values, this */
        freq = 0.0;
    }

    return freq;
}

/*******************************************************************************
** Function Name    : TestTimer_GetPllFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetPllFrequency(void)
{
    Ifx_SCU *scu = &MODULE_SCU;
    float32  oscFreq;
    float32  freq;

    oscFreq = TestTimer_GetOscFrequency();
    freq    = (oscFreq * (scu->SYSPLLCON0.B.NDIV + 1)) / ((scu->SYSPLLCON1.B.K2DIV + 1) * (scu->SYSPLLCON0.B.PDIV + 1));
    return freq;
}

/*******************************************************************************
** Function Name    : TestTimer_GetPerPllFrequency1
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetPerPllFrequency1(void)
{
    Ifx_SCU *scu = &MODULE_SCU;
    float32  pllFrequency1;
    float32  oscFreq;
    oscFreq       = TestTimer_GetOscFrequency();

    pllFrequency1 = (oscFreq * (scu->PERPLLCON0.B.NDIV + 1)) / ((scu->PERPLLCON0.B.PDIV + 1) * (scu->PERPLLCON1.B.K2DIV + 1));

    return pllFrequency1;
}

/*******************************************************************************
** Function Name    : TestTimer_GetPerPllFrequency2
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetPerPllFrequency2(void)
{
    Ifx_SCU *scu = &MODULE_SCU;
    float32  pllFrequency2;
    float32  oscFreq;
    oscFreq = TestTimer_GetOscFrequency();

    if (!(scu->PERPLLCON0.B.DIVBY))
    {
        pllFrequency2 = (oscFreq * (scu->PERPLLCON0.B.NDIV + 1)) / ((scu->PERPLLCON0.B.PDIV + 1) * (scu->PERPLLCON1.B.K3DIV + 1) * 1.6);
    }
    else
    {
        pllFrequency2 = (oscFreq * (scu->PERPLLCON0.B.NDIV + 1)) / ((scu->PERPLLCON0.B.PDIV + 1) * (scu->PERPLLCON1.B.K3DIV + 1) * 2);
    }

    return pllFrequency2;
}

/*******************************************************************************
** Function Name    : TestTimr_IfxScuCcu_getSourceFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
float32 TestTimr_IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource fsource)
{
    float32 sourcefreq;

    switch (SCU_CCUCON0.B.CLKSEL)
    {
    case IfxScu_CCUCON0_CLKSEL_fBack:
        sourcefreq = TestTimer_GetEvrFrequency();
        break;
    case IfxScu_CCUCON0_CLKSEL_fPll:

        switch (fsource)
        {
        case IfxScuCcu_Fsource_0:
            sourcefreq = TestTimer_GetPllFrequency();
            break;
        case IfxScuCcu_Fsource_1:
            sourcefreq = TestTimer_GetPerPllFrequency1();

            if (SCU_CCUCON1.B.PLL1DIVDIS == 0)
            {
                sourcefreq = sourcefreq / 2.0f;
            }

            break;
        case IfxScuCcu_Fsource_2:
            sourcefreq = TestTimer_GetPerPllFrequency2();
            break;
        default:
            sourcefreq = 0;
            break;
        }

        break;
    default:
        sourcefreq = 0;
        break;
    }

    return sourcefreq;
}

/*******************************************************************************
** Function Name    : TestTimer_GetStmFrequency
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static float32 TestTimer_GetStmFrequency(void)
{
    return TestTimr_IfxScuCcu_getSourceFrequency(IfxScuCcu_Fsource_0) / SCU_CCUCON0.B.STMDIV;
}

/*******************************************************************************
** Function Name    : TestTimer_GetStm
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static uint64 TestTimer_GetStm(Ifx_STM *stm)
{
    uint64 result;

    result  = stm->TIM0.U;
    result |= ((uint64)stm->CAP.U) << 32;

    return result;
}
#endif

