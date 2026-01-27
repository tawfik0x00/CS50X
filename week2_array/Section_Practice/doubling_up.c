#include <stdio.h>

int main(void)
{
    const int size = 5;
    int arr[size];

    arr[0] = 1;

    for (int i = 1; i < size; i++)
    {
        arr[i] = arr[i - 1] * 2;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%i\n", arr[i]);
    }
}