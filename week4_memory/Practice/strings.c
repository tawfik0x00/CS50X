#include <stdio.h>
//#include <cs50.h>

//typedef char* string;
// string was a pointer to a character
// for any language string keyword mean just a sequence of characters.

int main(void)
{
    char* s = "HI!";

    //printing locations addresses.
    printf("\tprint address use &name[]\n");
    printf("print address of s[0]: %p\n", &s[0]);
    printf("print address of s[1]: %p\n", &s[1]);
    printf("print address of s[2]: %p\n", &s[2]);
    printf("print address of s[3] the null character: %p\n", &s[3]);
    printf("\n");

    // every thing free in c language this print the address of pointers &s[index], or like (s + location).
    printf("\t print address using pointer arithmatics &(*(name + location)) the same way of &name[] [] == *()\n");
    printf("print address of s: %p\n", &(*(s)));
    printf("print address of s + 1: %p\n", &(*(s+1)));
    printf("print address of s + 2: %p\n", &(*(s+2)));
    printf("print address of s + 3: %p\n", &(*(s+3)));
    printf("\n");

    //start printint string from the point we give it to printf
    printf("\tprinting strings and substring starting from various location using pointer arithmatic [(name) (name + 1)]\n");
    printf("print string start from 0: %s\n", s);
    printf("print string start from 1: %s\n", s+1);
    printf("print string start from 2: %s\n", s+2);
    printf("\n");

    //shorts for *(s), *(s + 1), *(s + 2).
    printf("print one char from string using name[location], the same way for *(name + location)\n");
    printf("print character 0: %c\n", s[0]);
    printf("print character 1: %c\n", s[1]);
    printf("print character 2: %c\n", s[2]);
    printf("\n");

    //arithmatic operation values in pointers + 1 mean location, s[0], s[1], s[2].
    printf("%c\n", *(s));
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("\n");

    //print the address of some addresses like &s[0], &s[1], &s[2].
    printf("%p\n", s);
    printf("%p\n", s+1);
    printf("%p\n", s+2);


}