#include "RunnableList.h"
#include "LinkedList.h"
#include "Runnable.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct _RunnableList_PrivateData 
{
    RunnableInterface runnable;
    Utility_LinkedList_Handle linkedList;
} PrivateData;

static void run(RunnableInterface_Handle handle);

Utility_RunnableList_Handle Utility_RunnableList_create(void)
{
    PrivateData* me = malloc(sizeof(PrivateData));
    assert(me != NULL);
    memset(me, 0, sizeof(PrivateData));
    me->runnable.handle = me;
    me->runnable.run = run;
    me->linkedList = Utility_LinkedList_create();

    return me;
}

RunnableInterface* Utility_RunnableList_getRunnableInterface(Utility_RunnableList_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    return &me->runnable;
}

bool Utility_RunnableList_add(Utility_RunnableList_Handle handle, void* item)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    return Utility_LinkedList_add(me->linkedList, item);
}

static void run(RunnableInterface_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    uint32_t size = Utility_LinkedList_size(me->linkedList);
    uint32_t count = size;
    while (count)
    {
        Utility_Runnable_Handle handle = (Utility_Runnable_Handle) Utility_LinkedList_get(me->linkedList, size - count);
        assert(handle != NULL);
        RunnableInterface* iRunnable = Utility_Runnable_getRunnableInterface(handle);
        printf("Before: data %d is %d\n", size - count, Utility_Runnable_getCounter(handle));
        iRunnable->run(iRunnable->handle);
        printf("After: data %d is %d\n", size - count, Utility_Runnable_getCounter(handle));
        count --;
    }
}
