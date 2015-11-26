#include <stdlib.h>
#include <stddef.h>
#include "vector.h"

#define BUFFER_INCREMENT 100

VectorPTR VectorInit() {
    VectorPTR v = (VectorPTR) malloc(sizeof(Vector));
    v->length = 0;
    v->_max_size = 0;
    v->buffer = NULL;
    return v;
}

void vector_add(VectorPTR v, int item) {
    if (vector_full(v)) {
        vector_expand(v);
    }
    *(*(v->buffer + v->length)) = item;
    v->length++;
}

int vector_getAt(VectorPTR v, unsigned int index) {
    if (index >= v->length) {
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
    if (v->buffer == NULL) {
        v->buffer = (int**) calloc(sizeof(int*), v->_max_size);
    }
    else {
        realloc(v->buffer, v->_max_size);
    }
    for (int index = v->length; index < v->_max_size; index++) {
        *(v->buffer + index) = (int*) malloc(sizeof(int));
    }
}
