#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

typedef struct
{
    char *name;
    char *number;
}
person;

typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;

void init_stack(stack *s)
{
    s->size = 0;
}

int push(stack *s, char *name, char *number)
{
    if (s->size >= CAPACITY)
    {
        printf("Stack is full!\n");
        return -1;
    }

    s->people[s->size].name = strdup(name);
    s->people[s->size].number = strdup(number);
    s->size++;
    return 0;
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
    person p = s->people[s->size];

    free(p.name);
    free(p.number);

    return p;
}

void print_stack(stack *s)
{
    for (int i = 0; i < s->size; i++)
    {
        printf("Name: %s, Number: %s\n", s->people[i].name, s->people[i].number);
    }
}
int main(void)
{
    // create a an empty stack
    stack s;

    // initialize the stack
    init_stack(&s);

    push(&s, "Alice", "555-1234");
    push(&s, "Bob", "555-5678");
    push(&s, "Charlie", "555-8765");

    // print the stack
    printf("Stack after pushing three people:\n");

    print_stack(&s);

    // pop a person off the stack
    person p = pop(&s);
    printf("\n Popped: Name: %s, Number: %s\n", p.name, p.number);

    printf("\nStack after popping one person:\n");
    print_stack(&s);

    // free memory
    for (int i = 0; i < s.size; i++)
    {
        free(s.people[i].name);
        free(s.people[i].number);
    }

    return 0;
}
