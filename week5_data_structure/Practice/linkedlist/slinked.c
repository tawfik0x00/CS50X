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
node *createNode(int data){
    // allocate space for a new node
    node *n = malloc(sizeof(node));
    // check memory
    if (n == NULL)
    {
        return NULL;
    }
    // initialize
    n->value = data;
    n->next = NULL;

    // return the pointer
    return n;
}
bool find(node *head, int data)
{
    if (head != NULL)
    {
        for (node* trav = head; trav != NULL; trav = trav->next)
        {
            if (trav->value == data)
            {
                return true;
            }
        }
    }

    return false;
}
node *insert(node *head, int data)
{
    node *new = createNode(data);
    new->next = head;
    head = new;

    return head;
}
void destroy(node *head)
{
    if (head == NULL)
    {
        return;
    }

    destroy(head->next);
    free(head);
}

