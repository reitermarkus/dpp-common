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
 * packet structure and message type definitions
 * APP file (application processor)
 */


#ifndef __DPP_APP_MESSAGE_H__
#define __DPP_APP_MESSAGE_H__


/* 
 * S T R U C T S
 */

#pragma pack(1)    /* force alignment to 1 byte */


#define DPP_APP_HEALTH_LEN      22          /* bytes */
typedef struct {
  /* all values are from the last health period, unless otherwise stated */
  uint32_t          uptime;                 /* Uptime [seconds] */
  uint16_t          msg_cnt;                /* Number of received messages */
  uint16_t          core_vcc;               /* Core voltage [10^-3 V] */
  int16_t           core_temp;              /* Core temperature [10^-2 °C] */
  uint16_t          cpu_dc;                 /* CPU duty cycle [10^-2 %] */
  uint8_t           stack;                  /* Stack [watermark over the last period in %] */  
  uint8_t           nv_mem;                 /* Non-volatile memory usage [%] */
  uint16_t          supply_vcc;             /* Supply voltage [10^-3 V] */
  uint16_t          supply_current;         /* Supply [10^-5 A] */
  int16_t           temperature;            /* Temperature [10^-2 °C] */
  uint16_t          humidity;               /* Humidity [10^-2 %] */
} dpp_app_health_t;


#define DPP_IMU_LEN             12          /* bytes */
typedef struct {
  uint16_t          acc_x;                  /* Accelerometer X-axis raw data */
  uint16_t          acc_y;                  /* Accelerometer Y-axis raw data */
  uint16_t          acc_z;                  /* Accelerometer Z-axis raw data */
  uint16_t          mag_x;                  /* Magnetometer X-axis raw data */
  uint16_t          mag_y;                  /* Magnetometer Y-axis raw data */
  uint16_t          mag_z;                  /* Magnetometer Z-axis raw data */
} dpp_imu_t;


#define DPP_WGPS_STATUS_LEN     18          /* bytes */
typedef struct {
  int16_t           inc_x;                  /* Inclinometer X raw data */
  int16_t           inc_y;                  /* Inclinometer Y raw data */
  uint16_t          gnss_sv_queue;          /* Number of gnss_sv messages in queue */
  uint16_t          wgps_status_queue;      /* Number of wgps_status messages in queue */
  uint16_t          app_health_queue;       /* Number of app_health messages in queue */
  uint16_t          event_queue;            /* Number of events in queue */
  uint32_t          card_usage;             /* Card usage [kB] */
  uint16_t          status;                 /* Bit0: gps power state (on/off) */
} dpp_wgps_status_t;


#define DPP_GNSS_SV_LEN         42          /* bytes */
typedef struct {    
  uint8_t           rcvTow[8];              /* Receiver time of week (converted from IEEE-754 to integer) */
  uint16_t          week;                   /* GPS week number */
  int8_t            leapS;                  /* GPS leap seconds */
  uint8_t           numMeas;                /* Number of measurements */
  uint8_t           recStat;                /* Receiver tracking status bitfield */
  uint8_t           prMes[8];               /* Pseudo-range measurement (converted from IEEE-754 to integer) */
  uint8_t           cpMes[8];               /* Carrier-phase measurement (converted from IEEE-754 to integer) */
  uint8_t           doMes[4];               /* Doppler measurement (converted from IEEE-754 to integer) */
  uint8_t           gnssId;                 /* GNSS identifier */
  uint8_t           svId;                   /* Satellite identifier */
  uint8_t           cno;                    /* Carrier-to-noise density ratio [db-Hz] */
  uint16_t          locktime;               /* Carrier phase locktime counter [ms] */
  uint8_t           prStDev;                /* Estimated pseudo-range std. deviation */
  uint8_t           cpStDev;                /* Estimated carrier-phase std. deviation */
  uint8_t           doStDev;                /* Estimated doppler std. deviation */
  uint8_t           trkStat;                /* Tracking status bitfield */
} dpp_gnss_sv_t;


#define DPP_GEOPHONE_ACQ_LEN    64          /* bytes*/
typedef struct {
  uint64_t          start_time;             /* Timestamp of trigger */
  uint64_t          first_time;             /* Timestamp of first ADC sample */
  uint32_t          samples;                /* Total no. of samples */
  uint32_t          peak_pos_val;           /* Positive peak value (can be pos or neg!) of ADC */
  uint32_t          peak_pos_sample;        /* Positive peak location: sample no. of peak value of ADC */
  uint32_t          peak_neg_val;           /* Negative peak value (can be pos or neg!) of ADC */
  uint32_t          peak_neg_sample;        /* Negative peak location: sample no. of peak value of ADC */
  uint32_t          trg_count_pos;          /* Count of positive triggers */
  uint32_t          trg_count_neg;          /* Count of negative triggers */
  uint32_t          trg_last_pos_sample;    /* Last positive TRG location: sample no. of ADC */
  uint32_t          trg_last_neg_sample;    /* Last negative TRG location: sample no. of ADC */
  uint16_t          trg_gain;               /* Amplification gain value of TRG */
  uint16_t          trg_th_pos;             /* Positive TRG threshold value [mV] */
  uint16_t          trg_th_neg;             /* Negative TRG threshold value [mV] */
  uint8_t           trg_source;             /* Source of initial trigger. 0: external | 1: positive threshold, 2: negative threshold */
  uint8_t           adc_pga;                /* ADC PGA value. 0: PGA is off. */
  uint32_t          id;                     /* acquisition ID */
} dpp_geophone_acq_t;

#pragma pack()


#endif /* __DPP_APP_MESSAGE_H__ */
