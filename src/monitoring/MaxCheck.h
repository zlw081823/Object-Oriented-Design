#ifndef MAXCHECK_H
#define MAXCHECK_H

#include "../common.h"
#include "../utility/RunnableInterface.h"

typedef struct _MaxCheck_PrivateData* MaxCheck_Handle;

typedef struct _MaxCheck_Configuration
{
    int32_t tripLevel;
    int32_t tripTime;
} MaxCheck_Configuration;

MaxCheck_Handle MaxCheck_create(const MaxCheck_Configuration *configuration, int32_t *target);

void MaxCheck_setEnableStatus(MaxCheck_Handle handle, bool isCheckEnabled);

bool MaxCheck_getCheckResult(MaxCheck_Handle handle);

RunnableInterface* MaxCheck_getRunnableInterface(MaxCheck_Handle handle);

#endif