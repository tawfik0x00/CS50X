#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_row(int spaces, int bricks);

int main(void)
{
    // get the height of the pyramid
    int height = get_height("Height: ");

    // start print the pyramid
    for (int i = 1; i <= height; i++)
    {
        // print every row in the pyramid
        print_row(height - i, i);
    }
}
int get_height(string prompt)
{
    int n;
    // while the values less than 1 re-prompt the user
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1);
    // return the value
    return n;
}
void print_row(int spaces, int bricks)
{
    // first print the spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // print the bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    // take a new line
    printf("\n");
}
