#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Compare two elements */
typedef int (*CompareFunc)(const void *, const void *);


/* Swap two generic elements */
void swap(void *arr, size_t i, size_t j, size_t size) {
    unsigned char temp[size];

    memcpy(temp, (char *)arr + i * size, size);
    memcpy((char *)arr + i * size,
           (char *)arr + j * size, size);
    memcpy((char *)arr + j * size, temp, size);
}


/* Heapify down */
void heapify(void *arr, size_t i, size_t n,
             size_t size, CompareFunc compare) {

    size_t max = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n &&
        compare((char *)arr + left * size,
                (char *)arr + max * size) > 0) {
        max = left;
    }

    if (right < n &&
        compare((char *)arr + right * size,
                (char *)arr + max * size) > 0) {
        max = right;
    }

    if (max != i) {
        swap(arr, i, max, size);
        heapify(arr, max, n, size, compare);
    }
}


/* Build max heap */
void buildMaxHeap(void *arr, size_t n,
                  size_t size, CompareFunc compare) {

    for (int i = (int)n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n, size, compare);
    }
}


/* Generic Heap Sort */
void heapSort(void *arr, size_t n,
              size_t size, CompareFunc compare) {

    buildMaxHeap(arr, n, size, compare);

    for (size_t i = n - 1; i > 0; i--) {

        swap(arr, 0, i, size);

        heapify(arr, 0, i, size, compare);
    }
}


/* Comparator for integers */
int compareInt(const void *a, const void *b) {

    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;
    if (x < y)
        return -1;

    return 0;
}


/* Print integer array */
void printIntArray(int arr[], size_t n) {

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


int main() {

    int arr[] = {
        10, 5, 17, 20, 30,
        4, 1, 90, 8, 69
    };

    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    printIntArray(arr, n);

    heapSort(
        arr,
        n,
        sizeof(int),
        compareInt
    );

    printf("After sorting:\n");
    printIntArray(arr, n);

    return 0;
}
