#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int number;
}
node;

int main(int argc, char *argv[])
{
    // define an empty list
    node *list = NULL;

    // iterate over command-line arguments
    for (int i = 1; i < argc; i++)
    {
        // first convert ascii value to an int
        int number = atoi(argv[i]);

        // create a node and initiazlie its values
        node *n = malloc(sizeof(node));

        // check the memory
        if (n == NULL)
        {
            return 1;
        }

        // initialize the values of the node
        n->number = number;
        n->next = NULL;

        // if the list is empty prepend it
        if (list == NULL)
        {
            list = n;
        }
        else if(n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            // itrate over nodes
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // check if reach the end
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }

                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // print nodes
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // free nodes
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
