#include <stdio.h>
#include <cs50.h>

int fact(int n);

int main(void)
{
    int number = get_int("Factorial of: ");
    printf("%i\n",fact(number));
}
int fact(int n)
{
    if ( n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
