#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *names = fopen(argv[1], "r"); // to open the file w=write, r=read, a= append.

    // check the file opend
    if (names == NULL)
    {
        return 1;
    }

    // read and write to the stdout.
    char ch;
    while ((ch = fgetc(names)) != EOF)
    {
        printf("%c", ch);
    }

    printf("\n");

    fclose(names); // to close our file
}