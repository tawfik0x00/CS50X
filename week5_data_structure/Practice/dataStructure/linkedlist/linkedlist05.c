#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node* next;
    struct node* prev;
}
node;

node* insert(node* head, int number);
void deletnode(node* head, int x);

int main(void)
{
    node* list = NULL;

    list = insert(list, 4);
    list = insert(list, 5);
    list = insert(list, 6);


    deletnode(list, 5);

    for (node* ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

}
node* insert(node* head, int number)
{
    node* new = malloc(sizeof(node));

    if (new == NULL)
    {
        return NULL;
    }

    new->number = number;
    new->prev = NULL;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        return head;
    }
    else
    {

        head->prev = new;
        new->next = head;
        head = new;
        
        return head;
    }

}

void deletnode(node* head, int x)
{

    node* temp = head;
    // if it is the first node
    if (temp != NULL && temp->number == x)
    {

        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->number != x)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("element not found in linked list\n");
    }

    temp->prev->next = temp->next;
    free(temp);
    return;

}