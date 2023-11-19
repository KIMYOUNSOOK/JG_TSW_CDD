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
**          FILE  : TestCan.h
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





#ifndef TESTCAN_H
#define TESTCAN_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Can_17_McmCan.h"
#include "Lin_17_AscLin.h"

#if 0 /* RSW */
#include "CanIf.h"
#include "Gen_RCAN.h"
#endif

#if 1 // @SURE - ADI-EXAMPLE
#include "adi_wil_example_debug_functions.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* CAN Transmit Type */
#define TESTCAN_CANTYPE_CLASSICAL_CAN       0U
#define TESTCAN_CANTYPE_FD_CAN              1U

/*
 * CAN Rx ID
 */
/* External */
#define TESTCAN_ID_BMS_RX_00                (uint16)(0x100U)
#define TESTCAN_ID_BMS_RX_01                (uint16)(0x101U)
#define TESTCAN_ID_BMS_RX_02                (uint16)(0x102U)
#define TESTCAN_ID_BMS_RX_03                (uint16)(0x103U)
#define TESTCAN_ID_BMS_RX_04                (uint16)(0x104U)

/* Internal */
/* Sub-MCU State */
#define TESTCAN_ID_BMS_RX_SUB_STATE         (uint16)(0x105U) // 261

/* Sub-MCU Software Version */
#define TESTCAN_ID_BMS_RX_SUB_SW_VERSION1   (uint16)(0x106U) // 262
#define TESTCAN_ID_BMS_RX_SUB_SW_VERSION2   (uint16)(0x107U) // 263
#define TESTCAN_ID_BMS_RX_SUB_SW_VERSION3   (uint16)(0x108U) // 264

/* Sub-MCU Cell Voltage */
#define TESTCAN_ID_BMS_RX_SUB_CV_00         (uint16)(0x110U) // 272
#define TESTCAN_ID_BMS_RX_SUB_CV_01         (uint16)(0x111U)
#define TESTCAN_ID_BMS_RX_SUB_CV_02         (uint16)(0x112U)
#define TESTCAN_ID_BMS_RX_SUB_CV_03         (uint16)(0x113U)
#define TESTCAN_ID_BMS_RX_SUB_CV_04         (uint16)(0x114U)
#define TESTCAN_ID_BMS_RX_SUB_CV_05         (uint16)(0x115U)
#define TESTCAN_ID_BMS_RX_SUB_CV_06         (uint16)(0x116U)
#define TESTCAN_ID_BMS_RX_SUB_CV_07         (uint16)(0x117U)
#define TESTCAN_ID_BMS_RX_SUB_CV_08         (uint16)(0x118U)
#define TESTCAN_ID_BMS_RX_SUB_CV_09         (uint16)(0x119U)
#define TESTCAN_ID_BMS_RX_SUB_CV_10         (uint16)(0x11AU)
#define TESTCAN_ID_BMS_RX_SUB_CV_11         (uint16)(0x11BU)
#define TESTCAN_ID_BMS_RX_SUB_CV_12         (uint16)(0x11CU)
#define TESTCAN_ID_BMS_RX_SUB_CV_13         (uint16)(0x11DU)
#define TESTCAN_ID_BMS_RX_SUB_CV_14         (uint16)(0x11EU)
#define TESTCAN_ID_BMS_RX_SUB_CV_15         (uint16)(0x11FU)
#define TESTCAN_ID_BMS_RX_SUB_CV_16         (uint16)(0x120U)
#define TESTCAN_ID_BMS_RX_SUB_CV_17         (uint16)(0x121U)
#define TESTCAN_ID_BMS_RX_SUB_CV_18         (uint16)(0x122U)
#define TESTCAN_ID_BMS_RX_SUB_CV_19         (uint16)(0x123U)
#define TESTCAN_ID_BMS_RX_SUB_CV_20         (uint16)(0x124U)
#define TESTCAN_ID_BMS_RX_SUB_CV_21         (uint16)(0x125U)
#define TESTCAN_ID_BMS_RX_SUB_CV_22         (uint16)(0x126U)
#define TESTCAN_ID_BMS_RX_SUB_CV_23         (uint16)(0x127U)
#define TESTCAN_ID_BMS_RX_SUB_CV_24         (uint16)(0x128U)
#define TESTCAN_ID_BMS_RX_SUB_CV_25         (uint16)(0x129U)
#define TESTCAN_ID_BMS_RX_SUB_CV_26         (uint16)(0x12AU)
#define TESTCAN_ID_BMS_RX_SUB_CV_27         (uint16)(0x12BU)
#define TESTCAN_ID_BMS_RX_SUB_CV_28         (uint16)(0x12CU)
#define TESTCAN_ID_BMS_RX_SUB_CV_29         (uint16)(0x12DU)
#define TESTCAN_ID_BMS_RX_SUB_CV_30         (uint16)(0x12EU)
#define TESTCAN_ID_BMS_RX_SUB_CV_31         (uint16)(0x12FU)
#define TESTCAN_ID_BMS_RX_SUB_CV_32         (uint16)(0x130U)
#define TESTCAN_ID_BMS_RX_SUB_CV_33         (uint16)(0x131U)
#define TESTCAN_ID_BMS_RX_SUB_CV_34         (uint16)(0x132U)
#define TESTCAN_ID_BMS_RX_SUB_CV_35         (uint16)(0x133U)
#define TESTCAN_ID_BMS_RX_SUB_CV_36         (uint16)(0x134U)
#define TESTCAN_ID_BMS_RX_SUB_CV_37         (uint16)(0x135U)
#define TESTCAN_ID_BMS_RX_SUB_CV_38         (uint16)(0x136U)
#define TESTCAN_ID_BMS_RX_SUB_CV_39         (uint16)(0x137U)
#define TESTCAN_ID_BMS_RX_SUB_CV_40         (uint16)(0x138U)
#define TESTCAN_ID_BMS_RX_SUB_CV_41         (uint16)(0x139U)
#define TESTCAN_ID_BMS_RX_SUB_CV_42         (uint16)(0x13AU)
#define TESTCAN_ID_BMS_RX_SUB_CV_43         (uint16)(0x13BU)
#define TESTCAN_ID_BMS_RX_SUB_CV_44         (uint16)(0x13CU)
#define TESTCAN_ID_BMS_RX_SUB_CV_45         (uint16)(0x13DU)
#define TESTCAN_ID_BMS_RX_SUB_CV_46         (uint16)(0x13EU)
#define TESTCAN_ID_BMS_RX_SUB_CV_47         (uint16)(0x13FU) // 319

