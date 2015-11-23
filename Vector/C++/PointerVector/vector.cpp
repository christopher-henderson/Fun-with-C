#include <stddef.h>
#include <stdlib.h>
#include "vector.hpp"

#define BUFFER_INCREMENT 100

template <class T>
Vector<T>::Vector() {
    number_of_items = 0;
    buffer_size = 0;
}

template <class T>
Vector<T>::~Vector() {
    if (buffer == NULL) return;
    for (int index=0; index<number_of_items; index++) {
        free(*(buffer + index));
    }
    free(buffer);
}

template <class T>
void Vector<T>::add(const T &item) {
    if (should_resize()) {
        resize();
    }
    *(buffer + number_of_items) = (T*) malloc(sizeof(T));
    *(*(buffer + number_of_items++)) = item;
}

template <class T>
T Vector<T>::pop(const int &index) {
    const int resolved_index = resolve_index(index);
    range_check(index);
    T value = *(*(buffer + index));
    --number_of_items;
    for (int i=index; i < number_of_items; i++) {
        *(buffer + i) = *(buffer + i + 1);
    }
    return value;
}

template <class T>
void Vector<T>::remove(const int &index) {
    pop(index);
}

template <class T>
T& Vector<T>::operator[](const int &index) const {
    const int resolved_index = resolve_index(index);
    range_check(resolved_index);
    return *(*(buffer + resolved_index));
}

template <class T>
T& Vector<T>::operator[](const int &index) {
    const int resolved_index = resolve_index(index);
    range_check(resolved_index);
    return *(*(buffer + resolved_index));
}

template <class T>
int Vector<T>::resolve_index(const int &index) const {
    if (index >= 0) {
        return index;
    }
    int res = number_of_items + index;
    return number_of_items + index;
}

template <class T>
void Vector<T>::range_check(const int &index) const {
    return;
}

template <class T>
void Vector<T>::resize(void) {
    const unsigned int new_size = buffer_size + BUFFER_INCREMENT;
    T** new_buffer = (T**) malloc(sizeof(T*)*new_size);
    for (int i=0; i < buffer_size; i++) {
        *(new_buffer + i) = *(buffer + i);
    }
    buffer = new_buffer;
    buffer_size = new_size;
}
