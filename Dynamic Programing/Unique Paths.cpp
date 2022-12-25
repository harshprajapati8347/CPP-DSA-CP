// 62. Unique Paths

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// EXE1: Input: m = 3, n = 7
// Output: 28

// EXE:2 Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
             // dp[i][j] is the number of unique paths to reach the (i,j)th cell
        
        // base case: there is only one unique path to reach the (i,0)th cell and the (0,j)th cell
        // Matrix form: 
        // 1 1 1 1 1 1 1
        // 1 0 0 0 0 0 0
        // 1 0 0 0 0 0 0
        for (int i = 0; i < m; i++) // base case
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) // base case
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++) 
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // the number of unique paths to reach the (i,j)th cell is the sum of the number of unique paths to reach the (i-1,j)th cell and the (i,j-1)th cell
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 2);
    return 0;
}