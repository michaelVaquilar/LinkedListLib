#include <stdio.h>
#include "LinkedListLib.c"

int main() {
    int i = 10;
    int x = 20;
    int y = 30;
    LIST *list = Init();

    Add(list, &i);
    Add(list, &x);
    Add(list, &y);
    void *test = *(list->tail->value);
    printf("%d", test);
    return 0;
}