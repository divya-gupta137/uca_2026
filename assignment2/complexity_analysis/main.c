#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

int main()
{
    srand(time(NULL));

    int size;
    int i;

    printf("Execution Time Analysis (milliseconds)\n\n");

    for(size = START_SIZE; size <= START_SIZE + STEP_SIZE * (ITERATIONS - 1); size += STEP_SIZE)
    {
        printf("\n===============================\n");
        printf("Array Size = %d\n", size);
        printf("===============================\n");

        int *original = (int *)malloc(size * sizeof(int));
        int *temp = (int *)malloc(size * sizeof(int));

        if(original == NULL || temp == NULL)
        {
            printf("Memory Allocation Failed\n");
            return 1;
        }

        /* ---------------- RANDOM INPUT ---------------- */

        printf("\nRandom Array\n");

        generateRandom(original, size);

        memcpy(temp, original, size * sizeof(int));
        clock_t start = clock();
        bubbleSort(temp, size);
        clock_t end = clock();
        printf("Bubble Sort      : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size * sizeof(int));
        start = clock();
        insertionSort(temp, size);
        end = clock();
        printf("Insertion Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size * sizeof(int));
        start = clock();
        selectionSort(temp, size);
        end = clock();
        printf("Selection Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size * sizeof(int));
        start = clock();
        quickSort(temp,0,size-1);
        end = clock();
        printf("Quick Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size * sizeof(int));
        start = clock();
        mergeSort(temp,0,size-1);
        end = clock();
        printf("Merge Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size * sizeof(int));
        start = clock();
        heapSort(temp,size);
        end = clock();
        printf("Heap Sort        : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);



        /* ---------------- ASCENDING ---------------- */

        printf("\nAscending Array\n");

        generateAscending(original,size);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        bubbleSort(temp,size);
        end = clock();
        printf("Bubble Sort      : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        insertionSort(temp,size);
        end = clock();
        printf("Insertion Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        selectionSort(temp,size);
        end = clock();
        printf("Selection Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        quickSort(temp,0,size-1);
        end = clock();
        printf("Quick Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        mergeSort(temp,0,size-1);
        end = clock();
        printf("Merge Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        heapSort(temp,size);
        end = clock();
        printf("Heap Sort        : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);



        /* ---------------- DESCENDING ---------------- */

        printf("\nDescending Array\n");

        generateDescending(original,size);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        bubbleSort(temp,size);
        end = clock();
        printf("Bubble Sort      : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        insertionSort(temp,size);
        end = clock();
        printf("Insertion Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        selectionSort(temp,size);
        end = clock();
        printf("Selection Sort   : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        quickSort(temp,0,size-1);
        end = clock();
        printf("Quick Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        mergeSort(temp,0,size-1);
        end = clock();
        printf("Merge Sort       : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        memcpy(temp, original, size*sizeof(int));
        start = clock();
        heapSort(temp,size);
        end = clock();
        printf("Heap Sort        : %.2f ms\n",
               ((double)(end-start))*1000/CLOCKS_PER_SEC);

        free(original);
        free(temp);
    }

    return 0;
}
