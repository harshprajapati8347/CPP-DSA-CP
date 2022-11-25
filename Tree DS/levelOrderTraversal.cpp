/*
            1      Level 0  (1)         Sum = 1
           / \
          2   3    Level 1  (2,3)       Sum = 5
        / \  / \
       4  5 6  7   Level 2  (4,5,6,7)   Sum = 22

       LOT = 1 2 3 4 5 6 7
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == NULL) // check If Tree us Empty
    {
        return;
    }
    queue<Node *> q; // Create a Queue
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
};

int sumAtK(Node *root, int k){
    if(root == NULL){
        return -1;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        if(node != NULL){
            if(level == k){
                sum += node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
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
    levelOrderTraversal(root);
    cout << endl;

    cout << sumAtK(root, 1);
    return 0;
}