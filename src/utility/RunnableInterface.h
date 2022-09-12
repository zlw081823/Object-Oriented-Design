
#ifndef RUNNABLEINTERFACE_H
#define RUNNABLEINTERFACE_H

typedef void* RunnableInterface_Handle;

typedef void (*RunnableInterface_run)(RunnableInterface_Handle handle);

typedef struct _RunnableInterface
{
    RunnableInterface_Handle handle;
    RunnableInterface_run run;
} RunnableInterface;

#endif
