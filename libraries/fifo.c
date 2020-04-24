/*
 * fifo.c (32-bit version)
 * a simple and lightweight ring buffer / FIFO queue
 *
 *  Created on: Apr 23, 2020
 *      Author: rdaforno
 */

#include "dpp_lib.h"


#define FIFO_GET_ELEM_BY_INDEX(idx)   (void*)((uint32_t)((fifo_meta_t*)fifo)->buffer_addr + (idx * ((fifo_meta_t*)fifo)->elem_size))

/*---------------------------------------------------------------------------*/
void fifo_clear(fifo_t fifo)
{
  if (fifo) {
    ((fifo_meta_t*)fifo)->write_idx = 0;
    ((fifo_meta_t*)fifo)->read_idx = 0;
  }
}
/*---------------------------------------------------------------------------*/
bool fifo_is_empty(const fifo_t fifo)
{
  if (fifo) {
    return (((fifo_meta_t*)fifo)->read_idx == ((fifo_meta_t*)fifo)->write_idx);
  }
  return true;
}
/*---------------------------------------------------------------------------*/
bool fifo_is_full(const fifo_t fifo)
{
  if (fifo) {
    fifo_meta_t* f = (fifo_meta_t*)fifo;
    uint32_t w = ((f->write_idx + 1) == f->num_elem) ? 0 : (f->write_idx + 1);
    return (w == f->read_idx);
  }
  return true;
}
/*---------------------------------------------------------------------------*/
/* get current fill level */
uint32_t fifo_get_used_space(const fifo_t fifo)
{
  if (fifo) {
    fifo_meta_t* f = (fifo_meta_t*)fifo;
    if (f->write_idx < f->read_idx) {
      return (f->num_elem - f->read_idx + f->write_idx);
    }
    return (f->write_idx - f->read_idx);
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
uint32_t fifo_get_free_space(const fifo_t fifo)
{
  return (((fifo_meta_t*)fifo)->num_elem - fifo_get_used_space(fifo));
}
/*---------------------------------------------------------------------------*/
bool fifo_push(fifo_t fifo, const void* elem)
{
  if (!fifo || !elem || fifo_is_full(fifo)) {
    return false;
  }
  fifo_meta_t* f = (fifo_meta_t*)fifo;
  memcpy(FIFO_GET_ELEM_BY_INDEX(f->write_idx), elem, f->elem_size);
  f->write_idx++;
  if (f->write_idx == f->num_elem) {
    f->write_idx = 0;
  }
  return false;
}
/*---------------------------------------------------------------------------*/
bool fifo_pop(fifo_t fifo, void* elem)
{
  if (!fifo || !elem || !fifo_is_empty(fifo)) {
    return false;
  }
  fifo_meta_t* f = (fifo_meta_t*)fifo;
  memcpy(elem, FIFO_GET_ELEM_BY_INDEX(f->read_idx), f->elem_size);
  ((fifo_meta_t*)fifo)->read_idx++;
  if (f->read_idx == f->num_elem) {
    f->read_idx = 0;
  }
  return true;
}
/*---------------------------------------------------------------------------*/
const void* fifo_peek(const fifo_t fifo)
{
  if (fifo && !fifo_is_empty(fifo)) {
    return FIFO_GET_ELEM_BY_INDEX(((fifo_meta_t*)fifo)->read_idx);
  }
  return NULL;
}
/*---------------------------------------------------------------------------*/
