#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 26

typedef struct node
{
    char *name;
    struct node *next;
}
node;

node* hash_table[MAX];

unsigned int hash_function(char c);
void insert(char* name);
void lookup(char letter);

int main(void)
{
    // Insert some names into the hash table
    insert("alice");
    insert("bob");
    insert("carol");
    insert("dave");
    insert("erin");

    // Lookup the names that start with a given letter
    lookup('a');
    lookup('b');
    lookup('c');
    lookup('d');
    lookup('e');

    return 0;
}
unsigned int hash_function(char c)
{
    return tolower(c) - 'a';
}
void insert(char* name)
{
    int index = hash_function(name[0]);

    node* n = malloc(sizeof(node));

    n->next = NULL;
    n->name = name;

    if (hash_table[index] == NULL)
    {
        hash_table[index] = n;
    }
    else
    {
        node* current = hash_table[index];

        while (current != NULL)
        {
            current = current->next;
        }
        current = n;

    }

}
void lookup(char letter)
{
    int index = hash_function(letter);
    node* current = hash_table[index];
    printf("Name that start with %c:\n", toupper(letter));

    while (current != NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}