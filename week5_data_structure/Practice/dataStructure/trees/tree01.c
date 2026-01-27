#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* right;
    struct node* left;
}
node;

void free_tree(node* root);
void print_tree(node* root);
node* newNode(int data);

int main(void)
{

}
void free_tree(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // rcursion case
    // free right subtree
    free_tree(root->right);
    // free left subtree
    free_tree(root->left);
    // action
    free(root);
}

void inorderTraversal(node* root)
{
    // base case
    // stop here and start execute other code.
    if (root == NULL)
    {
        return;
    }

    // recursion case.
    print_tree(root->left);
    printf("%d \n", root->data);
    print_tree(root->right);
}
void preorderTraveral(node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
node *insert(node* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
    {
        root = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root = isnert(root->right, data);
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
node* search(node* root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}
node* delet_node(node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delet(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delet(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
    }
}