/*
 * memb.c (32-bit version)
 * static memory block allocation
 *
 *  Created on: Apr 24, 2020
 *      Author: rdaforno
 */

#include "dpp_lib.h"

/*---------------------------------------------------------------------------*/
void* memb_allocate_block(memb_t memb)
{
  if (!memb) {
    return NULL;
  }
  memb_meta_t* m = (memb_meta_t*)memb;
  if (!m->valid_bits) {
    return NULL;
  }
  uint32_t i;
  /* linear search */
  for (i = 0; i < m->num_blocks; i++) {
    uint32_t bitmask = (1 << (i & 31));
    if ((m->valid_bits[i >> 5] & bitmask) == 0) {
      m->valid_bits[i >> 5] |= bitmask;                         /* set bit (mark as used) */
      return (void*)((uint32_t)m->blocks + i * m->block_size);  /* return block address */
    }
  }
  return NULL;  /* no free block found */
}
/*---------------------------------------------------------------------------*/
bool memb_release_block(memb_t memb, void* block_addr)
{
  if (!memb) {
    return false;
  }
  memb_meta_t* m = (memb_meta_t*)memb;
  if (!m->block_size) {
    return false;
  }
  uint32_t block_idx = ((uint32_t)block_addr - (uint32_t)m->blocks) / m->block_size;
  if (block_idx < m->num_blocks) {
    uint32_t bitmask = (1 << (block_idx & 31));
    if (m->valid_bits[block_idx >> 5] & bitmask) {
      m->valid_bits[block_idx >> 5] &= ~bitmask;
      return true;
    }
  }
  return false;   /* block not found */
}
/*---------------------------------------------------------------------------*/
void memb_init(memb_t memb)
{
  if (memb) {
    memb_meta_t* m = (memb_meta_t*)memb;
    if (m->valid_bits) {
      memset(m->valid_bits, 0, (m->num_blocks + 31) / 32 + (m->num_blocks * m->block_size));
    }
  }
}
/*---------------------------------------------------------------------------*/
uint32_t memb_get_block_size(memb_t memb)
{
  if (memb) {
    return ((memb_meta_t*)memb)->block_size;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
uint32_t memb_get_block_count(memb_t memb)
{
  if (memb) {
    return ((memb_meta_t*)memb)->num_blocks;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
uint32_t memb_get_free_block_count(memb_t memb)
{
  if (!memb) {
    return 0;
  }
  memb_meta_t* m = (memb_meta_t*)memb;
  if (!m->valid_bits) {
    return 0;
  }
  uint32_t i, cnt = 0;
  for (i = 0; i < m->num_blocks; i++) {
    uint32_t bitmask = (1 << (i & 31));
    if ((m->valid_bits[i >> 5] & bitmask) == 0) {
      cnt++;
    }
  }
  return cnt;
}
/*---------------------------------------------------------------------------*/
