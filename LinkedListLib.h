
#ifndef LINKEDLIST_LINKEDLISTLIB_H
#define LINKEDLIST_LINKEDLISTLIB_H

#include <stdbool.h>

typedef struct Node{
    void **value;
    struct Node *next;
    struct Node *previous;
} NODE;

typedef struct LList{
    NODE* head;
    NODE* tail;
    int count;
    int sizeOfData;
} LIST;


LIST *Init();

void Add(LIST *list, void *value);

void *Get(LIST *list, int index);

void DestroyList(LIST *list);

void DumpList(LIST *list);

int IndexOf(LIST *list, void *value);

bool InsertNodeBeforeTarget(LIST *list, void *TargetValue, void *newValue);

bool InsertNodeAfterTarget(LIST *list, void *TargetValue, void *newValue);

NODE *WalkToNode(LIST *list, int location);

int compareTo(void *valOne, void *valTwo, int size);

#endif //LINKEDLIST_LINKEDLISTLIB_H