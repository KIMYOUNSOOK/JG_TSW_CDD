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
**          FILE  : TestLin.c
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

#include "IfxAsclin_reg.h"
#include "Lin_17_AscLin_Cfg.h"
#include "TestLin.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define MODE_SLA             0x01 // Slave Response
#define MODE_MAS             0x02 // Master Response
#define MODE_STS             0x04 // Slave to Slave Response

#define LIN_RECEIVE_SUPPORT    (0)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    boolean m_bEnable;

    /* LIN structure */
    Lin_PduType m_tLinPdu;
    uint8 m_aRspBuffer[8];
    uint8 *m_pRspSdu;
    uint8 **m_ppRspSdu;
    
    uint8 m_nMode;

    uint32 m_nTxCnt;
    uint32 m_nRxCnt;

    uint8 m_aTxBuffer[8];
    uint8 m_aRxBuffer[8];

    uint16 m_n10msSeq;

} TESTLIN_INSTANCE_T;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void _Send_LinMsg(void);
static void _Recv_LinMsg(void);


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
static TESTLIN_INSTANCE_T l_tTestLin_Inst;


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Function Name    : TestLin_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_Init(void)
{
    memset(&l_tTestLin_Inst, 0U, sizeof(TESTLIN_INSTANCE_T));

    l_tTestLin_Inst.m_pRspSdu = (uint8 *)&l_tTestLin_Inst.m_aRspBuffer[0];
    l_tTestLin_Inst.m_ppRspSdu = (uint8 **)&l_tTestLin_Inst.m_pRspSdu;

    l_tTestLin_Inst.m_bEnable = TRUE;

} /*End of TestLin_Init */

/*******************************************************************************
** Function Name    : TestLin_Send
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : nMode = 0:Slave, 1:Master
**
*******************************************************************************/
uint8 TestLin_Send(uint8 nId, uint8 nMode, uint8 *pData, uint8 nDlc)
{
    uint8 nRet = 0U;
    Std_ReturnType stdResult = E_OK;
    uint8 Channel = Lin_17_AscLinConf_LinChannel_LinChannel_0;

    l_tTestLin_Inst.m_tLinPdu.Pid = nId;
    l_tTestLin_Inst.m_tLinPdu.Cs = LIN_ENHANCED_CS;
    
    if(nMode & MODE_MAS)
    {
        l_tTestLin_Inst.m_tLinPdu.Drc = LIN_MASTER_RESPONSE;
    }
    else if(nMode & MODE_STS)
    {
        l_tTestLin_Inst.m_tLinPdu.Drc = LIN_SLAVE_TO_SLAVE;
    }
    else // MODE_SLA
    {
        l_tTestLin_Inst.m_tLinPdu.Drc = LIN_SLAVE_RESPONSE;
    }
    
    l_tTestLin_Inst.m_tLinPdu.Dl = nDlc;
    l_tTestLin_Inst.m_tLinPdu.SduPtr = pData;
    l_tTestLin_Inst.m_nMode = nMode;

    if(nMode & MODE_SLA)
    {
        Lin_StatusType linStatus;
        uint32 WaitLoop = 0;

        stdResult = Lin_17_AscLin_SendFrame(Channel, &l_tTestLin_Inst.m_tLinPdu);
        if(stdResult == E_OK)
        {
            while(1) 
            {
                linStatus = Lin_17_AscLin_GetStatus(Channel, l_tTestLin_Inst.m_ppRspSdu);
                if((linStatus == LIN_RX_OK) || (WaitLoop >= 0xFFF0))
                {
                    break;
                }
                
                WaitLoop++;
            };

            if((linStatus == LIN_RX_OK) && (WaitLoop < 0xFFF0))
            {
                l_tTestLin_Inst.m_nRxCnt++;
                memcpy(l_tTestLin_Inst.m_aRxBuffer, l_tTestLin_Inst.m_pRspSdu, nDlc);
            }
            else
            {
                nRet = 1U;
            }
        }
        else
        {
            nRet = 1U;
        }
    }
    else if(nMode & MODE_MAS)
    {
        l_tTestLin_Inst.m_nTxCnt++;

        stdResult = Lin_17_AscLin_SendFrame(Channel, &l_tTestLin_Inst.m_tLinPdu);
        if(stdResult == E_OK)
        {
        #if 0
            Lin_StatusType linStatus;
            uint32 WaitLoop = 0;
        
            while(1) 
            {
                linStatus = Lin_17_AscLin_GetStatus(Channel, (uint8 **)&l_tTestLin_Inst.m_tLinPdu.SduPtr);
                if((linStatus == LIN_TX_OK) || (WaitLoop >= 0xFFF0))
                {
                    break;
                }
                
                WaitLoop++;
            };
        
            if((linStatus == LIN_TX_OK) && (WaitLoop < 0xFFF0))
            {
                l_tTestLin_Inst.m_nTxCnt++;
                memcpy(l_tTestLin_Inst.m_aTxBuffer, l_tTestLin_Inst.m_tLinPdu.SduPtr, nDlc);
            }
            else
            {
                nRet = 1U;
            }
        #else
            memcpy(l_tTestLin_Inst.m_aTxBuffer, l_tTestLin_Inst.m_tLinPdu.SduPtr, nDlc);
        #endif
        }
        else
        {
            nRet = 1U;
        }
    }

    return nRet;

} /*End of TestLin_Send */

