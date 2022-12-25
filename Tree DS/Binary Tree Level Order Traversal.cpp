// Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level). 
// Input : root = [ 3, 9, 20, null, null, 15, 7 ] 
// Output : [ [3], [ 9, 20 ], [ 15, 7 ] ]

#include<iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans; // vector to store the final answer
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;  // queue of TreeNode
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size();  // size of the queue
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front(); // current node
                q.pop(); // pop the current node
                level.push_back(curr->val); // push the value of the current node in the level vector
                if (curr->left != NULL) 
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            ans.push_back(level); // push the level vector in the final answer vector
        }
        return ans;
    }
};