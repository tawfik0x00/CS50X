#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *pdf = fopen(argv[1],"r");

    if (pdf == NULL)
    {
        printf("Can't open that file\n");
        return 2;
    }

    uint8_t buffer[4];

    fread(buffer,1,4,pdf);

    uint8_t segnature[] = {37, 80, 68, 70};

    for (int i = 0; i < 4; i++)
    {
        if (segnature[i] != buffer[i])
        {
            printf("Invalid file\n");
            fclose(pdf);
            return 3;
        }
    }

    fclose(pdf);
    return 0;
}