#include <stdio.h>
#include <cs50.h>

int fib(int x);

int main(void)
{
    int x = get_int("fib_number: ");
    printf("%i\n",fib(x));
}
int fib(int x)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    else
        return fib(x - 1) + fib(x - 2);
}