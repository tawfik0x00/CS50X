#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    char* s = get_string("s: ");

    if (s == NULL)
    {
        return 1;
    }

    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }

    char* t = malloc(l+1);

    if (t == NULL)
    {
        return 1;
        free(t);
    }

    // + 1 for nul chars buffer overflow
    sprintf(t, "%s", s);

    int lt = 0;
    while (t[lt] != '\0')
    {
        lt++;
    }

    if (lt > 0)
    {
        t[0] = t[0] - 32;
    }


    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("s: %p\n", s);
    printf("t: %p\n", t);

    free(t);
    return 0;
}