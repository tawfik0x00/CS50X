#include <stdio.h>
/*
Linear Search
*/
int linearSearch(int arr[], int number, int length);

int main(void)
{
    const int size = 5;
    int arr[] = {10, 20, 30, 40, 50};
    int number = 20;

    int result = linearSearch(arr, number, size);

    if (result != -1)
    {
        printf("%i found at index %i\n", number, result);
    }
    else
    {
        printf("%i not found\n", number);
    }

}
int linearSearch(int arr[], int number, int length)
{
    /*
    Input: takes arr[] of type int, number of type int
    ouput: should return index if found, -1 if not found
    */
    /*
        for each door from left to right:
            if 50 is behind the door:
                return true

        return false
    */

    /*
        For i from 0 to n - 1:
            If 50 is behind door[i]:
                Return true
        Return false
   */

    // we can abstract this algorithm into function.

    // we need to determine size of an array


    for (int i = 0; i < length; i++)
    {
        if (arr[i] == number)
        {
            return i;
        }
    }

    return -1;
}
