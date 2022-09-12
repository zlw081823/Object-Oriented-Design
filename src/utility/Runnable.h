#ifndef UTILITY_RUNNABLE
#define UTILITY_RUNNABLE

#include "../common.h"
#include "RunnableInterface.h"

typedef struct _Runnable_PrivateData* Utility_Runnable_Handle;

Utility_Runnable_Handle Utility_Runnable_create(uint32_t counterInitValue);

RunnableInterface* Utility_Runnable_getRunnableInterface(Utility_Runnable_Handle handle);

uint32_t Utility_Runnable_getCounter(Utility_Runnable_Handle handle);

#endif
