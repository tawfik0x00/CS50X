#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));

    //*x = 72;
    //*(x + 1) = 73;
    //*(x + 2) = 33; // + 1 mean location not byte.
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
    return 0;

}