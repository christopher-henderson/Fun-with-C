#include <stdio.h>

void sort(int*, unsigned int, int (*)(int));
void insertion_sort(int*, unsigned int, int (*)(int));
void quick_sort(int*, unsigned int, unsigned int, int (*)(int));
int partition(int*, unsigned int, unsigned int, int (*)(int));

void sort(int* collection, unsigned int size, int (*key)(int)) {
    if (size < 20) {
        insertion_sort(collection, size, key);
    } else {
        quick_sort(collection, 0, size - 1, key);
    }
}

void insertion_sort(int* collection, unsigned int size, int (*key)(int)) {
    int temp;
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = i; j > 0 && key(*(collection + j - 1)) > key(*(collection + j)); j--) {
            temp = *(collection + j);
            *(collection + j) = *(collection + j - 1);
            *(collection + j - 1) = temp;
        }
    }
}

void quick_sort(int* collection, unsigned low, unsigned int high, int (*key)(int)) {
    if (low < high) {
        int p = partition(collection, low, high, key);
        quick_sort(collection, low, p, key);
        quick_sort(collection, p + 1, high, key);
    }
}

int partition(int* collection, unsigned low, unsigned int high, int (*key)(int)) {
    int temp;
    int pivot = key(*(collection + low));
    low--;
    high++;
    while (1) {
        do {
            low++;
        } while (key(*(collection + low)) < pivot);
        do {
            high--;
        } while (key(*(collection + high)) > pivot);
        if (low < high) {
            temp = *(collection + low);
            *(collection + low) = *(collection + high);
            *(collection + high) = temp;
        } else {
            return high;
        }
    }
}

int key(int item) {
    return ((float)(item + 5)) / 2;
}

int main() {
    int* qsort_collection = (int[]) {21, 20, 19, 18, 17, 16, 15, 14, 13, 12,
        11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int* insort_collection = (int[]) {5, 4, 3, 2 ,1};
    sort(insort_collection, 5, (void*) key);
    sort(qsort_collection, 21, (void*) key);
    for (int i = 0; i < 5; i++) {
        printf("%i, ", *(insort_collection + i));
    }
    printf("\n");
    for (int i = 0; i < 21; i++) {
        printf("%i, ", *(qsort_collection + i));
    }
    printf("\n");
    return 0;
}