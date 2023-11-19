/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dma_PBCfg.c                                                   **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-04-10, 15:29:39               !!!IGNORE-LINE !!!         **
**                                                                            **
**  GENERATOR : Build b191017-0938                 !!!IGNORE-LINE !!!         **
**                                                                            **
**  BSW MODULE DECRIPTION : NA                                                **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dma configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Dma.h"

/*******************************************************************************
**                    Customer specific includes                              **
*******************************************************************************/

/*******************************************************************************
**          Resource partition error notification functions                   **
*******************************************************************************/

/* User defined notification functions to be called by DMA driver in case
 * of error from the resource partitions */
/* Error notification function from Resource Partition 0 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 1 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 2 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 3 */
/* <**No notification function is configured for this resource partition**> */
/* ************************************************************************** */

/*******************************************************************************
**              Channel specific notification functions                       **
*******************************************************************************/

/* User defined notification functions for channels to be called by
 * the DMA driver in case of channel interrupts */
/* <***** No Channel specific notifications are configured *****> */
/* ******************************************************************* */


/* ***************** Configuration of the TCSes ***************** */
              
          
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */


#include "Dma_MemMap.h"

/* DMA channel 2 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_2_TcsConfigRoot[]=
{
  /* Dma Channel 2 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The source address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the source address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the source address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The dest address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the dest address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the dest address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The shadow address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the shadow address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the shadow address */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

              
          
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */


#include "Dma_MemMap.h"

/* DMA channel 3 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_3_TcsConfigRoot[]=
{
  /* Dma Channel 3 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The source address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the source address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the source address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The dest address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the dest address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the dest address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The shadow address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the shadow address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the shadow address */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

              
          
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */


#include "Dma_MemMap.h"

/* DMA channel 5 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_5_TcsConfigRoot[]=
{
  /* Dma Channel 5 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The source address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the source address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the source address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The dest address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the dest address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the dest address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The shadow address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the shadow address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the shadow address */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

              
          
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */


#include "Dma_MemMap.h"

/* DMA channel 6 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_6_TcsConfigRoot[]=
{
  /* Dma Channel 6 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The source address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the source address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the source address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The dest address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the dest address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the dest address */
    (uint32 *)NULL_PTR,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: The shadow address type needs the typecast here. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Typecast to be done for the shadow address */
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Typecast to be done for the shadow address */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

/* ************************************************************** */

/* *************** Channel root configuration list ************** */


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
/* Configuration of all the DMA channels */
static const Dma_ChConfigType Dma_kChConfigRoot_Core0[]=
{
  {
    &Dma_kChannel_2_TcsConfigRoot[0U], /* TCS config Root */
    NULL_PTR, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)2U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
  {
    &Dma_kChannel_3_TcsConfigRoot[0U], /* TCS config Root */
    NULL_PTR, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)3U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
  {
    &Dma_kChannel_5_TcsConfigRoot[0U], /* TCS config Root */
    NULL_PTR, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)5U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
  {
    &Dma_kChannel_6_TcsConfigRoot[0U], /* TCS config Root */
    NULL_PTR, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)6U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  }};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"



