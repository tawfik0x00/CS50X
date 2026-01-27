// we need to understand this algorithm
#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);
void printArray(int arr[], int n);

int main(void)
{
    const int size = 10;
    int arr[] = {9, 8, 7, 6};
    printf("Array before sorting.\n");
    printArray(arr, size);
    printf("Array after sorting.\n");
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);

}
void mergeSort(int arr[], int left, int right)
{
    /*
    If only one number
        Quit
    Else
        Sort left half of number
        Sort right half of number
    Merge sorted halves

    */
    // if left >= right the array is olredy sorted its have onle one element.
    // we doesn't do any thing
    if (left < right)
    {
        // calculate the middle point of this array.
        int mid = left + (right - left) / 2;

        // sort left half
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // after two array sorted or reach one element for each.
        // we merge them
        merge(arr, left, mid, right);

    }
}
void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1; // size of left array
    int n2 = right - middle; // size of right array

    // temporary array
    int L[n1], R[n2];

    // copy data to Left temp array
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    // copy data to right temp array.
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[middle + 1 + i];
    }

    // Merge temp array to original array
    int i = 0, j = 0;
    int k = left; // for original array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining element of left if any
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    // copy remaining elements of right if any
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
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
