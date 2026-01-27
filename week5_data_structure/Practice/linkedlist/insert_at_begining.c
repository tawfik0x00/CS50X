#include <stdio.h>
#include <stdlib.h>

// create struct called node contain number and pointer to next node.
typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(int argc, char *argv[])
{
    // head of the list
    node *list = NULL;

    // For each command-line argument
    for (int i = 0; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]); // atoi mean ascii to integer

        // Allocate node for number
        node *n = malloc(sizeof(node));

        // check memory
        if (n == NULL)
        {
            return 1;
        }

        // initialize the node
        n->number = number;
        n->next = list;
        list = n;
    }

    // print numbers
    // initialize temp pointer to traverse all nodes and print the numbers inside it
    node *ptr = list;
    while (ptr != NULL)
    {
        // dereferance and access number field
        printf("%i\n", ptr->number);
        // now pointer updated to the nex node
        ptr = ptr->next;
    }

    // free nodes
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
