#ifndef _VECTOR_H_
#define _VECTOR_H_
#define BUFFER_SIZE 20

#include <stddef.h>
#include <stdlib.h>

template <class T>
class Vector {
    public:
        Vector();
        ~Vector();
        void add(const T &item);
        T pop(const int &index);
        void remove(const int &index);
        T& operator [](const int &index) const;
        T& operator [](const int &index);
        inline unsigned int length() { return number_of_items; }


    private:
        void resize(void);
        inline bool should_resize() const { return number_of_items == buffer_size; };
        void range_check(const int &index) const;
        int resolve_index(const int &index) const;
        unsigned int number_of_items;
        unsigned int buffer_size;
        T** buffer;
};

#endif