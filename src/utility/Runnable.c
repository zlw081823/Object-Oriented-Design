#include "Runnable.h"

#include <stdlib.h>
#include <assert.h>

typedef struct _Runnable_PrivateData
{
    RunnableInterface iRunnable;
    uint32_t counter;
} PrivateData;

static void run(RunnableInterface_Handle handle);

Utility_Runnable_Handle Utility_Runnable_create(uint32_t counterInitValue)
{
    PrivateData* me = malloc(sizeof(PrivateData));
    assert(me != NULL);

    me->iRunnable.handle = me;
    me->iRunnable.run = run;
    me->counter = counterInitValue;

    return me;
}

RunnableInterface* Utility_Runnable_getRunnableInterface(Utility_Runnable_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    return &me->iRunnable;
}

uint32_t Utility_Runnable_getCounter(Utility_Runnable_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    return me->counter;
}

static void run(RunnableInterface_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    me->counter++;
}


