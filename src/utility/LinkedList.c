#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdio.h>

typedef struct _LinkedList_Node
{
    struct _LinkedList_Node* next;
    uint32_t* dataPtr;
} Node;

typedef struct _LinkedList_PriviateData
{
    Utility_LinkedList_Handle handle;
    Node* first;
    uint32_t size;
} PrivateData;

Utility_LinkedList_Handle Utility_LinkedList_create(void)
{
    PrivateData* me = malloc(sizeof(PrivateData));
    assert(me != NULL);
    // memset(me, 0, sizeof(PrivateData));
    me->first = NULL;
    me->size = 0;
    me->handle = me;

    return me;
}

bool Utility_LinkedList_add(Utility_LinkedList_Handle handle, uint32_t* dataPtr)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);
    Node* node = me->first;
    Node* newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->next = NULL;
    newNode->dataPtr = dataPtr;

    if (node)
    {
        node->next = newNode;
        while (node)
        {
            node = node->next;
        }
    }
    else
    {
        me->first = newNode;
    }
    me->size ++;

    return OPERATION_SUCCEESS;
}

uint32_t* Utility_LinkedList_get(Utility_LinkedList_Handle handle, uint32_t index)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);
    assert(index < me->size);
    
    uint32_t count = 0;
    Node* node = me->first;
    assert(node != NULL);
    for(count = 0; count < index; count++)
    {
        node = node->next;
    }

    return node->dataPtr;
}

uint32_t Utility_LinkedList_size(Utility_LinkedList_Handle handle)
{
    PrivateData* me = (PrivateData*) handle;
    assert(me != NULL);

    return me->size;
}
