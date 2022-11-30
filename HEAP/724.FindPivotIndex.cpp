// Find Pivot Index
// Input : nums = [ 1, 7, 3, 6, 5, 6 ] 
// Output : 3 
// Explanation : The pivot index is 3. 
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums){
        int sum = 0;
        int leftsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftsum == sum - leftsum - nums[i])
            {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;

    }

};

int main()
{
    Solution s;
    vector<int> v = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(v); 
    
    return 0;
}