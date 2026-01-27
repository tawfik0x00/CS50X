#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
node;

int main(int argc, char* argv[])
{
    // creat new head of list
    node* list = NULL;

    for (int i = 1; i < argc; i++)
    {
        // convert from string to int
        int number = atoi(argv[i]);

        // allocate node for number
        node* n = (node*)malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        n->data = number;
        // prepend node to list
        n->next = list;
        list = n;
    }

    // print numbers in linkedlist
    node* ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->data);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL)
    {
        node* next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

