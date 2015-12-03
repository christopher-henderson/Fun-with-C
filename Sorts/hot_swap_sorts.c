#include <stdio.h>

void sort(int* collection, unsigned int size, int (*)(int, int));
void insertion_sort(int* collection, unsigned int size, int (*)(int, int));
void quick_sort(int* collection, unsigned int low, unsigned int high, int (*)(int, int));
int partition(int* collection, unsigned int low, unsigned int high, int (*)(int, int));
int main();

void sort(int* collection, unsigned int size, int (*comp)(int, int)) {
    if (size < 20) {
        insertion_sort(collection, size, comp);
    } else {
        quick_sort(collection, 0, size - 1, comp);
    }
}

void insertion_sort(int* collection, unsigned int size, int (*comp)(int, int)) {
    int j;
    int temp;
    for (int i = 0; i < size; i++) {
        j = i;
        while (j > 0 && comp(*(collection + j), *(collection + j - 1))) {
            temp = *(collection + j);
            *(collection + j) = *(collection + j - 1);
            *(collection + j - 1) = temp;
            j--;
        }
    }
}

void quick_sort(int* collection, unsigned int low, unsigned high, int (*comp)(int, int)) {
    if (low < high) {
        int p = partition(collection, low, high, comp);
        quick_sort(collection, low, p, comp);
        quick_sort(collection, p + 1, high, comp);
    }
}

 int partition(int* collection, unsigned int low, unsigned int high, int (*comp)(int, int)) {
    int temp;
    int pivot = *(collection + low);
    low--;
    high++;
    while (1) {
        do {
            low++;
        } while(comp(*(collection + low), pivot));
        do {
            high--;
        } while(comp(pivot, *(collection + high)));
        if (low < high) {
            temp = *(collection + low);
            *(collection + low) = *(collection + high);
            *(collection + high) = *(collection + low);
        } else {
            return high;
        }
    }
 }

int comp(int a, int b) {
    return a > b;
}

int main() {
    int* small = (int[]) {5, 4, 3, 2, 1};
    int large[21];
    for (int i=20; i >= 0; i--) {
        large[i] = i;
    }
    sort(small, 5, (void*) comp);
    sort((int*) large, 21, (void*) comp);
    for (int i=0; i < 5; i++) {
        printf("%i, ", *(small + i));
    }
    printf("\n");
    for (int i=0; i < 21; i++) {
        printf("%i, ", *(((int*)large) + i));
    }
    printf("\n");
}