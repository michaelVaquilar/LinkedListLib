#include <stdio.h>
#include "LinkedListLib.c"

int main() {
    int i = 10;
    int x = 20;
    int y = 30;
    int b = 33;
    LIST *list = Init();

    Add(list, &i);
    Add(list, &x);
    Add(list, &y);

    InsertNodeBeforeTarget(list,&i,&b);

    printf("%d", *(list->head->value));
    return 0;
}