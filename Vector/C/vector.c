#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "vector.h"

#define BUFFER_INCREMENT 100

VectorPTR VectorInit() {
    VectorPTR v = (VectorPTR) malloc(sizeof(Vector));
    v->length = 0;
    v->_max_size = 0;
    v->buffer = NULL;
    return v;
}

int vector_add(VectorPTR v, int item) {
    if (vector_full(v)) {
        vector_expand(v);
    }
    return *(*(v->buffer + v->length++)) = item;
}

int vector_getAt(VectorPTR v, unsigned int index) {
    if (index >= v->length) {
        printf("Vector index out of bounds.\n");
        abort();
    }
    return *(*(v->buffer + index));
}

int vector_pop(VectorPTR v, unsigned int index) {
    int value = vector_getAt(v, index);
    for (int i = index; i < v->length - 1; i++) {
        *(v->buffer + i) = *(v->buffer + i + 1);
    }
    v->length--;
    return value;
}

void vector_remove(VectorPTR v, unsigned int index) {
    vector_pop(v, index);
}

int vector_full(VectorPTR v) {
    return v->length >= v->_max_size;
}

void vector_expand(VectorPTR v) {
    v->_max_size += BUFFER_INCREMENT;
    v->buffer = realloc(v->buffer, sizeof(int*) * v->_max_size);
    if (v->buffer == NULL) {
        fprintf(stderr, "Failed to allocate buffer.\n");
        abort();
    }
    int* init_ptr;
    for (int index = v->length; index < v->_max_size; index++) {
        init_ptr = (int*) malloc(sizeof(int));
        if (init_ptr == NULL) {
            fprintf(stderr, "Failed to initialize buffer.\n");
            abort();
        }
        *(v->buffer + index) = init_ptr;
    }
}
