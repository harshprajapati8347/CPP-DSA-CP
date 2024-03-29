//! NOT UNDERSTOOD
// 31. Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

//! Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]

// Algorithm:

// 1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// 2. Find the largest index l > k such that nums[k] < nums[l].
// 3. Swap nums[k] and nums[l].
// 4. Reverse the sub-array nums[k + 1:].
// 5. Return nums.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) // find the first decreasing number
            i--;
        if (i >= 0)
        {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) // find the first number that is larger than nums[i]
                j--;
            swap(nums[i], nums[j]); // swap the two numbers
        }
        reverse(nums.begin() + i + 1, nums.end()); // reverse the rest of the array
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}