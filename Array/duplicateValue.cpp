// 217. Contains Duplicate

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.empty())
        {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            if (++mp[i] > 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums);
return 0;
}