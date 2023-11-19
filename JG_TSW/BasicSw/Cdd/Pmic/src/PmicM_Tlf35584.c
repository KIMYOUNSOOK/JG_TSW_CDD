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
**          FILE  : PmicM_Tlf35584.c                                            
** 
**       PROJECT  : RBMS_STANDLAONE_TC275                                             
**       
**        AUTHOR  : Hyun Kang
**                                                                    
**       VERSION  : V1.1                                                       
**                                                                                                                                                                                                                                    
**      PLATFORM  : Infineon Aurix 275T                                         
**                                                                       
**   DESCRIPTION  : This file contains                                         
**                  - functionality of xxx                                                                                                                
**                                                                            
*******************************************************************************/


/*********************************************************************************************************************
**                                          Revision History                                                        **
**********************************************************************************************************************
 *  ------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author         Change Id     Description
 *  ------------------------------------------------------------------------------------------------------------------

 *	V1.0      2019-03-01  Hyun Kang      - 			   First Implementation


*********************************************************************************************************************/






/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <string.h>
#include "IfxQspi_reg.h"
#include "Spi.h"
#include "Irq.h"
#include "Port.h"
#include "PmicM_Tlf35584.h"
/* #include "Can_17_MCanP.h" @YGSON */
/* #include "SMC_swc.h" @YGSON */
#include "Utils.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define PMIC_SPI_M_CHANNEL                  SpiConf_SpiChannel_SpiChannel_2_PMIC
#define PMIC_SPI_M_SEQ                      SpiConf_SpiSequence_SpiSequence_2_PMIC

#define PMIC_SPI_M_PORT_MTSR                PortConf_PortContainer_8_PORT_15_PIN_6
#define PMIC_SPI_M_PORT_SCLK                PortConf_PortContainer_8_PORT_15_PIN_3
#define PMIC_SPI_M_PORT_CS                  DioConf_DioChannel_DioChannel_SPI2_CS
#define PMIC_SPI_M_PORT_MRST                PortConf_PortContainer_8_PORT_15_PIN_7

#define PMIC_SPI_HW_MODULE                  ((volatile Ifx_QSPI*)(volatile void*) &(MODULE_QSPI2))
#define PMIC_SPI_PATH                       SPI_QSPI2_INDEX

#define PMIC_SPI_GLOBALCONREG_EN_CLEARMASK  (0xFFFFFFFFU)
#define PMIC_SPI_GLOBALCONREG_EN_ENABLE     (0x01000000U)
#define PMIC_SPI_GLOBALCONREG_EN_DISABLE    (0xFEFFFFFFU)

#define SPI0_TRY_MAX_CNT	100
#define TLF35584_TRY_ENABLE_MAX	500

#define TLF35584_SF_STG_BP 0
#define TLF35584_SF_OV_BP 1
#define TLF35584_SF_UV_BP 2

#define REQ_HEAL 1

#define MODULE_CAN_NCR0		(*(volatile uint32*)0xF0018200)
#define MODULE_CAN_NCR1		(*(volatile uint32*)0xF0018300)
#define MODULE_CAN_NCR2		(*(volatile uint32*)0xF0018400)
#define MODULE_CAN_NCR3		(*(volatile uint32*)0xF0018500)

#define ABIST_FAIL 0x1
#define ABIST_SUCCESS 0x0
#define ABIST_TOTAL_RESULT 0x0		/*TestMode & Bit Position of Secondary Safety Shutdown Path logic Test */
#define SSSP_TEST 0x1			/*TestMode & Bit Position of Secondary Safety Shutdown Path logic Test */
#define SSSP_CND_TEST 0x2 		/*TestMode & Bit Position of Comparator and Deglitching logic related SSSP Test*/
#define SSSP_COMP_TEST 0x3 		/*TestMode / Bit Position of Comparator related SSSP Test */
#define INTGEN_TEST 0x4			/*TestMode / Bit Position of Interrupt Generation Test */
#define INTGEN_CND_TEST 0x5		/*TestMode / Bit Position of Comparator and Deglitching logic related INT Test*/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef struct
{
    /* 1st byte */
    boolean m_bIfAbistIfMon : 1U;
    boolean m_bSysFailVMonf : 1U;
    boolean m_bInitErrVMonf : 1U;
    boolean m_bAbistCtrl0Start  : 1U;
    boolean m_bAbistSelect0  : 1U;
    boolean m_bAbistSelect1  : 1U;
    boolean m_bAbistSelect2  : 1U;
    boolean m_bMonSf  : 1U;

    /* 2nd ~ 7th byte */
    uint8 m_nComplexDiag;
    uint8 m_nMonsf0;
    uint8 m_nMonsf1;
    uint8 m_nMonsf2;
    uint8 m_nMonsf3;
    uint8 m_nVmonstat;
    uint8 m_nDevstat;
    
} SM_DIAG_REPORT_T;/* Max 8Bytes */



/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/




/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


  
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint8 PmicM_Tlf35584_u8stUMon;   /* kh */

uint16 TLF35584_RecordData[4] = {0u};
uint16 SpiTxMsg;
uint16 SpiRxMsg;
uint32 SpiSeqResult = 0;
uint32 RecordIndex = 0;
uint16 SPI0_TryCount_Tx;
uint16 Tlf35584_EnableTryCount=0u;

uint8 IF_Mon=0u;
uint8 MONSF0_STG=0u;
uint8 MONSF2_UV=0u;
uint8 reg;
uint8 reg_n;

uint8 TLF35584_Sysfail =0;
uint8 TLF35584_Initerr =0;
uint8 TLF35584_If      =0;
uint8 TLF35584_Syssf   =0;
uint8 TLF35584_Wksf    =0;
uint8 TLF35584_Spisf   =0;
uint8 TLF35584_Monsf0  =0;
uint8 TLF35584_Monsf1  =0;
uint8 TLF35584_Monsf2  =0;
uint8 TLF35584_Monsf3  =0;
uint8 TLF35584_Otfail  =0;
uint8 TLF35584_Otwrnsf =0;
uint8 TLF35584_Vmonstat=0;
uint8 TLF35584_Devstat =0;
uint8 TLF35584_AbistCtrl0 =0;
uint8 TLF35584_AbistSel0 =0;
uint8 TLF35584_AbistSel1 =0;
uint8 TLF35584_AbistSel2 =0;

uint32 TLF35584_AbistFail1 =0;
uint32 TLF35584_AbistFail2 =0;

/* ABIST Report to CAN */
uint8 TLF35584_AbistResult = ABIST_SUCCESS;
uint8 TLF35584_AbistDiag0 = 0;
uint8 TLF35584_AbistDiag1 = 0;
uint8 TLF35584_AbistDiag2 = 0;
uint8 TLF35584_TestMode = 0;

static SM_DIAG_REPORT_T l_tSmDiagReport;
static uint8 TLF35584_SmTickCount = 1;

//volatile Spi_DataBufferType	TLF35584_SeqComplete = 0;

