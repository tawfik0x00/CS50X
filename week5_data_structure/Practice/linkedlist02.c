#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return 1;
        }

        new->number = number;
        new->next = NULL;

         if (list == NULL)
         {
            list = new;
         }
         else if (new->number < list->number)
         {
            new->next = list;
            list = new;
         }
         else
         {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
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
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}