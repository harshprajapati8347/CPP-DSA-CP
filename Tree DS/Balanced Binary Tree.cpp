//! 110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree = height(left) - height(right) <= 1

//? Tree Representation
// Input: root = [3,9,20,null,null,15,7]
//         3
//        / \
//       9  20
//         /  \
//        15   7
// Output: true

// Input: root = [1,2,2,3,3,null,null,4,4]
//         1
//        / \
//       2   2
//      / \
//     3   3
//    / \
//   4   4
// Output: false

//! Algorithm:
// 1. Calculate height of left and right subtree
// 2. If height difference is greater than 1, return false
// 3. Else, return true

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
    // Calculate height of tree
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.isBalanced(root) << endl;

    return 0;
}