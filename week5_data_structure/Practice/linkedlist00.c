#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number; // value
    struct node *next; // pointer of type node to reference the next node
}
node;

int main(int argc, char *argv[])
{
    // the head of our list
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = number; // derefernce the n and access the field number
        n->next = NULL; // make the next to the null

        // append node to the begining of the list
        n->next = list; // make n next points to list node
        list = n; // now we can make list points to n.
    }

    // print our linked list.
    // node *ptr = list;
    // while (ptr != NULL)
    // {
    //     printf("%i\n", ptr->number);
    //     ptr = ptr->next;
    // }

    // our we can use for to print the linked list

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // if we need to free the list we need to free every node
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}