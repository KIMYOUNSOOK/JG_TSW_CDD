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
**          FILE  : TestAdc.h
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


#ifndef TESTADC_H
#define TESTADC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define TESTADC_LEVEL_IG_ON             0x3FFU // 1023


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef enum
{
    /* Group0(AdcHwUnit0) */
    TESTADC_CH_AN2  = 0x00,
    TESTADC_CH_AN3,
    TESTADC_CH_AN4,
    TESTADC_CH_AN5,
    TESTADC_CH_AN6,
    TESTADC_CH_AN7,
    
    /* Group1(AdcHwUnit1) */
    TESTADC_CH_AN8,
    TESTADC_CH_AN10,
    TESTADC_CH_AN11, /* IG1 Key */
    TESTADC_CH_AN12,
    TESTADC_CH_AN13,
    TESTADC_CH_AN14,
    TESTADC_CH_AN15,

    /* Group2(AdcHwUnit2) */
    TESTADC_CH_AN16,
    TESTADC_CH_AN17,
    TESTADC_CH_AN18,
    TESTADC_CH_AN19,
    TESTADC_CH_AN20, /* ISO POS*/
    TESTADC_CH_AN21, /* ISO NEG*/
    TESTADC_CH_AN22,

    /* Group3(AdcHwUnit3) */
    TESTADC_CH_AN24,
    TESTADC_CH_AN25,
    TESTADC_CH_AN26,
    TESTADC_CH_AN27,
    TESTADC_CH_AN28,
    TESTADC_CH_AN29,
    TESTADC_CH_AN30,
    TESTADC_CH_AN31,

    /* Group8(AdcHwUnit8) */
    TESTADC_CH_AN33,
    TESTADC_CH_AN34,
    TESTADC_CH_AN35,

} TESTADC_CH_E;


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
    TestAdc_Init(void);
extern void
    TestAdc_10ms(void);
extern void
    TestAdc_100ms(void);
extern uint16
    TestAdc_GetValue(TESTADC_CH_E eChannel);


#endif /* TESTADC_H */

