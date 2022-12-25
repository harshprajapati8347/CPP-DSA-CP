// Given the root of a binary tree, determine if it is a valid binary search tree(BST).

// A valid BST is defined as follows :
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Algorithm:
// 1. Inorder traversal of a BST is always sorted.
// 2. So, we can do inorder traversal and check if the values are sorted or not.
// 3. If the values are sorted, then it is a BST.

// Input : root = [ 5, 1, 4, null, null, 3, 6 ] 
// Output : false 
// Explanation : The root node 's value is 5 but its right child' s value is 4.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left; 
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // constructor
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        TreeNode *prev = NULL; // to store the previous node
        return inorder(root, prev);
    }

    bool inorder(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL) // base case
            return true;
        if (!inorder(root->left, prev)) // left subtree
            return false;
        if (prev != NULL && prev->val >= root->val) // check if the values are sorted or not
            return false;
        prev = root; // update the previous node
        return inorder(root->right, prev); // right subtree
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.isValidBST(root) << endl;

    return 0;
}

// IP: 2 1 3
// OP: 1
// Time Complexity: O(n)
// Space Complexity: O(n)
