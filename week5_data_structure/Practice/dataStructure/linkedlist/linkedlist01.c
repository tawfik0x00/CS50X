#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(int c, char* inputs[])
{
    node *list = NULL;
    for (int i = 1; i < c; i++)
    {
        int number = atoi(inputs[i]);

        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = number;
        n->next = list;
        list = n;
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