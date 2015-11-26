#include <stdio.h>

void bubble_sort(int* collection, int length) {
    int temp;
    for (int _ = 0; _ < length; _++) {
        for (int index=0; index < length - 1; index ++) {
            if (*(collection + index) > *(collection + index + 1)) {
                temp = *(collection + index);
                *(collection + index) = *(collection + index + 1);
                *(collection + index + 1) = temp;
            }
        }
    }
}

int main() {
    int x[] = {12, 35 ,22 , 34, 2355, 12 ,5};
    bubble_sort((int*) x, 7);
    for (int i=0; i<7; i++) {
        printf("%i\n", x[i]);
    }
}