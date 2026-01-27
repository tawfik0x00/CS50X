#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // list of size 3
    int *list = malloc(sizeof(int) * 3);
    if (list == NULL)
        return 1;

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // list of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp = NULL)
    {
        free(list);
        return 1;
    }

    // copy list of size 3 into list of size4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    tmp[3] = 4;
    free(list);
    list = tmp;

    // print the list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
