#include "LinkedListLib.h"
#define NULL ((void*)0)
#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
    void **value;
    int size;
    struct Node *next;
    struct Node *previous;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;
int count = 0;
bool initialized = false;


/// Initializes the creation of the linked list.
/// \param value, the first value being added.
void Init(void *value){
    NODE *pList = (NODE*)malloc(sizeof(NODE));

    pList->value = value;
    pList->next = NULL;
    pList->previous = NULL;

    head = pList;
    tail = pList;
    initialized = true;
    count++;
}

/// Adds a value to the end of the linked list.
/// \param pList, pointer to the current list
/// \param value, value to be added
/// \return a pointer to the list that was dynamically allocated.
void *Add(void *value){
    if(!initialized){
        printf("ERROR! Must initialize linked list by calling Init(void *value)");
        exit(0);
    }
    NODE *pList = (NODE*)malloc(sizeof(NODE));

    pList->value = value;
    pList->previous = tail;
    pList->next = NULL;
    pList->previous->next = pList;
    tail = pList;
}

///Destroys the linked list by setting head and tail = null;
void DestroyList(){
    free(head); //find a way to free the originally allocated memory.
    free(tail);
    head = tail = NULL;
    count = 0;
}

void hello(void) {
    printf("Hello, World!\n");
}