/* Sub-MCU TEMP */
#define TESTCAN_ID_BMS_RX_SUB_TEMP_00       (uint16)(0x180U) // 384
#define TESTCAN_ID_BMS_RX_SUB_TEMP_01       (uint16)(0x181U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_02       (uint16)(0x182U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_03       (uint16)(0x183U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_04       (uint16)(0x184U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_05       (uint16)(0x185U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_06       (uint16)(0x186U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_07       (uint16)(0x187U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_08       (uint16)(0x188U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_09       (uint16)(0x189U)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_10       (uint16)(0x18AU)
#define TESTCAN_ID_BMS_RX_SUB_TEMP_11       (uint16)(0x18BU) // 395


/*
 * CAN Tx ID
 */

/* Main-MCU Cell Voltage */
#define TESTCAN_ID_BMS_TX_CV_00             (uint16)(0x200U) // 512
#define TESTCAN_ID_BMS_TX_CV_01             (uint16)(0x201U)
#define TESTCAN_ID_BMS_TX_CV_02             (uint16)(0x202U)
#define TESTCAN_ID_BMS_TX_CV_03             (uint16)(0x203U)
#define TESTCAN_ID_BMS_TX_CV_04             (uint16)(0x204U)
#define TESTCAN_ID_BMS_TX_CV_05             (uint16)(0x205U)
#define TESTCAN_ID_BMS_TX_CV_06             (uint16)(0x206U)
#define TESTCAN_ID_BMS_TX_CV_07             (uint16)(0x207U)
#define TESTCAN_ID_BMS_TX_CV_08             (uint16)(0x208U)
#define TESTCAN_ID_BMS_TX_CV_09             (uint16)(0x209U)
#define TESTCAN_ID_BMS_TX_CV_10             (uint16)(0x20AU)
#define TESTCAN_ID_BMS_TX_CV_11             (uint16)(0x20BU)
#define TESTCAN_ID_BMS_TX_CV_12             (uint16)(0x20CU)
#define TESTCAN_ID_BMS_TX_CV_13             (uint16)(0x20DU)
#define TESTCAN_ID_BMS_TX_CV_14             (uint16)(0x20EU)
#define TESTCAN_ID_BMS_TX_CV_15             (uint16)(0x20FU)
#define TESTCAN_ID_BMS_TX_CV_16             (uint16)(0x210U)
#define TESTCAN_ID_BMS_TX_CV_17             (uint16)(0x211U)
#define TESTCAN_ID_BMS_TX_CV_18             (uint16)(0x212U)
#define TESTCAN_ID_BMS_TX_CV_19             (uint16)(0x213U)
#define TESTCAN_ID_BMS_TX_CV_20             (uint16)(0x214U)
#define TESTCAN_ID_BMS_TX_CV_21             (uint16)(0x215U)
#define TESTCAN_ID_BMS_TX_CV_22             (uint16)(0x216U)
#define TESTCAN_ID_BMS_TX_CV_23             (uint16)(0x217U)
#define TESTCAN_ID_BMS_TX_CV_24             (uint16)(0x218U)
#define TESTCAN_ID_BMS_TX_CV_25             (uint16)(0x219U)
#define TESTCAN_ID_BMS_TX_CV_26             (uint16)(0x21AU)
#define TESTCAN_ID_BMS_TX_CV_27             (uint16)(0x21BU)
#define TESTCAN_ID_BMS_TX_CV_28             (uint16)(0x21CU)
#define TESTCAN_ID_BMS_TX_CV_29             (uint16)(0x21DU)
#define TESTCAN_ID_BMS_TX_CV_30             (uint16)(0x21EU)
#define TESTCAN_ID_BMS_TX_CV_31             (uint16)(0x21FU)
#define TESTCAN_ID_BMS_TX_CV_32             (uint16)(0x220U)
#define TESTCAN_ID_BMS_TX_CV_33             (uint16)(0x221U)
#define TESTCAN_ID_BMS_TX_CV_34             (uint16)(0x222U)
#define TESTCAN_ID_BMS_TX_CV_35             (uint16)(0x223U)
#define TESTCAN_ID_BMS_TX_CV_36             (uint16)(0x224U)
#define TESTCAN_ID_BMS_TX_CV_37             (uint16)(0x225U)
#define TESTCAN_ID_BMS_TX_CV_38             (uint16)(0x226U)
#define TESTCAN_ID_BMS_TX_CV_39             (uint16)(0x227U)
#define TESTCAN_ID_BMS_TX_CV_40             (uint16)(0x228U)
#define TESTCAN_ID_BMS_TX_CV_41             (uint16)(0x229U)
#define TESTCAN_ID_BMS_TX_CV_42             (uint16)(0x22AU)
#define TESTCAN_ID_BMS_TX_CV_43             (uint16)(0x22BU)
#define TESTCAN_ID_BMS_TX_CV_44             (uint16)(0x22CU)
#define TESTCAN_ID_BMS_TX_CV_45             (uint16)(0x22DU)
#define TESTCAN_ID_BMS_TX_CV_46             (uint16)(0x22EU)
#define TESTCAN_ID_BMS_TX_CV_47             (uint16)(0x22FU) // 559

