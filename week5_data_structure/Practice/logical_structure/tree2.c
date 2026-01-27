// BST
#include <stdio.h>
#include <stdlib.h>

// the node of the tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}
node;

node *create_node(int data);

int main(void)
{

}

// subfunction used with insert function
node *create_node(int data)
{
    // first allocate memory for the node
    node *n = (node *)malloc(sizeof(node));
    // check memory
    if (node == NULL)
    {
        return NULL;
    }
    // initialize the node
    n->data = data;
    n->left = n->right = NULL;
    // return the pointer of the node
    return n;
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = inser(root->right, data);
    }

    return root;
}
void in_order(node *root)
{
    if (root != NULL)
    {
        in_orders(root->left);
        printf("%i ", root->data);
        in_order(root->right);
    }
}
node *search(node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}
