/*******************************************************************************
 * @brief    HAL Task
 *
 * @details  Implement periodic call at user specified rate (intended to support calling processTask())
 *
 * Copyright (c) 2021 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary and confidential to Analog Devices, Inc. and its licensors.
 *******************************************************************************/
#include "adi_wil_hal_task.h"
#include "Platform_Types.h"
#if 1 // Using MCAL GPT Interrupt TIMER
#include "Gpt.h"
#endif
#include "adi_wil_example_isr_priorities.h"
#include "adi_wil_example_debug_functions.h"


#if 0 // @SURE - BLOCKED
#define HAL_TASK_STM           &MODULE_STM2   /* Which STM timer to use */
#define HAL_TASK_COMPARATOR    IfxStm_Comparator_1  /* which of the two available comparators to use to track elapsed time. see IfxStm_Comparator */

#if defined(TASK_DEBUG_ENABLE)
    #define TASK_DEBUG_PIN         &MODULE_P11,6    /* Define debug pin */
#endif

#define DBG_GPIO_0              &MODULE_P34,1                   /* @remark   Neo Jung : GPIO for debugging purpose       U11, N132 */ 
#define DBG_GPIO_1              &MODULE_P34,3                   /* @remark   Neo Jung : GPIO for debugging purpose       U12, N134 */ 
#endif
#if 0 // @SURE - BLOCKED
static uint32 HalTaskPeriodTicks;                  /* HAL_TASK_PERIOD_USEC converted to STM timer ticks */
static void(*pfTaskCb)(void) = (void *)0;    /* function pointer, points back to application callback */


IFX_INTERRUPT(HalTaskIsr, 0, ISR_PRIORITY_HAL_TASK);

/* ISR, services the hal_tmr interrupt */
void HalTaskIsr(void)
{
    /* increment the comparator value by the number of ticks to set next interrupt */
    IfxStm_increaseCompare(HAL_TASK_STM, HAL_TASK_COMPARATOR, HalTaskPeriodTicks);

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
static void(*pfTaskCb)(void) = (void *)0;    /* function pointer, points back to application callback */
static uint8 _TmrStart = 0;
#if 0 // Using MCAL GPT Interrupt TIMER
static uint8 _TmrId = 0;
#endif
/* ISR, services the hal_tmr interrupt */
void HalTaskIsr(void)
{
    /* call the application callback */
    if (pfTaskCb != (void *)0)
    {
        pfTaskCb();
    }
}

#if 0 // Using MCAL GPT Interrupt TIMER
void _HalTaskIsr(uint8 nId)
{
    HalTaskIsr();
}
#endif
#endif

bool adi_wil_hal_TaskStart(uint32_t iPeriodUs, void(*pfCb)(void))
{
#if 0 // @SURE - BLOCKED
    boolean result;
    IfxStm_CompareConfig HalTask;

#if defined(TASK_DEBUG_ENABLE)
    IfxPort_setPinModeOutput(TASK_DEBUG_PIN, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
#endif

    /* For portability, use provided functions to convert user requested period to appropriate number of timer ticks and store */
    HalTaskPeriodTicks = (uint32)IfxStm_getTicksFromMicroseconds(HAL_TASK_STM, iPeriodUs);

    IfxStm_initCompareConfig(&HalTask);           /* Initialize the configuration structure with default values */

    HalTask.comparator          = HAL_TASK_COMPARATOR; 
    HalTask.comparatorInterrupt = IfxStm_ComparatorInterrupt_ir1; 
    HalTask.compareOffset       = IfxStm_ComparatorOffset_0; 
    HalTask.compareSize         = IfxStm_ComparatorSize_32Bits; 
    HalTask.ticks               = HalTaskPeriodTicks;              /* Set the number of ticks after which the timer triggers an  interrupt for the first time */
    HalTask.triggerPriority     = ISR_PRIORITY_HAL_TASK;           /* Set the priority of the interrupt */
    HalTask.typeOfService       = IfxSrc_Tos_cpu0;                 /* Set the service provider for the interrupts */

    /* Configure the STM peripheral by passing the user configuration */
    /* IfxStm_initCompare returns true if init was successful */
    result = IfxStm_initCompare(HAL_TASK_STM, &HalTask);

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
        Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_2, iPeriodUs*100U); // 2.5ms
#else
        _TmrId = TestGpt_RegTimer(iPeriodUs, GPT_CONTINUE, _HalTaskIsr);
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


void adi_wil_hal_TaskStop(void)
{
#if 0 // @SURE - BLOCKED
    /* to stop TASK, just disable interrupt. Since the STM timer may be used by other features, this timer should be left running. */
    IfxStm_disableComparatorInterrupt(HAL_TASK_STM, HAL_TASK_COMPARATOR);

    /* clear the callback as well */
    pfTaskCb = (void *)0;
#else
    if(_TmrStart)
    {
#if 1 // Using MCAL GPT Interrupt TIMER
        Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_2);
#else
        //TestGpt_StopTimer(_TmrId);
        TestGpt_ClrTimer(_TmrId);
        _TmrId = 0;
#endif
        _TmrStart = 0;
    }
    /* clear the callback as well */
    pfTaskCb = (void *)0;
#endif
}
