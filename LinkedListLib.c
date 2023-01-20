#include "LinkedListLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool initialized = false; //tells us if the user has created a list or not yet.

/// Initializes our linked list so we have a memory location for it.
/// Using calloc so that the memory is already set to 0 instead of empty.
/// \return memory location that we will have access too.
LIST *Init(){
    initialized = true;
    return calloc(1, sizeof(LIST));
}

/// Adds a value to the linked list.
/// \param value, value to be added
/// \return none, only used as a break.
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


/// Destroys the list aka get's rid of the memory location
/// by freeing the allocated memory.
/// \param list, list to be destroyed
void DestroyList(LIST *list){
    if(!initialized){ return; }
    free(list);
}

/// Prints list to console line by line
/// \param list - pointer to the list.
void DumpList(LIST *list){
    if(list->count <= 0){ return; }
    NODE *curr = list->head;
    while(curr != NULL){
        printf("%d\n", *(curr->value));
        *curr = *curr->next;
    }
}
/// Finds the index of a specific value.
/// \param list, the linked list to search.
/// \param value, the value to look for.
/// \return int, the index of the value.
int IndexOf(LIST *list, void *value){
    if(list->count <= 0) { return -1;}
    NODE *curr = list->head;
    int counter = 1;
    while(curr->value != value && curr != NULL){
        *curr = *curr->next;
        counter++;
    }
    if(curr == NULL) { //In this case the value is not in the linkedlist.
        return -1;
    }
    return counter;
}

/// Inserts a node (aka value) before the target value the user is looking for.
/// \param list, list to insert the new item into.
/// \param TargetValue, value to insert new value at.
/// \param newValue, new value to be inserted.
/// \return true if the node was successfully added, false if the target value is not in the existing list.
bool InsertNodeBeforeTarget(LIST *list, void *TargetValue, void *newValue){
    int indexOfTarget = IndexOf(list, TargetValue);
    if(indexOfTarget == -1){
        return false;
    }
    NODE *curr = WalkToNode(list, indexOfTarget - 1);
    NODE *temp = calloc(1, sizeof(NODE));
    temp->value = newValue;
    temp->next = curr;
    *curr = *temp;
    list->count++;
    return true;
}

/// Inserts the new Node (aka value) after the specified target value.
/// \param list, the list to insert the new node into.
/// \param TargetValue, value to insert a new node after.
/// \param newValue, the new value to insert.
/// \return true if the node was successfully added, false if the target value is not in the existing list.
bool InsertNodeAfterTarget(LIST *list, void *TargetValue, void *newValue){
    int indexOfTarget = IndexOf(list, TargetValue);
    if(indexOfTarget == -1){
        return false;
    }
    NODE *curr = WalkToNode(list, indexOfTarget);
    NODE *temp = calloc(1, sizeof(NODE));
    temp->value = newValue;
    temp->next = curr;
    *curr = *temp;
    list->count++;
    return true;
}

/// Unlinks a node that has a specific value.
/// \param list, the list to remove the node from.
/// \param value, the value to remove.
/// \return true if the node was successfully removed, false if the target value is not in the existing list.
bool UnlinkNodeByValue(LIST *list, void *value){
    int indexOfTarget = IndexOf(list, value);
    if(indexOfTarget == -1){
        return false;
    }
    NODE *curr = WalkToNode(list, indexOfTarget - 1);
    NODE *temp = calloc(1, sizeof(NODE));
    *temp = *curr->next;
    *curr = *temp;
    return true;
}

/// Walks the linkedlist that it is given to a specific location.
/// \param list, the list to walk.
/// \param location, the location to walk to.
/// \return a pointer to the node that was walked to.
NODE *WalkToNode(LIST *list, int location){
    NODE *curr = list->head;
    for(int i = 0; i < location - 1; i++){
        *curr = *curr->next;
    }
    return curr;
}



