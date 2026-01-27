#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // itrate over every row of pixels
    for (int row = 0; row < height; row++)
    {
        // itrate over every column every single pixel
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixel = image[row][column];

            if (pixel.rgbtBlue == 0x00 && pixel.rgbtGreen == 0x00 && pixel.rgbtRed == 0x00)
            {
                image[row][column].rgbtRed = 0xff; // change our red colour in my pixel
            }
        }
    }
}