/* DIO */
#define TESTCAN_ID_BMS_TX_DIO_00            (uint16)(0x300U)
//#define TESTCAN_ID_BMS_TX_DIO_01            (uint16)(0x301U)

/* PWM */
#define TESTCAN_ID_BMS_TX_PWM_00            (uint16)(0x302U)
//#define TESTCAN_ID_BMS_TX_PWM_01            (uint16)(0x303U)

/* CMIC STATE */
#define TESTCAN_ID_BMS_TX_STATE_00          (uint16)(0x304U)

/* M-HSCAN(SUBCAN) */
#define TESTCAN_ID_BMS_TX_SUB_00            (uint16)(0x305U)
#define TESTCAN_ID_BMS_TX_SUB_01            (uint16)(0x306U)
#define TESTCAN_ID_BMS_TX_SUB_02            (uint16)(0x307U)
#define TESTCAN_ID_BMS_TX_SUB_03            (uint16)(0x308U)
#define TESTCAN_ID_BMS_TX_SUB_04            (uint16)(0x309U)
#define TESTCAN_ID_BMS_TX_SUB_05            (uint16)(0x30AU)
#define TESTCAN_ID_BMS_TX_SUB_06            (uint16)(0x30BU)

#if (ADK_OTAP) // V2.1.0 OTAP
/* OTAP */
#define TESTCAN_ID_BMS_TX_OTAP_STATE_00     (uint16)(0x30CU)
#define TESTCAN_ID_BMS_TX_OTAP_STATE_01     (uint16)(0x30DU)
#define TESTCAN_ID_BMS_TX_OTAP_STATE_02     (uint16)(0x30EU)
#endif

