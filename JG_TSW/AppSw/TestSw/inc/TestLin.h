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
**          FILE  : TestLin.h
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





#ifndef TESTLIN_H
#define TESTLIN_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Lin_17_AscLin.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* LIN Transmit Type */

/*
 * LIN Rx ID
 */
/* External */
#define TESTLIN_PID_BMS_RX_00              (0x28) // 40, Pid 0xA8

#define TESTLIN_PID_BMS_TX_STATE           (0x24) // 36, Pid 0x64

#define TESTLIN_ID_MASTER_REQ              (0x3C) // 60
#define TESTLIN_ID_SLAVE_RSP               (0x3D) // 61

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
    TestLin_Init(void);
extern uint8
    TestLin_Send(uint8 nId, uint8 nMode, uint8 *pData, uint8 nDlc);
#if 0
extern void
    TestLin_Recv(uint8 nId, uint8 nDlc, const uint8 *pData);
#endif
extern void
    TestLin_10ms(void);
extern void
    TestLin_100ms(void);
extern void
    TestLin_SetEnable(boolean bEnable);
extern boolean
    TestLin_GetEnable(void);
#if 0
extern void 
    TestLin_RxIndication(const Lin_PduType *pPduInfo);
extern void 
    TestLin_RxCalloutFunc(const void *PduStatePtr);
#endif

#endif /* TESTLIN_H */

