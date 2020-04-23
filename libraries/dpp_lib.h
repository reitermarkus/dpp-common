/*
 * dpp_lib.h
 *
 *  Created on: Mar 27, 2020
 *      Author: rdaforno
 */

#ifndef __DPP_LIB_H__
#define __DPP_LIB_H__

/* includes */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/* config */

#ifndef FIFO_STATIC_ALLOC
#define FIFO_STATIC_ALLOC         1         /* if static allocation is used, use the macro FIFO_CREATE() instead of the function fifo_create() */
#endif /* FIFO_STATIC_ALLOC */


/* macros */

#if FIFO_STATIC_ALLOC
#define FIFO_CREATE(fifo_name, element_size, num_elements)  static uint8_t fifo_name##_buffer[element_size * num_elements + sizeof(fifo_meta_t)]; \
                                                            static fifo_t fifo_name = fifo_name##_buffer; \
                                                            ((fifo_meta_t*)fifo_name)->write_idx = 0; \
                                                            ((fifo_meta_t*)fifo_name)->read_idx = 0; \
                                                            ((fifo_meta_t*)fifo_name)->elem_size = element_size; \
                                                            ((fifo_meta_t*)fifo_name)->num_elem = num_elements
#else
#define FIFO_CREATE(fifo_name, element_size, num_elements)  fifo_t fifo_name = fifo_create(element_size, num_elements)
#endif /* FIFO_STATIC_ALLOC */


/* typedefs */

typedef void* fifo_t;

// size must match FIFO_META_SIZE!
typedef struct fifo {
  uint32_t write_idx;
  uint32_t read_idx;
  uint32_t elem_size;
  uint32_t num_elem;
} fifo_meta_t;


/* function prototypes */

uint16_t crc16(const uint8_t* data, uint8_t num_bytes, uint16_t init_value);

uint32_t hexstr_to_uint32(const char* str);
uint32_t uint16_to_str(uint16_t val, char* out_buffer);

#if !FIFO_STATIC_ALLOC
fifo_t fifo_create(uint32_t elem_size, uint32_t num_elem);
#endif /* FIFO_STATIC_ALLOC */
void fifo_clear(fifo_t fifo);
bool fifo_push(fifo_t fifo, const void* elem);
bool fifo_pop(fifo_t fifo, void* elem);
const void* const fifo_peek(const fifo_t fifo);
bool fifo_is_empty(const fifo_t fifo);
bool fifo_is_full(const fifo_t fifo);
uint32_t fifo_get_used_space(const fifo_t fifo);
uint32_t fifo_get_free_space(const fifo_t fifo);


#endif /* __DPP_LIB_H__ */
