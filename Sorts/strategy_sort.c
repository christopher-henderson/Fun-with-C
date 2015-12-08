#include <stdio.h>

void sort(int*, unsigned int, int(*)(int, int));
void insertion_sort(int*, unsigned int, int(*)(int, int));
void quick_sort(int*, unsigned int, unsigned int, int(*)(int, int));
int partition(int*, unsigned int, unsigned int, int(*)(int, int));
void swap(int*, int, int);
int given_comp(int, int);

void sort(int* collection, unsigned int size, int(*comp)(int, int)) {
    if (size < 20) {
        insertion_sort(collection, size, comp);
    } else {
        quick_sort(collection, 0, size - 1, comp);
    }
}

void swap(int* collection, int left, int right) {
    int temp = *(collection + left);
    *(collection + left) = *(collection + right);
    *(collection + right) = temp;
}

void insertion_sort(int* collection, unsigned int size, int(*comp)(int, int)) {
    int j;
    int temp;
    for (int i = 0; i < size; i++) {
        for (j = i; j > 0 && comp(*(collection + j), *(collection + j - 1)); j--) {
            swap(collection, j - 1, j);
        }
    }
}

void quick_sort(int* collection, unsigned int low, unsigned int high, int(*comp)(int, int)) {
    if (low < high) {
        int p = partition(collection, low, high, comp);
        quick_sort(collection, low, p, comp);
        quick_sort(collection, p + 1, high, comp);
    }
}

int partition(int* collection, unsigned int low, unsigned int high, int(*comp)(int, int)) {
    int temp;
    int pivot = *(collection + low);
    low--;
    high++;
    while (1) {
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

int given_comp(int a, int b) {
    return a > b;
}

int main() {
    int x[] = {4, 8, 2, 5, 2, 2, 34, 89, 3, 90};
    int y[] = {4, 8, 2, 5, 2, 2, 34, 89, 3, 90, 4, 8, 2, 5, 2, 2, 34, 89, 3, 90, 4, 8, 2, 5, 2, 2, 34, 89, 3, 90};
    sort(x, 10, given_comp);
    sort(y, 30, given_comp);
    for (int i = 0; i < 10; i++) {
        printf("%i, ", x[i]);
    }
    printf("\n");
    for (int i = 0; i < 30; i++) {
        printf("%i, ", y[i]);
    }
    printf("\n");
}