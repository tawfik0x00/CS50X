#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_row(int sapces, int bricks);

int main(void)
{
    // first take the height of the pyramid
    int height = get_height("Height: ");

    // start printing the pyramid
    for (int row = 1; row <= height; row++)
    {
        // print every row
        print_row(height - row, row);
    }
}
int get_height(string prompt)
{
    int height;
    do
    {
        height = get_int("%s", prompt);
    }
    while (height < 1 || height > 8);
    return height;
}
void print_row(int spaces, int bricks)
{
    // first print the spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // print the bricks of first pyramid
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    // print the spaces between the two pyrmaids
    printf("  ");
    // print the bricks of the second pyramid
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    // take new line
    printf("\n");
}
