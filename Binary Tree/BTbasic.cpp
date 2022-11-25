#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // print tree
    cout << root->data << endl;
    cout << root->left->data << " " << root->right->data << endl;
    cout << root->left->left->data << " " << root->left->right->data << " " << root->right->left->data << " " << root->right->right->data << endl;
    return 0;
}