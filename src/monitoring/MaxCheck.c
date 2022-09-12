
#include "MaxCheck.h"
#include <stdlib.h>
#include <assert.h>

typedef struct _MaxCheck_PrivateData
{
    RunnableInterface runnable;
    MaxCheck_Handle base;
    int32_t *target;
    int32_t tripLevel;
    int32_t tripTime;
    bool isTripped;
    bool isCheckEnabled;
} PrivateData;

static void run(RunnableInterface_Handle handle);

MaxCheck_Handle MaxCheck_create(const MaxCheck_Configuration *configuration, int32_t *target)
{
    PrivateData* me = malloc(sizeof(PrivateData));
    assert(me != NULL);

    me->base = me;
    me->runnable.handle = me;
    me->runnable.run = &run;
    me->target = target;
    me->tripLevel = configuration->tripLevel;
    me->tripTime = configuration->tripTime; //TODO need to inject a timer module in order to trip
    me->isTripped = false;
    me->isCheckEnabled = false;

    return me;
}

static void run(RunnableInterface_Handle handle)
{
    assert(handle != NULL);
    PrivateData *me = (PrivateData*) handle;

    if (me->isCheckEnabled)
    {
        if (*me->target > me->tripLevel)
        {
            me->isTripped = true;
        }
        else
        {
            me->isTripped = false;
        }
    }
}

void MaxCheck_setEnableStatus(MaxCheck_Handle handle, bool isCheckEnabled)
{
    assert(handle != NULL);
    PrivateData *me = (PrivateData*) handle;

    me->isCheckEnabled = isCheckEnabled;
}

bool MaxCheck_getCheckResult(MaxCheck_Handle handle)
{
    assert(handle != NULL);
    PrivateData *me = (PrivateData*) handle;

    return me->isTripped;
}

RunnableInterface* MaxCheck_getRunnableInterface(MaxCheck_Handle handle)
{
    assert(handle != NULL);
    PrivateData *me = (PrivateData*) handle;

    return &me->runnable;
}
