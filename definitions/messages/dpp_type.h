/*
 * Copyright (c) 2017 - 2021, ETH Zurich, Computer Engineering Group (TEC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * dpp types
 * MASTER file
 */

#ifndef __DPP_TYPE_H__
#define __DPP_TYPE_H__


/* dpp command types */
typedef enum {
  /* general events */
  DPP_COMMAND_INVALID    = 0,
  DPP_COMMAND_RESET      = 1,

  /* application specific commands */
  DPP_COMMAND_CC430      = ((uint16_t)DPP_COMPONENT_ID_CC430 << 8),
#include "types/dpp_cc430_command_type.h"

  DPP_COMMAND_WGPS2      = ((uint16_t)DPP_COMPONENT_ID_WGPS2 << 8),
#include "types/dpp_wgps_command_type.h"

  DPP_COMMAND_GEOPHONE   = ((uint16_t)DPP_COMPONENT_ID_GEOPHONE << 8),
#include "types/dpp_geophone_command_type.h"

  DPP_COMMAND_DEVBOARD   = ((uint16_t)DPP_COMPONENT_ID_DEVBOARD << 8),
#include "types/dpp_devboard_command_type.h"

  DPP_COMMAND_SX1262     = ((uint16_t)DPP_COMPONENT_ID_SX1262 << 8),
#include "types/dpp_sx1262_command_type.h"

  DPP_COMMAND_GEO3X      = ((uint16_t)DPP_COMPONENT_ID_GEO3X << 8),
//#include "types/dpp_geophone3x_command_type.h"

  DPP_COMMAND_GEOMINI    = ((uint16_t)DPP_COMPONENT_ID_GEOMINI << 8),
//#include "types/dpp_geomini_command_type.h"

  DPP_COMMAND_BASEBOARD  = ((uint16_t)DPP_COMPONENT_ID_BASEBOARD << 8),
#include "types/dpp_baseboard_command_type.h"

  DPP_COMMAND_LASTID = 0xffff
} __attribute__((packed)) dpp_command_type_t;
ASSERT_SIZE(dpp_command_type_t, 2);


/* dpp event types */
typedef enum {
  /* general events (0 - 255) */
  DPP_EVENT_INVALID      = 0,

  /* application specific events */
  DPP_EVENT_CC430        = ((uint16_t)DPP_COMPONENT_ID_CC430 << 8),
#include "types/dpp_cc430_event_type.h"

  DPP_EVENT_WGPS2        = ((uint16_t)DPP_COMPONENT_ID_WGPS2 << 8),
#include "types/dpp_wgps_event_type.h"

  DPP_EVENT_GEOPHONE     = ((uint16_t)DPP_COMPONENT_ID_GEOPHONE << 8),
#include "types/dpp_geophone_event_type.h"

  DPP_EVENT_DEVBOARD     = ((uint16_t)DPP_COMPONENT_ID_DEVBOARD << 8),
#include "types/dpp_devboard_event_type.h"

  DPP_EVENT_SX1262       = ((uint16_t)DPP_COMPONENT_ID_SX1262 << 8),
#include "types/dpp_sx1262_event_type.h"

  DPP_EVENT_GEO3X        = ((uint16_t)DPP_COMPONENT_ID_GEO3X << 8),
#include "types/dpp_geophone3x_event_type.h"

  DPP_EVENT_GEOMINI      = ((uint16_t)DPP_COMPONENT_ID_GEOMINI << 8),
//#include "types/dpp_geomini_event_type.h"

  DPP_EVENT_BASEBOARD    = ((uint16_t)DPP_COMPONENT_ID_BASEBOARD << 8),
#include "types/dpp_baseboard_event_type.h"

  DPP_EVENT_LASTID       = 0xffff
} __attribute__((packed)) dpp_event_type_t;
ASSERT_SIZE(dpp_event_type_t, 2);


/* dpp fw packet types */
typedef enum {
  DPP_FW_TYPE_INVALID = (uint8_t)0,
  DPP_FW_TYPE_DATA,     /* FW data block ('data') */
  DPP_FW_TYPE_CHECK,    /* request FW verification ('info') */
  DPP_FW_TYPE_READY,    /* response to a FW validation request (header only, no payload) */
  DPP_FW_TYPE_DATAREQ,  /* request missing FW data packets ('req') */
  DPP_FW_TYPE_UPDATE,   /* initiate the FW update (header only, no payload) */
} __attribute__((packed)) dpp_fw_type_t;
ASSERT_SIZE(dpp_fw_type_t, 1);

#endif /* __DPP_TYPE_H__ */