const uint8 TLF35584_FwdRespTable[16][4]=
{   /* QUEST, RESP0, RESP1, RESP2, RESP3 */
		/* 0 */   { 0x00, 0xF0, 0x0F, 0xFF },
		/* 1 */   { 0x4F, 0xBF, 0x40, 0xB0 },
		/* 2 */   { 0x16, 0xE6, 0x19, 0xE9 },
		/* 3 */   { 0x59, 0xA9, 0x56, 0xA6 },
		/* 4 */   { 0x8A, 0x7A, 0x85, 0x75 },
		/* 5 */   { 0xC5, 0x35, 0xCA, 0x3A },
		/* 6 */   { 0x9C, 0x6C, 0x93, 0x63 },
		/* 7 */   { 0xD3, 0x23, 0xDC, 0x2C },
		/* 8 */   { 0x2D, 0xDD, 0x22, 0xD2 },
		/* 9 */   { 0x62, 0x92, 0x6D, 0x9D },
		/* 10 */  { 0x3B, 0xCB, 0x34, 0xC4 },
		/* 11 */  { 0x74, 0x84, 0x7B, 0x8B },
		/* 12 */  { 0xA7, 0x57, 0xA8, 0x58 },
		/* 13 */  { 0xE8, 0x18, 0xE7, 0x17 },
		/* 14 */  { 0xB1, 0x41, 0xBE, 0x4E },
		/* 15 */  { 0xFE, 0x0E, 0xF1, 0x01 }
};
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

uint16 TLF35584_ParityGeneration(uint16 Data);
void TLF35584_CommunicationRecord(uint16 RecordTxData, uint16 RecordRxData, uint8 Address);
uint8 TLF35584_ReadOperSts(void);
void TLF35584_MonVolSts(void);
void TLF35584_HealOperSts(void);
void TLF35584_UnlockProtectedRegister(void);
void TLF35584_LockProtectedRegister(void);
void TLF35584_SysWdConfig(void);
void TLF35584_Communication(uint16 Mode, uint8 Address, uint8 Data);
void TLF35584_SafetyMeasurment(void);

#if 1
static void __Delay_us(uint32 n)
{
    for(uint32 i = 0; i < ((n*(52500))/1000); i++)
    {
        NOP();
    }
}
#else
#include "Ifx_cfg.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"
#include "Mcu_Cfg.h"
uint32 Get_Fstm()
{
  uint32 Fsrc = 0;
  uint32 Fstm = 10;

  uint8 CLKSEL = SCU_CCUCON0.B.CLKSEL;

  if(CLKSEL == 1)
  {
    Fsrc = ((MCU_MAIN_OSC_FREQ * 1000000) * (SCU_SYSPLLCON0.B.NDIV + 1)) / ((SCU_SYSPLLCON0.B.PDIV + 1) * (SCU_SYSPLLCON1.B.K2DIV + 1));
  }
  else
  {
    Fsrc = (MCU_BACKUP_FREQ * 1000000);
  }

  Fstm = Fsrc / (SCU_CCUCON0.B.STMDIV);

  return Fstm;
}

typedef enum
{
  NS = 0, /* Not Supported */
  MS = 1, /* Millisecond */
  US = 2 /* Micro Seconds */
} Test_TimeUnit;

uint32 Get_Counter_Value(uint32 reqTime, Test_TimeUnit unitOfReqTime)
{
  uint32 Fstm = Get_Fstm();
  if(unitOfReqTime == MS)
  {
    return (uint32)((float)(((((float)Fstm / (1000.0))) * (reqTime)) + 0.5));
  }
  else if(unitOfReqTime == US)
  {
    return (uint32)((float)(((((float)Fstm / (1000000.0))) * (reqTime))));
  }
  else
  {
    return (uint32)0;
  }
}

static void __Delay_us(uint32 n)
{
    volatile uint32 ReadStm;
    uint32 Delay_Count, Delay_Compare_Count;

    Delay_Count = Get_Counter_Value(n,US);

    Delay_Compare_Count = Delay_Count + STM0_TIM0.U;

    ReadStm = STM0_TIM0.U;

    while( Delay_Compare_Count >= ReadStm)
    {
        ReadStm = STM0_TIM0.U;
    }
}
#endif

/*******************************************************************************
** Traceabilty      : Unit design requirement ID
** Syntax           : uint16 TLF35584_ParityGeneration(uint16 Data)
**
** Service ID       : N/A (Private)
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint16 Data
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function:
**   - Perform service xxx
**
*******************************************************************************/

uint16 TLF35584_ParityGeneration(uint16 Data)
{
	uint16 n = 0;

	while (Data)
	{
		Data &= Data-1;
		++n;
	}
	while (n > 1)
	{
		n = n-2;
	}

	return (n);

} /*End of TLF35584_ParityGeneration()*/


/*******************************************************************************
** Traceability      : Unit design requirement ID
**
** Syntax           : void TLF35584_CommunicationRecord(uint16 RecordTxData, uint16 RecordRxData, uint8 Address)
**
** Service ID       : N/A (Private)
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint16 RecodeTxData, uint16 RecodeRxData, uint8 Address
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: For record Tx,Rx Data. (Debugging Purpose)
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_CommunicationRecord(uint16 RecordTxData, uint16 RecordRxData, uint8 Address)
{

	TLF35584_RecordData[0] = RecordTxData;
	TLF35584_RecordData[1] = RecordRxData;
	TLF35584_RecordData[2] = Address;
	TLF35584_RecordData[3] = (RecordRxData >> 1) & 0x00FF;

	RecordIndex++;

	if(RecordIndex ==21)
	{
		RecordIndex=0;
	}
} /*End of TLF35584_CommunicationRecord()*/

/*******************************************************************************
** Traceability      : Unit design requirement ID
**
** Syntax           : uint8 TLF35584_ReadOperSts(void)
**
** Service ID       : N/A (Private)
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint16 RecodeTxData, uint16 RecodeRxData, uint8 Address
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: For record Tx,Rx Data. (Debugging Purpose)
**   - Perform service xxx
**
*******************************************************************************/

uint8 TLF35584_ReadOperSts(void)
{

	TLF35584_Communication(READ,DEVCTRL,0x00u);
	return (TLF35584_RecordData[3] & 0x07u);

}

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void TLF35584_MonVolSts(void)
**
** Service ID       : N/A (Private)
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For Monitoring TLF35584 Voltage status
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_MonVolSts(void)
{
	/* bit 0 : MONSF0  Short to ground */
	/* bit 2 : MONSF2 Under Voltage */

	TLF35584_Communication(READ,IF,0u);   /* Interrupt Flag read  */
	IF_Mon = (TLF35584_RecordData[3]&0x08) >> 3u; // 4th bit

	/* 1. Monitor Interrupt Flag */
	if(IF_Mon != 0u)
	{
		TLF35584_RecordData[3] = 0u;

		/* 2. Check detail MONSF0, MONSF2 Register */
		/* Short to ground */
		TLF35584_Communication(READ,MONSF0  , 0x0);
		MONSF0_STG = (uint8)TLF35584_RecordData[3];
		if(MONSF0_STG != 0u)
		{
			PmicM_Tlf35584_u8stUMon |= (0x01<<TLF35584_SF_STG_BP);
		}
		TLF35584_RecordData[3] = 0u; /* clear*/

		/* Under Voltage */
		TLF35584_Communication(READ,MONSF2  , 0x0);
		MONSF2_UV = (uint8)TLF35584_RecordData[3];
		if(MONSF2_UV != 0u)
		{
			PmicM_Tlf35584_u8stUMon|= (0x01<<TLF35584_SF_UV_BP);
		}
	}
}

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void TLF35584_HealOperSts(void)
**
** Service ID       : N/A (Private)
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For healing operation status as going to normal
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_HealOperSts(void)
{
#if 0 /* @YGSON */
	if(SMC_u8cmdPmicOperMod == REQ_HEAL)
	{
		/* Try to refresh the TLF35584 */
		PmicM_Tlf35584_Go_To_State(PMICM_NORMAL);


		/* Clear Flag */
		TLF35584_Communication(WRITE,SYSFAIL,0xFFu);
		TLF35584_Communication(WRITE,MONSF0,0xFFu);
		TLF35584_Communication(WRITE,MONSF2,0xFFu);
		TLF35584_Communication(WRITE,IF,0xFFu);


		/* Enable CAN controller */
	    CAN_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_CAN_NCR0, CAN_NCR_INIT_CLEARMASK, 0u)
		CAN_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_CAN_NCR1, CAN_NCR_INIT_CLEARMASK, 0u)
		CAN_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_CAN_NCR2, CAN_NCR_INIT_CLEARMASK, 0u)
		CAN_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_CAN_NCR3, CAN_NCR_INIT_CLEARMASK, 0u)

		PmicM_Tlf35584_u8stUMon = 0x0;

	}
