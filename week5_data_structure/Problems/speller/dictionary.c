// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 15000;
unsigned int dict_size;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int bucket = hash(word);
    node *trav = table[bucket];
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }

        trav = trav->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 1]; // 1 IS A NUL character
    dict_size = 0;
    // Read each word in the file
    while (fscanf(source, "%45s", word) == 1)
    {

        // create a node and copy the string to it
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            fclose(source);
            return false;
        }

        strcpy(n->word, word);
        int bucket = hash(word);

        n->next = table[bucket];
        table[bucket] = n;
        dict_size++;
    }

    // Close the dictionary file
    if (fclose(source) != 0)
    {
        unload();
        return false;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *next = current->next;
            free(current);
            current = next;
        }

        table[i] = NULL;
    }

    return true;
}
