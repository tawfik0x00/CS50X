#include <stdio.h>
#include <stdlib.h>

// define the node we will use to create a linked list
typedef struct node
{
    struct node* next;
    int number;
}
node;

int main(int argc, char *argv[])
{
    // define an empty linked list
    node *list = NULL;

    // loop over inputs in the command-line
    for (int i = 1; i < argc; i++)
    {
        // first convert the ascii value to integer
        int number = atoi(argv[i]);

        // create a node in memory
        node *n = malloc(sizeof(node));

        // check the memory
        if (n == NULL)
        {
            return 1;
        }
        // initialize the node
        n->number = number;
        n->next = NULL;

        // we need to add the node to the linked list
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            // iterate over nodes to reach the end of the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // if the next node is null link the node to the list and exit
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }


    }

    // print the nodes
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // free the nodes
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
