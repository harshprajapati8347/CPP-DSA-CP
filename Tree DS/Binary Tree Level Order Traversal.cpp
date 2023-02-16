// Binary Tree Level Order Traversal
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level). 
// Input : root = [ 3, 9, 20, null, null, 15, 7 ] 
// Output : [ [3], [ 9, 20 ], [ 15, 7 ] ]

//! Algorithm:
// 1. Create a queue of TreeNode
// 2. Push the root node in the queue
// 3. While the queue is not empty
// 4. Get the size of the queue
// 5. Create a vector to store the values of the nodes in the current level
// 6. For each node in the current level
// 7. Pop the current node from the queue
// 8. Push the value of the current node in the level vector
// 9. If the left child of the current node is not NULL, push it in the queue
// 10. If the right child of the current node is not NULL, push it in the queue
// 11. Push the level vector in the final answer vector


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Definition for a binary tree node.
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

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> ans = s.levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}