/* MCAN */
#define TESTCAN_ID_BMS_TX_MCAN              (uint16)(0x30FU)

/* ADC */
#define TESTCAN_ID_BMS_TX_ADC_00            (uint16)(0x310U) // 784
#define TESTCAN_ID_BMS_TX_ADC_01            (uint16)(0x311U)
#define TESTCAN_ID_BMS_TX_ADC_02            (uint16)(0x312U)
#define TESTCAN_ID_BMS_TX_ADC_03            (uint16)(0x313U)
#define TESTCAN_ID_BMS_TX_ADC_04            (uint16)(0x314U)
#define TESTCAN_ID_BMS_TX_ADC_05            (uint16)(0x315U)
#define TESTCAN_ID_BMS_TX_ADC_06            (uint16)(0x316U)
#define TESTCAN_ID_BMS_TX_ADC_07            (uint16)(0x317U)
#define TESTCAN_ID_BMS_TX_ADC_08            (uint16)(0x318U)
#define TESTCAN_ID_BMS_TX_ADC_09            (uint16)(0x319U) // 793

//#define TESTCAN_ID_BMS_TX_SUB_ADC_00        (uint16)(0x320U)
//#define TESTCAN_ID_BMS_TX_SUB_ADC_01        (uint16)(0x321U)

/* TEMP */
#define TESTCAN_ID_BMS_TX_TEMP_00           (uint16)(0x400U) // 1024
#define TESTCAN_ID_BMS_TX_TEMP_01           (uint16)(0x401U)
#define TESTCAN_ID_BMS_TX_TEMP_02           (uint16)(0x402U)
#define TESTCAN_ID_BMS_TX_TEMP_03           (uint16)(0x403U)
#define TESTCAN_ID_BMS_TX_TEMP_04           (uint16)(0x404U)
#define TESTCAN_ID_BMS_TX_TEMP_05           (uint16)(0x405U)
#define TESTCAN_ID_BMS_TX_TEMP_06           (uint16)(0x406U)
#define TESTCAN_ID_BMS_TX_TEMP_07           (uint16)(0x407U)
#define TESTCAN_ID_BMS_TX_TEMP_08           (uint16)(0x408U)
#define TESTCAN_ID_BMS_TX_TEMP_09           (uint16)(0x409U)
#define TESTCAN_ID_BMS_TX_TEMP_10           (uint16)(0x40AU)
#define TESTCAN_ID_BMS_TX_TEMP_11           (uint16)(0x40BU) // 1035


/* SUB TEMP */
#define TESTCAN_ID_BMS_TX_SUB_TEMP_00           (uint16)(0x46CU) // 1132
#define TESTCAN_ID_BMS_TX_SUB_TEMP_01           (uint16)(0x46DU)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_02           (uint16)(0x46EU)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_03           (uint16)(0x46FU)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_04           (uint16)(0x470U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_05           (uint16)(0x471U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_06           (uint16)(0x472U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_07           (uint16)(0x473U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_08           (uint16)(0x474U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_09           (uint16)(0x475U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_10           (uint16)(0x476U)
#define TESTCAN_ID_BMS_TX_SUB_TEMP_11           (uint16)(0x477U) // 1143


/* TLF35584 Diag */
#define TESTCAN_ID_BMS_TX_TLF35584_DIAG     (uint16)(0x500U)

