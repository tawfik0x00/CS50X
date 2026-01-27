#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("%c", argv[i][0]);
    }
    printf("\n");
}