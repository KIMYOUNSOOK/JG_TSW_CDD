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
**          FILE  : TestCan.c
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





/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>
#include "PmicM_Tlf35584.h"
//#include "Cmic_Manager.h"
#include "TestDio.h"
#include "TestAdc.h"
#include "TestIcu.h"
#include "TestFls.h"
#include "TestCan.h"
#if 1 // @SURE - ADI-EXAMPLE
#include "adi_wil_example_functions.h"
#include "adi_wil_example_acl.h"
#endif


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
//static const uint8 SW_VERSION[MAX_VERSION_LENGTH] = {TSW_SW_VERSION};


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
//static TESTCAN_INSTANCE_T l_tTestCan_Inst;


/*******************************************************************************
** Function Name    : TestCan_RxIndication
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestCan_RxIndication(const Can_HwType *pMailbox, const PduInfoType *pPduInfo)
{
    // Retrieve CanIf_RxIndication in CanIf_Cbk.c
 //   l_tTestCan_Inst.m_nRxCnt++;

 //   TestCan_Recv(pMailbox->CanId, (uint8)pPduInfo->SduLength, pPduInfo->SduDataPtr);

} /*End of TestCan_RxIndication */

/*******************************************************************************
** Function Name    : TestCan_RxCalloutFunc
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
bool TestCan_RxCalloutFunc (const Can_HwHandleType Hrh,
                      const Can_IdType CanId,
                      const uint8 CanDlc,
                      const uint8 *CanSduPtr)
{
    Can_HwType mailbox;
    PduInfoType pduInfo;


    mailbox.CanId = CanId;
    mailbox.Hoh = Hrh;

    pduInfo.SduLength = CanDlc;
    pduInfo.SduDataPtr = (uint8 *)CanSduPtr;

    TestCan_RxIndication(&mailbox, &pduInfo);

    return true;
}



