#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // base case
    if (input[1] == '\0')
    {
        return input[0] - '0';
    }

    // get the length
    int length = strlen(input);
    // get the last digit
    int last_digit = input[length - 1] - '0';
    // remove the last digit
    input[length - 1] = '\0';
    // recursive case
    return 10 * convert(input) + last_digit;
}
