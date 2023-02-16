//! 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// !Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

//! Algorithm:
// 1. Sort the intervals based on the start time.
// 2. Iterate through the intervals and check if the current interval's start time is less than or equal to the previous interval's end time.
// 3. If yes, then update the previous interval's end time to the maximum of the current interval's end time and the previous interval's end time.
// 4. If no, then add the current interval to the result vector.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort the intervals based on the start time.
        sort(intervals.begin(), intervals.end());

        // {1, 3}, {2, 6} => if (2<3) => {1,6<=interval-Push} else add {,}
        vector<vector<int>> result;
        for (auto interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                // If no, then add the current interval to the result vector.
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    vector<vector<int>> result = s.merge(intervals);
    for (auto interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
    
    return 0;
}