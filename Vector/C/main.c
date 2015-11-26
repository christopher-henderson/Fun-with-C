#include "vector.c"
#include <stdio.h>

int main() {
    struct Vector* v = VectorInit();
    add(v, 5);
    printf("%i\n", *(*(v->buffer + 0)));
}