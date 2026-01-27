#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(sizeof(int));
    int *y = NULL;
    y = x;
    *x = 5;

    printf("%i \t %i\n", *x, *y);
    free(x);
}