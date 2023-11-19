/*******************************************************************************
**                                                                            **
** Copyright (C) Suresofttech                                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Hyundai Mobis  **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            
**          FILE  : TestFls.c
** 
**       PROJECT  : BMS_STANDLAONE_TC275                                             
**       
**        AUTHOR  : Sungjin Ryu
**                                                                    
**       VERSION  : V1.0
**                                                                                                                                                                                                                                    
**      PLATFORM  : Infineon Aurix 275T                                         
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

 *  V1.0    20220216    Sungjin Ryu      -      First Implementation


*******************************************************************************/






#define FLS_LEGRY_USE                 (1)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>
#if (FLS_LEGRY_USE)
#include "IfxDmu_reg.h"
#include "IfxScu_reg.h"
#else
#include "FlsLoader.h"
#endif
#include "TestFls.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#if (FLS_LEGRY_USE)
/* Command Sequence Definitions */
#define FlashCmd_Addr1 (volatile unsigned int *)0xAF00AA50 /* Write, Erase Page */
#define FlashCmd_Addr2 (volatile unsigned int *)0xAF00AA58
#define FlashCmd_Addr3 (volatile unsigned int *)0xAF00AAA8
#define FlashCmd_Addr4 (volatile unsigned int *)0xAF00AAA8
    
#define FlashCmd_Addr0 (volatile unsigned int *)0xAF005554 /* Enter Page Mode*/
#define FlashLoad_Addr (volatile unsigned int *)0xAF0055F0
    
#define MEM(address) (*((volatile unsigned int *)(address))) 

// FlsLoader.c
#define FLS_WDT_PASSWORD_LOWER_MASK  ( 0x000000FCU )
/* mask for password Bits 8-15 */
#define FLS_WDT_PASSWORD_UPPER_MASK  ( 0x0000FF00U )

/* mask for password bits */
#define FLS_WDT_PASSWORD_MASK   \
                                    (FLS_WDT_PASSWORD_LOWER_MASK | \
                                     FLS_WDT_PASSWORD_UPPER_MASK)
                                     
#define FLS_WDT_RELOAD_MASK          ( 0xFFFF0000U )

/* mask for LCK and ENDINIT status bits */
#define FLS_WDT_STATUS_MASK          ( 0x00000003U )

#define FLS_NUM_1                 (1U)
#define FLS_NUM_2                 (2U)
#define FLS_NUM_3                 (3U)
#endif


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
typedef struct
{
    boolean m_bInit;
    uint32 m_nWrAddr;
    uint8 *m_pSrcData;
    uint8 m_SrcData[FLS_WRITE_BLOCK_LENGTH + 1];
    uint32 m_nSrcLen;
    uint32 m_nFlsResult;

} FLS_INST_T;


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
static FLS_INST_T l_tFls_Inst;


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (FLS_LEGRY_USE)
static void Fls_Test(void);
#endif


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : TestFls_Init
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TestFls_Init(void)
{
    memset(&l_tFls_Inst, 0x0U, sizeof(FLS_INST_T));
    l_tFls_Inst.m_bInit = 1U;

    //Fls_Test();
}/*End of TestFls_Init */

#if (FLS_LEGRY_USE)
/*******************************************************************************
** Function Name    : Fls_Safety_Endinit
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void Fls_Safety_Endinit(uint8 endinit_value)
{
    // FlsLoader_lResetSafetyENDINIT
    unsigned int NewValCon0;
    unsigned int NewPw;                   /* next password to be used */
    unsigned int NewRel;                  /* next reload value to be used */
    unsigned int Result;

    /* Safety Wdg register is acquired */
    /*MISRA2012_RULE_19_2_JUSTIFICATION: Union used for register type
         definition */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: SFR access */
    volatile Ifx_SCU_WDTS_CON0* ScuWdtcon0Ptr = &SCU_WDTS_CON0;
    
    /* save old value */
    NewValCon0 = SCU_WDTSCON0.U;

    /* get valid next password */
    Result = NewValCon0 & FLS_WDT_PASSWORD_MASK;
    Result = ( Result & FLS_WDT_PASSWORD_UPPER_MASK) |
             ((~(Result & FLS_WDT_PASSWORD_LOWER_MASK))
              & FLS_WDT_PASSWORD_LOWER_MASK );

    /* password sequencing will not be enabled at this time,
    no need for the run time calculation of password */
    NewPw = Result;
    /* get valid next timer reload */
    Result = NewValCon0 & FLS_WDT_RELOAD_MASK;
    /* Time control enable shall not be enabled by the system */
    NewRel = Result;
    /* build required password WDTCON0 value */
    NewValCon0 =  ( (NewRel) |              /* new reload value  */
                    (NewPw)  |              /* new Password */
                    (1u) );                 /* Clear LCK, keep ENDINIT set */

    ScuWdtcon0Ptr->U  = NewValCon0;        /* password access to unlock */

    NewValCon0 &= ~ FLS_WDT_STATUS_MASK;/*clear ENDINIT and LCK Bit */
    NewValCon0 |= (FLS_NUM_2 + endinit_value); /* set LCK Bit */

    ScuWdtcon0Ptr->U = NewValCon0;  /* write access and lock for Timeout mode */
}

