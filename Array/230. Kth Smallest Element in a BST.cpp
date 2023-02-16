//! 230. Kth Smallest Element in a BST

// Given the root of a binary search tree, and an integer k, return the kth smallest value(1 - indexed) of all the values of the nodes in the tree.

//? Example 1:
// Input : root = [ 5, 3, 6, 2, 4, null, null, 1 ], k = 3 Output : 3

//* Algorithm:
// 1. Do inorder traversal of the BST and store the elements in a vector.
// 2. Return the kth element of the vector.
// TC: O(n) SC: O(n)

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> v;
        inorder(root, v);
        return v[k - 1];
    }

    void inorder(TreeNode *root, vector<int> &v)
    {   // Inorder = Left, Root, Right
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    int k = 3;
    cout << s.kthSmallest(root, k) << endl;

    return 0;
}
