#ifndef SORTING_H
#define SORTING_H

void bubbleSort(int arr[], int n);

void insertionSort(int arr[], int n);

void selectionSort(int arr[], int n);

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

void generateRandom(int arr[], int n);
void generateAscending(int arr[], int n);
void generateDescending(int arr[], int n);

#endif
