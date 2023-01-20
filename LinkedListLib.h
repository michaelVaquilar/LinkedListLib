
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
} LIST;


LIST *Init();

void Add(LIST *list, void *value);

void DestroyList(LIST *list);

void DumpList(LIST *list);

int IndexOf(LIST *list, void *value);

bool InsertNodeBeforeTarget(LIST *list, void *TargetValue, void *newValue);

bool InsertNodeAfterTarget(LIST *list, void *TargetValue, void *newValue);

#endif //LINKEDLIST_LINKEDLISTLIB_H