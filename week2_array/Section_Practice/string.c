#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // string as typedef const *char string;
    string name = "mohamed";
    
    int length = strlen(name);

    for (int i = 0; i < length; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] -= 32;
        }
    }

    printf("%s\n", name);
}