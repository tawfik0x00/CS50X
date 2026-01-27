#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // get the minimum number to start
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // get the max to end if max less than or equal to min reprompt
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // start check number from min to max if prime print
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number == 1)
    {
        return false;
    }

    for (int factor = 2; factor < number; factor++)
    {
        // if we find any number give remainder of 0 mean this number divisble by number
        // other than 1 and itself because we start at 2 and end before the number.
        if (number % factor == 0)
        {
            return false;
        }
    }

    return true;
}
