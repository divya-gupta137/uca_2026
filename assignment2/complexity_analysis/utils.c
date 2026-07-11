#include <stdlib.h>
#include <time.h>
#include "sorting.h"

void generateRandom(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}
