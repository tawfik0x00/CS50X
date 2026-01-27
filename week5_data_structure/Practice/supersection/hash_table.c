#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// node structure
typedef struct node
{
    string phrase;
    struct node *next;
}
node;

// table of nodes
node *table[26];


int hash(string phrase);
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // initialize all nodes of the array with null.
    for (int i = 0; i < 26; i++)
    {
        table[i] = NULL;
    }

    // Add items
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");
        // get the bucket or the index we will the the phrase inside
        int bucket = hash(phrase);
        // create node and initialize it
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // add it to the node of index table at the begining
        n->phrase = phrase;
        n->next = table[bucket];
        table[bucket] = n;
    }

    // visualizer
    for (int i = 0; i < 26; i++)
    {
        printf("Bucket %i: ", i);
        visualizer(table[i]);
    }

    // Unload hash table
    for (int i = 0; i < 26; i++)
    {
        unload(table[i]);
    }


}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    return toupper(phrase[0]) - 'A';
    // return tolower(phars[0]) - 'a';
}
bool unload(node *list)
{
    while (list != NULL)
    {
        node *next = list->next;
        free(list);
        list = next;
    }

    return true;
}
void visualizer(node *list)
{
    while (list != NULL)
    {
        printf("%s -> ", list->phrase);
        list = list->next;
    }

    printf("NULL\n");
}
