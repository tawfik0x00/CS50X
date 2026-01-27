#include <stdio.h>

void swap(int *x, int *y)//x and y are pointers
{
    int temp = *x;//dereference work with values
    *x = *y;
    *y = temp;
}

int main(void)
{
    int x = 5;
    int y = 10;
    swap(&x, &y);//pass address ov variable.
    printf("x: %i\n", x);
    printf("y: %i\n", y);
}