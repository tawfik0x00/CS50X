#include <stdio.h>

int main(void)
{
    // & ampersand is get the address of the piece of memory
    // * asterisk is used to define a pointer and go to address and get value.
    // %p print address of pointer or address of any type.
    // * with printf is used to reverse the process and get value saved in place.

    int n = 50;
    int *p_n = &n;
    printf("address of n: %p\n", &n);
    printf("value of p_n: %p\n", p_n);
    printf("address of p_n: %p\n", &p_n);
    int *p2_n = p_n;
    printf("value of p2_n: %p\n", p2_n);
    printf("go to the address inside p_n: %i\n", *p_n);
    printf("go to the address inside p2_n: %i\n", *p2_n);
    

}