#include <stdio.h>
#include "vector.h"

int main() {
    VectorPTR v = VectorInit();
    vector_add(v, 5);
    vector_add(v, 6);
    vector_remove(v, 0);
    printf("%i\n", vector_pop(v, 0));
}