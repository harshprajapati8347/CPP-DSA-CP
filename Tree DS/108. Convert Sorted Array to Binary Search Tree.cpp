//! 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.
// Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted

//! Algorithm:
// 1. Find the middle element of the array.
// 2. Make that middle element the root of the BST.
// 3. Recursively do the same for the left half and right half of the array.
// 4. If there is no element in the array then return null.
// TC: O(n) SC: O(n)

#include<iostream>
#include<vector>
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        // middle element as root
        TreeNode *root = new TreeNode(nums[mid]); 
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = s.sortedArrayToBST(nums);
    
    return 0;
}