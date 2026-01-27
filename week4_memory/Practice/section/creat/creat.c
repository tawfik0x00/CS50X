#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //check argument.
    if (argc != 2)
    {
        printf("Wrong usage: Try ./create [filename]\n");
        return 1;
    }

    //get length of filename
    int filename_length = strlen(argv[1]);
    char  *filename = malloc(sizeof(char) * (filename_length + 1));

    if (filename == NULL)
    {
        return 1;
    }

    //write chars to new filename location.
    sprintf(filename, "%s", argv[1]);

    //open new file.
    FILE *new_file = fopen(filename, "w");

    if (new_file == NULL)
    {
        printf("Could not create file.'n");
        free(filename);
        fclose(new_file);
        return 1;
    }

    free(filename);
    fclose(new_file);
    return 0;

}