#endif
}

/*******************************************************************************
** Function Name    : TLF35584_SafetyMeasurment
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TLF35584_SafetyMeasurment(void)
{
    TLF35584_Communication(READ, MONSF0, 0x0);
    TLF35584_Monsf0 = (uint8)((SpiRxMsg >> 1) & 0xff);

    TLF35584_Communication(READ, MONSF1, 0x0);
    TLF35584_Monsf1 = (uint8)((SpiRxMsg >> 1) & 0xff);

    TLF35584_Communication(READ, MONSF2, 0x0);
    TLF35584_Monsf2 = (uint8)((SpiRxMsg >> 1) & 0xff);
    
    TLF35584_Communication(READ, MONSF3, 0x0);
    TLF35584_Monsf3 = (uint8)((SpiRxMsg >> 1) & 0xff);

    TLF35584_Communication(READ, VMONSTAT, 0x0);
    TLF35584_Vmonstat = (uint8)((SpiRxMsg >> 1) & 0xff);
    
    TLF35584_Communication(READ, DEVSTAT, 0x0);
    TLF35584_Devstat = (uint8)((SpiRxMsg >> 1) & 0xff);

}

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_Init(void)
**
** Service ID       : 01
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For healing operation status as going to normal
**   - Perform service xxx
**
*******************************************************************************/

void PmicM_Tlf35584_Init(void)
{
    memset(&l_tSmDiagReport, 0x00U, sizeof(SM_DIAG_REPORT_T));
    
    /* Disable Watchdog  */
    TLF35584_SysWdConfig();

    /* Wakeup Timer Configuration : 5s = 500(0x01F4) * 10ms, 6s = 600(0x0258) * 10ms, 10s = 1000(0x03E8) * 10ms, 60s = 6000(0x1770) * 10ms */
    // For the chosen time-base of 100 kHz the timer resolution is 10 ¥ìs and a wake up time between 10 ¥ìs to 168 s can be configured via SPI.
    // For the chosen time-base of 100 Hz the timer resolution is 10 ms and a wake up time between 10 ms to 1.9 days can be configured via SPI.
    // @@SURE - In case of DEVCFG0'WKTIMCYC=1(0:10us, 1:10ms), If set 50s, 50*1000ms=50000ms/100hz, WKTIMECFG0~2=500(0x1F4)
    TLF35584_Communication(WRITE,WKTIMCFG0, 0x58);
    TLF35584_Communication(WRITE,WKTIMCFG1, 0x02);
    TLF35584_Communication(WRITE,WKTIMCFG2, 0x00);

    /* Clear Status Flag */
    TLF35584_Communication(WRITE,IF,0x7F);
    TLF35584_Communication(WRITE,SYSSF,0x3F);
    TLF35584_Communication(WRITE,MONSF0,0xFF);
    TLF35584_Communication(WRITE,MONSF1,0xFF);
    TLF35584_Communication(WRITE,MONSF2,0xFF);
    TLF35584_Communication(WRITE,MONSF3,0xFF);
    TLF35584_Communication(WRITE,INITERR,0xFC);
    TLF35584_Communication(WRITE,SYSFAIL,0xC7);

    /* Go To NORMAL */
    PmicM_Tlf35584_Go_To_State(PMICM_NORMAL);
}


/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_MainFunction_100ms(void)
**
** Service ID       : 02
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For healing operation status as going to normal
**   - Perform service xxx
**
*******************************************************************************/

void PmicM_Tlf35584_MainFunction_100ms(void)
{
	TLF35584_MonVolSts();
	TLF35584_HealOperSts();

    /* Safety Measurement run every 500ms */
    if(TLF35584_SmTickCount >= 5) // 500ms
    {
        TLF35584_SmTickCount = 1;
        TLF35584_SafetyMeasurment();
        return;
    }
    
    TLF35584_SmTickCount++;
}

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_WakeupTimerEnable(uint8 EnableSt)
**
** Service ID       : 03
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For healing operation status as going to normal
**   - Perform service xxx
**
*******************************************************************************/

void PmicM_Tlf35584_WakeupTimerEnable(uint8 EnableSt)
{
    // 7:WKTIMEN, 6:WKTIMCYC, 5~4:NU, 3~0:TRDEL
    // WKTIMEN=1, WKTIMCYC=1(0:10us, 1:10ms), TRDEL=(0:100us, 1:200us, ~~~, 15:1600us)
	if(EnableSt==STD_ON)
	{
		TLF35584_Communication(WRITE,DEVCFG0, 0xC8);	/* Wake-up Timer Enable, Wake timer unit = 10ms */
	}
	else
	{
		TLF35584_Communication(WRITE,DEVCFG0, 0x48);	/* Wake-up Timer Disable, Wake timer unit = 10ms */
	}
}





/*******************************************************************************
** Traceability      : Unit design requirement ID
**
** Syntax           : void TLF35584_UnlockProtectedRegister(void)
**
** Service ID       :
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: Unlock Protected register
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_UnlockProtectedRegister(void)
{
	/* UNLOCK - Send password sequence */
	TLF35584_Communication(WRITE,PROTCFG, 0xAB);
	TLF35584_Communication(WRITE,PROTCFG, 0xEF);
	TLF35584_Communication(WRITE,PROTCFG, 0x56);
	TLF35584_Communication(WRITE,PROTCFG, 0x12);

} /*End of TLF35584_UnlockProtectedRegister()*/


/*******************************************************************************
** Traceabilty      : Unit design requirement ID
** Syntax           : void TLF35584_LockProtectedRegister(void)
**
** Service ID       :
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: Lock Protected register
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_LockProtectedRegister(void)
{
	/* LOCK - Send password sequence */
	TLF35584_Communication(WRITE,PROTCFG, 0xDF);
	TLF35584_Communication(WRITE,PROTCFG, 0x34);
	TLF35584_Communication(WRITE,PROTCFG, 0xBE);
	TLF35584_Communication(WRITE,PROTCFG, 0xCA);

} /*End of TLF35584_LockProtectedRegister()*/


