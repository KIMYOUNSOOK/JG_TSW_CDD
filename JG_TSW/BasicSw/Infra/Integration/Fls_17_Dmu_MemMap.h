/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Fls_17_Dmu_MemMap.h                                                      **
**                                                                            **
**  VERSION   :                                              **
**                                                                            **
**  DATE      :                                                             **
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
**  SPECIFICATION(S) : Specification of FLS_17_DMU Driver,                      **
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
#if defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.Unspecified"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.Unspecified" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.Unspecified"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.Unspecified" "ClearedData.Cpu0.Unspecified" far-absolute RW
#pragma align_variables 4
#endif
#undef  FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.32bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.32bit" "ClearedData.Cpu0.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR

#elif defined FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.Cpu0.8bit"
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.Cpu0.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.Cpu0.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.8bit"  "ClearedData.Cpu0.8bit" far-absolute RW
#endif
#undef  FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR

#elif defined FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.Cpu0.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.Cpu0.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.Cpu0.32bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.32bit"  "ClearedData.Cpu0.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section fardata restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR

/******************* Config Data Sections *************************/
#elif defined FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu0.Unspecified"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu0.Unspecified" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu0.Unspecified"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu0.Unspecified" far-absolute R
#pragma align_variables 4
#endif
#undef  FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
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
#elif defined FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code "Code.Cpu0"
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Code.Cpu0" ax
#elif defined _GHS_C_TRICORE_
#pragma ghs section text  = ".Code.Cpu0"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CODE "Code.Cpu0" RX
#endif
#undef  FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR

#endif

#else  /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 
/************************EMPTY SECTIONS***************************************/
#if defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef  FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef  FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef  FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef  FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef  FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef  FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
#undef  FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
#undef  FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 

#if defined MEMMAP_ERROR
#error "Fls_17_Dmu_MemMap.h, wrong pragma command"
#endif
