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
**          FILE  : PmicM_Tlf35584.h
** 
**       PROJECT  : RBMS_STANDLAONE_TC275                                             
**       
**        AUTHOR  : Hyun Kang
**                                                                    
**       VERSION  : V1.0
**                                                                                                                                                                                                                                    
**      PLATFORM  : Infineon Aurix 275T                                         
**                                                                       
**   DESCRIPTION  : Header of the CanIf_Cfg
**                                                                            
*******************************************************************************/


/*********************************************************************************************************************
**                                          Revision History                                                        **
**********************************************************************************************************************
 *  ------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author         Change Id     Description
 *  ------------------------------------------------------------------------------------------------------------------

 *	V1.0      2019-07-01  Hyun Kang      - 			   First Implementation


*********************************************************************************************************************/


#ifndef PMICM_TLF35584_H
#define PMICM_TLF35584_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Spi.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*  @TLF35584 Function Mode definitions   */

#define WRITE 					((uint8)0x1U)
#define READ  					((uint8)0x0U)

#define PMICM_INIT    			 	((uint8)0x01U)
#define PMICM_NORMAL    				((uint8)0x02U)
#define PMICM_SLEEP    				((uint8)0x03U)
#define PMICM_STANDBY  				((uint8)0x04U)
#define PMICM_WAKE     				((uint8)0x05U)

#define TLF35584_VMON_OK	   	((uint8)0x0U)
#define TLF35584_VMON_NG     	((uint8)0x01U)

/*****************************************************************************
 @TLF35584 Register definitions
*****************************************************************************/
#define DEVCFG0            ((uint8)0x00U)    /* Device configuration 0 */
#define DEVCFG1            ((uint8)0x01U)    /* Device configuration 1 */
#define DEVCFG2            ((uint8)0x02U)    /* Device configuration 2 */
#define PROTCFG            ((uint8)0x03U)    /* Protection register */
#define SYSPCFG0           ((uint8)0x04U)    /* System protected configuration 0 */
#define SYSPCFG1           ((uint8)0x05U)    /* System protected configuration 1 */
#define WDCFG0             ((uint8)0x06U)    /* Watchdog configuration 0 */
#define WDCFG1             ((uint8)0x07U)    /* Watchdog configuration 1 */
#define FWDCFG             ((uint8)0x08U)    /* Functional Watchdog configuration */
#define WWDCFG0            ((uint8)0x09U)    /* Window Watchdog configuration 0 */
#define WWDCFG1            ((uint8)0x0AU)    /* Window Watchdog configuration 1 */
#define GTM                ((uint8)0x3FU)    /* Global test mode */



/*   TLF35584_B   */
#define RSYSPCFG0           ((uint8)0x0BU)   /* System configuration 0 status */
#define RSYSPCFG1           ((uint8)0x0CU)   /* System configuration 1 status */
#define RWDCFG0             ((uint8)0x0DU)   /* Watchdog configuration 0 status */
#define RWDCFG1             ((uint8)0x0EU)   /* Watchdog configuration 1 status */
#define RFWDCFG             ((uint8)0x0FU)   /* Functional watchdog configuration status */
#define RWWDCFG0            ((uint8)0x10U)   /* Window watchdog configuration 0 status */
#define RWWDCFG1            ((uint8)0x11U)   /* Window watchdog configuration 1 status */
#define	WKTIMCFG0      		((uint8)0x12U)   /* Wake timer configuration 0 */
#define WKTIMCFG1           ((uint8)0x13U)   /* Wake timer configuration 1 */
#define WKTIMCFG2           ((uint8)0x14U)   /* Wake timer configuration 2 */

