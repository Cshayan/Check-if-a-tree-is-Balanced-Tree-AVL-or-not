#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
int height(struct node *curr)
{
    if(curr == NULL)
        return -1;
    if(curr->left == NULL && curr->right == NULL)
        return 0;
    int lh= height(curr->left);
    int rh= height(curr->right);

    if(lh > rh)
        return (lh+1);
    else
        return (rh+1);
}
int isBalanced(struct node *root)
{
    struct node *temp = root;
    if(temp == NULL)                     //empty tree is always balanced
        return 1;

    int lheight= height(temp->left);
    int rheight= height(temp->right);

    /* if difference of heights of left and right subtree is not more than one and
    the left and right subtrees are also balanced then it is height-balanced*/

    if(abs(lheight - rheight) <=1 && isBalanced(temp->left) && isBalanced(temp->right))
                return 1;

        return 0;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if(isBalanced(root))
      printf("\nTree is balanced\n");
    else
      printf("\nTree is not balanced\n");

    return 0;
}
