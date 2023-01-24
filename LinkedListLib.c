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
        list->tail = list->tail->next;
    }
    list->count++;
}

/// Gets the value at the specific index.
/// \param list, list to get value from.
/// \param index, index to get value at.
/// \return the value at the index.
void *Get(LIST *list, int index){
    NODE *curr = WalkToNode(list, index);
    return curr->value;
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
        if(curr->next == NULL){ break; }
        *curr = *curr->next;
    }
}
/// Finds the index of a specific value.
/// \param list, the linked list to search.
/// \param value, the value to look for.
/// \return int, the index of the value.
int IndexOf(LIST *list, void *value){
    if(list->count <= 0) { return -1;}
    NODE *curr  = list->head;
    int counter = 1;
    while(curr != NULL){
        if(curr->value == value){ return counter; }
        if(curr->next == NULL) { return -1; }
        *curr = *curr->next;
        counter++;
    }
    return -1;
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
    NODE *curr  = WalkToNode(list, indexOfTarget - 1);
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
    NODE *curr  = WalkToNode(list, indexOfTarget - 1);
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
    NODE *curr  = WalkToNode(list, indexOfTarget - 1);
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
    NODE *curr  = list->head;
    for(int i = 0; i < location; i++){
        *curr = *curr->next;
    }
    return curr;
}

/// Finds the middle of the linked list
/// \param start, the beginning node of the list
/// \return the middle node
NODE *findMid(NODE *start){
    NODE *fastTemp = start->next;
    NODE *slowTemp = start;

    while(fastTemp != NULL){
        fastTemp = fastTemp->next;

        if(fastTemp != NULL) {
            fastTemp = fastTemp->next;
            slowTemp = slowTemp->next;
        }
    }
    return slowTemp;
}

/// Sorts the list, took this code from my old C# linkedlist and converted it.
/// \param list, our linked list
/// \param leftCursor, left cursor
/// \param rightCursor, right cursor
/// \return
NODE *Sort(LIST *list, NODE *leftCursor, NODE *rightCursor){
    NODE *temp;

    if(leftCursor == NULL)
        return rightCursor;
    if(rightCursor == NULL)
        return leftCursor;

    if(leftCursor->value < rightCursor->value){
        temp = leftCursor;
        temp->next = Sort((leftCursor->next, rightCursor));
        list->tail = temp->next;
    }
    else{
        temp = rightCursor;
        temp->next = Sort(list, leftCursor, rightCursor->next);
        list->tail = temp->next;
    }
    return temp;
}

NODE *MergeSort(LIST *list, NODE *start){
    if(start == NULL || start->next == NULL)
        return start;

    NODE *endOf1st = findMid(start);
    NODE *begOf2nd = endOf1st->next;
    endOf1st->next = NULL;

    NODE *LHS = start;
    NODE *RHS = begOf2nd;

    LHS = MergeSort(list,LHS);
    RHS = MergeSort(list,RHS);

    NODE *sorted = Sort(list,LHS, RHS);

    list->head = sorted;

    return sorted;

}



