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
    NODE *pList = calloc(1, sizeof(NODE));
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
    list->count++;
}


///Destroys the linked list by setting head and tail = null;
void DestroyList(LIST *list){
    free(list);
}

/// Prints list to console line by line
/// \param list - pointer to the list.
void DumpList(LIST *list){
    NODE *curr = list->head;
    while(curr != NULL){
        printf("%d\n", *(curr->value));
        *curr = *curr->next;
    }
}
int IndexOf(LIST *list, void *value){
    NODE *curr = list->head;
    int counter = 1;
    while(curr->value != value){
        *curr = *curr->next;
        counter++;
    }
    return counter;
}

