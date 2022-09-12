#ifndef UTILITY_LINKEDLIST_H
#define UTILITY_LINKEDLIST_H

#include "../common.h"

typedef struct _LinkedList_PriviateData* Utility_LinkedList_Handle;

Utility_LinkedList_Handle Utility_LinkedList_create(void);

bool Utility_LinkedList_add(Utility_LinkedList_Handle handle, uint32_t* dataPtr);

uint32_t* Utility_LinkedList_get(Utility_LinkedList_Handle handle, uint32_t index);

uint32_t Utility_LinkedList_size(Utility_LinkedList_Handle handle);

#endif