/*******************************************************************************
** Function Name    : Fls_Safety_Endinit
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void Fls_CheckBusy(void)
{
    uint32 reg = 0U;

    do
    {
        reg = DMU_HF_STATUS.U;
    }while((reg & 0x0000003DU) != 0);
}

/*******************************************************************************
** Function Name    : Fls_lWrite
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static uint8 Fls_lWrite(uint32 nAddr, uint8 *pData, uint32 nSize)
{
    uint32 i = 0U;
    uint32 tempDataL  = 0U;
    uint32 tempDataH  = 0U;
    uint32 loadAddr = 0U;

    *FlashCmd_Addr0 = 0xFA; /* Clear Status */

    /* Program Flash */
    if ((nAddr & 0xFF000000UL) == 0x80000000UL)
    {
        *FlashCmd_Addr0 = 0x50;
    }
    /* Data Flash */
    else if ((nAddr & 0xFF000000UL) == 0xAF000000UL)
    {
        *FlashCmd_Addr0 = 0x5D;
    }
    else
    {
        return TRUE;
    }

    loadAddr = 0xAF0055F0; // Load Page

    // load buffer
    for (i = 0; i < nSize; i += 8)
    {
        tempDataL = *(pData + i);
        tempDataL += ((uint32)*(pData + i + 1)) << 8;
        tempDataL += ((uint32)*(pData + i + 2)) << 16;
        tempDataL += ((uint32)*(pData + i + 3)) << 24;
        tempDataH = ((uint32)*(pData + i + 4));
        tempDataH += ((uint32)*(pData + i + 5)) << 8;
        tempDataH += ((uint32)*(pData + i + 6)) << 16;
        tempDataH += ((uint32)*(pData + i + 7)) << 24;;

        /*load page assembly buffer first 32-bits*/
        MEM(loadAddr + 0) = tempDataL;
        MEM(loadAddr + 4) = tempDataH;
    }

    Fls_Safety_Endinit(0);
    
    // write page
    *FlashCmd_Addr1 = nAddr;
    *FlashCmd_Addr2 = 0x00;
    *FlashCmd_Addr3 = 0xA0;

    /* Program Flash */
    if ((nAddr & 0xFF000000UL) == 0x80000000UL)
    {
        *FlashCmd_Addr4 = 0xAA; // write page
    }
    /* Data Flash */
    else if ((nAddr & 0xFF000000UL) == 0xAF000000UL)
    {
        *FlashCmd_Addr4 = 0xA6; // write burst
    }

    Fls_Safety_Endinit(1);
    Fls_CheckBusy();

    return FALSE;
}

/*******************************************************************************
** Function Name    : Fls_lErase
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static uint8 Fls_lErase(uint32 nAddr)
{
    *FlashCmd_Addr0 = 0xFA; /* Clear Status */

    Fls_Safety_Endinit(0); // clear, disable

    *FlashCmd_Addr1 = nAddr;
    *FlashCmd_Addr2 = 1; // 1 sector
    *FlashCmd_Addr3 = 0x80;
    *FlashCmd_Addr4 = 0x50; // Erase Logical Sector Range, 0x5F Verify Erase Logical Sector

    Fls_Safety_Endinit(1); // set, enable
    Fls_CheckBusy();

    return FALSE;
}
#endif

/*******************************************************************************
** Function Name    : TestFls_CalcChksum
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint16 TestFls_CalcChksum(uint8 *pData, uint16 nSize)
{
    uint16 i = 0U;
    uint16 checksum = 0U;
    uint8 *tempPtr = pData;

    checksum = 0;

    for (i = 0; i < nSize; i++)
    {
        checksum += *(tempPtr + i);
    }

    return checksum;
}

/*******************************************************************************
** Function Name    : TestFls_Erase
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint8 TestFls_Erase(uint32 nAddr)
{
#if (FLS_LEGRY_USE)
    uint32 m_nFlsResult = FLS_RESULT_ERR_NONE;
    uint8 errStatus = TRUE;

    if(l_tFls_Inst.m_bInit)
    {
        errStatus = Fls_lErase(nAddr);
        if(errStatus)
        {
            // fls error
            m_nFlsResult = FLS_RESULT_ERR_ERASE;
        }
    }
    else
    {
        m_nFlsResult = FLS_RESULT_ERR_INIT;
    }

    l_tFls_Inst.m_nFlsResult = m_nFlsResult;
    return (m_nFlsResult != FLS_RESULT_ERR_NONE) ? TRUE : FALSE;
#else
    FlsLoader_ReturnType retval;
    retval = FlsLoader_Erase(nAddr, 1U/*1sector*/);
    return (retval != FLSLOADER_E_OK) ? TRUE : FALSE;
