#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *top = NULL;
int L = 0;

void push(int value);
int pop();

int main(void)
{
    for (int i = 1; i <= 20; i++)
    {
        push(i);
    }
    for (int i = 0; i < L; i++)
    {
        printf("%i\n", pop());
    }
}
void push(int value)
{
    node *new_node = malloc(sizeof(node));

    new_node->number = value;
    new_node->next = top;
    top = new_node;
    L++;
}
int pop()
{
    // check if is empty
    if (top == NULL)
    {
        printf("stack is empty\n");
        return -1;
    }

    // to hold node top points to it to remove after change top pointing
    node *hold_remove = top;
    int value = hold_remove->number;
    top = top->next;
    free(hold_remove);
    return value;
}
int peek()
{
    if (top == NULL)
    {
        return -1;
    }

    return top->number;
}
int isEmpty()
{
    return top == NULL;
}
// we don't need function to check if is full because its grow dynamically