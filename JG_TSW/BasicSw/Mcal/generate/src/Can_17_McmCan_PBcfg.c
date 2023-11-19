
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 28.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-02-15, 15:18:28          !!!IGNORE-LINE!!!               **
**                                                                            **
**  GENERATOR : Build b191017-0938            !!!IGNORE-LINE!!!               **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Can configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2 and **
**                     4.4.0                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* [cover parentID={BDE616FE-5D39-4b9d-9390-8351CC6C490C}]
[/cover] */
/* Include CAN Driver Header File */
#include "Can_17_McmCan.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
                  /* CAN L-PDU Receive Callout Function */
/******************************************************************************/

extern boolean TestCan_RxCalloutFunc (const Can_HwHandleType Hrh,
                      const Can_IdType CanId,
                      const uint8 CanDlc,
                      const uint8 *CanSduPtr);
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
               Can Controller Configurations for Core0
********************************************************************************
    { Can node Base Address,Combination value of Rx pin select and
    Loopback mode Support,{First Tx Hardware Object, No.of Tx Hardware Objects,
    First Rx Standard Hardware Object, No.of Rx Standard Hardware Objects,
    First Rx Extended Hardware Object, No.of Rx Extended Hardware Objects},
    Default baudrate Config index,First baudrate index for the controller,
    No.of baudrate configuration,Associated kernel Id, Controller Hw Id,
    Logical controller Id,[FD support status] }
********************************************************************************
       Note: [1] The configuration shall be generated only for the activated
                 controller
             [2] The Generation of FD support status Shall be enabled only if
             atleast one of the baudrates configured in the configuration set is
             FD.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerConfigType \
  Can_17_McmCan_kControllerConfigCore0[4] =
{
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0208100U,
    /* combination of Loopback and receive input pin selection setting */
    0x1U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x0U,
      /* Total no of Tx Message configured */
      0xcU,
      /* Rx Message SID filter mask start Index */
      0x0U,
      /* Total no of SID filter mask configured */
      0x9U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x0U,
    /* Start index value of Baudrate configuration */
    0x0U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x0U,
    /* The CAN controller Hw Index */
    0x00U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    0,
    /* FD support status of the controller */
    TRUE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_INTERRUPT,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2001006U,
  },
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0208500U,
    /* combination of Loopback and receive input pin selection setting */
    0x4U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0xcU,
      /* Total no of Tx Message configured */
      0xcU,
      /* Rx Message SID filter mask start Index */
      0x9U,
      /* Total no of SID filter mask configured */
      0x1U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x1U,
    /* Start index value of Baudrate configuration */
    0x1U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x0U,
    /* The CAN controller Hw Index */
    0x01U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    1,
    /* FD support status of the controller */
    TRUE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2081000U,
  },
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0208900U,
    /* combination of Loopback and receive input pin selection setting */
    0x1U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x18U,
      /* Total no of Tx Message configured */
      0x2U,
      /* Rx Message SID filter mask start Index */
      0xaU,
      /* Total no of SID filter mask configured */
      0x41U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x2U,
    /* Start index value of Baudrate configuration */
    0x2U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x0U,
    /* The CAN controller Hw Index */
    0x02U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    2,
    /* FD support status of the controller */
    TRUE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_INTERRUPT,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_INTERRUPT,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2001066U,
  },
  {
    /* Can controller Base Node address */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Node structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN_N*)0xf0208d00U,
    /* combination of Loopback and receive input pin selection setting */
    0x4U,
    /* The controller Hw object configuration mapping information */
    {
      /* Tx Message storage start Index */
      0x1aU,
      /* Total no of Tx Message configured */
      0x1U,
      /* Rx Message SID filter mask start Index */
      0x4bU,
      /* Total no of SID filter mask configured */
      0x1U,
      /* Rx Message XID filter mask start Index */
      0x0U,
      /* Total no of XID filter mask configured */
      0x0U
    },
    /* Default baudrate configuration Index */
    0x3U,
    /* Start index value of Baudrate configuration */
    0x3U,
    /* Total no of Baudrate configuration */
    0x1U,
    /* The controller Associated Kernel configuration Index */
    0x0U,
    /* The CAN controller Hw Index */
    0x03U,
    /* The CAN controller Logical Hw Index - Controller ID defined by user */
    3,
    /* FD support status of the controller */
    TRUE,
    /* RxFIFO0 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* RxFIFO1 Processing configuration */
    CAN_17_MCMCAN_RX_FIFO_NOT_CONFIGURED,
    /* Hrh polling mask for NDAT1 */
    0x0U,
    /* Hrh polling mask for NDAT2 */
    0x0U,
    /* Hth polling mask for the controller */
    0x0U,
    /* Interrupt mask for the controller */
    0x2081000U,
  }
};

