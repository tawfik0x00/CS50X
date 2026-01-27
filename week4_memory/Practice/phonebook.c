#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    FILE *pointer = fopen("tawfik.csv", "a");

    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(pointer, "%s,%s\n", name, number);

    fclose(pointer);
}
