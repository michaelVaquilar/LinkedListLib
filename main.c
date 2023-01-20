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

    int b = IndexOf(list, &x);
    printf("%i", b);
    return 0;
}