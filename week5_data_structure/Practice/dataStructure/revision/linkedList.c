#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(int argc, char* argv[])
{
    // define header of our linked list
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            for (node* ptr = list; ptr != NULL; ptr = ptr->next)
            {
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

    for (node* ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node* ptr = list;
    while (ptr != NULL)
    {
        node* next = ptr->next;
        free(ptr);
        ptr = next;
    }
}