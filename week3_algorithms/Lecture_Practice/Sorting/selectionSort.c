/*
Selection Sort
*/
#include <stdio.h>

void selectionSort(int arr[], int n);
void printArray(int arr[], int n);
void swap(int *a, int *b);

int main(void)
{
    const int size = 10;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("Array before sorting.\n");
    printArray(arr, size);
    printf("Array after sorting.\n");
    selectionSort(arr, size);
    printArray(arr, size);

}
void selectionSort(int arr[], int n)
{
    /*
    For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
    */
   
    //  أول لوب بتتكر عشان ترتب العناصر
    // loop to the second last element the last element doesn't need to be checked
    for (int i = 0; i < n - 1; i++)
    {
        // define min_indx as i were i is the first element of unsorted part
        int min_indx = i;
        // start find smallest element and compare
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_indx])
            {
                min_indx = j;
            }
        }
        // swapt smallest element with first element for unsorted part
        swap(&arr[i], &arr[min_indx]);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
