#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 26
#define MAX_CHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[ALPHA]; // array of pointers to other node of the same type
} node;
// Root of trie
node *root;
// buffer to save the name of every dog.
char name[MAX_CHAR];

bool check(char *word);
bool unload(void);
void unloader(node *current);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // define our root
    root = malloc(sizeof(node));

    root->is_word = false;

    for (int i = 0; i < ALPHA; i++)
    {
        root->children[i] = NULL;
    }

    // Add word to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';

            if (cursor->children[index] == NULL)
            {
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < ALPHA; j++)
                {
                    new->children[j] = NULL;
                }

                cursor->children[index] = new;
            }

            cursor = cursor->children[index];
        }

        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}
bool check(char *word)
{
    node *cursor = root;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = tolower(word[i]) - 'a';

        if (index < 0 || index >= ALPHA)
        {
            return false;
        }
        if (cursor->children[index] == NULL)
        {
            return false;
        }

        cursor = cursor->children[index];
    }

    return cursor->is_word;
}

bool unload(void)
{
    unloader(root);
    return true;
}

void unloader(node *current)
{
    for (int i = 0; i < ALPHA; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    free(current);
}
