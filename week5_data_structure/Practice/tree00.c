#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *right;
    struct node *left;
}
node;

void free_tree(node *root);
void print_tree(node *root);
bool search(node *tree, int number);

int main(void)
{
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;

    tree = n;

    // Add number ot list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;

    tree->left = n;


    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;

    tree->right = n;

    print_tree(tree);

    free_tree(tree);

    return 0;
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    // action
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // print in order way.
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

bool search(node *tree, int number)
{
    bool status = false;

    if (tree == NULL)
    {
        status = false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else if (number == tree->number)
    {
        status = true;
    }

    return status;

}