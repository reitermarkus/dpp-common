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
 * command types specific to APP (application processor)
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
CMD_EVENT_SX1262_STAG_CONFS,            /* 0x01 | Change radio configurations for staggered wakeup */                       /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_EVENT_SX1262_STAG_RX_MODE,          /* 0x02 | Change staggerd wakeup mode */                                            /* @param: ALWAYS_RX = 0, LORA_CAD = 1, LORA_DUTY_CYCLE_CAD_STOPMODE = 2 */
CMD_EVENT_SX1262_BS_CONFS,              /* 0x03 | Change radio configurations for sending to base station*/                 /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_EVENT_SX1262_LEADER_CONFS,          /* 0x04 | Change radio configurations for leader election and data aggregation */   /* @param: arg32[0]: LoRa/FSK (1 bit), Spreading Factor (15 bits), Bandwidth (16 bits); arg32[1]: Code Rate (8 bits), Tx Power (8 bits), Preamble (16 bits) */
CMD_EVENT_SX1262_STOP_MODE,             /* 0x05 | Change to stop mode 2 for given duration */                               /* @param: Duration after which the node should wake up, in ms */
CMD_EVENT_SX1262_ADD_EVENT_CONF,        /* 0x06 | Add new event configuration */                                            /* @param: TBD */
CMD_EVENT_SX1262_DEL_EVENT_CONF,        /* 0x07 | Delete event configuration */                                             /* @param: TBD */
CMD_EVENT_SX1262_CHANGE_LEADER_ELECTION /* 0x08 | Change the leader election modi */                                        /* @param: leader_election_modi_t */
/* Label -----------------------    | #No. | Description ----------------------------*/