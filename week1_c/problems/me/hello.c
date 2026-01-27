#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get the user name
    string name = get_string("What's your name? ");
    // print to the screen hello + name
    printf("Hello, %s\n", name);
}

