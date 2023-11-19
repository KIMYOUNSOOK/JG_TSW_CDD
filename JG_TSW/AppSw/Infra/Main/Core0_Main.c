/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Cpu0_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2016-08-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Example Cpu0 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
#ifdef AURIX2G_MCAL_DEMOAPP
#include "DemoApp.h"
#else
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
#include "IfxScu_reg.h"
#include "IfxSrc_reg.h"
#include "IfxAsclin_reg.h"
#include "IfxPms_reg.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Irq.h"
#include "Port.h"
#include "Spi.h"
#include "Adc.h"
#include "Icu_17_TimerIp.h"
#include "SchM_Can_17_McmCan.h"
#include "Can_17_McmCan.h"
#include "Lin_17_AscLin.h"
#include "Dma.h"

//#include "Cmic_Conf.h"
#include "TestStm.h"
#include "TestApp.h"
#if 0 /* RSW */
#include "TestCan.h"
#endif
#endif
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void _Init_Mcu(void);
static void _Init_Gpt(void);
static void _Init_Port(void);
static void _Init_Dma(void);
static void _Init_Spi(void);
static void _Init_Adc(void);
static void _Init_Icu(void);
static void _Init_Can(void);
static void _Init_AscLin(void);
#if 0
static void _Init_FlsDmu(void);
#endif
#if 0
static void _Init_FlsLoader(void);
#endif


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

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

void core0_main (void)
{
  volatile unsigned short LoopFlag = 1U;
  unsigned short cpuWdtPassword;
  unsigned short safetyWdtPassword;


  ENABLE();
  /*
   * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
   * Enable the watchdog in the demo if it is required and also service the watchdog periodically
   * */
  cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
  safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
  Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);
  Ifx_Ssw_disableSafetyWatchdog(safetyWdtPassword);

#ifdef AURIX2G_MCAL_DEMOAPP
  DemoApp_Init();
  DemoApp();
#else
  _Init_Mcu();
  _Init_Port();
  _Init_Gpt();
  _Init_Dma();
  _Init_Spi();
  _Init_Adc();
  _Init_Icu();
  _Init_Can();
  _Init_AscLin();

  TestApp_Init();
#endif
  
  while (LoopFlag == 1U)
  {
#if 1 // Using MCAL GPT Interrupt TIMER
    #if 0 /* RSW */
    if(CAN_IsRswDownload())
    {
        TestApp_RunTask();
    }
    #else
    //TestApp_RunTask();
    #endif
#endif
  }
}

/*******************************************************************************
** Function Name    : _Init_Mcu
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Mcu(void)
{
    const Mcu_ConfigType *pConfig = NULL_PTR;
    volatile Mcu_ClockType nClockId = 0U;
    Std_ReturnType nInitClockRetVal;
    Mcu_PllStatusType eMcu_GetPllStatusRetVal = MCU_PLL_STATUS_UNDEFINED;

    pConfig = &Mcu_Config;
    Mcu_Init(pConfig);
    nInitClockRetVal = Mcu_InitClock(nClockId);

    if (nInitClockRetVal == E_OK)
    {
        do
        {
            eMcu_GetPllStatusRetVal = Mcu_GetPllStatus();
        }while (eMcu_GetPllStatusRetVal != MCU_PLL_LOCKED);
    }

#if (MCU_DISTRIBUTE_PLL_CLOCK_API == STD_ON)
    Mcu_DistributePllClock();
#endif

#if 0 // FREQ.SPREAD CONTROL
    unsigned short safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
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
    Ifx_Ssw_clearSafetyEndinit(safetyWdtPassword);
    PMS_EVRSDCTRL0.U = 0x3039000A; // 0x30390001 => 0x3039000A
    Ifx_Ssw_setSafetyEndinit(safetyWdtPassword);
#endif

} /*End of _Init_Mcu */

/*******************************************************************************
** Function Name    : _Init_Gpt
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Gpt(void)
{
    /* Initialiase interrupt request configurations */
#if (MCU_GTM_USED == STD_ON)
    IrqGtm_Init();
    SRC_GTMATOM00.B.SRE = 1U;
    SRC_GTMATOM10.B.SRE = 1U;
#if 1 // Using MCAL GPT Interrupt TIMER
    SRC_GTMATOM20.B.SRE = 1U;
    SRC_GTMATOM30.B.SRE = 1U;
    SRC_GTMATOM40.B.SRE = 1U;
    #endif
#endif
    IrqGpt_Init();

    /* Initialize GPT driver */
    Gpt_Init(&Gpt_Config);

#if 1 // Using MCAL GPT Interrupt TIMER
    #if !(CMIC_CONF_ONLY_ADI_WIL_RUN)
    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    /* Start timer for system tick generation */
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 1000U); // 10us
    //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 10000U); // 100us
    //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 100000U); // 1ms
    //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 1000000U); // 10ms
    #endif
#endif

#if 1 // Using MCAL GPT Interrupt TIMER
    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1); // 3ms

    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_2); // 2.5ms

    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_3); // 1ms
    
    /* Enable notification for system tick generation */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_4); // 50ms
#endif

} /*End of _Init_Gpt */

/*******************************************************************************
** Function Name    : _Init_Port
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Port(void)
{
    const Port_ConfigType * pConfig = NULL_PTR;
    pConfig = &Port_Config;
    Port_Init(pConfig);

} /*End of _Init_Port */

