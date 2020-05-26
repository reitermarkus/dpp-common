/*
 * Copyright (c) 2019, Swiss Federal Institute of Technology (ETH Zurich).
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
 *
 * Authors: Reto Da Forno
 *          Tonio Gsell
 *          Tobias Gatschet
 */

/*
 * command types specific to SX1262
 *
 *
 * typedef enum {
 *   ...
 *   DPP_COMMAND_[device_name]  = [start_id],
 *   [your_defines]
 *   ...
 * } dpp_command_type_t;
 *
 * add a comma after each define!
 */

/* Label -----------------------    | #No. | Description ----------------------------*/

/* Event-driven approach events */
CMD_SX1262_CONF_WKUP,              /* 0x01 | Change radio configurations for staggered wakeup */                       /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_SX1262_STAG_RX_MODE,           /* 0x02 | Change staggered wakeup mode */                                           /* @param: ALWAYS_RX = 0, LORA_CAD = 1, LORA_DUTY_CYCLE_CAD_STOPMODE = 2 */
CMD_SX1262_CONF_BS,                /* 0x03 | Change radio configurations for sending to base station*/                 /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_SX1262_CONF_ELECTION,          /* 0x04 | Change radio configurations for leader election and data aggregation */   /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_SX1262_ELECTION_MODUS,         /* 0x05 | Change the leader election modus */                                       /* @param: leader_election_modi_t */
CMD_SX1262_STOP_MODE,              /* 0x06 | Change to stop mode 2 for given duration */                               /* @param: Duration after which the node should wake up, in ms */
CMD_SX1262_CONF_EVENT_ADD,         /* 0x07 | Add new event configuration */                                            /* @param: TBD */
CMD_SX1262_CONF_EVENT_DEL,         /* 0x08 | Delete event configuration */                                             /* @param: TBD */

CMD_SX1262_RESERVED9,
CMD_SX1262_RESERVED10,
CMD_SX1262_RESERVED11,
CMD_SX1262_RESERVED12,
CMD_SX1262_RESERVED13,
CMD_SX1262_RESERVED14,
CMD_SX1262_RESERVED15,
CMD_SX1262_RESERVED16,
CMD_SX1262_RESERVED17,
CMD_SX1262_RESERVED18,

CMD_SX1262_RESET,                     /* 0x13 | perform a software reset */

/* Baseboard commands */
CMD_SX1262_BASEBOARD_ENABLE,          /* 0x14 | Schedule baseboard enable */           /* @param: enable time (32-bit timestamp), time flag (0 = absolute time as UNIX timestamp, 1 = relative time in seconds), wakeup command for baseboard (2 bytes)  */
CMD_SX1262_BASEBOARD_DISABLE,         /* 0x15 | Schedule baseboard disable */          /* @param: disable time (32-bit timestamp), time flag (0 = absolute time as UNIX timestamp, 1 = relative time in seconds) */
CMD_SX1262_BASEBOARD_ENABLE_PERIODIC, /* 0x16 | Schedule periodic baseboard enable */  /* @param: enable time hour [0..23] (1 byte), enable time minute [0..59] (1 byte), period in minutes (2 bytes, set to 0 to disable), wakeup command for baseboard (2 bytes)  */

/* Label -----------------------    | #No. | Description ----------------------------*/
