#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    // prompt for string.
    string text = get_string("Message: ");

    // Get length of text
    int LENGTH = strlen(text);

    // Create array of length to save ascii values
    char DECIMAL_VALUES[LENGTH];
    
    // Save ascii values inside our array
    for (int i = 0; i < LENGTH; i++)
    {
        DECIMAL_VALUES[i] = (int)text[i];
    }

    //convert decimal to binary.
    char BINARY_VALUES[LENGTH][BITS_IN_BYTE];
    for (int i = 0; i < LENGTH; i++)
    {
        // to operate over every digit 8 times start from index n - 1 to save from right to left
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            // moduls 2
            BINARY_VALUES[i][j] = DECIMAL_VALUES[i] % 2;
            // devide by 2
            DECIMAL_VALUES[i] = DECIMAL_VALUES[i] / 2;
        }
    }

    //print bulbs
    for (int i = 0; i < LENGTH; i++)
    {
        //notes j is the index
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb((int)BINARY_VALUES[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
