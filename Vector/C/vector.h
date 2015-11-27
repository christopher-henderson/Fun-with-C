#ifndef _VECTOR_J
#define _VECTOR_J

typedef struct {
    unsigned int length;
    unsigned int _max_size;
    int** buffer;
} Vector, *VectorPTR;

VectorPTR VectorInit();
int vector_add(VectorPTR v, int item);
int vector_getAt(VectorPTR v, unsigned int index);
int vector_pop(VectorPTR v, unsigned int index);
void vector_remove(VectorPTR v, unsigned int index);
int vector_full(VectorPTR v);
void vector_expand(VectorPTR v);

#endif