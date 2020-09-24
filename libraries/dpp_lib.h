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


/* --- config --- */



/* --- macros --- */

/* statically allocate memory blocks on the heap */
#define MEMB_CREATE(memb_name, block_size, num_blocks)      static uint8_t memb_name##_memb[((num_blocks + 31) / 32) + block_size * num_blocks] = { 0 }; \
                                                            static memb_meta_t memb_name##_memb_info = { block_size, num_blocks, (uint32_t*)memb_name##_memb, (void*)((uint32_t)memb_name##_memb + ((num_blocks + 31) / 32)) }; \
                                                            memb_t memb_name = &memb_name##_memb_info

#define LIST_CREATE(list_name, element_size, num_elements)  static uint8_t list_name##_memb[((num_elements + 31) / 32) + (sizeof(list_elem_t) + element_size) * num_elements] = { 0 }; \
                                                            static memb_meta_t list_name##_memb_info = { (sizeof(list_elem_t) + element_size), num_elements, (uint32_t*)list_name##_memb, (void*)((uint32_t)list_name##_memb + ((num_elements + 31) / 32)) }; \
                                                            static list_meta_t list_name##_list = { 0, &list_name##_memb_info }; \
                                                            list_t list_name = &list_name##_list

#define FIFO_CREATE(fifo_name, element_size, num_elements)  static uint8_t fifo_name##_fifo_buffer[element_size * num_elements] = { 0 }; \
                                                            static fifo_meta_t fifo_name##_fifo_info = { 0, 0, element_size, num_elements, fifo_name##_fifo_buffer }; \
                                                            fifo_t fifo_name = &fifo_name##_fifo_info


/* --- typedefs --- */

typedef void* memb_t;     /* just an alias for memb_meta_t to hide the contents of the struct from the user */

typedef struct memb {
  uint32_t  block_size;
  uint32_t  num_blocks;
  uint32_t* valid_bits;
  void*     blocks;
} memb_meta_t;

typedef void* fifo_t;     /* just an alias for fifo_meta_t to hide the contents of the struct from the user */

typedef struct fifo {
  uint32_t write_idx;
  uint32_t read_idx;
  uint32_t elem_size;
  uint32_t num_elem;
  void*    buffer_addr;
} fifo_meta_t;

typedef void* list_t;     /* just an alias for list_meta_t to hide the contents of the struct from the user */

typedef struct list_elem {
  uint32_t key;
  void*    next;
} list_elem_t;

typedef struct list_meta {
  list_elem_t* head;
  memb_t       list_mem;
} list_meta_t;


/* --- function prototypes --- */

uint16_t crc16(const uint8_t* data, uint8_t num_bytes, uint16_t init_value);

uint32_t hexstr_to_uint32(const char* str);
uint32_t uint16_to_str(uint16_t val, char* out_buffer);
uint32_t bytes_to_hexstr(const uint8_t* bytes, uint32_t num_bytes, char* out_buffer, uint32_t buffer_size);

void     memb_init(memb_t memb);
void*    memb_allocate_block(memb_t memb);
bool     memb_release_block(memb_t memb, void* block_addr);
uint32_t memb_get_block_size(memb_t memb);
uint32_t memb_get_block_count(memb_t memb);
uint32_t memb_get_free_block_count(memb_t memb);

void     list_init(list_t list);
bool     list_insert(list_t list, uint32_t key, const void* data);
bool     list_remove(list_t list, const void* elem);
bool     list_remove_by_key(list_t list, uint32_t key);
bool     list_remove_head(list_t list, void* data);
const void* list_get_head(const list_t list);
uint32_t list_get_head_key(const list_t list);

void     fifo_clear(fifo_t fifo);
bool     fifo_push(fifo_t fifo, const void* elem);
bool     fifo_pop(fifo_t fifo, void* elem);
const void* fifo_peek(const fifo_t fifo);
bool     fifo_is_empty(const fifo_t fifo);
bool     fifo_is_full(const fifo_t fifo);
uint32_t fifo_get_used_space(const fifo_t fifo);
uint32_t fifo_get_free_space(const fifo_t fifo);


#endif /* __DPP_LIB_H__ */