/*******************************************************************************
** Function Name    : _Init_Can
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Can(void)
{
    #define CAN_SRC_SET_SRE (0x00000400U)

    /* Initialize CAN interrupt */
    IrqCan_Init();

    Can_17_McmCan_Init(&Can_17_McmCan_Config);

    /* Enter Critical Section */
    SchM_Enter_Can_17_McmCan_CanIntCtrl();

    /* CAN0:CAN00 - GCAN */
    SRC_CAN_CAN0_INT0.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT1.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT2.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT3.U |= CAN_SRC_SET_SRE;

    /* CAN0:CAN01 - QCCAN */
    SRC_CAN_CAN0_INT4.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT5.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT6.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT7.U |= CAN_SRC_SET_SRE;

    /* CAN0:CAN02 - SUBCAN */
    SRC_CAN_CAN0_INT8.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT9.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT10.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT11.U |= CAN_SRC_SET_SRE;

    /* CAN0:CAN03 - MCAN */
    SRC_CAN_CAN0_INT12.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT13.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT14.U |= CAN_SRC_SET_SRE;
    SRC_CAN_CAN0_INT15.U |= CAN_SRC_SET_SRE;

    /* Exit Critical Section */
    SchM_Exit_Can_17_McmCan_CanIntCtrl();

    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_0_GCAN, CAN_T_START);
    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_1_QCCAN, CAN_T_START);
    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_2_SUBCAN, CAN_T_START);
    Can_17_McmCan_SetControllerMode(Can_17_McmCanConf_CanController_CanController_3_MCAN, CAN_T_START);

} /*End of _Init_Can */

/*******************************************************************************
** Function Name    : _Init_Dma
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Dma(void)
{
    const Dma_ConfigType * ConfigPtr = NULL_PTR;

    /* Initialiase interrupt request configurations */
    IrqDma_Init();

#if 0 // No need to set
    /* SPI0 - CMIC2 */
    SRC_DMACH2.B.SRE = 1; // SPI0_TX
    SRC_DMACH3.B.SRE = 1; // SPI0_RX
    /* SPI1 - CMIC1 */
    SRC_DMACH5.B.SRE = 1; // SPI1_TX
    SRC_DMACH6.B.SRE = 1; // SPI1_RX
#endif

    ConfigPtr = &Dma_Config;
    Dma_Init(ConfigPtr);

} /*End of _Init_Dma */

/*******************************************************************************
** Function Name    : _Init_Spi
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Spi(void)
{
    const Spi_ConfigType * pConfig = NULL_PTR;

    /* Initialize SPI driver */
    pConfig = &Spi_Config;
    Spi_Init(pConfig);

    /* Initialiase interrupt request configurations */
    IrqSpi_Init();
#if 1 // DMA
    /* SPI0 - CMIC2 */
    SRC_QSPI0RX.B.SRE = 1;
    SRC_QSPI0TX.B.SRE = 1;
    SRC_QSPI0ERR.B.SRE = 1;
    SRC_QSPI0PT.B.SRE = 1;
    SRC_QSPI0U.B.SRE = 1;

    /* SPI4 - CMIC1 */
    SRC_QSPI4RX.B.SRE = 1;
    SRC_QSPI4TX.B.SRE = 1;
    SRC_QSPI4ERR.B.SRE = 1;
    SRC_QSPI4PT.B.SRE = 1;
    SRC_QSPI4U.B.SRE = 1;
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
#endif

} /*End of _Init_Spi */

/*******************************************************************************
** Function Name    : _Init_Adc
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Adc(void)
{
    #define SRE_ENABLE (1U<<10U)

    const Adc_ConfigType * pConfig = NULL_PTR;

    /* Initialize ADC interrupt */
    IrqAdc_Init();

    SRC_VADCG0SR0.U |= SRE_ENABLE;
    SRC_VADCG1SR0.U |= SRE_ENABLE;
    SRC_VADCG2SR0.U |= SRE_ENABLE;
    SRC_VADCG3SR0.U |= SRE_ENABLE;
    SRC_VADCG8SR0.U |= SRE_ENABLE;
    
    pConfig = &Adc_Config;
    Adc_Init(pConfig);

} /*End of _Init_Adc */

/*******************************************************************************
** Function Name    : _Init_Icu
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_Icu(void)
{
    /* enable interrupt system, check McuGtmTimChannelAllocationConf in MCAL module */
    SRC_GTMTIM04.B.SRE = 1U; // check GtmTimGlobalConf_0 4
    SRC_GTMTIM17.B.SRE = 1U; // check GtmTimGlobalConf_1 7

    /* initialize ICU configuration */
    Icu_17_TimerIp_Init(&Icu_17_TimerIp_Config);

} /*End of _Init_Icu */

/*******************************************************************************
** Function Name    : _Init_AscLin
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void _Init_AscLin(void)
{
    IrqAsclin_Init();
    SRC_ASCLIN10TX.B.SRE = 1U;
    SRC_ASCLIN10RX.B.SRE = 1U;
    SRC_ASCLIN10ERR.B.SRE = 1U;

    Lin_17_AscLin_Init(&Lin_17_AscLin_Config);
    Lin_17_AscLin_WakeupInternal(Lin_17_AscLinConf_LinChannel_LinChannel_0);

} /*End of _Init_AscLin */
