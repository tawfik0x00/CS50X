#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}
node;
int main(void)
{

}
node* create(int value)
{
    node* new = malloc(sizeof(node));
    if (new == NULL)
    {
        return;
    }
    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    return new;
}
bool find(node* head, int value)
{
    if (head == NULL)
    {
        return false;
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == value)
        {
            return true;
        }
    }
    return false;
}
node* insertBegining(node* head, int value)
{
    node* new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }
    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        head->prev = new;
        new->next = head;
        head = new;
    }

    return head;
}
node* insertEnd(node* head, int value)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }

    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        for (node* ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                new->prev = ptr;
                ptr->next = new;
            }
        }
    }

    return head;
}
void delet(node* head, int value)
{
    if (head == NULL)
    {
        return;
    }

    for (node* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->number == value)
        {
            ptr->prev->next = ptr->next;
            free(ptr);
            break;
        }
    }
}