// 6258. Longest Square Streak in an Array

// You are given an integer array nums. A subsequence of nums is called a square streak if:

// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int count = 0;
        int max = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == nums[i] * nums[i])
                {
                    count++;
                }
            }
            if (count > max)
            {
                max = count;
            }
            count = 0;
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 6, 16, 8, 2};
    cout << s.longestSquareStreak(nums);
       
    return 0;
}