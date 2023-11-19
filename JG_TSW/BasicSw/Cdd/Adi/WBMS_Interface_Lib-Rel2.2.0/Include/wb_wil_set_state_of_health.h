/******************************************************************************
 * @file    wb_wil_set_state_of_health.h
 *
 * @brief   Set the State of health on a node
 *
 * Copyright (c) 2022 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc. and its licensors.
 *****************************************************************************/

#ifndef WB_WIL_SET_STATE_OF_HEALTH_H
#define WB_WIL_SET_STATE_OF_HEALTH_H

#include "adi_wil_types.h"
#include "wbms_cmd_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Public functions *
 *****************************************************************************/

adi_wil_err_t wb_wil_SetStateOfHealthAPI (adi_wil_pack_internals_t * const pInternals,
                                          uint64_t iDeviceId,
                                          uint8_t iPercentage);

void wb_wil_HandleSetStateOfHealthResponse (adi_wil_pack_internals_t * const pInternals,
                                            uint64_t iDeviceId,
                                            wbms_cmd_resp_generic_t const * const pResponse);

#ifdef __cplusplus
}
#endif
#endif  // WB_WIL_SET_STATE_OF_HEALTH_H
