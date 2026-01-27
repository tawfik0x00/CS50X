#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // each year we get n = n/3 - n/4 update n value every year.

    // TODO: Prompt for start size
    // Reprompt if start is less than 9 and ask user until enter a number greater than 9
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    // Reprompt if user enter end is less than start.
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    
    // TODO: Calculate number of years until we reach threshold
    // Create year counter to add 1 to it every year until reach our end size
    // every time we update our start size every time we in another year.
    int yearCounter = 0;

    while (start < end)
    {
        start += (start / 3) - (start / 4);
        yearCounter++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", yearCounter);

}