/*******************************************************************************
              Controller Id to Index Map configuration for Core0
********************************************************************************
    {Array holding the respective logical Controller ID at the core specific
    controller index }
********************************************************************************
           Note: This shall be generated only for the controllers allocated
           for the current core.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerIndexType \
  Can_17_McmCan_kControllerIndexingCore0[4] =
{0,1,2,3};

/*******************************************************************************
              Message RAM partition configuration for Core0
********************************************************************************
      {{start address of SID section,start address of XID section,
      start address of FIFO0 section,start address of FIFO1 section,start
      address of Rx dedicated buffer section,start address of Tx Event section,
      start address of Tx dedicated buffer section},Tx_ded_Buff size,
      Tx_Evnt size,[Rx_FIFO0 size],[Rx_FIFO0 Threshold],[Rx_FIFO1 size],
      [Rx_FIFO1 Threshold],[Tx_Queue size],[Tx_Queue Enable Status]}
********************************************************************************
           Note: This shall be generated only for the activated controller
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerMsgRAMConfigType \
  Can_17_McmCan_kControllerMsgRAMMapConfigCore0[4] =
{
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0200000UL,
      0x00000000UL,
      0xf0200024UL,
      0x00000000UL,
      0x00000000UL,
      0xf02002acUL,
      0xf020030cUL
    },
    0xcU,
    0xcU,
    0x9U,
    0x1U,
    0x0U,
    0x0U},
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf020066cUL,
      0x00000000UL,
      0x00000000UL,
      0x00000000UL,
      0xf0200670UL,
      0xf02006b8UL,
      0xf0200718UL
    },
    0xcU,
    0xcU,
    0x0U,
    0x0U,
    0x0U,
    0x0U},
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0200a78UL,
      0x00000000UL,
      0xf0200b7cUL,
      0xf0201a1cUL,
      0x00000000UL,
      0xf0201dc4UL,
      0xf0201dd4UL
    },
    0x2U,
    0x2U,
    0x34U,
    0x1U,
    0xdU,
    0x1U},
  {
    /* Start Address of each section within the Message RAM */
    {
      0xf0201e64UL,
      0x00000000UL,
      0x00000000UL,
      0x00000000UL,
      0xf0201e68UL,
      0xf0201eb0UL,
      0xf0201eb8UL
    },
    0x1U,
    0x1U,
    0x0U,
    0x0U,
    0x0U,
    0x0U}
};

