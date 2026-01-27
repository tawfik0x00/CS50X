#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 26

typedef struct node
{
    char *name;
    struct node *next;
}
node;

node *hash[MAX]; // give me array of nodes pointers to linked list of strings.
void insert(char *name);
int hashf(char c);
void lockup(char c);
void freehash(void);

int main(void)
{
    insert("mohamed");
    insert("tawfik");
    insert("mo2tz");
    insert("toto");

    lockup('m');

    freehash();
}
void insert(char *name)
{
    int index = hashf(name[0]);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }

    n->next = NULL;
    n->name = name;

    if (hash[index] == NULL)
    {
        hash[index] = n;
    }
    else
    {
        n->next = hash[index];
        hash[index] = n;
    }
}

int hashf(char c)
{
    return tolower(c) - 97;
}

void lockup(char c)
{
    int index = hashf(c);

    node* temp = hash[index];

    while (temp != NULL)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}
void freehash(void)
{
    for (int i = 0; i <= MAX; i++)
    {
        if (hash[i] != NULL)
        {
            node *temp = hash[i];
            while (temp != NULL)
            {
                node *next = temp->next;
                free(temp);
                temp = next;
            }
        }
    }
}