/* *************************************************************** */
/* ************* Configuration structure of each core ************* */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
static const Dma_CoreSpecificChConfigType Dma_ChConfigRootCore0=
{
  /* Core specific config pointer */
  &Dma_kChConfigRoot_Core0[0],
  /* Total number of DMA channels in core 0 */
  4
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
/* **************************************************************** */

/* ************* Base Configuration Structure of DMA ************* */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
#include "Dma_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
declaration as per Autosar guidelines. This data structure may be needed
by SW units using Mcu Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Dma_ConfigType Dma_Config=
{
  
  {
    /* Channel Configuration root for Core 0*/
    /* This is the number of resources:0 */
    &Dma_ChConfigRootCore0,
    /* Channel Configuration root for Core 1*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 2*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 3*/
    /* This is the number of resources:0 */
    NULL_PTR,
  },
  /* MoveEngine Error config for ME0 and ME1 */
  {0X00000000U,0X00000000U},
  /* Access partition configuration */
  {
    /* Bus master configuration */
    {0XFFFFFFFFU,0XFFFFFFFFU,0XFFFFFFFFU,0XFFFFFFFFU},
    /* Resource partition configuration */
    {  0X01U,  0X01U,  0X01U,  0X01U}
  },
  /* { Channel Position Index, Channel Core Map } - The mapping data of channels */
  {
    {255, 255 }, /* Channel 0 */
    {255, 255 }, /* Channel 1 */
    {0, 0 }, /* Channel 2 */
    {1, 0 }, /* Channel 3 */
    {255, 255 }, /* Channel 4 */
    {2, 0 }, /* Channel 5 */
    {3, 0 }, /* Channel 6 */
    {255, 255 }, /* Channel 7 */
    {255, 255 }, /* Channel 8 */
    {255, 255 }, /* Channel 9 */
    {255, 255 }, /* Channel 10 */
    {255, 255 }, /* Channel 11 */
    {255, 255 }, /* Channel 12 */
    {255, 255 }, /* Channel 13 */
    {255, 255 }, /* Channel 14 */
    {255, 255 }, /* Channel 15 */
    {255, 255 }, /* Channel 16 */
    {255, 255 }, /* Channel 17 */
    {255, 255 }, /* Channel 18 */
    {255, 255 }, /* Channel 19 */
    {255, 255 }, /* Channel 20 */
    {255, 255 }, /* Channel 21 */
    {255, 255 }, /* Channel 22 */
    {255, 255 }, /* Channel 23 */
    {255, 255 }, /* Channel 24 */
    {255, 255 }, /* Channel 25 */
    {255, 255 }, /* Channel 26 */
    {255, 255 }, /* Channel 27 */
    {255, 255 }, /* Channel 28 */
    {255, 255 }, /* Channel 29 */
    {255, 255 }, /* Channel 30 */
    {255, 255 }, /* Channel 31 */
    {255, 255 }, /* Channel 32 */
    {255, 255 }, /* Channel 33 */
    {255, 255 }, /* Channel 34 */
    {255, 255 }, /* Channel 35 */
    {255, 255 }, /* Channel 36 */
    {255, 255 }, /* Channel 37 */
    {255, 255 }, /* Channel 38 */
    {255, 255 }, /* Channel 39 */
    {255, 255 }, /* Channel 40 */
    {255, 255 }, /* Channel 41 */
    {255, 255 }, /* Channel 42 */
    {255, 255 }, /* Channel 43 */
    {255, 255 }, /* Channel 44 */
    {255, 255 }, /* Channel 45 */
    {255, 255 }, /* Channel 46 */
    {255, 255 }, /* Channel 47 */
    {255, 255 }, /* Channel 48 */
    {255, 255 }, /* Channel 49 */
    {255, 255 }, /* Channel 50 */
    {255, 255 }, /* Channel 51 */
    {255, 255 }, /* Channel 52 */
    {255, 255 }, /* Channel 53 */
    {255, 255 }, /* Channel 54 */
    {255, 255 }, /* Channel 55 */
    {255, 255 }, /* Channel 56 */
    {255, 255 }, /* Channel 57 */
    {255, 255 }, /* Channel 58 */
    {255, 255 }, /* Channel 59 */
    {255, 255 }, /* Channel 60 */
    {255, 255 }, /* Channel 61 */
    {255, 255 }, /* Channel 62 */
    {255, 255 }, /* Channel 63 */
    {255, 255 }, /* Channel 64 */
    {255, 255 }, /* Channel 65 */
    {255, 255 }, /* Channel 66 */
    {255, 255 }, /* Channel 67 */
    {255, 255 }, /* Channel 68 */
    {255, 255 }, /* Channel 69 */
    {255, 255 }, /* Channel 70 */
    {255, 255 }, /* Channel 71 */
    {255, 255 }, /* Channel 72 */
    {255, 255 }, /* Channel 73 */
    {255, 255 }, /* Channel 74 */
    {255, 255 }, /* Channel 75 */
    {255, 255 }, /* Channel 76 */
    {255, 255 }, /* Channel 77 */
    {255, 255 }, /* Channel 78 */
    {255, 255 }, /* Channel 79 */
    {255, 255 }, /* Channel 80 */
    {255, 255 }, /* Channel 81 */
    {255, 255 }, /* Channel 82 */
    {255, 255 }, /* Channel 83 */
    {255, 255 }, /* Channel 84 */
    {255, 255 }, /* Channel 85 */
    {255, 255 }, /* Channel 86 */
    {255, 255 }, /* Channel 87 */
    {255, 255 }, /* Channel 88 */
    {255, 255 }, /* Channel 89 */
    {255, 255 }, /* Channel 90 */
    {255, 255 }, /* Channel 91 */
    {255, 255 }, /* Channel 92 */
    {255, 255 }, /* Channel 93 */
    {255, 255 }, /* Channel 94 */
    {255, 255 }, /* Channel 95 */
    {255, 255 }, /* Channel 96 */
    {255, 255 }, /* Channel 97 */
    {255, 255 }, /* Channel 98 */
    {255, 255 }, /* Channel 99 */
    {255, 255 }, /* Channel 100 */
    {255, 255 }, /* Channel 101 */
    {255, 255 }, /* Channel 102 */
    {255, 255 }, /* Channel 103 */
    {255, 255 }, /* Channel 104 */
    {255, 255 }, /* Channel 105 */
    {255, 255 }, /* Channel 106 */
    {255, 255 }, /* Channel 107 */
    {255, 255 }, /* Channel 108 */
    {255, 255 }, /* Channel 109 */
    {255, 255 }, /* Channel 110 */
    {255, 255 }, /* Channel 111 */
    {255, 255 }, /* Channel 112 */
    {255, 255 }, /* Channel 113 */
    {255, 255 }, /* Channel 114 */
    {255, 255 }, /* Channel 115 */
    {255, 255 }, /* Channel 116 */
    {255, 255 }, /* Channel 117 */
    {255, 255 }, /* Channel 118 */
    {255, 255 }, /* Channel 119 */
    {255, 255 }, /* Channel 120 */
    {255, 255 }, /* Channel 121 */
    {255, 255 }, /* Channel 122 */
    {255, 255 }, /* Channel 123 */
    {255, 255 }, /* Channel 124 */
    {255, 255 }, /* Channel 125 */
    {255, 255 }, /* Channel 126 */
    {255, 255 }, /* Channel 127 */
  },
  {
    /* Bit map of the channels with TRL enabled */
    0x0U,
    0x0U,
    0x0U,
    0x0U,
  },
  /* Total number of DMA channels */
  0X00000004U,
};
/* ************************************************************** */


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
