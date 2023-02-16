// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
// Use Hash Table
// Algorithm:
// 1. Create a Hash Table with size 101.
// 2. Traverse the array and store the frequency of each element in the Hash Table.
// 3. Traverse the Hash Table and for each element, add the number of pairs possible with that element to the result.
// 4. Return the result.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        for (auto i : hash)
        {
            result += (i.second * (i.second - 1)) / 2;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << s.numIdenticalPairs(nums);
    
    return 0;
}