/*******************************************************************************
            CAN Controller Baudrate Configurations for Core0
********************************************************************************
           { CANx_NBTP value, Configured Baudrate ,FDBaudrate config Index ,
             FD Support Status  }
********************************************************************************
                           Baudrate Setting
    (uint32)((NSJW << 25)|(NBRP << 16)|(TSEG1 << 8)|(TSEG2))
    NSJW   -> CanControllerSyncJumpWidth - 1
    NTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
    NTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerBaudrateConfigType \
  Can_17_McmCan_kBaudrateConfigCore0[4] =
{
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 1 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6013e0fU,
    500U,
    0x0U,
    TRUE
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 1 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6013e0fU,
    500U,
    0x1U,
    TRUE
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 1 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6013e0fU,
    500U,
    0x2U,
    TRUE
  },
  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 1 */
    /* NSJW   -> 3  */
    /* NTSEG1 -> 62  */
    /* NTSEG2 -> 15  */
    0x6013e0fU,
    500U,
    0x3U,
    TRUE
  }
};

/*******************************************************************************
                CAN Controller FD Config Parameters for Core0
********************************************************************************
           { CANx_DBTP value, TrcvDelayCompensationOffset, BRS Status }
********************************************************************************

        (uint32)((DBRP << 16)|(DTSEG1 << 8)|(DTSEG2 << 4)|(DSJW ))
        DSJW   -> CanControllerSyncJumpWidth - 1
        DTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
        DTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_ControllerFDBaudrateConfigType \
  Can_17_McmCan_kFDBaudrateConfigCore0[4] =
{
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 7 */
    /* DSJW   -> 0  */
    /* DTSEG1 -> 2  */
    /* DTSEG2 -> 0  */
    0x70200U,
    0x0U,
    TRUE
  },
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 7 */
    /* DSJW   -> 0  */
    /* DTSEG1 -> 2  */
    /* DTSEG2 -> 0  */
    0x70200U,
    0x0U,
    TRUE
  },
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 7 */
    /* DSJW   -> 0  */
    /* DTSEG1 -> 2  */
    /* DTSEG2 -> 0  */
    0x70200U,
    0x0U,
    TRUE
  },
  {
    /* Configured FD Baudrate -> 2000 kbps */
    /* Actual Baudrate     -> 2000.0 kbps */
    /* DBRP   -> 7 */
    /* DSJW   -> 0  */
    /* DTSEG1 -> 2  */
    /* DTSEG2 -> 0  */
    0x70200U,
    0x0U,
    TRUE
  }
};

/*******************************************************************************
    CAN Controller Handling of Events for Core0 : Interrupt/Polling
********************************************************************************
        { CanTxProcessing Mode, CanRxProcessing Mode,
          CanBusoffProcessing Mode, CanWakeupProcessing Mode }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/
/* CanConfigSet -> CAN Controller - Handling of Events */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_EventHandlingType \
  Can_17_McmCan_kEventHandlingConfigCore0[4] =
{
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  },
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  },
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  },
  {
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT,
      CAN_17_MCMCAN_INTERRUPT
  }
};
/*******************************************************************************
               Receive Hardware Object Configurations for Core0
********************************************************************************
        This is the combination of SID filter elements
        Rx Object -> { Combination of Mask and filter value S0, HRH HwObject Id,
        Hw Controller Id, Rx BufferType, [Pretended Support Status] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_SIDFilterConfigType \
  Can_17_McmCan_kSIDFilterConfigCore0[76] =
{
  {
    0x890007ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890107ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890207ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890307ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890407ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x8fdf07ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x8fe007ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x8fe407ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x8fe507ffU,
    0U,
    0U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0xbfff0000U,
    1U,
    1U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  },
  {
    0x890507ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890607ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890707ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x890807ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891007ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891107ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891207ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891307ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891407ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891507ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891607ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891707ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891807ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891907ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891a07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891b07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891c07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891d07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891e07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x891f07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892007ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892107ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892207ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892307ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892407ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892507ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892607ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892707ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892807ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892907ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892a07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892b07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892c07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892d07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892e07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x892f07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893007ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893107ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893207ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893307ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893407ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893507ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893607ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893707ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893807ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893907ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893a07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893b07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893c07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893d07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893e07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x893f07ffU,
    2U,
    2U,
    CAN_17_MCMCAN_RX_FIFO0
  },
  {
    0x918007ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918107ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918207ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918307ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918407ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918507ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918607ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918707ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918807ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918907ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918a07ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x918b07ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0x966607ffU,
    3U,
    2U,
    CAN_17_MCMCAN_RX_FIFO1
  },
  {
    0xbfff0000U,
    4U,
    3U,
    CAN_17_MCMCAN_RX_DED_BUFFER
  }
};
/*******************************************************************************
           Transmit Hardware Object Configurations for Core0
********************************************************************************
 Tx Object -> { CanTxHwObjId, CanTxBuffIndx, HwControllerId, [CanFdPaddValue],
               CanTxHwObjIdType , CanTxBufferType, CanTrigTxStatus}
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_TxHwObjectConfigType \
  Can_17_McmCan_kTxHwObjectConfigCore0[27] =
{
  {
    5U,
    0U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    6U,
    1U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    7U,
    2U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    8U,
    3U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    9U,
    4U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    10U,
    5U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    11U,
    6U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    12U,
    7U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    13U,
    8U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    14U,
    9U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    15U,
    10U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    16U,
    11U,
    0U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    17U,
    0U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    18U,
    1U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    19U,
    2U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    20U,
    3U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    21U,
    4U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    22U,
    5U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    23U,
    6U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    24U,
    7U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    25U,
    8U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    26U,
    9U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    27U,
    10U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    28U,
    11U,
    1U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    29U,
    0U,
    2U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    30U,
    1U,
    2U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  },
  {
    31U,
    0U,
    3U,
    0U,
    CAN_17_MCMCAN_ID_STANDARD,
    CAN_17_MCMCAN_TX_DED_BUFFER,
    FALSE
  }
};

/******************************************************************************/
             /* CAN Configuration Pointer for Core0 */
