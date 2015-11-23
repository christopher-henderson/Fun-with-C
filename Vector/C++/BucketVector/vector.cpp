#include "vector.hpp"
#include <iostream>
#define BUFFER_SIZE 20
#define BASE_BUFFER_INCREMENT 10

template <class T>
Vector<T>::Vector() {
    length = 0;
    num_buffers = 0;
    base_buffer_size = 0;
}

template <class T>
T& Vector<T>::operator[] (unsigned const int &index) const {
    range_check(index);
    return *(get_final_pointer(index));
}

template <class T>
T& Vector<T>::operator[] (unsigned const int &index) {
    range_check(index);
    return *(get_final_pointer(index));
}

template <class T>
void Vector<T>::add(const T &item) {
    if (should_add_buffer()) {
        add_buffer();
    }
    *(get_final_pointer(length++)) = item;
}

template <class T>
T Vector<T>::pop(const unsigned int &index) {
    T value = (*this)[index];
    for (int i=index; i<length-1; i++) {
        (*this)[i] = (*this)[i+1];
    }
    return value;
}

template <class T>
void Vector<T>::remove(const unsigned int &index) {
    pop(index);
}

template <class T>
void Vector<T>::range_check(const unsigned int &index) const {
    if (index >= length) {
        // throw
    }
}

template <class T>
void Vector<T>::add_buffer(void) {
    if (num_buffers == base_buffer_size ) {
        grow_base_buffer();
    }
    *(base_buffer + num_buffers) = (T*) malloc(sizeof(T)*BUFFER_SIZE);
    num_buffers++;
}

template <class T>
void Vector<T>::grow_base_buffer(void) {
    unsigned int new_buffer_size = base_buffer_size + BASE_BUFFER_INCREMENT;
    T** temp = (T**) malloc(sizeof(T*)*new_buffer_size);
    for (unsigned int offset=0; offset < base_buffer_size; offset++) {
        *(temp + offset) = *(base_buffer + offset);
    }
    base_buffer = temp;
    base_buffer_size = new_buffer_size;
}

template <class T>
bool Vector<T>::should_add_buffer(void) {
    return !(length % BUFFER_SIZE);
}

template <class T>
T* Vector<T>::get_final_pointer(unsigned const int &index) const {
    unsigned int offset = index / BUFFER_SIZE;
    unsigned int internal_index = index % BUFFER_SIZE;
    return *(base_buffer + offset) + internal_index;
}

