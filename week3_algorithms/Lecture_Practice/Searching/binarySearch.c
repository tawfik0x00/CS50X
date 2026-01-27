#include <stdio.h>

int binarySearchIter(int arr[], int start, int end, int number);
int binarySearchRec(int arr[], int start, int end, int number);

int main(void)
{
    const int size = 5;
    int arr[] = {10, 20, 30, 40, 50};
    int number1 = 20;
    int number2 = 100;

    int result1 = binarySearchIter(arr, 0, size - 1, number1);
    if (result1 != -1)
    {
        printf("%i found at index %i\n", number1, result1);
    }
    else
    {
        printf("%i not found.\n", number1);
    }

    int result2 = binarySearchIter(arr, 0, size - 1, number2);
    if (result2 != -1)
    {
        printf("%i found at index %i\n", number2, result2);
    }
    else
    {
        printf("%i not found.\n", number2);
    }

    int number3 = 40;
    int result3 = binarySearchRec(arr, 0, size - 1, number3);
    if (result3 != -1)
    {
        printf("%i found at index %i\n", number3, result3);
    }
    else
    {
        printf("%i not found.\n", number3);
    }

    int number4 = 101;
    int result4 = binarySearchRec(arr, 0, size - 1, number4);
    if (result4 != -1)
    {
        printf("%i found at index %i\n", number4, result4);
    }
    else
    {
        printf("%i not found\n", number4);
    }

    return 0;
}
int binarySearchIter(int arr[], int start, int end, int number)
{
    /*
        If no doors left
            Return false
        If 50 is behind middle door
            Return true
        Else if 50 < middle door
            Search left half
        Else if 50 > middle door
            Search right half
    */

    /*
        If no doors left
            Return false
        If 50 is behind door[middle]
            Return true
        If 50 is < doors[middle]
            Search doors[0] through doors[middle - 1]
        If 50 > doors[middle]
            Search doors[middle + 1] through doors[n - 1]
   */

    // we need to calculate middle
    // we need to know when to stop search

    // while start <= end
    while (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (arr[middle] == number)
        {
            return middle;
        }
        else if (number < arr[middle])
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return -1;

}
int binarySearchRec(int arr[], int start, int end, int number)
{
    // check to continute search or stop
    if (start <= end)
    {
        // calculate middle
        int middle = start + (end - start) / 2;

        // if number found return index
        if (number == arr[middle])
        {
            return middle;
        }
        else if (number < arr[middle])
        {
            return binarySearchRec(arr, start, middle - 1, number);
        }
        else
        {
            return binarySearchRec(arr, middle + 1, end, number);
        }
    }

    // if not stop
    return -1;
}
