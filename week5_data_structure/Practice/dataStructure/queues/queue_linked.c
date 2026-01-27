#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
node;

typedef struct
{
    node *front;
    node *rear;
}
queue;
// initialize
void init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(queue *q)
{
    // will return 1 if is true and 0 if is false;
    return q->front == NULL;
}

void enqueue(queue *q, int item)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = item;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->reqr = new_node;
    }
}