// 226. Invert Binary Tree
// Given the root of a binary tree, invert the tree, and return its root.
// Input: root = [4,2,7,1,3,6,9] Output: [4,7,2,9,6,3,1]

// Tree Representation:
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Inverted Tree Representation:
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

//! Algorithm:
// 1. Swap left and right
// 2. Recursively invert left and right 
// TC = O(n), SC = O(n)

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *temp = root->left; // swap left and right
        root->left = root->right;
        root->right = temp;
        invertTree(root->left); // recursively invert left and right
        invertTree(root->right);
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution s;
    s.invertTree(root);

    cout << root->val << endl;
    cout << root->left->val << " " << root->right->val << endl;
    cout << root->left->left->val << " " << root->left->right->val << " " << root->right->left->val << " " << root->right->right->val << endl;
    return 0;
}