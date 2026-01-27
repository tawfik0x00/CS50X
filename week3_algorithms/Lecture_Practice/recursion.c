#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}
void draw(int n)
{
    // base case
    if (n <= 0)
    {
        return;
    }
    else
    {
        // recursive case
        draw(n - 1);
        // action will start when reach base case
        for (int i = 0; i < n; i++)
        {
            printf("#");
        }

        printf("\n");
    }
}