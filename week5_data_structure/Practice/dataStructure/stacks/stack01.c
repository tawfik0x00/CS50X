#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

node *top = NULL;

void push(int item);
int pop();
int peek();
int isEmpty();

int main(void)
{
   push(10);
   push(20);
   push(30);

   // Print the top element of the stack
   printf("Top element of the stack: %d\n", peek());

   // Pop an element from the stack
   pop();

   // Print the top element of the stack again
   printf("Top element of the stack: %d\n", peek());
}

void push(int item)
{
    node *new = malloc(sizeof(node));

    new->value = item;
    new->next = top;

    top = new;
}
int pop()
{
    if (isEmpty())
    {
        printf("stack is empty.\n");
        return -1;
    }

    node *pop = top;
    int value = pop->value;
    top = top->next;

    free(pop);
    return value;
}
int peek()
{
    if (isEmpty())
    {
        printf("stack is empty.\n");
    }

    return top->value;
}
int isEmpty()
{
    return top == NULL;
}