#define DEVCTRL             ((uint8)0x15U)   /* Device control */
#define DEVCTRLN            ((uint8)0x16U)   /* Device control inverted request */
#define WWDSCMD             ((uint8)0x17U)   /* Window watchdog service command */
#define FWDRSP              ((uint8)0x18U)   /* Functional watchdog response command */
#define FWDRSPSYNC          ((uint8)0x19U)   /* Functional watchdog response command with synchronization */
#define SYSFAIL             ((uint8)0x1AU)   /* Failure status flags */
#define INITERR             ((uint8)0x1BU)   /* Init error status flags */
#define IF                  ((uint8)0x1CU)   /* Interrupt flags */
#define SYSSF               ((uint8)0x1DU)   /* System status flags */
#define WKSF                ((uint8)0x1EU)   /* Wake up status flags */
#define SPISF               ((uint8)0x1FU)   /* SPI status flags */
#define MONSF0              ((uint8)0x20U)   /* Monitor status flags 0 */
#define MONSF1              ((uint8)0x21U)   /* Monitor status flags 1 */
#define MONSF2              ((uint8)0x22U)   /* Monitor status flags 2 */
#define MONSF3              ((uint8)0x23U)   /* Monitor status flags 3 */
#define OTFAIL              ((uint8)0x24U)   /* Over temperature failure status flags */
#define OTWRNSF             ((uint8)0x25U)   /* Over temperature warning status flags */
#define VMONSTAT            ((uint8)0x26U)   /* Voltage monitor status */
#define DEVSTAT             ((uint8)0x27U)   /* Device status */
#define PROTSTAT            ((uint8)0x28U)   /* Protection status */
#define WWDSTAT             ((uint8)0x29U)   /* Window watchdog status */
#define FWDSTAT0            ((uint8)0x2AU)   /* Functional watchdog status 0 */
#define FWDSTAT1            ((uint8)0x2BU)   /* Functional watchdog status 1 */

#define ABIST_CTRL0         ((uint8)0x2CU)   /* ABIST control0 */
#define ABIST_CTRL1         ((uint8)0x2DU)   /* ABIST control1 */
#define ABIST_SELECT0       ((uint8)0x2EU)   /* ABIST select 0 */
#define ABIST_SELECT1       ((uint8)0x2FU)   /* ABIST select 1 */
#define ABIST_SELECT2       ((uint8)0x30U)   /* ABIST select 2 */

                     				         /* Buck trim */
#define BCK_FREQ_CHANGE     ((uint8)0x31U)   /* Buck switching frequency change */
#define BCK_FRE_SPREAD      ((uint8)0x32U)   /* Buck Frequency spread */
#define BCK_MAIN_CTRL       ((uint8)0x33U)   /* Buck main control */
/*   TLF35584_B End    */



/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

typedef enum
{
	DEFAULT_VAL   				= 0,
	BY_SPI_COMMND 				= 1,
	BY_WAKEUP_TIMER				= 2,
	BY_LDO_UC_CURRENT_MONITOR	= 3,
	BY_ENA_SIG					= 4,
	BY_WAK_SIG					= 5
}tWakeupSt;



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern uint8 PmicM_Tlf35584_u8stUMon;  /* For RBMS, KH */
extern uint8 TLF35584_AbistResult;

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

extern void PmicM_Tlf35584_Go_To_State(uint8 State);
extern void PmicM_Tlf35584_Init(void);
extern void PmicM_Tlf35584_ClearWakeupStatus(void);
extern void PmicM_Tlf35584_ReadWakeupStatus(tWakeupSt *WakSt);
extern void PmicM_Tlf35584_MainFunction_100ms(void);
extern void PmicM_Tlf35584_WakeupTimerEnable(uint8 EnableSt);
extern uint8 PmicM_Tlf35584_Get_CurrState(void);

extern void TLF35584_ABIST(void);
extern void TLF35584_ABIST_SafetyPath(void);
extern void TLF35584_ABIST_GenIt(void);
//extern void TLF35584_ABIST_ComparatorDeglitching(void);

extern void TLF35584_IfMonClear(void);
extern void TLF35584_RegisterClear(uint8 address);
extern void TLF35584_AbistVarClear(void);
extern void TLF35584_ReportAbistDiag(uint8 TestMode);
extern uint8 *TFL35584_GetSmReport(void);

#if 1 // FREQ.SPREAD CONTROL
extern void TLF35584_SetBckFreSpread(uint8 nFRE_SP_THR);
#endif

#endif /* PMICM_TLF35584_H_ */