/* High Voltage CMIC Diag */
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG01    (uint16)(0x501U) // 1281
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG02    (uint16)(0x502U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG03    (uint16)(0x503U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG04    (uint16)(0x504U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG05    (uint16)(0x505U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG06    (uint16)(0x506U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG07    (uint16)(0x507U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG08    (uint16)(0x508U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG09    (uint16)(0x509U)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG10    (uint16)(0x50AU)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG11    (uint16)(0x50BU)
#define TESTCAN_ID_BMS_TX_MAX1785x_DIAG12    (uint16)(0x50CU) // 1292

/* MAC Address */
#define TESTCAN_ID_BMS_TX_MAC_ADDR_00       (uint16)(0x600U) // 1536
#define TESTCAN_ID_BMS_TX_MAC_ADDR_01       (uint16)(0x601U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_02       (uint16)(0x602U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_03       (uint16)(0x603U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_04       (uint16)(0x604U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_05       (uint16)(0x605U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_06       (uint16)(0x606U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_07       (uint16)(0x607U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_08       (uint16)(0x608U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_09       (uint16)(0x609U)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_10       (uint16)(0x60AU)
#define TESTCAN_ID_BMS_TX_MAC_ADDR_11       (uint16)(0x60BU) // 1547

/* OpenWire Detection */
#define TESTCAN_ID_BMS_TX_OWD_FAIL_DATA00   (uint16)(0x610U)
#define TESTCAN_ID_BMS_TX_OWD_FAIL_DATA01   (uint16)(0x611U)
#define TESTCAN_ID_BMS_TX_OWD_FAIL_DATA02   (uint16)(0x612U)

/* Main MCU & Sub MCU SW/HW Version */
#define TESTCAN_ID_BMS_TX_MAIN_SW_VERSION1  (uint16)(0x620U)
#define TESTCAN_ID_BMS_TX_MAIN_SW_VERSION2  (uint16)(0x621U)

#define TESTCAN_ID_BMS_TX_SUB_SW_VERSION1   (uint16)(0x622U)
#define TESTCAN_ID_BMS_TX_SUB_SW_VERSION2   (uint16)(0x623U)
#define TESTCAN_ID_BMS_TX_SUB_SW_VERSION3   (uint16)(0x624U)

#define TESTCAN_ID_BMS_TX_MAIN_SW_CHKSUM    (uint16)(0x625U)

/* Received data packet node #1 ~ #12 */
#define TESTCAN_ID_BMS_TX_RECV_DATA_STATUS  (uint16)(0x626U)

#define TESTCAN_ID_BMS_TX_ADI_MPROC_VERSION (uint16)(0x627U) // Main processor software version

/* RSSI */
#define TESTCAN_ID_BMS_TX_RSSI00            (uint16)(0x630U)
#define TESTCAN_ID_BMS_TX_RSSI01            (uint16)(0x631U)
#define TESTCAN_ID_BMS_TX_RSSI02            (uint16)(0x632U)
#define TESTCAN_ID_BMS_TX_RSSI03            (uint16)(0x633U)
#define TESTCAN_ID_BMS_TX_RSSI04            (uint16)(0x63AU)
#define TESTCAN_ID_BMS_TX_RSSI05            (uint16)(0x63BU)
#define TESTCAN_ID_BMS_TX_RSSI06            (uint16)(0x63CU)
#define TESTCAN_ID_BMS_TX_RSSI07            (uint16)(0x63DU)

/* PDR(Packet Delivery Ratio */
#define TESTCAN_ID_BMS_TX_PDR00             (uint16)(0x634U)
#define TESTCAN_ID_BMS_TX_PDR01             (uint16)(0x635U)
#define TESTCAN_ID_BMS_TX_PDR02             (uint16)(0x636U)
#define TESTCAN_ID_BMS_TX_PDR03             (uint16)(0x637U)
#define TESTCAN_ID_BMS_TX_PDR04             (uint16)(0x638U)
#define TESTCAN_ID_BMS_TX_PDR05             (uint16)(0x639U)

#define TESTCAN_ID_BMS_TX_LATENCY_NODE01                  (uint16)(0x230U) // 560
#define TESTCAN_ID_BMS_TX_LATENCY_NODE02                  (uint16)(0x231U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE03                  (uint16)(0x232U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE04                  (uint16)(0x233U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE05                  (uint16)(0x234U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE06                  (uint16)(0x235U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE07                  (uint16)(0x236U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE08                  (uint16)(0x237U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE09                  (uint16)(0x238U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE10                  (uint16)(0x239U)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE11                  (uint16)(0x23AU)
#define TESTCAN_ID_BMS_TX_LATENCY_NODE12                  (uint16)(0x23BU) // 571

// PATH STABLE (CMIC#1 ~ CMIC#12, MAX 48)
#define TESTCAN_ID_BMS_TX_MNGR_NODE01_PS_DATA00           (uint16)(0x640U) // 1600
#define TESTCAN_ID_BMS_TX_MNGR_NODE01_PS_DATA01           (uint16)(0x641U)
#define TESTCAN_ID_BMS_TX_MNGR_NODE01_PS_DATA02           (uint16)(0x642U)
#define TESTCAN_ID_BMS_TX_MNGR_NODE01_PS_DATA03           (uint16)(0x643U) // 1603
// ~~~~~~~
#define TESTCAN_ID_BMS_TX_MNGR_NODE12_PS_DATA03           (uint16)(0x66FU) // 1647

#define TESTCAN_ID_BMS_TX_MNGR_PS_ACCU_DATA00             (uint16)(0x670U) // 1648
#define TESTCAN_ID_BMS_TX_MNGR_PS_ACCU_DATA01             (uint16)(0x671U)
#define TESTCAN_ID_BMS_TX_MNGR_PS_ACCU_DATA02             (uint16)(0x672U)
#define TESTCAN_ID_BMS_TX_MNGR_PS_ACCU_DATA03             (uint16)(0x673U) // 1651

// PATH STABLE (CMIC#1 ~ CMIC#12, MAX 48)
#define TESTCAN_ID_BMS_TX_MNGR_CH01_PS_DATA00             (uint16)(0x674U) // 1652
#define TESTCAN_ID_BMS_TX_MNGR_CH01_PS_DATA01             (uint16)(0x675U)
#define TESTCAN_ID_BMS_TX_MNGR_CH01_PS_DATA02             (uint16)(0x676U) // 1654
// ~~~~~~~
#define TESTCAN_ID_BMS_TX_MNGR_CH12_PS_DATA02             (uint16)(0x6A3U) // 1699

#if 0
// Network Metadata (Node#1 ~ Node#12, Pakcet#1 ~ #3, MAX 108)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT01_DATA00             (uint16)(0x6B0U) // 1712
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT01_DATA01             (uint16)(0x6B1U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT01_DATA02             (uint16)(0x6B2U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT02_DATA00             (uint16)(0x6B3U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT02_DATA01             (uint16)(0x6B4U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT02_DATA02             (uint16)(0x6B5U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT03_DATA00             (uint16)(0x6B6U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT03_DATA01             (uint16)(0x6B7U)
#define TESTCAN_ID_BMS_TX_NETDATA_NODE01_PKT03_DATA02             (uint16)(0x6B8U)
// ~~~~~~~
#define TESTCAN_ID_BMS_TX_NETDATA_NODE12_PKT03_DATA02             (uint16)(0x71BU) // 1819
#endif

#define TESTCAN_ID_BMS_TX_RSSI08            (uint16)(0x720U) // 1824
#define TESTCAN_ID_BMS_TX_RSSI09            (uint16)(0x721U)
#define TESTCAN_ID_BMS_TX_RSSI10            (uint16)(0x722U)
#define TESTCAN_ID_BMS_TX_RSSI11            (uint16)(0x723U) // 1827

#if 0 /* RSW */
// CanObjectId
#define CAN_MSG_ID_BMS_RX_DCM_REQ           (0U) /* GCAN, CanHardwareObject_2 in MCAL */

#define CAN_MSGOBJ_BMS_RX_FUNC_REQ          (0U) /* GCAN's 1st CanHardwareObject Index, CAN_OBJ_FUNCREQ, Should use real rx hw object number for RSW Code */
#define CAN_MSGOBJ_BMS_RX_PHYS_REQ          (10U) /* CAN_OBJ_PHYREQ, Should use real rx hw object number for RSW Code */

#define CAN_ID_BMS_RX_FUNC_REQ          (0x7DFU) /* CAN_ID_FUNCREQ, Inca -> Main */
#define CAN_ID_BMS_RX_PHYS_REQ          (0x7E4U) /* CAN_ID_PHYREQ, Inca -> Main */
#define CAN_ID_BMS_TX_PHYS_RSP          (0x7ECU) /* CAN_ID_PHYRSP, Main -> Inca */

/* SUB */
#define CAN_ID_BMS_RX_MSG_SUB_FUN       (0x7E0U)    // INCA -> Main
#define CAN_ID_BMS_RX_MSG_SUB_PHY       (0x7E5U)    // INCA -> Main
#define CAN_ID_BMS_RX_MSG_SUB_RSP       (0x666U)    // sub -> Main
#define CAN_ID_BMS_TX_MSG_SUB_FUN       (0x777U)    // Main -> sub
#define CAN_ID_BMS_TX_MSG_SUB_PHY       (0x778U)    // Main -> sub

/* Diagnosis object number */
#define CAN_MSGOBJ_DIAFUN_REQ           (0U) /* kMSGOBJ_DIAFUN_REQ */
#define CAN_MSGOBJ_DIAPHY_REQ           (1U) /* kMSGOBJ_DIAPHY_REQ */
#define CAN_MSGOBJ_DIAPHY_RSP           (2U) /* kMSGOBJ_DIAPHY_RSP */
#define CAN_MSGOBJ_CCP_CRO              (3U) /* kMSGOBJ_CCP_CRO */
#endif


/*
 * CAN Rx HW OBJECT
 */
#define TESTCAN_HWOBJ_MAX                   32U // CanObjectId in MCAL
#define TESTCAN_HWOBJ_RX_GCAN               0U
#define TESTCAN_HWOBJ_RX_QCCAN              1U
#define TESTCAN_HWOBJ_RX_SUBCAN00           2U
#define TESTCAN_HWOBJ_RX_SUBCAN01           3U
#define TESTCAN_HWOBJ_RX_MCAN               4U
#define TESTCAN_HWOBJ_RX_MAX                5U // 1st Transmit CanObjectId in MCAL

/*
 * CAN Tx HW OBJECT
 */
/* G-CAN */
#define TESTCAN_HWOBJ_TX_GCAN_00            (0U) // 5
#define TESTCAN_HWOBJ_TX_GCAN_01            (1U)
#define TESTCAN_HWOBJ_TX_GCAN_02            (2U)
#define TESTCAN_HWOBJ_TX_GCAN_03            (3U)
#define TESTCAN_HWOBJ_TX_GCAN_04            (4U)
#define TESTCAN_HWOBJ_TX_GCAN_05            (5U) // 10
#define TESTCAN_HWOBJ_TX_GCAN_06            (6U)
#define TESTCAN_HWOBJ_TX_GCAN_07            (7U)
#define TESTCAN_HWOBJ_TX_GCAN_08            (8U)
#define TESTCAN_HWOBJ_TX_GCAN_09            (9U)
#define TESTCAN_HWOBJ_TX_GCAN_10            (10U)
#define TESTCAN_HWOBJ_TX_GCAN_11            (11U) // 16

/* H-CAN (QCCAN) */
#define TESTCAN_HWOBJ_TX_QCCAN_00           (12U) // 17
#define TESTCAN_HWOBJ_TX_QCCAN_01           (13U)
#define TESTCAN_HWOBJ_TX_QCCAN_02           (14U)
#define TESTCAN_HWOBJ_TX_QCCAN_03           (15U) // 20
#define TESTCAN_HWOBJ_TX_QCCAN_04           (16U)
#define TESTCAN_HWOBJ_TX_QCCAN_05           (17U)
#define TESTCAN_HWOBJ_TX_QCCAN_06           (18U)
#define TESTCAN_HWOBJ_TX_QCCAN_07           (19U)
#define TESTCAN_HWOBJ_TX_QCCAN_08           (20U)
#define TESTCAN_HWOBJ_TX_QCCAN_09           (21U)
#define TESTCAN_HWOBJ_TX_QCCAN_10           (22U)
#define TESTCAN_HWOBJ_TX_QCCAN_11           (23U) // 28

/* M-HSCAN */
#define TESTCAN_HWOBJ_TX_SUBCAN_00          (24U) // 29
#define TESTCAN_HWOBJ_TX_SUBCAN_01          (25U) // 30

/* MCAN */
#define TESTCAN_HWOBJ_TX_MCAN_00            (26U) // 31

#define TESTCAN_HWOBJ_TX_LAST               (26U) // TESTCAN_HWOBJ_TX_MCAN_00

/* !!! HWOBJ(RX/TX) MAX 32EA (0 ~ 31) */
#if (TESTCAN_HWOBJ_MAX < ((TESTCAN_HWOBJ_TX_LAST + 1) + TESTCAN_HWOBJ_RX_MAX))
#error "Check HW objec index in CAN module of MCAL"
#endif


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

extern void
    TestCan_RxIndication(const Can_HwType *pMailbox, const PduInfoType *pPduInfo);


#endif /* TESTCAN_H */

