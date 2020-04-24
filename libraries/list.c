/*
 * list.c (32-bit version)
 * linked list, elements are sorted in increasing order according to a key (unsigned integer)
 *
 *  Created on: Apr 23, 2020
 *      Author: rdaforno
 */

#include "dpp_lib.h"

#define LIST_ELEM_DATA(elem)    (void*)((uint32_t)elem + sizeof(list_elem_t))

/*---------------------------------------------------------------------------*/
void list_init(list_t list)
{
  if (list) {
    list_meta_t* l = (list_meta_t*)list;
    memb_init(l->list_mem);
    l->head = NULL;
  }
}
/*---------------------------------------------------------------------------*/
void list_link(list_t list, list_elem_t* elem)
{
  if (!list || !elem) {
    return;
  }
  list_elem_t* curr = ((list_meta_t*)list)->head;
  list_elem_t* prev = NULL;
  /* look for suitable position to insert this element */
  while (curr) {
    if (curr->key >= elem->key) {
      break;
    }
    prev = curr;
    curr = curr->next;
  }
  elem->next = curr;
  if (!prev) {
    /* becomes new head */
    ((list_meta_t*)list)->head = elem;
  } else {
    prev->next = elem;
  }
}
/*---------------------------------------------------------------------------*/
bool list_insert(list_t list, uint32_t key, const void* data)
{
  if (!list || !data) {
    return false;
  }
  list_meta_t* l = (list_meta_t*)list;
  /* find a free spot */
  list_elem_t* elem = memb_allocate_block(l->list_mem);
  if (elem) {
    elem->key = key;
    /* copy data */
    uint32_t data_len = memb_get_block_size(l->list_mem) - sizeof(list_elem_t);
    memcpy(LIST_ELEM_DATA(elem), data, data_len);
    list_link(list, elem);
    return true;
  }
  return false;
}
/*---------------------------------------------------------------------------*/
bool list_remove_head(list_t list, void* data)
{
  if (!list) {
    return false;
  }
  list_meta_t* l = (list_meta_t*)list;
  if (l->head) {
    if (data) {
      /* copy into output buffer */
      uint32_t data_len = memb_get_block_size(l->list_mem) - sizeof(list_elem_t);
      memcpy(data, LIST_ELEM_DATA(l->head), data_len);
    }
    /* free the memory block */
    if (!memb_release_block(l->list_mem, l->head)) {
      return false;
    }
    l->head = l->head->next;
    return true;
  }
  return false;
}
/*---------------------------------------------------------------------------*/
const void* list_get_head(const list_t list)
{
  if (!list || !((list_meta_t*)list)->head) {
    return NULL;
  }
  return LIST_ELEM_DATA(((list_meta_t*)list)->head);
}
/*---------------------------------------------------------------------------*/
uint32_t list_get_head_key(const list_t list)
{
  if (!list || !((list_meta_t*)list)->head) {
    return 0;
  }
  return ((list_meta_t*)list)->head->key;
}
/*---------------------------------------------------------------------------*/