#if 0
/*******************************************************************************
** Function Name    : TestLin_Recv
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_Recv(uint8 nId, uint8 nDlc, const uint8 *pData)
{
    if(nId == 0) return;
    
    switch (nId)
    {
        case TESTLIN_PID_BMS_RX_00:
            break;

        default:
            break;
    }

}/*End of TestLin_Recv */
#endif

/*******************************************************************************
** Function Name    : TestLin_10ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_10ms(void)
{
#if (LIN_RECEIVE_SUPPORT)
    _Recv_LinMsg();
    #if 0 // for test
    if(l_tTestLin_Inst.m_aRxBuffer[0] != 0x00)
    {
        _Send_LinMsg();
        memset(l_tTestLin_Inst.m_aRxBuffer, 0x0, 8);
    }
    #endif

    l_tTestLin_Inst.m_n10msSeq ++;
    l_tTestLin_Inst.m_n10msSeq %= 10;

#else
    _Send_LinMsg();

    l_tTestLin_Inst.m_n10msSeq ++;
    l_tTestLin_Inst.m_n10msSeq %= 10;
#endif

} /*End of TestLin_10ms */

/*******************************************************************************
** Function Name    : TestLin_100ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_100ms(void)
{
    ;
    
}/*End of TestLin_100ms */

/*******************************************************************************
** Function Name    : TestLin_SetEnable
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_SetEnable(boolean bEnable)
{
    l_tTestLin_Inst.m_bEnable = bEnable;

} /*End of TestLin_SetEnable */

/*******************************************************************************
** Function Name    : TestLin_GetEnable
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
boolean TestLin_GetEnable(void)
{
    return l_tTestLin_Inst.m_bEnable;

} /*End of TestLin_GetEnable */

#if 0
/*******************************************************************************
** Function Name    : TestLin_RxIndication
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_RxIndication(const Lin_PduType *pPduInfo)
{
    // Retrieve Lin_17_AscLin_IsrReceive in Lin_17_Asclin.c
    l_tTestLin_Inst.m_nRxCnt++;

    TestLin_Recv(pPduInfo->Pid, pPduInfo->Dl, pPduInfo->SduPtr);

} /*End of TestLin_RxIndication */

/*******************************************************************************
** Function Name    : TestLin_RxCalloutFunc
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestLin_RxCalloutFunc(const void *PduStatePtr)
{
    Lin_PduType *pPduInfo = (Lin_PduType *)PduStatePtr;

    memcpy(&l_tTestLin_Inst.m_tLinPdu, pPduInfo, sizeof(Lin_PduType));
    
    TestLin_RxIndication(pPduInfo);
    
}
#endif

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/

/*******************************************************************************
** Function Name    : _Send_LinMsg
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : send data from master
**
*******************************************************************************/
static void _Send_LinMsg(void)
{
#if 0
    Std_ReturnType stdResult;
    uint8 aTxBuffer[6] = {0xAA, 0x55, 0xCC, 0x33, 0xFF};
    uint8 Channel = Lin_17_AscLinConf_LinChannel_LinChannel_0;

    l_tTestLin_Inst.m_tLinPdu.Pid = 0x24;
    l_tTestLin_Inst.m_tLinPdu.Cs = LIN_ENHANCED_CS;
    l_tTestLin_Inst.m_tLinPdu.Drc = LIN_MASTER_RESPONSE;
    l_tTestLin_Inst.m_tLinPdu.Dl = 6;
    l_tTestLin_Inst.m_tLinPdu.SduPtr = (uint8 *)&aTxBuffer[0];

    stdResult = Lin_17_AscLin_SendFrame(Channel, &l_tTestLin_Inst.m_tLinPdu);
    if(stdResult == E_OK)
    {
        memcpy(l_tTestLin_Inst.m_aTxBuffer, l_tTestLin_Inst.m_tLinPdu.SduPtr, l_tTestLin_Inst.m_tLinPdu.Dl);
    }
    else
    {
    }
#else
    uint8 aTxBuffer[8] = {0xAA, 0x55, 0xCC, 0x33, 0xFF, 0x00, 0x00, 0x00};
    #if 0 // for test
    static uint8 tryCnt = 0;

    aTxBuffer[5] = tryCnt;
    tryCnt++;
    if(tryCnt >= 255) tryCnt = 0;
    #endif
    
    TestLin_Send(TESTLIN_PID_BMS_TX_STATE, MODE_MAS, aTxBuffer, sizeof(aTxBuffer));
#endif

} /*End of _Send_LinMsg */

/*******************************************************************************
** Function Name    : _Recv_LinMsg
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : receive response data from slave
**
*******************************************************************************/
static void _Recv_LinMsg(void)
{
    uint8 aTxBuffer[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8 rxId = TESTLIN_PID_BMS_RX_00;

    TestLin_Send(rxId, MODE_SLA, aTxBuffer, sizeof(aTxBuffer));

} /*End of _Recv_LinMsg */