/******************************************************************************/
    /* Core sepcific CAN configurations */
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_CoreConfigType \
  Can_17_McmCan_kMcmCanConfigCore0=
{
  /* Number of controllers configured for the core */
  4,
  /* Array of all the controllers configured */
  &Can_17_McmCan_kControllerIndexingCore0[0],
  /* Pointer to CAN controller configuration settings */
  &Can_17_McmCan_kControllerConfigCore0[0],
  /* Pointer to Message RAM configuration settings */
  &Can_17_McmCan_kControllerMsgRAMMapConfigCore0[0],
  /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
  &Can_17_McmCan_kEventHandlingConfigCore0[0],
  /* Pointer to Baudrate configuration settings */
  &Can_17_McmCan_kBaudrateConfigCore0[0],
  /* Pointer to FDBaudrate configuration settings */
  &Can_17_McmCan_kFDBaudrateConfigCore0[0],
  /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping */
  &Can_17_McmCan_kTxHwObjectConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Standard
     messages */
  &Can_17_McmCan_kSIDFilterConfigCore0[0],
  /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Extended
  messages */
  NULL_PTR
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
              CAN Kernel configuration parameters
********************************************************************************
     { CAN Global Kernel Address, The status of the nodes in the configured
     kernel }
********************************************************************************
           Note: 1. If any of CAN controllers in the kernel is not activated
                 then, the configuration for that kernel will not be generated.
                 2. CAN controllers that are activated in the kernel will be
                 set to True state and the pending controller nodes shall be
                 set to False state.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_McmModuleConfigType \
  Can_17_McmCan_kMcmCanModuleConfig[1] =
{
  {
    /* The Global Base address of Kernel module */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
    cast the generated address with CAN Kernel structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
    integer type. Permitted for special function registers.*/
    (volatile Ifx_CAN*) 0xf0200000U,
    /* The CAN node is enabled or not within the kernel*/
    {
      /* Node 0 of kernel enable state */
      TRUE,
      /* Node 1 of kernel enable state */
      TRUE,
      /* Node 2 of kernel enable state */
      TRUE,
      /* Node 3 of kernel enable state */
      TRUE
    }
  }
};
/*******************************************************************************
              Overall CAN Hth Indexing Configuration
********************************************************************************
     { Hth handle Core assignment, Hth handle logical index (HOH ID),
     Hth handle core specific index}
********************************************************************************
           Note: 1. If there are no Transmit objects configured, this structure
           shall not be generated.
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_HthIndexType \
  Can_17_McmCan_kMcmCanHthIndexConfig[27] =
{
  {0,0,0},
  {0,0,1},
  {0,0,2},
  {0,0,3},
  {0,0,4},
  {0,0,5},
  {0,0,6},
  {0,0,7},
  {0,0,8},
  {0,0,9},
  {0,0,10},
  {0,0,11},
  {0,1,12},
  {0,1,13},
  {0,1,14},
  {0,1,15},
  {0,1,16},
  {0,1,17},
  {0,1,18},
  {0,1,19},
  {0,1,20},
  {0,1,21},
  {0,1,22},
  {0,1,23},
  {0,2,24},
  {0,2,25},
  {0,3,26}
};
/*******************************************************************************
              Overall CAN Logical Controller Indexing Configuration
********************************************************************************
     { CAN Controller Core assignment, CAN logical indexing indicating the core
       specific indexing,Physical node index and kernel index}
********************************************************************************
           Note:
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_LogicalControllerIndexType \
  Can_17_McmCan_kMcmCanLogicContIndexConfig[4] =
{
  {0,0,0,0},
  {0,1,1,0},
  {0,2,2,0},
  {0,3,3,0}
};
/******************************************************************************/
        /* Overall Physical CAN Controller Indexing Configuration */
/******************************************************************************/
      /* Physical CAN indexing indicating the Logical controller ID,
         Core specific controller ID and Core assignment.
         This has a constant array size of 12
         i.e.(PhyKernelID * No of Node in kernel)+(PhyNodeID)*/
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
static const Can_17_McmCan_PhyControllerIndexType \
  Can_17_McmCan_kMcmCanPhyContIndexConfig[12] =
{
  {0,0,0},
  {1,1,0},
  {2,2,0},
  {3,3,0},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255},
  {255,255,255}
};
/******************************************************************************/
                  /* Overall CAN Configuration */
