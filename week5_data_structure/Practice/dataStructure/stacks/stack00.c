#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int is_full();
int is_empty();
void push(int item);
int pop();
int peek();

int main(void)
{
    // Push some elements onto the stack
   push(10);
   push(20);
   push(30);

   // Print the top element of the stack
   printf("Top element of the stack: %d\n", peek());

   // Pop an element from the stack
   pop();

   // Print the top element of the stack again
   printf("Top element of the stack: %d\n", peek());

   // Check if the stack is empty
   if (is_empty()) {
      printf("The stack is empty\n");
   } else {
      printf("The stack is not empty\n");
   }

   // Check if the stack is full
   if (is_full()) {
      printf("The stack is full\n");
   } else {
      printf("The stack is not full\n");
   }

   return 0;
}
int is_empty()
{
    return top == -1;
}
int is_full()
{
    return top == MAX_SIZE - 1;
}
void push(int item)
{
    // secure my code
    // check if is full
    if (is_full())
    {
        printf("stack overflow.\n");
        return;
    }
    // add element to stack.
    top++;
    stack[top] = item;
}
int pop()
{
    // check if is empty
    if (is_empty())
    {
        return -1;
    }

    int data = stack[top];
    top--;
    return data;
}
int peek()
{
    if (is_empty())
    {
        return -1;
    }
    return stack[top];
}
