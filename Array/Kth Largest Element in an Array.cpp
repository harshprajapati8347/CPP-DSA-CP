// 215. Kth Largest Element in an Array
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// You must solve it in O(n) time complexity.

// Input : nums = [ 3, 2, 1, 5, 6, 4 ], k = 2 Output : 5

// Algorithm:
// 1. Sort the array
// 2. Return the kth element from the end

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    int k = 2;
    cout << s.findKthLargest(nums, k);
    
    return 0;
}