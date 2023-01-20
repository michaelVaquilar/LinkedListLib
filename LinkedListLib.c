#include "LinkedListLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool initialized = false;

/// Initializes our linked list so we have a memory location for it.
/// Using calloc so that the memory is already set to 0 instead of empty.
/// \return memory location
LIST *Init(){
    initialized = true;
    return calloc(1, sizeof(LIST));
}

/// Adds a value to the end of the linked list.
/// \param value, value to be added
/// \return none
void Add(LIST *list, void *value) {
    NODE *pList = calloc(1, sizeof(LIST));
    pList->value = value;
    if(!initialized){
        return;
    }
    else if(list->count <= 0) {
        list->head = pList;
        list->tail = pList;
    }
    else {
        list->tail->next = pList;
        pList->previous = list->tail;
        list->tail = pList;
    }
}


///Destroys the linked list by setting head and tail = null;
void DestroyList(LIST *list){
    free(list);
}

void hello(void) {
    printf("Hello, World!\n");
}