#endif
}

/*******************************************************************************
** Function Name    : TestFls_Read
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint8 TestFls_Read(uint32 nAddr, uint8 *pData, uint32 nSize)
{
#if (FLS_LEGRY_USE)
    uint32 LoopCount = 0, idx = 0;
    uint32 *srcPtr = (uint32 *)nAddr;
    uint32 m_nFlsResult = FLS_RESULT_ERR_NONE;

    memset(pData, 0x0U, nSize);
    
    if(l_tFls_Inst.m_bInit)
    {
        for(LoopCount = 0; LoopCount < (nSize / 4); LoopCount++)
        {
            pData[idx + 0] = (uint8)((*(uint32 *)srcPtr & 0x000000FF) >> 0);
            pData[idx + 1] = (uint8)((*(uint32 *)srcPtr & 0x0000FF00) >> 8);
            pData[idx + 2] = (uint8)((*(uint32 *)srcPtr & 0x00FF0000) >> 16);
            pData[idx + 3] = (uint8)((*(uint32 *)srcPtr & 0xFF000000) >> 24);
            idx += 4;
            ++srcPtr;
        }
    }
    else
    {
        m_nFlsResult = FLS_RESULT_ERR_INIT;
    }

    l_tFls_Inst.m_nFlsResult = m_nFlsResult;
    return (m_nFlsResult != FLS_RESULT_ERR_NONE) ? TRUE : FALSE;
#else
    uint32 *SourcePtr = NULL;
    uint32 LoopCount = 0, idx = 0;
    SourcePtr = (uint32*)nAddr;
    for(LoopCount = 0; LoopCount < (nSize / 4); LoopCount++)
    {
        pData[idx + 0] = (uint8)((*(uint32 *)SourcePtr & 0x000000FF) >> 0);
        pData[idx + 1] = (uint8)((*(uint32 *)SourcePtr & 0x0000FF00) >> 8);
        pData[idx + 2] = (uint8)((*(uint32 *)SourcePtr & 0x00FF0000) >> 16);
        pData[idx + 3] = (uint8)((*(uint32 *)SourcePtr & 0xFF000000) >> 24);
        idx += 4;
        ++SourcePtr;
    }
    
    return FALSE;
#endif
}

/*******************************************************************************
** Function Name    : TestFls_Write
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint8 TestFls_Write(uint32 nAddr, uint8 *pData, uint32 nSize)
{
#if (FLS_LEGRY_USE)
    uint32 blk = 0U;
    uint8 errStatus = TRUE;
    uint32 m_nFlsResult = FLS_RESULT_ERR_NONE;

    if(l_tFls_Inst.m_bInit)
    {
        if((nSize == 0) || ((nSize % FLS_WRITE_BLOCK_LENGTH) != 0))
        {
            // invalid parameter
            m_nFlsResult = FLS_RESULT_INVALID_PARAMETERS;
        }
        else
        {
            for(blk = 0; blk < (nSize/FLS_WRITE_BLOCK_LENGTH); blk++)
            {
                l_tFls_Inst.m_nWrAddr = (uint32)(nAddr + (blk * FLS_WRITE_BLOCK_LENGTH));
                l_tFls_Inst.m_pSrcData = (uint8 *)(pData + (blk * FLS_WRITE_BLOCK_LENGTH));
                memset(l_tFls_Inst.m_SrcData, 0x0, sizeof(l_tFls_Inst.m_SrcData));
                memcpy(l_tFls_Inst.m_SrcData, l_tFls_Inst.m_pSrcData, FLS_WRITE_BLOCK_LENGTH);
                l_tFls_Inst.m_nSrcLen = FLS_WRITE_BLOCK_LENGTH;
                errStatus = Fls_lWrite(l_tFls_Inst.m_nWrAddr, l_tFls_Inst.m_SrcData, l_tFls_Inst.m_nSrcLen);
                if(errStatus)
                {
                    // fls error
                    m_nFlsResult = FLS_RESULT_ERR_WRITE;
                    break;
                }
            }
        }
    }
    else
    {
        m_nFlsResult = FLS_RESULT_ERR_INIT;
    }

    l_tFls_Inst.m_nFlsResult = m_nFlsResult;
    return (m_nFlsResult != FLS_RESULT_ERR_NONE) ? TRUE : FALSE;
#else
    FlsLoader_ReturnType retval;
    retval = FlsLoader_Write(nAddr, nSize, pData);
    return (retval != FLSLOADER_E_OK) ? TRUE : FALSE;
#endif
}

/*******************************************************************************
** Function Name    : Fls_Test
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
static void Fls_Test(void)
{
#if (FLS_LEGRY_USE)
#if 0 // for test
    // DFLASH
    #if 1
    {
        uint32 blk = 0, i = 0U;
        uint8 flsErr = 0;
        
        uint8 _FLASH_RDATA[128] = {0, };
        uint8 _FLASH_WDATA[128] = {0, };

        TestFls_Erase(DFLASH_BLK_2_ADDR);
        for(blk = 0; blk < (DFLASH_BLOCK_SIZE/sizeof(_FLASH_WDATA)); blk++)
        {
            //TestFls_Read(DFLASH_BLK_2_ADDR, _FLASH_RDATA, sizeof(_FLASH_RDATA));
            //TestFls_Read(DFLASH_BLK_2_ADDR, _FLASH_RDATA, sizeof(_FLASH_RDATA));
            memset(_FLASH_WDATA, 0x0, sizeof(_FLASH_WDATA));
            for(i = 0; i < sizeof(_FLASH_WDATA); i++)
            {
                _FLASH_WDATA[i] = (uint8)i;
            }
            TestFls_Write(DFLASH_BLK_2_ADDR + (blk*sizeof(_FLASH_WDATA)), _FLASH_WDATA, sizeof(_FLASH_WDATA));
            TestFls_Read(DFLASH_BLK_2_ADDR + (blk*sizeof(_FLASH_RDATA)), _FLASH_RDATA, sizeof(_FLASH_RDATA));
            if(memcmp(_FLASH_WDATA, _FLASH_WDATA, sizeof(_FLASH_WDATA)) != 0)
            {
                flsErr = 1;
                break;
            }
        }

        if(flsErr)
        {
            l_tFls_Inst.m_nFlsResult = FLS_RESULT_FAIL;
        }
    }
    #endif
    // PFLASH
    #if 0
    {
        uint32 i = 0U;
        TestFls_Read(PFLASH_BLOCK_0_BASE + 0x00B00000, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        TestFls_Erase(PFLASH_BLOCK_0_BASE + 0x00B00000);
        TestFls_Read(PFLASH_BLOCK_0_BASE + 0x00B00000, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        for(i = 0; i < sizeof(_FLASH_WDATA); i++)
        {
            _FLASH_WDATA[i] = (uint8)i;
        }
        TestFls_Write(PFLASH_BLOCK_0_BASE + 0x00B00000, _FLASH_WDATA, sizeof(_FLASH_WDATA));
        TestFls_Read(PFLASH_BLOCK_0_BASE + 0x00B00000, _FLASH_RDATA, sizeof(_FLASH_RDATA));
    }
    #endif
    // HSM
    #if 0
    {
        uint32 i = 0U;
        TestFls_Read(ROM_HSM_START, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        TestFls_Erase(ROM_HSM_START);
        TestFls_Read(ROM_HSM_START, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        for(i = 0; i < sizeof(_FLASH_WDATA); i++)
        {
            _FLASH_WDATA[i] = (uint8)i;
        }
        TestFls_Write(ROM_HSM_START, _FLASH_WDATA, sizeof(_FLASH_WDATA));
        TestFls_Read(ROM_HSM_START, _FLASH_RDATA, sizeof(_FLASH_RDATA));
    }
    #endif
    // DFLASH0_UCB
    #if 0
    {
        uint32 i = 0U;
        TestFls_Read(DFLASH0_UCB_BLK_0_ADDR, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        TestFls_Erase(DFLASH0_UCB_BLK_0_ADDR);
        TestFls_Read(DFLASH0_UCB_BLK_0_ADDR, _FLASH_RDATA, sizeof(_FLASH_RDATA));
        for(i = 0; i < sizeof(_FLASH_WDATA); i++)
        {
            _FLASH_WDATA[i] = (uint8)i;
        }
        TestFls_Write(DFLASH0_UCB_BLK_0_ADDR, _FLASH_WDATA, sizeof(_FLASH_WDATA));
        TestFls_Read(DFLASH0_UCB_BLK_0_ADDR, _FLASH_RDATA, sizeof(_FLASH_RDATA));
    }
    #endif
#endif
#endif

}/*End of Fls_Test */

