#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }
    // open file1
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL)
    {
        return 1;
    }

    FILE *file2 = fopen(argv[2], "w");
    if (file2 == NULL)
    {
        return 1;
    }

    char c;

    while ((c = fgetc(file1)) != EOF)
    {
        fputc(c, file2);
    }

    fclose(file1);
    fclose(file2);

}