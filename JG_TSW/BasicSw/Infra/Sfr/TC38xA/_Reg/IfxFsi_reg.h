/**
 * \file IfxFsi_reg.h
 * \brief
 * \copyright Copyright (c) 2020 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC38XA_UM_V1.5.0.R0
 * Specification: TC3xx User Manual V1.5.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg Fsi address
 * \ingroup IfxSfr_Fsi_Registers
 * 
 * \defgroup IfxSfr_Fsi_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 * \defgroup IfxSfr_Fsi_Registers_Cfg_Fsi 2-FSI
 * \ingroup IfxSfr_Fsi_Registers_Cfg
 *
 *
 */
#ifndef IFXFSI_REG_H
#define IFXFSI_REG_H 1
/******************************************************************************/
#include "IfxFsi_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Fsi_Registers_Cfg_BaseAddress
 * \{  */

/** \brief FSI object */
#define MODULE_FSI /*lint --e(923, 9078)*/ ((*(Ifx_FSI*)0xF8030000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Fsi_Registers_Cfg_Fsi
 * \{  */
/** \brief 4, Communication Register 1 */
#define FSI_COMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_1*)0xF8030004u)

/** \brief 5, Communication Register 2 */
#define FSI_COMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_COMM_2*)0xF8030005u)

/** \brief 6, HSM Communication Register 1 */
#define FSI_HSMCOMM_1 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_1*)0xF8030006u)

/** \brief 7, HSM Communication Register 2 */
#define FSI_HSMCOMM_2 /*lint --e(923, 9078)*/ (*(volatile Ifx_FSI_HSMCOMM_2*)0xF8030007u)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXFSI_REG_H */
