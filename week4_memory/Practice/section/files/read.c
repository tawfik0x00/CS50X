#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s + file\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("file didn't exist\n");
        fclose(input);
        return 1;
    }

    char read_buffer[4];
    fread(read_buffer, 1, 3, input);
    read_buffer[3] = '\0';// the null terminator for printf to stop printing.
    printf("%s\n", read_buffer);

    fclose(input);
    return 0;

}