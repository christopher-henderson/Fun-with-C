#ifndef _VECTOR_H_
#define _VECTOR_H_
#define BUFFER_SIZE 20

#include <stddef.h>
#include <stdlib.h>

template <class T>
class Vector {
    public:
        Vector();
        void add(const T &item);
        T pop(const unsigned int &index);
        void remove(const unsigned int &index);
        T& operator [](const unsigned int &index) const;
        T& operator [](const unsigned int &index);
        unsigned int length;

    private:
        void add_buffer(void);
        void grow_base_buffer(void);
        bool should_add_buffer(void);
        void range_check(const unsigned int &index) const;
        T* get_final_pointer(unsigned const int &index) const;

        unsigned int num_buffers;
        unsigned int base_buffer_size;
        T** base_buffer;
};

#endif