#include <stdio.h>
#include "LinkedListLib.c"

int main() {
    int i = 10;
    int x = 20;
    Init(&i);
    Add(&x);
    void *value = *(tail->value);
    printf("%d", value);
    DestroyList();
    void *value2 = *(tail->value);
    printf("%d", value2);
    return 0;
}