/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void TLF35584_Communication(uint16 Mode, uint8 Address, uint8 Data)
**
** Service ID       :
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint16 Mode, uint8 Address, uint8 Data
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: For communication with TLF35584 , User can read and write Data to TLF by API
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_Communication(uint16 Mode, uint8 Address, uint8 Data)
{
    uint8 nRet;
    SpiTxMsg = (  (Mode<<15) |      /* Write command */
            (Address << 9) |        /* Address */
            (Data << 1) );          /* Data */
    SpiTxMsg |= TLF35584_ParityGeneration(SpiTxMsg); /* Parity */

    Spi_SetupEB(PMIC_SPI_M_CHANNEL, (Spi_DataBufferType *)&SpiTxMsg, (Spi_DataBufferType *)&SpiRxMsg, 1);

    nRet = Spi_SyncTransmit(PMIC_SPI_M_SEQ);
    SPI0_TryCount_Tx = 0;

    do
    {
        SPI0_TryCount_Tx++;
        SpiSeqResult = Spi_GetSequenceResult(PMIC_SPI_M_SEQ);
    }while((SpiSeqResult != SPI_SEQ_OK) && (SPI0_TryCount_Tx <= SPI0_TRY_MAX_CNT));

    TLF35584_CommunicationRecord(SpiTxMsg,SpiRxMsg,Address);
} /*End of TLF35584_Communication()*/


/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_Go_To_State(uint8 State)
**
** Service ID       : 04
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint8 State
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: TLF35585 state control (register set)
**   - Perform service xxx
**
*******************************************************************************/


void PmicM_Tlf35584_Go_To_State(uint8 State)
{
	static uint8 Read_State=0u;

	switch(State)
	{
	case PMICM_INIT:
		reg = 0xE1;
		break;
	case PMICM_NORMAL:
		reg = 0xEA;
		break;
	case PMICM_SLEEP:
		reg = 0xE3;
		break;
	case PMICM_STANDBY:
		reg = 0x04; /* 0x00000100 */
		break;
	case PMICM_WAKE:
		reg = 0xE5;
		break;

	default:
		reg = 0;
	break;
	}

	reg_n = ((~reg) & 0xEF);

	/* unlock access of protected register  */
	TLF35584_UnlockProtectedRegister();

    if(State == PMICM_STANDBY)
    {
        TLF35584_Communication(WRITE, SYSPCFG0, 0x00);
    }
        
	TLF35584_Communication(WRITE, DEVCTRL, reg);
	TLF35584_Communication(WRITE, DEVCTRLN, reg_n);

	/* lock access of protected register  */
	TLF35584_LockProtectedRegister();

	/* Read-Back */
	Read_State = PmicM_Tlf35584_Get_CurrState();

} /*End of PmicM_Tlf35584_Go_To_State()*/



/*******************************************************************************
** Traceability     : Unit design requirement ID
** Syntax           : uint8 PmicM_Tlf35584_Get_CurrState(void)
**
** Service ID       : 05
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : uint8 State
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : This function: TLF35585 state control (register set)
**   - Perform service xxx
**
*******************************************************************************/


uint8 PmicM_Tlf35584_Get_CurrState(void)
{
	uint8 CurrState = 0u;

	TLF35584_Communication(READ,DEVSTAT,0u);
	CurrState = (TLF35584_RecordData[3] & 0x07u);

	return CurrState;

}

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void TLF35584_SysWdConfig(void)
**
** Service ID       :
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For configuration System WD function
**   - Perform service xxx
**
*******************************************************************************/

void TLF35584_SysWdConfig(void)
{

    /* unlock access of protected register  */
    TLF35584_UnlockProtectedRegister();

    /* +send TLF35584 configuration */
    TLF35584_Communication(WRITE,SYSPCFG0, 0x01); /* Enable request for standby LDO : STBYEN=1 */
    //TLF35584_Communication(WRITE,SYSPCFG0, 0x00); /* Enable request for standby LDO : STBYEN=0 */
    __Delay_us(2000); /* wait for 2ms (timeout) */
    TLF35584_Communication(WRITE,SYSPCFG1, 0x0); /* SS2DEL=no delay, ERRSLPEN=Disable ERR monitor in sleep, ERREN=Disable ERR monitor, ERRRECEN=0, ERRREC=0 */
    TLF35584_Communication(WRITE,WDCFG0, 0x93);  /* WWDETHR=9, WWDEN=Disable, FWDEN=Disable, WWDTSEL=SPI trigger, WDCYC=1ms tick */
    TLF35584_Communication(WRITE,WDCFG1, 0x9);   /* WDSLPEN=Disable watchdog in sleep, FWDETHR=0 */
    TLF35584_Communication(WRITE,FWDCFG, 0xB);   /* WDHBTP=600 wd cycle, Heartbeat timer period */
    TLF35584_Communication(WRITE,WWDCFG0, 0x2);  /* CW=150 wd cycle */
    TLF35584_Communication(WRITE,WWDCFG1, 0x3);  /* OW=200 wd cycle */

    /* lock access of protected register  */
    TLF35584_LockProtectedRegister();


} /*End of TLF35584_SysWdConfig()*/
/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_ReadWakeupStatus(tWakeupSt *WakSt)
**
** Service ID       : 06
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : tWakeupSt *WakSt
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For reading wakeup status of TLF35584
**   - Perform service xxx
**
*******************************************************************************/

void PmicM_Tlf35584_ReadWakeupStatus(tWakeupSt *WakSt)
{

	TLF35584_Communication(READ,WKSF,0x00u);
	if((TLF35584_RecordData[3] & 0x10u)==0x10u)
	{
		*WakSt = BY_SPI_COMMND;
	}
	else if((TLF35584_RecordData[3] & 0x08u)==0x08u)
	{
		*WakSt = BY_WAKEUP_TIMER;
	}
	else if((TLF35584_RecordData[3] & 0x04u)==0x04u)
	{
		*WakSt = BY_LDO_UC_CURRENT_MONITOR;
	}
	else if((TLF35584_RecordData[3] & 0x02u)==0x02u)
	{
		*WakSt = BY_ENA_SIG;
	}
	else if((TLF35584_RecordData[3] & 0x01u)==0x01u)
	{
		*WakSt = BY_WAK_SIG;
	}
	else
	{
		*WakSt = DEFAULT_VAL;
	}
}

/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : void PmicM_Tlf35584_ClearWakeupStatus(void)
**
** Service ID       : 07
**
** Sync/Async       : N/A (option for OS)
**
** Reentrancy       : N/A (option for OS)
**
** Parameters(in)   : -
**
** Parameters (out) : -
**
** Return value     : void
**
** Description      : For reading wakeup status of TLF35584
**   - Perform service xxx
**
*******************************************************************************/

void PmicM_Tlf35584_ClearWakeupStatus(void)
{
	TLF35584_Communication(WRITE,WKSF,0xFFu);
}


