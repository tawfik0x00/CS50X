#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* right;
    struct node* left;
}
node;

void free_tree(node *root);
void print_tree(node *root);
node* insert(node* root, int data);
node* newNode(int data);

int main(void)
{
    node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the binary tree: \n");
    print_tree(root);
    free_tree(root);
    return 0;
}
void free_tree(node* root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
void print_tree(node* root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->data);
    print_tree(root->right);
}
node* insert(node* root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
node* newNode(int data)
{
    node* n = malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}