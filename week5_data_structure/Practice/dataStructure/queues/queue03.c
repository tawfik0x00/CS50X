#include <stdio.h>
#include <stdlib.h>

typedef struct Q
{
    int value;
    struct Q* next;
    struct Q* prev;
}
queue;

queue* enqueue(queue* q, int item);
queue* dequeue(queue* q);
void display(queue* q);
void free_queue(queue* q);

int dequeue_element = 0;

int main(void)
{
    queue* que = NULL;

    for (int i = 1; i <= 3; i++)
    {
        que = enqueue(que, i);
    }

    //display(que);
    // que = dequeue(que);
    printf("%i\n", dequeue_element);

    free_queue(que);
    free(que);

    // display(que);


}
queue* enqueue(queue* q, int item)
{
    queue* new = malloc(sizeof(queue));

    if (new == NULL)
    {
        return NULL;
    }

    new->value = item;
    new->next = NULL;
    new->prev = NULL;

    if (q == NULL)
    {
        q = new;
        return q;
    }
    else
    {
        for (queue* ptr = q; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                new->prev = ptr;
                ptr->next = new;
                break;
            }
        }
    }
    return q;
}
queue* dequeue(queue* q)
{
    if (q == NULL)
    {
        printf("queue is empty\n");
        return NULL;
    }
    else
    {
        queue* temp = q;
        dequeue_element = q->value;
        q->next->prev = NULL;
        q = q->next;
        free(temp);
        return q;
    }
    // this for stack not queue
    // for (queue *ptr = q; ptr != NULL; ptr = ptr->next)
    // {
    //     if (ptr->next == NULL)
    //     {
    //         value = ptr->value;
    //         ptr->prev->next = NULL;
    //         free(ptr);
    //         break;
    //     }
    // }


}
void display(queue* q)
{
    for (queue* ptr = q; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->value);
    }
    return;
}
void free_queue(queue* q)
{
   queue* ptr = q;
   while (ptr != NULL)
   {
        queue* hold = ptr;
        ptr->next->prev = NULL;
        ptr = ptr->next;
        free(hold);
   }
   return;
}