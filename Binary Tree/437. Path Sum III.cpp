//! 437. Path Sum III
// Given the root of a binary tree and an integer targetSum, return the 
//? number of paths 
// where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3

// Algorithm: Recursion
// 1. If the current node is null, return 0.
// 2. Recursively call the function for the left and right subtrees with the target sum as the target sum minus the current node's value.
// 3. If the current node's value is equal to the target sum, add 1 to the result.
// 4. Return the result.

#include<iostream>
#include<unordered_map>
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
    unordered_map<long, int> map;
    int count = 0;

    void countPathSum(TreeNode *root, int target, long sum)
    {
        if (!root)
            return;
        sum += root->val;
        if (sum == target)
            count++;
        if (map.find(sum - target) != map.end())
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        countPathSum(root, targetSum, 0);
        return count;
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    
    Solution s;
    cout << s.pathSum(root, 8) << endl;
    
    return 0;
}

//! Using DFS

// Algorithm
// 1. Use DFS to find all paths from the root to the leaf.
// 2. For each path, check if the sum of the path is equal to the target sum.

// #include <iostream>
// #include <vector>
// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
//     int count = 0;

//     void dfs(TreeNode *root, int target, vector<int> &path)
//     {
//         if (!root)
//             return;
//         path.push_back(root->val);
//         int sum = 0;
//         for (int i = path.size() - 1; i >= 0; i--)
//         {
//             sum += path[i];
//             if (sum == target)
//                 count++;
//         }
//         dfs(root->left, target, path);
//         dfs(root->right, target, path);
//         path.pop_back();
//     }

//     int pathSum(TreeNode *root, int targetSum)
//     {
//         vector<int> path;
//         dfs(root, targetSum, path);
//         return count;
//     }
// };

// int main(){
//     TreeNode *root = new TreeNode(10);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(-3);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(2);
//     root->right->right = new TreeNode(11);
//     root->left->left->left = new TreeNode(3);
//     root->left->left->right = new TreeNode(-2);
//     root->left->right->right = new TreeNode(1);
    
//     Solution s;
//     cout << s.pathSum(root, 8) << endl;
    
//     return 0;
// }