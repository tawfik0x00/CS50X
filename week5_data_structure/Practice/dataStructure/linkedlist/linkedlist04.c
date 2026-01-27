#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sllist
{
    int number;
    struct sllist* next;
}
sllnode;

sllnode* create(int item);

sllnode* insert_in_start(sllnode* head, int item);
sllnode* insert_in_end(sllnode* head, int item);
sllnode* insert_in_order(sllnode* head, int item);

void display_linkedlist(sllnode* head);
void destroy_linkedlist(sllnode* head);
void delet_singel_element(sllnode* head, int item);

bool find(sllnode* head, int item);


int main(void)
{
    sllnode* list = NULL;

    for (int i = 0; i < 20; i++)
    {
        sllnode* temp = insert_in_end(list, i + 1);

        if (temp == NULL)
        {
            return 1;
        }

        list = temp;
    }

    display_linkedlist(list);
    delet_singel_element(list, 15);
    display_linkedlist(list);
    destroy_linkedlist(list);
    return 0;
}

sllnode* create(int item)
{
    sllnode* new = malloc(sizeof(sllnode));

    if (new == NULL)
    {
        return NULL;
    }

    new->number = item;
    new->next = NULL;

    return new;
}
bool find(sllnode* head, int item)
{
    sllnode* ptr = head;

    while (ptr != NULL)
    {
        if (ptr->number == item)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}
sllnode* insert_in_start(sllnode* head, int item)
{
    sllnode* new = malloc(sizeof(sllnode));

    if (new == NULL)
    {
        return NULL;
    }
    new->number = item;
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
sllnode* insert_in_end(sllnode* head, int item)
{
    sllnode* new = malloc(sizeof(sllnode));

    if (new == NULL)
    {
        return NULL;
    }

    new->number = item;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        for (sllnode* ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                ptr->next = new;
                break;
            }
        }
    }

    return head;
}
void destroy_linkedlist(sllnode* head)
{
    // base case
    if (head == NULL)
    {
            return;
    }
    // recursion case
    destroy_linkedlist(head->next);
    // action
    free(head);
}
sllnode* insert_in_order(sllnode* head, int item)
{
    sllnode* new = malloc(sizeof(sllnode));

    if (new == NULL)
    {
        return NULL;
    }

    new->number = item;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else if (new->number < head->number)
    {
        // add at the begining
        new->next = head;
        head = new;
    }
    else
    {
        for (sllnode* ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                ptr->next = new;
                break;
            }

            if (new->number < ptr->next->number)
            {
                new->next = ptr->next;
                ptr->next = new;
                break;
            }
        }
    }

    return head;
}
void display_linkedlist(sllnode* head)
{
    for (sllnode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return;
}
void delet_singel_element(sllnode* head, int item)
{
    sllnode* prev = NULL;
    sllnode* temp = head;
    // if only one node
    if (temp != NULL && temp->number == item)
    {
            head = temp->next;
            free(temp);
            return;
    }

    // stop loop when reach NULL or when find item.
    while (temp != NULL && temp->number != item)
    {
        // save previous node
        prev = temp;
        // move to next node
        temp = temp->next;
    }
    // if we not found the element.
    if (temp == NULL)
    {
        printf("element not found in linked list\n");
        return;
    }
    // else now we still in node have the number
    // so we will delet it
    prev->next = temp->next;
    free(temp);

    return;
}