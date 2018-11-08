/*
 * Copyright (c) 2017, Swiss Federal Institute of Technology (ETH Zurich).
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
 *          Akos Pasztor
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

/* Label ------------------- | #No. | Description ----------------------------*/

CMD_GEOPHONE_RESET,         /* 0x01 | Perform Reset */                  /* @param none */
CMD_GEOPHONE_SELFTEST,      /* 0x02 | Perform Self-Test */              /* @param none */
CMD_GEOPHONE_OPMODE,        /* 0x03 | Operation Mode */                 /* @param 0: normal, @see enum OpModes */
CMD_GEOPHONE_EXTTRG,        /* 0x04 | External Trigger */               /* @param none */
CMD_GEOPHONE_TRG_GAIN,      /* 0x05 | Trigger Amplification Gain */     /* @param 0: stage1, 1: stage2 */
CMD_GEOPHONE_TRG_TH_POS,    /* 0x06 | Trigger Positive Threshold */     /* @param voltage [1500-3000] mV */
CMD_GEOPHONE_TRG_TH_NEG,    /* 0x07 | Trigger Negative Threshold */     /* @param voltage [0-1500] mV */
CMD_GEOPHONE_POSTTRG,       /* 0x08 | ADC Post-trigger interval */      /* @param > 0 seconds */
CMD_GEOPHONE_TIMEOUT,       /* 0x09 | ADC Sampling Timeout */           /* @param > 0 seconds */
CMD_GEOPHONE_ADC_PGA,       /* 0x0A | ADC PGA Value */                  /* @param [0-128] */
CMD_GEOPHONE_ADC_FORMAT,    /* 0x0B | ADC Output Format */              /* @param 0: two's complement, 1: offset binary */
CMD_GEOPHONE_IMU_FREQ,      /* 0x0C | IMU Sampling Frequency */         /* @param [0-10] Hz */
CMD_GEOPHONE_REQ_ADCDATA,   /* 0x0D | Request ADC data (waveform) */    /* @param acquisition ID */


/* Label ------------------- | #No. | Description ----------------------------*/
