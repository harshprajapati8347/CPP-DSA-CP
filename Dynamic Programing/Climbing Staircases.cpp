//  70. Climbing Stairs

// You are climbing a staircase.It takes n steps to reach the top. Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

// Exe1 : Input : n = 2 Output : 2
// Explanation : There are two ways to climb to the top.
// 1. 1 step + 1
// step 2. 2 steps

// Exe2 : Input : n = 3 Output : 3
// Explanation : There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Hint : Fibonacci Number : F(n) = F(n - 1) + F(n - 2)

// Err : Time Limit Exceeded

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n, int dp[])
    {
        if (n <= 1)
            return dp[n] = 1;

        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }

    // Returns number of ways to reach s'th stair
    int climbStairs(int n)
    {
        int dp[n + 1]; // dp[i] stores the number of ways to reach i'th stair
        memset(dp, -1, sizeof dp); // initialize dp[] with -1 
        fib(n, dp); // fill dp[] using fibonacci
        return dp[n]; 
    }
};
int main()
{
    Solution s;
    int n;
    cin>>n;
    cout << s.climbStairs(n);
    return 0;    
}

// tc: O(2^n)
// sc: O(n)