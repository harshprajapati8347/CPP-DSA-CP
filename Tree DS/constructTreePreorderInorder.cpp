// Connstruct tree from given Inorder and Postorder traversals
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int search(int arr[], int strt, int end, int value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

void inorderPrint(node *root)
{
    if(root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

node *buildTree(int preorder[], int inorder[], int inStrt, int inEnd)
{
    static int preIndex = 0;
    if (inStrt > inEnd) // base case : if inorderStart > inorderEnd then return NULL 
        return NULL;
    node *tNode = new node;
    tNode->data = preorder[preIndex++];
    tNode->left = NULL;
    tNode->right = NULL;
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(inorder, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(preorder, inorder, inStrt, inIndex-1);
    tNode->right = buildTree(preorder, inorder, inIndex+1, inEnd);
    return tNode;
}

    int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    // build tree
    node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);    

    return 0;
}