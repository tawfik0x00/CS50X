#include <stdio.h>

void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void swap(int *a, int *b);

int  main(void)
{
    const int size = 10;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("Array before sorting.\n");
    printArray(arr, size);
    printf("Array after sorting.\n");
    bubbleSort(arr, size);
    printArray(arr, size);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[], int n)
{
    /*
    Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    If no swaps
        Quit
    */
    for (int i = 0; i < n - 1; i++)
    {
        int swp = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swp++;
            }
        }

        if (swp == 0)
            break;
    }
}
