// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.If target exists, then return its index.Otherwise, return -1.
// TODO: You must write an algorithm with O(log n) runtime complexity.

// Algorithm: Binary Search
//Ans : Psuedo code 
// 1. Set low = 0 and high = n-1
// 2. If low > high, then stop: target is not present in array. Return -1.
// 3. Set mid = (low + high) / 2
// 4. If A[mid] < target, then set low = mid + 1 and go to step 2.
// 5. If A[mid] > target, then set high = mid - 1 and go to step 2.
// 6. Now A[mid] = target, so return mid.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0; // left pointer
        int right = nums.size() - 1; // Right pointer
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) // target found => return
            {
                return mid;
            }
            else if (nums[mid] < target) // target > mid => move left pointer++
            {
                left = mid + 1;
            }
            else // right pointer--
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s.search(nums, target);

    return 0;
}