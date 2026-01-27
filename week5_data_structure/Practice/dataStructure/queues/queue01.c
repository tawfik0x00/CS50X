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
    node *rear
}
queue;

int main()
{
    queue q;
}
void init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
int isEmpty(queue *q)
{
    return q->front == NULL;
}
void enqueue(queue *q, int item)
{
    node *new = malloc(sizeof(node));
    new->data = item;
    new->next = NULL;

    if (isEmpty(q))
    {
        q->front = new;
        q->rear = new;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
    }

}
int dequeu(queue *q)
{
    int item;
    node *temp;
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    temp = q->front;
    item = temp->data;
    q->front = temp->next;
    free(temp);
    return item;
}