//******************************************************************************
// @Function	 	void TLF35584_ReadDiagnosisRegister(void)
// @Description   	For Read diagnosis registers
// @Return Value	None
// @Parameters    	None
//******************************************************************************
void TLF35584_ReadDiagnosisRegister(void)
{

	//memset(TLF35584_RecordData, 0U, 20*8);  // Test Purpose, To Initialize Record memory
	//RecordIndex=0;

	TLF35584_Communication(READ,SYSFAIL,0);
	TLF35584_Sysfail=(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,INITERR , 0x0);
	TLF35584_Initerr =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,IF      , 0x0);
	TLF35584_If      =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,SYSSF   , 0x0);
	TLF35584_Syssf   =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,WKSF    , 0x0);
	TLF35584_Wksf    =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,SPISF   , 0x0);
	TLF35584_Spisf   =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,MONSF0  , 0x0);
	TLF35584_Monsf0  =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,MONSF1  , 0x0);
	TLF35584_Monsf1  =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,MONSF2  , 0x0);
	TLF35584_Monsf2  =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,MONSF3  , 0x0);
	TLF35584_Monsf3  =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,OTFAIL  , 0x0);
	TLF35584_Otfail  =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,OTWRNSF , 0x0);
	TLF35584_Otwrnsf =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,VMONSTAT, 0x0);
	TLF35584_Vmonstat=(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,DEVSTAT , 0x0);
	TLF35584_Devstat =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,ABIST_CTRL0 , 0x0);
	TLF35584_AbistCtrl0 =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,ABIST_SELECT0 , 0x0);
	TLF35584_AbistSel0 =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,ABIST_SELECT1 , 0x0);
	TLF35584_AbistSel1 =(uint8)(SpiRxMsg >> 1)&0xff;
	TLF35584_Communication(READ,ABIST_SELECT2 , 0x0);
	TLF35584_AbistSel2 =(uint8)(SpiRxMsg >> 1)&0xff;

/*
	TLF35584_Communication(READ,SYSFAIL,0);
	TLF35584_Communication(READ,INITERR , 0x0);
	TLF35584_Communication(READ,IF      , 0x0);
	TLF35584_Communication(READ,SYSSF   , 0x0);
	TLF35584_Communication(READ,WKSF    , 0x0);
	TLF35584_Communication(READ,SPISF   , 0x0);
	TLF35584_Communication(READ,MONSF0  , 0x0);
	TLF35584_Communication(READ,MONSF1  , 0x0);
	TLF35584_Communication(READ,MONSF2  , 0x0);
	TLF35584_Communication(READ,MONSF3  , 0x0);
	TLF35584_Communication(READ,OTFAIL  , 0x0);
	TLF35584_Communication(READ,OTWRNSF , 0x0);
	TLF35584_Communication(READ,VMONSTAT, 0x0);
	TLF35584_Communication(READ,DEVSTAT , 0x0);*/

} /*End of TLF35584_ReadDiagnosisRegister()*/


//************************************************************************************************************
// @Function	 	void TLF35584_ABIST(void)
// @Description   	None
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************
void TLF35584_ABIST(void)
{

	TLF35584_ABIST_SafetyPath();
	TLF35584_ABIST_GenIt();


} /*End of TLF35584_ABIST()*/



//************************************************************************************************************
// @Function	 	void TLF_ABIST_SafetyPath(void)
// @Description   	For clearing wakeup status of TLF35584
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************

