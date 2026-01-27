#include <stdio.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int is_empty();
int is_full();
void enqueue(int item);
int dequeue();
int peek();
void display();

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Peeked item: %d\n", peek());
    printf("Dequeued item: %d\n", dequeue());
    display();
    return 0;
}
int is_empty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}
int is_full()
{
    if (rear == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int item)
{
    if (is_full())
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = item;
    }
}
int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        int value = queue[front];
        front++;
        return value;
    }
}
int peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return queue[front];
}
void display()
{
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        printf("Queue elements are:\n");

        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}