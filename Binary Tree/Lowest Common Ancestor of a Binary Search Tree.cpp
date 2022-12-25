// Given a binary search tree(BST), find the lowest common ancestor(LCA)node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia : “The lowest ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants(where we allow a node to be a descendant of itself).”

// Input : root = [ 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 ] p = 2, q = 8
// Output : 6
// Explanation : The LCA of nodes 2 and 8 is 6.

#include <iostream>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    Solution s;
    cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;

    return 0;
}