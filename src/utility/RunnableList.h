#ifndef UTILITY_RUNNABLELIST_H
#define UTILITY_RUNNABLELIST_H

#include "../common.h"
#include "RunnableInterface.h"

typedef struct _RunnableList_PrivateData* Utility_RunnableList_Handle;

Utility_RunnableList_Handle Utility_RunnableList_create(void);

RunnableInterface* Utility_RunnableList_getRunnableInterface(Utility_RunnableList_Handle handle);

bool Utility_RunnableList_add(Utility_RunnableList_Handle handle, void* item);

#endif
