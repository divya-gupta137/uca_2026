#include <stdio.h>

void heapify (int arr[], int i, int n) {
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if( left < n && arr[i] < arr[max]) {
        max = left;
    }
    if (right < n && arr[i] < arr[max]) {
        max = right;
    }
    if(max != i) {
        swap(arr, i, max);
        heapify(arr, max, n);
    }
}

void swap (int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sorting(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i);
    }
}


int main() {
    int arr[] = {10, 5, 17, 20, 30, 4, 1, 90, 8, 69};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before heap: ");
    printHeap(arr, n);

    buildMaxHeap(arr, n);

    printf("After heapify: ");
    printHeap(arr, n);

    printf("Now sorting: ");
    sorting(arr, n);

    printHeap(arr, n);

    return 0;
}


