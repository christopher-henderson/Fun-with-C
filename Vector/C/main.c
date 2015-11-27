#include <stdio.h>
#include "vector.h"

int main() {
    VectorPTR v = VectorInit();
    for (int i = 0; i < 1001; i++) {
        vector_add(v, i);
    }
    for (int i = 0; i < 1001; i++) {
        printf("%i\n", vector_getAt(v, i));
    }
    vector_getAt(v, 1001);
}