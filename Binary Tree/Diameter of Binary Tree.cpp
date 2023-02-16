//! 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

//? Time Complexity: O(n)
// Space Complexity: O(n)

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

//! Simple Algorithm: DFS
// 1. DFS to find the height of the left and right subtree
// 2. Update the diameter if the sum of the height of the left and right subtree is greater than the current diameter
// 3. Return the height of the current node 

#include<iostream>
#include<algorithm>
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0; // diameter
        height(root, ans);
        return ans;
    }
    int height(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;
}
