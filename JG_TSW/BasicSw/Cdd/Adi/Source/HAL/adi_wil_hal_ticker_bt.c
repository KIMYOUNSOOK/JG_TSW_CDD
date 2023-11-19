/*******************************************************************************
 * @brief    HAL Ticker layer
 *
 * @details  Implement 32-bit free-running timer
 *
 * Copyright (c) 2021 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary and confidential to Analog Devices, Inc. and its licensors.
 *******************************************************************************/
#include "adi_wil_hal_ticker.h"
#include "adi_wil_hal.h"
#if 0 // @SURE - BLOCKED
#include "IfxStm.h"
#else
#include "Platform_Types.h"
#include "IfxScu_reg.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "Mcu_Cfg.h"
#include "Ifx_Ssw_Infra.h"
#endif
#include "adi_wil_example_isr_priorities.h"
#include "adi_wil_example_debug_functions.h"

#define HAL_TICKER_BT_TICK_MSEC   (1)            /* hal_ticker should increment every msec, see WIL documentation */
#define HAL_TICKER_BT_STM         &MODULE_STM1   /* Which STM timer to use */

static uint32 HalTickerTicks;      /* HAL_TICKER_BT_TICK_MSEC converted to STM timer ticks */

#if 1 // @SURE - ADDED
#define IFXSCU_EVR_OSC_FREQUENCY         (100000000.0)
#ifndef IFX_CFG_SCU_SYSCLK_FREQUENCY
#    define IFX_CFG_SCU_SYSCLK_FREQUENCY 20000000     /**< \brief Default External SysClk pin frequency */
#endif

typedef enum
{
    IfxScuCcu_PllInputClockSelection_fOsc1   = 0, /**< \brief Backup clock select */
    IfxScuCcu_PllInputClockSelection_fOsc0   = 1, /**< \brief fOsc0 or XTAL clock select */
    IfxScuCcu_PllInputClockSelection_fSysclk = 2  /**< \brief fOsc1 */
} IfxScuCcu_PllInputClockSelection;
static float32 GetOscFrequency(void)
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

static float32 GetPllFrequency(void)
{
    Ifx_SCU *scu = &MODULE_SCU;
    float32  oscFreq;
    float32  freq;

    oscFreq = GetOscFrequency();
    freq    = (oscFreq * (scu->SYSPLLCON0.B.NDIV + 1)) / ((scu->SYSPLLCON1.B.K2DIV + 1) * (scu->SYSPLLCON0.B.PDIV + 1));
    return freq;
}

static uint32 Get_Fstm()
{
    float32 sourcefreq;
    uint32 Fstm;
    sourcefreq = GetPllFrequency();
    Fstm = sourcefreq / SCU_CCUCON0.B.STMDIV;
    return Fstm;
}

static sint32 Stm_getTicksFromMilliseconds(uint32 milliSeconds)
{
    sint32 freq = (sint32)Get_Fstm();
    return (sint32)(freq / (1000)) * milliSeconds;
}

static uint64 Stm_get(Ifx_STM *stm)
{
    uint64 result;

    result  = stm->TIM0.U;
    result |= ((uint64)stm->CAP.U) << 32;

    return result;
}
#endif
adi_wil_hal_err_t adk_debug_TickerBTInit(void)
{
#if 0 // @SURE - BLOCKED
    adi_wil_hal_err_t result = ADI_WIL_HAL_ERR_SUCCESS;

    /* The STM timers run automatically out of reset, so no hardware configuration required at init. */

    /* For portability, use provided functions to convert 3msec to appropriate number of timer ticks and store */
    HalTickerTicks = (uint32)IfxStm_getTicksFromMilliseconds(HAL_TICKER_BT_STM, HAL_TICKER_BT_TICK_MSEC);

    return result;
#else
    adi_wil_hal_err_t result = ADI_WIL_HAL_ERR_SUCCESS;
    HalTickerTicks = (uint32)Stm_getTicksFromMilliseconds(HAL_TICKER_BT_TICK_MSEC);
    return result;
#endif
}


adi_wil_hal_err_t adk_debug_TickerBTStart(void)
{
    adi_wil_hal_err_t result = ADI_WIL_HAL_ERR_SUCCESS;

    /* The STM timers run automatically out of reset, so no hardware configuration required at start. */

    return result;
}


uint32_t adk_debug_TickerBTGetTimestamp(void)
{
#if 0 // @SURE - BLOCKED
    /* read current value of STM (STM is 64-bit timer) and divide to convert to milliseconds */
    uint64 iNow = IfxStm_get(HAL_TICKER_BT_STM) / (uint64)HalTickerTicks;
    return (uint32_t)iNow;
#else
    /* read current value of STM (STM is 64-bit timer) and divide to convert to milliseconds */
    uint64 iNow = Stm_get(HAL_TICKER_BT_STM) / (uint64)HalTickerTicks;
    return (uint32_t)iNow;
#endif
}


adi_wil_hal_err_t adk_debug_TickerBTStop(void)
{
    adi_wil_hal_err_t result = ADI_WIL_HAL_ERR_SUCCESS;

    /* Since the STM timer may be used by other features, this timer should be left running. Nothing to do here. */

    return result;
}

uint32_t	GetTick_1ms(void)
{
    /* read current value of STM (STM is 64-bit timer) and divide to convert to milliseconds */
    uint64 iNow = Stm_get(HAL_TICKER_BT_STM) / (uint64)HalTickerTicks;
   return (uint32_t)iNow;
   
}

