#include <stdio.h>
#include <cs50.h>

void bubbleSort(int arr[], int size);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%i\n", arr[i]);
    }
}
void bubbleSort(int arr[], int size)
{
    // bubble sort
    for (int pass = 0; pass < size - 1; pass++)
    {
        int swap = 0;
        // steps
        for (int step = 0; step < size - 1 - pass; step++)
        {
            if (arr[step] > arr[step + 1])
            {
                int temp = arr[step];
                arr[step] = arr[step + 1];
                arr[step + 1] = temp;
                swap = 1;
            }
        }
        // if no swaps
        if (swap == 0)
        {
            return;
        }
    }
}