void TLF35584_ABIST_SafetyPath(void)
{


	/********* Testing the activation of the secondary safety shutdown path  *****************/
#ifdef SSSP

	TLF35584_TestMode = SSSP_TEST;
	/* Send READ or WRITE command to TLF35584 */
	TLF35584_Communication(READ,DEVSTAT,0x0); 				 /* 1. DEVSTAT : if DEVSTAT is normal mode, go to NORMAL */

	if(((SpiRxMsg >> 1) & 0x7) != NORMAL){

		PmicM_Tlf35584_Go_To_State(NORMAL);
	}

															/* 2. Check SS1/2 is High (with scope)  */
	/* Send READ or WRITE command to TLF35584 */
	uint8 AbistSelSet0 = 0x02;
	uint8 AbistSelSet1 = 0x00;
	uint8 AbistSelSet2 = 0x00;

	TLF35584_Communication(WRITE,ABIST_SELECT0,AbistSelSet0 ); 		/* 3. 0x02 ucov, Select comparator to make Secondary Safety Shutdown Path */
	TLF35584_Communication(WRITE,ABIST_SELECT1,AbistSelSet1 );
	TLF35584_Communication(WRITE,ABIST_SELECT2,AbistSelSet2 );

	TLF35584_Communication(WRITE,ABIST_CTRL0,0x7); 			/* 4. single comparator, on the full path and start ABIST */
	__Delay_us(200);											/* wait for 200us (timeout) */

	TLF35584_ReadDiagnosisRegister();						/* 5. read Diag. Registers  */


	if((TLF35584_If & 0x48) != 0x40){						/* IF.ABIST, IF.MON (1b)*/
		TLF35584_AbistFail1 |= 0x1<<0;						/* Test Fail */
	}
	if((TLF35584_Sysfail & 0x4)!= 0x4){						/* SYSFAIL.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<2;						/* Test Fail */
	}
	if((TLF35584_Initerr & 0x4)!= 0x4){						/* INITERR.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<3;						/* Test Fail */
	}
	if((TLF35584_AbistCtrl0 & 0xF1)!= 0x50){				/* ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)*/
		TLF35584_AbistFail1 |= 0x1<<4;						/* Test Fail */
	}
	if((TLF35584_AbistSel0 & 0xFF)!= 0x0){					/* ABIST_SELECT0 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<5;						/* Test Fail */
	}
	if((TLF35584_AbistSel1 & 0xFF)!= 0x0){					/* ABIST_SELECT1 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<6;						/* Test Fail */
	}
	if((TLF35584_AbistSel2 & 0xFF)!= 0x0){					/* ABIST_SELECT2 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<7;						/* Test Fail */
	}

	if((TLF35584_Monsf1 & 0xFF)!= AbistSelSet0){			/* MONSF1 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<8;						/* Test Fail */
	}
	if((TLF35584_Monsf2 & 0xFF)!= AbistSelSet1){			/* MONSF2 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<9;						/* Test Fail */
	}
	if((TLF35584_Monsf3 & 0xFF)!= AbistSelSet2){			/* MONSF3 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<10;						/* Test Fail */
	}
	if((TLF35584_Monsf3 & 0xFF)!= AbistSelSet2){			/* MONSF3 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<11;						/* Test Fail */
	}

	if((TLF35584_Devstat & 0x07)!= 0x5){					/* DEVSTAT (WAKE)*/
		TLF35584_AbistFail1 |= 0x1<<12;						/* Test Fail */
	}
	TLF35584_ReportAbistDiag(TLF35584_TestMode);							/* Report ABIST result */
	TLF35584_IfMonClear(); 									/* clear IF, MONSF */
	TLF35584_AbistVarClear();
	AbistSelSet0 =0 ;
	AbistSelSet1 =0;
	AbistSelSet2 =0;
#endif


	/************** Testing the comparator logic and the corresponding deglitching logic ****************/

	/*  Secondary safety shutdown path  related    */


	uint8 AbistSelSet0 = 0x27; /* except for VCOREOV  2F -> 27*/
	uint8 AbistSelSet1 = 0x06; /* except for VCOREUV  0E -> 06*/
	uint8 AbistSelSet2 = 0xC1;


	TLF35584_TestMode = SSSP_CND_TEST;

	/* Send READ or WRITE command to TLF35584 */
	TLF35584_Communication(READ,DEVSTAT,0x0); 				 /* 1. DEVSTAT : if DEVSTAT is normal mode, go to NORMAL */
	if(((SpiRxMsg >> 1) & 0x7) != PMICM_NORMAL)
	{

		PmicM_Tlf35584_Go_To_State(PMICM_NORMAL);
	}

	/* Send READ or WRITE command to TLF35584 */


	TLF35584_Communication(WRITE,ABIST_SELECT0,AbistSelSet0 ); 		/* WRITE ABIST_SELECT0-2 : PREGOV UCOV STBYOV VCOREOV VREFOV */
	TLF35584_Communication(WRITE,ABIST_SELECT1,AbistSelSet1 );		/* UCUV STBYUV VCOREUV */
	TLF35584_Communication(WRITE,ABIST_SELECT2,AbistSelSet2 );		/* VBATOV BIASLOW BIASHI */

	TLF35584_Communication(WRITE,ABIST_CTRL0,0x3); 					/*  PREDEFINED SEQ. on the full path and start ABIST */
	__Delay_us(1000);													/* wait for 1ms (timeout) */

	TLF35584_ReadDiagnosisRegister();						/* 5. read Diag. Registers  */

	if((TLF35584_If & 0x48) != 0x40)
	{						/* IF.ABIST, IF.MON (1b)*/
		TLF35584_AbistFail1 |= 0x1<<0 ;										/* Test Fail */
	}

	if((TLF35584_Sysfail & 0x4)!= 0x4)
	{						/* SYSFAIL.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<1 ;										/* Test Fail */
	}

	if((TLF35584_Initerr & 0x4)!= 0x4)
	{						/* INITERR.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<2 ;										/* Test Fail */
	}

	if((TLF35584_AbistCtrl0 & 0xF1)!= 0x50)
	{				/* ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)*/
		TLF35584_AbistFail1 |= 0x1<<3 ;										/* Test Fail */
	}

	if((TLF35584_AbistSel0 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT0 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<4 ;										/* Test Fail */
	}

	if((TLF35584_AbistSel1 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT1 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<5 ;										/* Test Fail */
	}

	if((TLF35584_AbistSel2 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT2 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<6 ;										/* Test Fail */
	}

	if((TLF35584_Monsf1 & 0xFF)!= AbistSelSet0)
	{			/* MONSF1 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<7 ;										/* Test Fail */
	}

	if((TLF35584_Monsf2 & 0xFF)!= AbistSelSet1)
	{			/* MONSF2 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<8 ;										/* Test Fail */
	}

	if((TLF35584_Monsf3 & 0xFF)!= AbistSelSet2)
	{			/* MONSF3 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail1 |= 0x1<<9 ;										/* Test Fail */
	}

	if((TLF35584_Devstat & 0x07)!= 0x5)
	{					/* DEVSTAT (WAKE)*/
		TLF35584_AbistFail1 |= 0x1<<10 ;										/* Test Fail */
	}
	TLF35584_ReportAbistDiag(TLF35584_TestMode);							/* Report ABIST result */
	TLF35584_IfMonClear(); 									/* clear IF, MONSF */
	TLF35584_AbistVarClear();

	/********* Completed the comparator logic and the corresponding deglitching logic ************/
	/********* Comparator only : INTOV is only available test comp. only   *****************/

	TLF35584_TestMode = SSSP_COMP_TEST;
	TLF35584_Communication(READ,DEVSTAT,0x0); 				 /* 1. DEVSTAT : if DEVSTAT is normal mode, go to PMICM_NORMAL */
	if(((SpiRxMsg >> 1) & 0x7) != PMICM_NORMAL)
	{

		PmicM_Tlf35584_Go_To_State(PMICM_NORMAL);
	}
	AbistSelSet0 = 0x0;
	AbistSelSet1 = 0x0;
	AbistSelSet2 = 0x8;

	TLF35584_Communication(WRITE,ABIST_SELECT0,AbistSelSet0 ); 		/* WRITE ABIST_SELECT0-2 : INTOV */
	TLF35584_Communication(WRITE,ABIST_SELECT1,AbistSelSet1 );
	TLF35584_Communication(WRITE,ABIST_SELECT2,AbistSelSet2 );
	TLF35584_Communication(WRITE,ABIST_CTRL0,0x5); 					/* SINGLE COMPAROR, COMPARATOR ONLY, START		 */

	__Delay_us(100);  /* wait for  100us  */


	TLF35584_ReadDiagnosisRegister();						/* 5. read Diag. Registers  */


	if((TLF35584_If & 0x48) != 0x40)
	{						/* IF.ABIST, IF.MON (1b)*/
		TLF35584_AbistFail1= 0x1<<11 ;						/* Test Fail */
	}

	if((TLF35584_Sysfail & 0x4)!= 0x0)
	{						/* SYSFAIL.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<12 ;						/* Test Fail */
	}

	if((TLF35584_Initerr & 0x4)!= 0x0)
	{						/* INITERR.VMONF (1b)*/
		TLF35584_AbistFail1 |= 0x1<<13 ;						/* Test Fail */
	}

	if((TLF35584_AbistCtrl0 & 0xF1)!= 0x50)
	{				/* ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)*/
		TLF35584_AbistFail1 |= 0x1<<14 ;						/* Test Fail */
	}
	if((TLF35584_AbistSel0 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT0 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<15 ;						/* Test Fail */
	}

	if((TLF35584_AbistSel1 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT1 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<16 ;						/* Test Fail */
	}

	if((TLF35584_AbistSel2 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT2 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<17 ;						/* Test Fail */
	}

	if((TLF35584_Monsf1 & 0xFF)!= 0x0)
	{							/* MONSF1 (0b)*/
		TLF35584_AbistFail1 |= 0x1<<18 ;						/* Test Fail */
	}
	if((TLF35584_Monsf2 & 0xFF)!= 0x0)
	{							/* MONSF2  (0b)*/
		TLF35584_AbistFail1 |= 0x1<<19 ;						/* Test Fail */
	}
	if((TLF35584_Monsf3 & 0xFF)!= 0x0)
	{							/* MONSF3  (0b)*/
		TLF35584_AbistFail1 |= 0x1<<20 ;						/* Test Fail */
	}

	if((TLF35584_Devstat & 0x07)!= PMICM_NORMAL)
	{					/* DEVSTAT (WAKE)*/
		TLF35584_AbistFail1 |= 0x1<<21;							/* Test Fail */
	}
	TLF35584_ReportAbistDiag(TLF35584_TestMode);							/* Report ABIST result */
	TLF35584_IfMonClear(); 									/* clear IF, MONSF */
	TLF35584_AbistVarClear();

	AbistSelSet0 =0 ;
	AbistSelSet1 =0;
	AbistSelSet2 =0;

}


//************************************************************************************************************
// @Function	 	void TLF35584_ClearWakeupStatus(void)
// @Description   	For clearing wakeup status of TLF35584
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************

void TLF35584_ABIST_GenIt(void)
{

	/* Testing the generation of an interrupt event  */

	uint8 AbistSelSet0 =0x80;
	uint8 AbistSelSet1 =0x0;
	uint8 AbistSelSet2 =0x0;

	TLF35584_TestMode = INTGEN_TEST;

	//INIT or WAKE recommended, Go

	/* Send READ or WRITE command to TLF35584 */
	TLF35584_Communication(READ,DEVSTAT,0x0); /*read DEVSTAT  *//* 1. DEVSTAT : if DEVSTAT is normal mode, go to NORMAL */
	if(((SpiRxMsg >> 1) & 0x7) != PMICM_NORMAL){

		PmicM_Tlf35584_Go_To_State(PMICM_NORMAL);	/* go to NORMAL  */
	}

	TLF35584_Communication(WRITE,ABIST_SELECT0,AbistSelSet0 ); /* 0x80 QT2  , Select generation interrupt related comparator  */
	TLF35584_Communication(WRITE,ABIST_SELECT1,AbistSelSet1 );
	TLF35584_Communication(WRITE,ABIST_SELECT2,AbistSelSet2 );

	TLF35584_Communication(WRITE,ABIST_CTRL0,0xF); /*  interrupt related comparators shall be tested interr, single comparater, on the full path and start ABIST */

	__Delay_us(200);  /* wait for  200us  */


	TLF35584_ReadDiagnosisRegister();						/* 5. read Diag. Registers  */


	if((TLF35584_If & 0x48) != 0x08)
	{						/* IF.ABIST(0b), IF.MON (1b)*/
		TLF35584_AbistFail2 |= 0x1<<0;						/* Test Fail */
	}

	if((TLF35584_Sysfail & 0x4)!= 0x0)
	{						/* SYSFAIL.VMONF (0b)*/
		TLF35584_AbistFail2 |= 0x1<<1;						/* Test Fail */
	}

	if((TLF35584_Initerr & 0x4)!= 0x0)
	{						/* INITERR.VMONF (0b)*/
		TLF35584_AbistFail2 |= 0x1<<2;						/* Test Fail */
	}

	if((TLF35584_AbistCtrl0 & 0xF1)!= 0x50)
	{				/* ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)*/
		TLF35584_AbistFail2 |= 0x1<<3;						/* Test Fail */
	}

	if((TLF35584_AbistSel0 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT0 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<4;						/* Test Fail */
	}

	if((TLF35584_AbistSel1 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT1 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<5;						/* Test Fail */
	}

	if((TLF35584_AbistSel2 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT2 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<6;						/* Test Fail */
	}


	if((TLF35584_Monsf1 & 0xFF)!= AbistSelSet0)
	{			/* MONSF1 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<7;						/* Test Fail */
	}

	if((TLF35584_Monsf2 & 0xFF)!= AbistSelSet1)
	{			/* MONSF2 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<8;						/* Test Fail */
	}

	if((TLF35584_Monsf3 & 0xFF)!= AbistSelSet2)
	{			/* MONSF3 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<9;						/* Test Fail */
	}

	if((TLF35584_Devstat & 0x07)!= PMICM_NORMAL)
	{					/* DEVSTAT (NORMAL)*/
		TLF35584_AbistFail2 |= 0x1<<10;						/* Test Fail */
	}


	TLF35584_ReportAbistDiag(TLF35584_TestMode);							/* Report ABIST result */
	TLF35584_IfMonClear(); 									/* clear IF, MONSF */
	TLF35584_AbistVarClear();



	/************** Testing the comparator logic and the corresponding deglitching logic ****************/
	/* Interrupt(INT)  related 	*/
	TLF35584_TestMode = INTGEN_CND_TEST;

	AbistSelSet0 =0xD0 ;
	AbistSelSet1 =0xF1;
	AbistSelSet2 =0x30;

	TLF35584_Communication(WRITE,ABIST_SELECT0,AbistSelSet0 ); 	/* WRITE ABIST_SELECT0-2 TRK2OV TRK1OV COMOV */
	TLF35584_Communication(WRITE,ABIST_SELECT1,AbistSelSet1 );	/* TRK2UV TRK1UV VREFUV COMUV PREGUV */
	TLF35584_Communication(WRITE,ABIST_SELECT2,AbistSelSet2 );	/* BG12OV BG12UV */

	TLF35584_Communication(WRITE,ABIST_CTRL0,0xB);				/*  interrupt related comparators shall be tested, PREDEFINED SEQ. on the full path and start ABIST */

	__Delay_us(1000);  /* wait for  1ms  */


	TLF35584_ReadDiagnosisRegister();						/* 5. read Diag. Registers  */


	if((TLF35584_If & 0x48) != 0x48)
	{						/* IF.ABIST(0b), IF.MON (1b)*/
		TLF35584_AbistFail2 |= 0x1<<11;						/* Test Fail */
	}
	if((TLF35584_Sysfail & 0x4)!= 0x0)
	{						/* SYSFAIL.VMONF (0b)*/
		TLF35584_AbistFail2 |= 0x1<<12;						/* Test Fail */
	}

	if((TLF35584_Initerr & 0x4)!= 0x0)
	{						/* INITERR.VMONF (0b)*/
		TLF35584_AbistFail2 |= 0x1<<13;						/* Test Fail */
	}

	if((TLF35584_AbistCtrl0 & 0xF1)!= 0x50)
	{				/* ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)*/
		TLF35584_AbistFail2 |= 0x1<<14;						/* Test Fail */
	}

	if((TLF35584_AbistSel0 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT0 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<15;						/* Test Fail */
	}

	if((TLF35584_AbistSel1 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT1 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<16;						/* Test Fail */
	}

	if((TLF35584_AbistSel2 & 0xFF)!= 0x0)
	{					/* ABIST_SELECT2 (0b)*/
		TLF35584_AbistFail2 |= 0x1<<17;						/* Test Fail */
	}

	if((TLF35584_Monsf1 & 0xFF)!= AbistSelSet0)
	{			/* MONSF1 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<18;						/* Test Fail */
	}

	if((TLF35584_Monsf2 & 0xFF)!= AbistSelSet1)
	{			/* MONSF2 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<19;						/* Test Fail */
	}

	if((TLF35584_Monsf3 & 0xFF)!= AbistSelSet2)
	{			/* MONSF3 (same as prev. ABIST_SELECT configuration)*/
		TLF35584_AbistFail2 |= 0x1<<20;						/* Test Fail */
	}

	if((TLF35584_Devstat & 0x07)!= PMICM_NORMAL)
	{					/* DEVSTAT (NORMAL)*/
		TLF35584_AbistFail2 |= 0x1<<21;						/* Test Fail */
	}

	TLF35584_ReportAbistDiag(TLF35584_TestMode);							/* Report ABIST result */
	TLF35584_IfMonClear(); 									/* clear IF, MONSF */
	TLF35584_AbistVarClear();

	AbistSelSet0 =0 ;
	AbistSelSet1 =0;
	AbistSelSet2 =0;

}


//****************************************************************************
// Safety function for TLF35584
//****************************************************************************
//************************************************************************************************************
// @Function	 	void TLF35584_IfMonClear(void)
// @Description   	None
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************
void TLF35584_IfMonClear(void){

	TLF35584_RegisterClear(IF);
	TLF35584_RegisterClear(MONSF0);
	TLF35584_RegisterClear(MONSF1);
	TLF35584_RegisterClear(MONSF2);
	TLF35584_RegisterClear(MONSF3);
	TLF35584_RegisterClear(SYSFAIL);
	TLF35584_RegisterClear(INITERR);
};

//************************************************************************************************************
// @Function	 	void TLF35584_RegisterClear(void)
// @Description   	None
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************
void TLF35584_RegisterClear(uint8 address)
{

	/* Send READ or WRITE command to TLF35584 */
	TLF35584_Communication(READ,address,0x0);

	/* Send READ or WRITE command to TLF35584 */
	TLF35584_Communication(WRITE,address,(((SpiRxMsg >> 1)) & 0xFF));

} /*End of TLF35584_RegisterClear()*/

//************************************************************************************************************
// @Function	 	void TLF35584_AbistVarClear(void)
// @Description   	None
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************

void TLF35584_AbistVarClear(void)
{
	TLF35584_Sysfail =0;
	TLF35584_Initerr =0;
	TLF35584_If      =0;
	TLF35584_Syssf   =0;
	TLF35584_Wksf    =0;
	TLF35584_Spisf   =0;
	TLF35584_Monsf0  =0;
	TLF35584_Monsf1  =0;
	TLF35584_Monsf2  =0;
	TLF35584_Monsf3  =0;
	TLF35584_Otfail  =0;
	TLF35584_Otwrnsf =0;
	TLF35584_Vmonstat=0;
	TLF35584_Devstat =0;
	TLF35584_AbistCtrl0 =0;
	TLF35584_AbistSel0 =0;
	TLF35584_AbistSel1 =0;
	TLF35584_AbistSel2 =0;

} /*End of TLF35584_AbistVarClear()*/

//************************************************************************************************************
// @Function	 	void TLF35584_AbistVarClear(void)
// @Description   	None
// @Return Value	None
// @Parameters    	None
//************************************************************************************************************

void TLF35584_ReportAbistDiag(uint8 TestMode)
{
	if(TLF35584_AbistFail1 != 0x0 || TLF35584_AbistFail2 != 0x0)
	{
		TLF35584_AbistResult |= (ABIST_FAIL<<TestMode);
		TLF35584_AbistResult |= (ABIST_FAIL<<ABIST_TOTAL_RESULT);
	}
	TLF35584_AbistDiag0 |= TLF35584_AbistSel0;
	TLF35584_AbistDiag1 |= TLF35584_AbistSel1;
	TLF35584_AbistDiag2 |= TLF35584_AbistSel2;


} /*End of TLF35584_ReportAbistDiag()*/

/*******************************************************************************
** Function Name    : TFL35584_GetSmReport
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
uint8 *TFL35584_GetSmReport(void)
{
    /*
        0x1<<0 : IF.ABIST, IF.MON (1b)
        0x1<<1 : SYSFAIL.VMONF (1b)
        0x1<<2 : INITERR.VMONF (1b)
        0x1<<3 : ABIST_CTRL0.START(0b) /ABIST_CTRL0.STATUS (0101b)
        0x1<<4 : ABIST_SELECT0 (0b)
        0x1<<5 : ABIST_SELECT1 (0b)
        0x1<<6 : ABIST_SELECT2 (0b)
        0x1<<7 : MONSF1 (same as prev. ABIST_SELECT configuration)
    */

    l_tSmDiagReport.m_bIfAbistIfMon = ((TLF35584_AbistResult & 0x01) >> 0);
    l_tSmDiagReport.m_bSysFailVMonf = ((TLF35584_AbistResult & 0x02) >> 1);
    l_tSmDiagReport.m_bInitErrVMonf = ((TLF35584_AbistResult & 0x04) >> 2);
    l_tSmDiagReport.m_bAbistCtrl0Start = ((TLF35584_AbistResult & 0x08) >> 3);
    l_tSmDiagReport.m_bAbistSelect0 = ((TLF35584_AbistResult & 0x10) >> 4);
    l_tSmDiagReport.m_bAbistSelect1 = ((TLF35584_AbistResult & 0x20) >> 5);
    l_tSmDiagReport.m_bAbistSelect2 = ((TLF35584_AbistResult & 0x40) >> 6);
    l_tSmDiagReport.m_bMonSf = ((TLF35584_AbistResult & 0x80) >> 7);

    l_tSmDiagReport.m_nMonsf0 = TLF35584_Monsf0;
    l_tSmDiagReport.m_nMonsf1 = TLF35584_Monsf1;
    l_tSmDiagReport.m_nMonsf2 = TLF35584_Monsf2;
    l_tSmDiagReport.m_nMonsf3 = TLF35584_Monsf3;
    l_tSmDiagReport.m_nVmonstat = ((TLF35584_Vmonstat >> 2) & 0x3F); // 0xFC >> 2 = 0x3F
    l_tSmDiagReport.m_nDevstat = TLF35584_Devstat; // 0xFA (Device status 2:0 Normal)
    l_tSmDiagReport.m_nComplexDiag = (TLF35584_Monsf0) ? (1 << 0) : (0 << 0);
    l_tSmDiagReport.m_nComplexDiag |= (TLF35584_Monsf1) ? (1 << 1) : (0 << 1);
    l_tSmDiagReport.m_nComplexDiag |= (TLF35584_Monsf2) ? (1 << 2) : (0 << 2);
    l_tSmDiagReport.m_nComplexDiag |= (TLF35584_Monsf3) ? (1 << 3) : (0 << 3);

    return (uint8 *)&l_tSmDiagReport;
}

#if 1 // FREQ.SPREAD CONTROL
/*******************************************************************************
** Function Name    : TLF35584_SetBckFreSpread
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void TLF35584_SetBckFreSpread(uint8 nFRE_SP_THR)
{
    static uint8 tempFRE_SP_THR = 0x0;
    /* Spread specturm - reduce noise
        Select the percentage of frequency spread(+/-). 
        The mean frequency is reduced by the percentage as well keeping the maximum frequency at the nominal frequency selected by FRE.
        FRE_SP_THR : 0x00 No spread, 0x2B 1%, 0x55 2%, 0x80 3%, 0xAA 4%, 0xD5 5%, 0xFF 6% 0x00 Reset
    */
    if(tempFRE_SP_THR == nFRE_SP_THR)
    {
        return;
    }

    tempFRE_SP_THR = nFRE_SP_THR;
    TLF35584_Communication(WRITE, BCK_FRE_SPREAD, nFRE_SP_THR);
    TLF35584_Communication(WRITE, BCK_MAIN_CTRL, 0x40);
    TLF35584_Communication(READ, BCK_MAIN_CTRL, 0x00);
    while(1)
    {
        if(((SpiRxMsg >> 1) & 0x7) == 0)
        {
            break;
        }
    }
    TLF35584_Communication(WRITE, BCK_MAIN_CTRL, 0x00);

} /*End of TLF35584_SetBckFreSpread()*/
#endif

/*******************************************************************************
**                             Template                                      **/
/*******************************************************************************
** Traceability      : Unit design requirement ID
** Syntax           : Std_ReturnType ModuleName_TestFunction                    
**                    (                                                       
**                      uint8 Mode,                                  
**                      uint8* DataBufferPtr                     
**                    )                                                                                                                         
**                                      
** Service ID       : 0x01 (Only for global variable)                                                   
**                                                                            
** Sync/Async       : Synchronous                                             
**                                                                            
** Reentrancy       : reentrant                                               
**                                                                            
** Parameters(in)   : Description of in parameter                       
**                                                                            
** Parameters (out) : Description of out parameter                                                         
**                                                                            
** Return value     : E_OK/E_NOT_OK                                           
**                                                                            
** Description      : This function:                                          
**   - Perform service xxx                                            
**                                                           
**                                                                            
*******************************************************************************/
