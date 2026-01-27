#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

typedef struct
{
    int array[CAPACITY];
    int front;
    int size;
}
queue;

void enqueue(queue *q, int item);

int main(void)
{
    // define new queue.
    queue q;
    q.front = -1;
    q.size = -1;

    enqueue(&q, 5);
    enqueue(&q, 6);

    printf("%i\n", q.array[0]);
    printf("%i\n", q.array[1]);
}

void enqueue(queue *q, int item)
{
    if (q->size == CAPACITY - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->size++;
    q->array[q->size] = item;

    return;

}
int dequeue(queue* q)
{
    if (q->front == -1)
    {
        printf("empty\n");
        return -1;
    }

    int value = q->array[q->front];
    q->front++;
    return value;
}