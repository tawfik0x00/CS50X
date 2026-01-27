#include <stdio.h>
#include <stdlib.h>

#define CAP 100

typedef struct
{
    char *name;
    char *number;
}
person;

typedef struct
{
    person people[CAP];
    int size;
}
stack;

void init_stack(stack *s);
int push(stack *s, char* name, char *number);
void print_stack(stack *s);
person pop(stack *s);

int main(void)
{
    // define an empty stack
    stack st;

    init_stack(&st);

    push(&st, "Alice", "555-1234");
    push(&st, "Bob", "555-5678");
    push(&st, "Charlie", "555-8765");

    // print the stack
    printf("Stack after pushing three people:\n");

    print_stack(&st);

    // pop a person off the stack
    person p = pop(&st);
    printf("\n Popped: Name: %s, Number: %s\n", p.name, p.number);

    printf("\nStack after popping one person:\n");
    print_stack(&st);




}
void init_stack(stack *s)
{
    s->size = 0;
}
int push(stack *s, char *name, char *number)
{
    if (s->size >= CAP)
    {
        printf("STACK IS FULL\n");
        return -1;
    }

    s->people[s->size].name = name;
    s->people[s->size].number = number;
    s->size++;
    return 0;
}

void print_stack(stack *s)
{
    for (int i = s->size - 1; i >= 0; i--)
    {
        printf("Name: %s, Number: %s\n", s->people[i].name, s->people[i].number);
    }
}

person pop(stack *s)
{
    if (s->size == 0)
    {
        printf("Stack is empty!\n");
        person empty = {NULL, NULL};
        return empty;
    }

    s->size--;
    return s->people[s->size];
}
