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
**          FILE  : TestFls.h
** 
**       PROJECT  : RBMS_STANDLAONE_TC275                                             
**       
**        AUTHOR  : Sungjin Ryu
**                                                                    
**       VERSION  : V1.0
**                                                                                                                                                                                                                                    
**      PLATFORM  : Infineon Aurix 275T                                         
**                                                                       
**   DESCRIPTION  : Header of the Flash Module
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


#ifndef TESTFLS_H
#define TESTFLS_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* flash RW's result */
#define FLS_RESULT_ERR_NONE                    (0x00000000U)
#define FLS_RESULT_ERR_INIT                    (0x00000001U)
#define FLS_RESULT_ERR_READ                    (0x00000002U)
#define FLS_RESULT_ERR_WRITE                   (0x00000003U)
#define FLS_RESULT_ERR_ERASE                   (0x00000004U)
#define FLS_RESULT_FAIL                        (0x00000010U)
#define FLS_RESULT_INVALID_PARAMETERS          (0x00000011U)

#define FLS_READ_BLOCK_LENGTH                  (32)
#define FLS_WRITE_BLOCK_LENGTH                 (32)

/*
    TC375의 HSM 관련 메모리는 아래와 같습니다
    0xA0020000--0xA0047FFF에 HSM 펌웨어가 위치합니다
    또한 0xA0000000--0xA01FFFFF 까지는 HSM 펌웨어가 위치한 부분을 제외하고
    메인 롬이 들어갑니다
*/
/******************************************************************************/
/* PFLASH_0 */
/******************************************************************************/
#define PFLASH_BLOCK_0_BASE             (0x80000000)
#define PFLASH_BLOCK_SIZE               (0x4000U) // 1sector 16Kbyte
#define PFLASH_MAX_SIZE                 (10*1024*1024) // Max 3+3+3+1=10Mbyte,
#define PFLASH_BLOCK_MAX                (PFLASH_MAX_SIZE/PFLASH_BLOCK_SIZE)

/* Database in PFLASH */
/* BLOCK0 */
#define PFLASH_BLK_0_ADDR               (PFLASH_BLOCK_0_BASE)

/* BLOCK1 */
#define PFLASH_BLK_1_ADDR               (PFLASH_BLK_0_ADDR + PFLASH_BLOCK_SIZE)

/* BLOCK2 */
#define PFLASH_BLK_2_ADDR               (PFLASH_BLK_1_ADDR + PFLASH_BLOCK_SIZE)

/******************************************************************************/
/* HSM */
/******************************************************************************/
#define ROM_HSM_START                   (0x80020000)
#define ROM_HSM_END                     (0x80050000)
#define ROM_HSM_SIZE                    (ROM_HSM_END - ROM_HSM_START)
#define DFLASH_HSM_BLOCK_0_BASE         (ROM_HSM_START)
#define DFLASH_HSM_BLOCK_SIZE           (0x4000U) // 1sector 16Kbyte
#define DFLASH_HSM_MAX_SIZE             (ROM_HSM_SIZE) // Max 192Kbyte,
#define DFLASH_HSM_BLOCK_MAX            (DFLASH_HSM_MAX_SIZE/DFLASH_HSM_BLOCK_SIZE)
        
/******************************************************************************/
/* DFLASH_0 */
/******************************************************************************/
#define DFLASH_BLOCK_0_BASE             (0xAF000000) // ~ 0xAF07FFFF (512Kbyte)
#define DFLASH_BLOCK_SIZE               (0x2000) // 1sector 8Kbyte
#define DFLASH_MAX_SIZE                 (512*1024) // Max 512Kbyte,
#define DFLASH_BLOCK_MAX                (DFLASH_MAX_SIZE/DFLASH_BLOCK_SIZE)

/* Database in DFLASH */
/* BLOCK0 */
#define DFLASH_BLK_0_ADDR               (DFLASH_BLOCK_0_BASE)

/* BLOCK1 */
#define DFLASH_BLK_1_ADDR               (DFLASH_BLK_0_ADDR + DFLASH_BLOCK_SIZE)

/* BLOCK2 */
#define DFLASH_BLK_2_ADDR               (DFLASH_BLK_1_ADDR + DFLASH_BLOCK_SIZE)

/******************************************************************************/
/* DFLASH_UCB */
/******************************************************************************/
// Max size 24Kbytes
// Sector size 512bytes (0x200)
// DFLASH0_UCB_MS0
#define DFLASH0_UCB_BLOCK_0_BASE        (0xAF400000)
#define DFLASH0_UCB_BLOCK_SIZE          (0x200)
#define DFLASH0_UCB_MAX_SIZE            (24*1024) // Max 24Kbyte,

/* Database in DFLASH0_UCB */
/* BLOCK0 */
#define DFLASH0_UCB_BLK_0_ADDR          (DFLASH0_UCB_BLOCK_0_BASE)

/* BLOCK1 */
#define DFLASH0_UCB_BLK_1_ADDR          (DFLASH0_UCB_BLK_0_ADDR + DFLASH0_UCB_BLOCK_SIZE)

/* BLOCK2 */
#define DFLASH0_UCB_BLK_2_ADDR          (DFLASH0_UCB_BLK_1_ADDR + DFLASH0_UCB_BLOCK_SIZE)

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
extern void TestFls_Init(void);
extern uint16 TestFls_CalcChksum(uint8 *pData, uint16 nSize);
extern uint8 TestFls_Erase(uint32 nAddr);
extern uint8 TestFls_Read(uint32 nAddr, uint8 *pData, uint32 nSize);
extern uint8 TestFls_Write(uint32 nAddr, uint8 *pData, uint32 nSize);

#endif /* TESTFLS_H */
