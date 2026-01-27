#include <stdio.h>

int main(int argc, char *argv[])
{
    //check inputs
    if (argc != 3)
    {
        printf("Usage: %s + filename1 filename2\n", argv[0]);
        return 1;
    }
    //remmember file name
    char *infile = argv[1];
    char *outfile = argv[2];
    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    //open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not creat %s.\n", outfile);
        return 3;
    }
    //read infile's BITMAPFILEHEADER 14 BYTE.
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    //read infile's BITMAPINFOHEADER 40 BYTE.
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }
}