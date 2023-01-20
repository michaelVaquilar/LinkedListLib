
#ifndef LINKEDLIST_LINKEDLISTLIB_H
#define LINKEDLIST_LINKEDLISTLIB_H

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
void hello(void);

LIST *Init();

void Add(LIST *list, void *value);

void DestroyList(LIST *list);


#endif //LINKEDLIST_LINKEDLISTLIB_H