/*******************************************************************************
 * @brief    HAL Task
 *
 * @details  Implement periodic call at user specified rate (intended to support calling processTask())
 *
 * Copyright (c) 2021 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary and confidential to Analog Devices, Inc. and its licensors.
 *******************************************************************************/
#include "adi_wil_hal_task.h"
#if 0 // @SURE - BLOCKED
#include "IfxStm.h"
#else
#include "Platform_Types.h"
#if 1 // Using MCAL GPT Interrupt TIMER
#include "Gpt.h"
#else
#include "TestGpt.h"
#endif
#endif
#include "adi_wil_example_isr_priorities.h"

#include "adi_wil_example_debug_functions.h"

#if 0 // @SURE - BLOCKED
#define HAL_TASK_CB_STM           &MODULE_STM1   /* Which STM timer to use */
#define HAL_TASK_CB_COMPARATOR    IfxStm_Comparator_0  /* which of the two available comparators to use to track elapsed time. see IfxStm_Comparator */

#if defined(TASK_DEBUG_ENABLE)
    #define TASK_DEBUG_PIN         &MODULE_P11,6    /* Define debug pin */
#endif

static uint32 HalTaskCBPeriodTicks;                  /* HAL_TASK_PERIOD_USEC converted to STM timer ticks */
static void(*pfTaskCb)(void) = (void *)0;    /* function pointer, points back to application callback */
#else
static void(*pfTaskCb)(void) = (void *)0;    /* function pointer, points back to application callback */
static uint8 _TmrStart = 0;
#if 0 // Using MCAL GPT Interrupt TIMER
static uint8 _TmrId = 0;
#endif
#endif


#if 0 // @SURE - BLOCKED
IFX_INTERRUPT(HalTaskCBIsr, 0, ISR_PRIORITY_HAL_TASK_CB);

/* ISR, services the hal_tmr interrupt */
void HalTaskCBIsr(void)
{
    /* increment the comparator value by the number of ticks to set next interrupt */
    IfxStm_increaseCompare(HAL_TASK_CB_STM, HAL_TASK_CB_COMPARATOR, HalTaskCBPeriodTicks);

#if defined(TASK_DEBUG_ENABLE)
    IfxPort_togglePin(TASK_DEBUG_PIN);
#endif


    /* call the application callback */
    if (pfTaskCb != (void *)0)
    {
        IfxCpu_enableInterrupts();
        pfTaskCb();
    }

#if defined(TASK_DEBUG_ENABLE)
    IfxPort_togglePin(TASK_DEBUG_PIN);
#endif
}
#else
/* ISR, services the hal_tmr interrupt */
void HalTaskCBIsr(void)
{
    /* call the application callback */
    if (pfTaskCb != (void *)0)
    {
        pfTaskCb();
    }
}

#if 0 // Using MCAL GPT Interrupt TIMER
void _HalTaskCBIsr(uint8 nId)
{
    HalTaskCBIsr();
}
#endif
#endif

bool adi_wil_hal_TaskCBStart(uint32_t iPeriodUs, void(*pfCb)(void))
{
#if 0 // @SURE - BLOCKED
    boolean result;
    IfxStm_CompareConfig HalTask;

#if defined(TASK_DEBUG_ENABLE)
    IfxPort_setPinModeOutput(TASK_DEBUG_PIN, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
#endif

    /* For portability, use provided functions to convert user requested period to appropriate number of timer ticks and store */
    HalTaskCBPeriodTicks = (uint32)IfxStm_getTicksFromMicroseconds(HAL_TASK_CB_STM, iPeriodUs);

    IfxStm_initCompareConfig(&HalTask);           /* Initialize the configuration structure with default values */

    HalTask.comparator          = HAL_TASK_CB_COMPARATOR; 
    HalTask.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0; 
    HalTask.compareOffset       = IfxStm_ComparatorOffset_0; 
    HalTask.compareSize         = IfxStm_ComparatorSize_32Bits; 
    HalTask.ticks               = HalTaskCBPeriodTicks;              /* Set the number of ticks after which the timer triggers an  interrupt for the first time */
    HalTask.triggerPriority     = ISR_PRIORITY_HAL_TASK_CB;           /* Set the priority of the interrupt */
    HalTask.typeOfService       = IfxSrc_Tos_cpu0;                 /* Set the service provider for the interrupts */

    /* Configure the STM peripheral by passing the user configuration */
    /* IfxStm_initCompare returns true if init was successful */
    result = IfxStm_initCompare(HAL_TASK_CB_STM, &HalTask);

    /* store the callback if init suceeded */
    if (result)
    {
        pfTaskCb = pfCb;
    }

    return (bool)result;
#else
    boolean result = true;
    if(!_TmrStart)
    {
#if 1 // Using MCAL GPT Interrupt TIMER
        Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_4, iPeriodUs*100U);
#else
        _TmrId = TestGpt_RegTimer(iPeriodUs, GPT_CONTINUE, _HalTaskCBIsr);
        TestGpt_StartTimer(_TmrId);
#endif
        _TmrStart = 1;
    }
    /* store the callback if init suceeded */
    if (result)
    {
        pfTaskCb = pfCb;
    }

    return (bool)result;
#endif
}


void adi_wil_hal_TaskCBStop(void)
{
#if 0 // @SURE - BLOCKED
    /* to stop TASK, just disable interrupt. Since the STM timer may be used by other features, this timer should be left running. */
    IfxStm_disableComparatorInterrupt(HAL_TASK_CB_STM, HAL_TASK_CB_COMPARATOR);

    /* clear the callback as well */
    pfTaskCb = (void *)0;
#else
    if(_TmrStart)
    {
#if 1 // Using MCAL GPT Interrupt TIMER
        Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_4);
#else
        TestGpt_ClrTimer(_TmrId);
        _TmrId = 0;
#endif
        _TmrStart = 0;
    }
    /* clear the callback as well */
    pfTaskCb = (void *)0;
#endif
}
