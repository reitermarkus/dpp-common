/*
 * stringutils.c
 * string utilities
 *
 *  Created on: Mar 27, 2020
 *      Author: rdaforno
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

