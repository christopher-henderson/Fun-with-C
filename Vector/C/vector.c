#include <stdlib.h>
#include <stddef.h>

#define BUFFER_INCREMENT 100

struct Vector {
    unsigned int length;
    unsigned int _max_size;
    int** buffer;
};

struct Vector* VectorInit() {
    struct Vector* v = (struct Vector*) malloc(sizeof(struct Vector));
    v->length = 0;
    v->_max_size = 0;
    v->buffer = NULL;
    return v;
}

int full(const struct Vector* vector) {
    return vector->length >= vector->_max_size;
}

void expand(struct Vector* v) {
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

void add(struct Vector* v, int item) {
    if (full(v)) {
        expand(v);
    }
    *(*(v->buffer + v->length)) = item;
    v->length++;
}