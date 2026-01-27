#include <stdio.h>
void draw(int n);
int main(void)
{
    draw(8);
}
void draw(int n)
{
    if (n <= 0)
        return;
    else
    {
        draw(n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}