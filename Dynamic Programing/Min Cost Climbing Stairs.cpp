// Dynamic Programming
// 746. Min Cost Climbing Stairs

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Exe: Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size(); // n is the number of stairs
        vector<int> dp(n + 1, 0); // dp[i] is the minimum cost to reach the ith stair
        dp[0] = cost[0]; // dp[0] is the minimum cost to reach the 0th stair
        dp[1] = cost[1]; // dp[1] is the minimum cost to reach the 1st stair
        for (int i = 2; i < n; i++) 
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; // min of the cost to reach the (i-1)th stair and the (i-2)th stair + the cost of the ith stair
        }
        return min(dp[n - 1], dp[n - 2]); // min of the cost to reach the (n-1)th stair and the (n-2)th stair
    }
};

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    cout << s.minCostClimbingStairs(cost);
    return 0;
}