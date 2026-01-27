#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string phrase = get_string("Pharse: ");

    for (int i = 0, n = strlen(phrase); i < n - 1; i++)
    {
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order!\n");
            return 0;
        }
    }

    printf("In alphabetical order!\n");
    return 0;
}