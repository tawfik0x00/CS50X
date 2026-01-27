#include <stdio.h>

#define MAX 10
int stack[MAX];
int top = -1;

void push(int element);
int pop();
int peek();
int isEmpty();
int isFull();

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", pop());
    }

    if (isEmpty())
    {
        printf("empty stack\n");
    }
}

void push(int element)
{
    // if top == last indx of my stack array return error message overflow.
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    // increment top to move into next place to save my value
    top++;
    // save my element in indx top now top is the last element in stack
    stack[top] = element;
}
int pop()
{
    // check if stack is empty
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    // get the last element
    int element = stack[top];
    // remove last element
    top--;
    return element;
}
int peek()
{
    // check if stack is empty
    if (top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    // return top element of the stack
    return stack[top];
}
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX - 1;
}