/******************************************************************************/
      /* Over all CAN configurations, structure that points to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using CAN Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Can_17_McmCan_ConfigType \
  Can_17_McmCan_Config=
{
  /********************* Core specific configuration set **********************/
  /* Pointer to the Core specific CAN configuration set */
  {
    &Can_17_McmCan_kMcmCanConfigCore0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
  },
  /****************** Global data shared amongst all cores ********************/
  /* Number of Kernels configured */
  1U,
  /* Number of Hrh configured */
  (Can_HwHandleType)5U,
  /* The number of hardware objects (includes Tx and Rx) configured in a
  ConfigSet */
  (Can_HwHandleType) 32U,

  /* Trigger transmit Enabled or not */
FALSE,

  /* Pointer to CAN Kernel configuration */
  &Can_17_McmCan_kMcmCanModuleConfig[0],
  /* Pointer holding physical controller index data */
  &Can_17_McmCan_kMcmCanPhyContIndexConfig[0],
  /* Pointer holding logical controller index data */
  &Can_17_McmCan_kMcmCanLogicContIndexConfig[0],
  /* Pointer holding configured Hth index data */
  &Can_17_McmCan_kMcmCanHthIndexConfig[0],
  /* CAN L-PDU Receive Callout Function */
  (Can_17_McmCan_LPduRxCalloutFnPtrType) TestCan_RxCalloutFunc
  /* MISRA2012_RULE_11_3_JUSTIFICATION: cast between pointer to another type does not cause any side effect.*/
  /* MISRA2012_RULE_11_1_JUSTIFICATION: cast between pointer to another type does not cause any side effect.*/
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

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
**                      Private Function Definitions                          **
*******************************************************************************/
