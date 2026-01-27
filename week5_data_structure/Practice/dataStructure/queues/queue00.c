#include <stdio.h>
// queue using array
#define MAX_SIZE 10

int queue[MAX_SIZE];

int front = -1;
int rear = -1;

int isEmpty();
int isFull();
void enqueue(int item);
int dequeue();
void display();
int peek();

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Peeked item: %d\n", dequeue());
    display();
}
int isEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if (rear == MAX_SIZE -1)
        return 1;
    return 0;
}
void enqueue(int item)
{

    if (isFull())
    {
        printf("queue overflow\n");
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
    if (isEmpty())
    {
        printf("queue is empty.\n");
        return -1;
    }

    int value = queue[front];
    front++;
    return value;
}
int peek()
{
    if (isEmpty())
    {
        printf("queue is empty.\n");
        return -1;
    }

    return queue[front];
}
void display()
{
    if (isEmpty())
    {
        printf("queue is empty.\n");
        return;
    }

    printf("Queue elements are:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%i ", queue[i]);
    }

    printf("\n");
}
