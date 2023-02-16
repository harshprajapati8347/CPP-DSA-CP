// 2560. House Robber IV
// There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

// The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

// You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

// You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

// Example 1:

// Input: nums = [2,3,5,9], k = 2
// Output: 5
// Explanation:
// There are three ways to rob at least 2 houses:
// - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
// - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
// - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
// Therefore, we return min(5, 9, 9) = 5.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= k <= (nums.length + 1)/2

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &a, int k, int i, vector<int> &dp)
    {
        if (i >= a.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int take = 0;
        int nt = solve(a, k, i + 1, dp);

        if (a[i] <= k)
        {
            return dp[i] = max(solve(a, k, i + 2, dp) + 1, nt);
        }
        return dp[i] = nt;
    }

    bool chk(vector<int> &a, int k, int req)
    {
        vector<int> dp(a.size());
        for (int i = 0; i < a.size(); i++)
        {
            dp[i] = -1;
        }
        int maxi = solve(a, k, 0, dp);
        return maxi >= req;
    }

    int minCapability(vector<int> &nums, int k)
    {
        int s = 0;
        int e = 1000000000;
        while (s + 1 < e)
        {
            int m = s + (e - s) / 2;
            if (chk(nums, m, k))
            {
                e = m;
            }
            else
            {
                s = m;
            }
        }
        return e;
    }
};

int main()
{
    Solution s;
    vector<int> a = {2, 3, 5, 9};
    int k = 2;
    cout << s.minCapability(a, k) << endl;

    return 0;
}
