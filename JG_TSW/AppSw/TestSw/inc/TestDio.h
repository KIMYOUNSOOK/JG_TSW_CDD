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
**          FILE  : TestDio.h
**
**       PROJECT  : BMS_STANDLAONE_TC375                                             
**
**        AUTHOR  : Hyun Kang
**
**       VERSION  : V1.0
**
**      PLATFORM  : Infineon Aurix 375TP                                         
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

 *  V1.0    20211105    YG.SON      -           First Implementation


*******************************************************************************/


#ifndef TESTDIO_H
#define TESTDIO_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


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
    TestDio_Init(void);
extern void
    TestDio_100ms(void);
extern void
    TestDio_SetValue(const uint8 *pData);
extern void
    TestDio_GetValue(uint8 *pData);
extern boolean
    TestDio_GetIg1(void);
extern boolean 
    TestDio_GetAccWup(void);
extern boolean 
    TestDio_GetSolarWup(void);
extern boolean 
    TestDio_GetPressureWup(void);
extern boolean 
    TestDio_GetMCanWup(void);
extern void
    TestDio_SetPwrOff(boolean bLevel);
#if 1 // CAN-IG, MCAN
extern void
    TestDio_CtrlMcanEn(boolean bLevel);
extern void
    TestDio_CtrlMcanStandby(boolean bLevel);
#endif
extern void
    TestDio_SetIsoPosEn(boolean bLevel);
extern void
    TestDio_SetIsoNegEn(boolean bLevel);


#endif /* TESTDIO_H */

