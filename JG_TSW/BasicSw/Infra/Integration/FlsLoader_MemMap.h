/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : FlsLoader_MemMap.h                                            **
**                                                                            **
**  VERSION   :  <to be filled>                                               **
**                                                                            **
**  DATE      : 25/11/2019                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY :                                                            **
**                                                                            **
**  DESCRIPTION  : This file contains the mapping of Memory Section           **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of FLSLOADER Driver,                      **
**   AUTOSAR Release <4.2.2>                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
#define MEMMAP_ERROR
#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))
/*DATA Section*/
/*To be used for all global or static variables.*/
/*Variable to be cleared at startup or reset is palced here - .bss*/
#if defined FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farbss "ClearedData.Cpu0.8bit"
  #elif defined _GNU_C_TRICORE_
    #pragma section  "ClearedData.Cpu0.8bit" aw
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section bss = ".ClearedData.Cpu0.8bit"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section DATA "InitData.Cpu0.8bit" "ClearedData.Cpu0.8bit" far-absolute RW
  #endif
    #undef  FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farbss restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR

#elif defined FLSLOADER_START_SEC_VAR_INIT_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farbss "InitData.Cpu0.8bit"
  #elif defined _GNU_C_TRICORE_
    #pragma section  "InitData.Cpu0.8bit" aw
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section bss = ".InitData.Cpu0.8bit"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section DATA "InitData.Cpu0.8bit" "" far-absolute RW
  #endif
    #undef  FLSLOADER_START_SEC_VAR_INIT_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_VAR_INIT_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farbss restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_VAR_INIT_QM_LOCAL_8
    #undef MEMMAP_ERROR


#elif defined FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #ifdef _TASKING_C_TRICORE_
    #pragma section farbss "ClearedData.Cpu0.32bit"
    #pragma align 4
  #elif defined _GNU_C_TRICORE_
    #pragma section  "ClearedData.Cpu0.32bit" aw 4
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section bss = ".ClearedData.Cpu0.32bit"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section DATA "InitData.Cpu0.32bit" "ClearedData.Cpu0.32bit" far-absolute RW
  #endif
    #undef  FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #ifdef _TASKING_C_TRICORE_
    #pragma align restore
    #pragma section farbss restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR

/***************** Static Global Constants Sections ************************/
#elif defined FLSLOADER_START_SEC_CONST_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farrom  "Const.Cpu0.8bit"
  #elif defined _GNU_C_TRICORE_
    #pragma section  "Const.Cpu0.8bit" a
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section rodata = ".Const.Cpu0.8bit"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CONST "Const.Cpu0.8bit" far-absolute R
  #endif
    #undef  FLSLOADER_START_SEC_CONST_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
  #ifdef _TASKING_C_TRICORE_
    #pragma section farrom restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
    #undef MEMMAP_ERROR

#elif defined FLSLOADER_START_SEC_CONST_QM_LOCAL_32
  #ifdef _TASKING_C_TRICORE_
    #pragma section farrom  "Const.Cpu0.32bit"
    #pragma align 4
  #elif defined _GNU_C_TRICORE_
    #pragma section  "Const.Cpu0.32bit" a 4
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section rodata = ".Const.Cpu0.32bit"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CONST "Const.Cpu0.32bit" far-absolute R
  #endif
    #undef  FLSLOADER_START_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
  #ifdef _TASKING_C_TRICORE_
    #pragma align restore
    #pragma section farrom restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR

/* Code Sections */
/*
To be used for mapping code to application block, boot block, external flash etc.
codePeriod is the typical period time value and unit of the ExecutableEntitys in this MemorySection.
The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
*/
#elif defined FLSLOADER_START_SEC_CODE_QM_LOCAL
  #ifdef _TASKING_C_TRICORE_
    #pragma section code "Code.Cpu0"
  #elif defined _GNU_C_TRICORE_
    #pragma section "Code.Cpu0" ax
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section text  = ".Code.Cpu0"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CODE "Code.Cpu0" RX
  #endif
    #undef  FLSLOADER_START_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CODE_QM_LOCAL
  #ifdef _TASKING_C_TRICORE_
    #pragma section code restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR

#elif defined FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
#if (defined (RAMRUN) && (RAMRUN == 4)) || (APP_SW == DEMO_APP)
  #ifdef _TASKING_C_TRICORE_
    #pragma section code "FLSLOADERRAMCODE"
  #elif defined _GNU_C_TRICORE_
    #pragma section ".FLSLOADERRAMCODE" ax
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section text  = ".FLSLOADERRAMCODE"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CODE "FLSLOADERRAMCODE" RX
  #endif
 #else
  #ifdef _TASKING_C_TRICORE_
    #pragma section code "Code.Cpu0"
  #elif defined _GNU_C_TRICORE_
    #pragma section "Code.Cpu0" ax
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section text  = ".Code.Cpu0"
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CODE "Code.Cpu0" RX
  #endif
  #endif
    #undef  FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
  #ifdef _TASKING_C_TRICORE_
    #pragma section code restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #endif
    #undef  FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MEMMAP_ERROR

#elif defined FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #ifdef _TASKING_C_TRICORE_
    #pragma section code "Code.Cpu0"
  #elif defined _GNU_C_TRICORE_
    #pragma section "Code.Cpu0" ax
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section CODE "Code.Cpu0" RX
   #elif defined _GHS_C_TRICORE_
     #pragma ghs section text  = ".Code.Cpu0"
  #endif
    #undef  FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
  #ifdef _TASKING_C_TRICORE_
    #pragma section code restore
  #elif defined _GNU_C_TRICORE_
    #pragma section
  #elif defined _DIABDATA_C_TRICORE_
    #pragma section 
  #elif defined _GHS_C_TRICORE_
       #pragma ghs section
  #endif
	#undef  FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
	#undef MEMMAP_ERROR
#endif

#else  /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 
/************************EMPTY SECTIONS***************************************/
#if defined FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef  FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef  FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef  FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef  FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_CONST_QM_LOCAL_8
    #undef  FLSLOADER_START_SEC_CONST_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
    #undef  FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_CONST_QM_LOCAL_32
    #undef  FLSLOADER_START_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
    #undef  FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_CODE_QM_LOCAL
    #undef  FLSLOADER_START_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_CODE_QM_LOCAL
    #undef  FLSLOADER_STOP_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef  FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef  FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MEMMAP_ERROR
#elif defined FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
   #undef  FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
   #undef MEMMAP_ERROR
#elif defined FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
   #undef  FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
   #undef MEMMAP_ERROR 
#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 

#if defined MEMMAP_ERROR
#error "FlsLoader_MemMap.h, wrong pragma command"
#endif
