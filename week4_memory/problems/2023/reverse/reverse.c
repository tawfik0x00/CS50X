#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: %s + file_input file_output\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "rb");

    if (input == NULL)
    {
        printf("failed to open the file %s\n", argv[1]);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Invalid format\n");
        return 1;
    }

    if (header.audioFormat != 1)
    {
        printf("Invalid format\n");
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Can't create %s\n", argv[2]);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8f

    // we need buffer to save our block
    // 1 block is array of bytes of particular size
    BYTE block[size];// this where will save the block

    // now we need to move the pointer to the end of the file

    // we need to pint after the end of the file by 4 bytes
    if (fseek(input, size, SEEK_END))
    {
        return 1;
    }

    while (ftell(input) - size > sizeof(header))
    {
        if (fseek(input, -2 * size, SEEK_CUR))
        {
            return 1;
        }

        fread(&block, size, 1, input);
        fwrite(&block, size, 1, output);
    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
   return header.numChannels * (header.bitsPerSample / 8);
}