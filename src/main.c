#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "utility/RunnableList.h"
#include "utility/Runnable.h"

int main(int argc, char *argv[]) 
{
//    if( argc == 2 ) {
//       printf("The argument supplied is %s\n", argv[1]);
//    }
//    else if( argc > 2 ) {
//       printf("Too many arguments supplied.\n");
//    }
//    else {
//       printf("One argument expected.\n");
//    }

    Utility_RunnableList_Handle runnableList = Utility_RunnableList_create();
    printf("created\n");

    Utility_Runnable_Handle runnableHandle = Utility_Runnable_create(2);
    Utility_RunnableList_add(runnableList, runnableHandle);
    runnableHandle = Utility_Runnable_create(22);
    Utility_RunnableList_add(runnableList, runnableHandle);

    RunnableInterface* runnable = Utility_RunnableList_getRunnableInterface(runnableList);
    runnable->run(runnable->handle);
    runnable->run(runnable->handle);
    
    return 1;
}
