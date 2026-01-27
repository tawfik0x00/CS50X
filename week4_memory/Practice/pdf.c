#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s + filename\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Can't open this file\n");
        return 1;
    }

    uint8_t buffer[4];

    fread(buffer, 1, 4, input);

    if (buffer[0] == 37 && buffer[1] == 80 && buffer[2] == 68 && buffer[3] == 70)
    {
        printf("PDF File\n");
    }
    else
    {
        printf("Not PDF File\n");
    }

    fclose(input);
    return 0;
}