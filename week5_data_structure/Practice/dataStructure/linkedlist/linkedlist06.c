#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;
int main(void)
{

}
node* create(int item)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }

    new->value = item;
    new->next = NULL;

    return new;
}
bool find(node* head, int item)
{
    if (head == NULL)
    {
        return false;
    }

    for (node* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->value == item)
        {
            return true;
        }
    }

    return false;
}
node* insertBegining(node* head, int item)
{
    // insertion o(1)
    node* new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }

    new->value = item;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head = new;
    }

    return head;
}
node* insertEnd(node* head, int item)
{
    // insertion o(n)
    node* new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }

    new->value = item;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        for (node *trav = head; trav != NULL; trav = trav->next)
        {
            if (trav->next == NULL)
            {
                trav->next = new;
                break;
            }
        }
    }

    return head;
}
void destroy(node* head)
{
    /*
        while (head != NULL)
        {
            node* temp = head->next;
            free(head);
            head = temp;
        }
    */
   if (head == NULL)
   {
        return;
   }

   destroy(head->next);

   free(head);
}
void delet(node* head, int item)
{
    if (head != NULL && head->value == item)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    node* prev = NULL;
    node* curr = head;

    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return;
    }

    prev->next = curr->next;
    free(curr);
}