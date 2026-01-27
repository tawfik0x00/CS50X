#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user input, make sure it's postive
    int length;
    do
    {
        length = get_int("Size of array: ");
    }
    while (length < 1);

    // Declare our array
    int array[length];

    // Initialize the first value of the array
    array[0] = 1;

    // Print the first value
    printf("%i\n", array[0]);
    
    for (int i = 1; i < length; i++)
    {
        array[i] = array[i-1] * 2;
        printf("%i\n", array[i]);
    }
}