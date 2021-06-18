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

#include <stdint.h>

/*---------------------------------------------------------------------------*/
/* convert an ASCII string of up to 8 hex characters to an unsigned int */
uint32_t hexstr_to_uint32(const char* str)
{
  if (!str) {
    return 0;
  }
  uint32_t      res = 0;
  uint_fast8_t  cnt = 8;
  /* skip leading '0x' if present */
  if (*str == '0' && *(str + 1) == 'x') {
    str += 2;
  }
  while (*str && cnt) {
    if (*str >= 'A' && *str <= 'F') {
      res += *str - 'A' + 10;
    } else if (*str >= 'a' && *str <= 'f') {
      res += *str - 'a' + 10;
    } else if (*str >= '1' && *str <= '9') {
      res += *str - '0';
    } else {
      /* invalid character -> abort */
      break;
    }
    res <<= 4;    /* shift to the left by 4 bits */
    str++;
    cnt--;
  }
  return res;
}
/*---------------------------------------------------------------------------*/
uint32_t uint16_to_str(uint16_t val, char* out_buffer)
{
  if (!out_buffer) {
    return 0;
  }
  uint32_t div = 10000;
  uint32_t num = 0;
  while (div) {
    uint32_t digit = val / div;
    if (num || digit || div == 1) { /* skip leading zeros */
      *out_buffer++ = '0' + digit; /* write the digit into the output buffer */
      val -= digit * div;          /* subtract the most significant digit */
      num++;
    }
    div /= 10;
  }
  *out_buffer = 0;                 /* close the string */
  return num;                      /* return the # written characters */
}
/*---------------------------------------------------------------------------*/
uint32_t bytes_to_hexstr(const uint8_t* bytes, uint32_t num_bytes, char* out_buffer, uint32_t buffer_size)
{
  if (!bytes || !num_bytes || !out_buffer || buffer_size < 3) {
    return 0;
  }
  uint32_t len = 0;
  buffer_size -= 3;
  while (num_bytes && (len < buffer_size)) {
    char upper_bits = ((*bytes) >> 4) + '0';
    char lower_bits = ((*bytes) & 0x0f) + '0';
    if (upper_bits > '9') {
      upper_bits += ('A' - '9' - 1);
    }
    if (lower_bits > '9') {
      lower_bits += ('A' - '9' - 1);
    }
    out_buffer[len++] = upper_bits;
    out_buffer[len++] = lower_bits;
    bytes++;
    num_bytes--;
  }
  out_buffer[len++] = 0;

  // return the number of written bytes
  return len;
}
/*---------------------------------------------------------------------------*/
int32_t str_to_int32(const char* str)
{
  int32_t val = 0;
  uint8_t neg = 0;
  /* skip nun-numerical character at the beginning */
  while (*str && (*str < '0' || *str > '9') && (*str != '-')) {
    str++;
  }
  if (*str && (*str == '-')) {
    neg = 1;
  }
  while (*str && (*str >= '0' && *str <= '9')) {
    val = val * 10 + (*str - '0');
    str++;
  }
  if (neg) {
    val = -val;
  }
  return val;
}
/*---------------------------------------------------------------------------*/
