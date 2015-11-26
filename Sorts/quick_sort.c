#include <stdio.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);

void quick_sort(int* collection, int low, int high) {
    if (low < high) {
        int p = partition(collection, low, high);
        quick_sort(collection, low, p);
        quick_sort(collection, p + 1, high);
    }
}

int partition(int* collection, int low, int high) {
    int pivot = *(collection + low);
    low -= 1;
    high += 1;
    while (1) {
        do {
            low += 1;
        } while (*(collection + low) < pivot);
        do {
            high -= 1;
        } while (*(collection + high) > pivot);
        if (low < high) {
            int temp = *(collection + low);
            *(collection + low) = *(collection + high);
            *(collection + high) = temp;
        } else {
            return high;
        }
    }
}

int main() {
    int x[] = {13, 53 , 5 ,2 ,77, 3, 2};
    quick_sort((int*) x, 0, 6);
    for (int i=0; i<7; i++) {
        printf("%i\n", x[i]);
    }
}