#include <stdio.h>

int main(void)
{
    int x = 50;
    int *pointer = &x;

    printf("go to value inside pointer: %i\n", *pointer);
    printf("value of pointer is address: %p\n", pointer);
    printf("address of x variable is: %p\n", &x);
    printf("the address of the pointer: %p\n", &pointer);
    printf("\n");

    // create pointer to save address of another pointer.
    int **NewPointer = &pointer;
    printf("the address of pointer: %p\n", &pointer);
    printf("the value inside the pointer of pointer: %p\n", NewPointer);
    printf("\n");

    printf("the value inside pointer by NewPointer: %p\n", *NewPointer);
    printf("the value of pointer: %p\n", pointer);
    printf("\n");

    printf("value of x: %d\n", x);
    printf("go to the address in pointer and get the value: %d\n", *pointer);
    printf("go to the address inside this pointer and go the address inside this location and get the value: %d\n", **NewPointer);

}