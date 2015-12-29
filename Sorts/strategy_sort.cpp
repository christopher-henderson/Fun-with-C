#include <iostream>

template <class T>
void sort(T* collection, unsigned int size,
        unsigned int (*)(const T&, const T&));

template <class T>
void quick_sort(T* collection, unsigned int low, unsigned int high,
        unsigned int (*)(const T&, const T&));

template <class T>
unsigned int partition(T* collection, unsigned int low, unsigned int high,
        unsigned int (*)(const T&, const T&));

template <class T>
void insertion_sort(T* collection, unsigned int size,
        unsigned int (*)(const T&, const T&));

template <class T>
void swap(T* collection, unsigned int low, unsigned int high);

template <class T>
unsigned int comp(const T& a, const T& b);

template <class T>
void sort(T* collection, unsigned int size,
        unsigned int (*comp)(const T&, const T&)) {
    if (size < 25) {
        insertion_sort(collection, size, comp);
    } else {
        quick_sort(collection, 0, size, comp);
    }
}

template <class T>
void swap(T* collection, unsigned int low, unsigned int high) {
    T temp = *(collection + low);
    *(collection + low) = *(collection + high);
    *(collection + high) = temp;
}

template <class T>
unsigned int comp(const T& a, const T& b) {
    return a < b;
}

template <class T>
void quick_sort(T* collection, unsigned int low, unsigned int high,
        unsigned int (*comp)(const T&, const T&)) {
    if (low < high) {
        unsigned int p = partition(collection, low, high, comp);
        quick_sort(collection, low, p, comp);
        quick_sort(collection, p + 1, high, comp);
    }
}

template <class T>
unsigned int partition(T* collection, unsigned int low, unsigned int high,
        unsigned int (*comp)(const T&, const T&)) {
    T pivot = *(collection + low);
    low--;
    high++;
    while (true) {
        do {
            low++;
        } while (comp(*(collection + low), pivot));
        do {
            high--;
        } while (comp(pivot, *(collection + high)));
        if (low < high) {
            swap(collection, low, high);
        } else {
            return high;
        }
    }
}

template <class T>
void insertion_sort(T* collection, unsigned int size,
        unsigned int (*comp)(const T&, const T&)) {
    for (unsigned int i=0; i < size; i++) {
        for (unsigned int j=i; j > 0 && comp(*(collection + j), *(collection + j - 1)); j--) {
            swap(collection, j - 1, j);
        }
    }
}

int main() {
    int small[] = {3, 5, 2, 8, 23, 6, 2, 1, 5};  //9
    int large[] = {3, 5, 2, 8, 23, 6, 2, 1, 5, 3, 5, 2, 8, 23, 6, 2, 1, 5, 3, 5, 2, 8, 23, 6, 2, 1, 5,3, 5, 2, 8, 23, 6, 2, 1, 5, 3, 5, 2, 8, 23, 6, 2, 1, 5};  // 45
    sort(small, 9, comp);
    sort(large, 45, comp);
    for (int i=0; i < 9; i++) {
        std::cout << *(small + i) << ", ";
    }
    std::cout << std::endl;
        for (int i=0; i < 45; i++) {
        std::cout << *(large + i) << ", ";
    }
    std::cout << std::endl;
    return 0;
}