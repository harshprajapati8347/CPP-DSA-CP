//! 6300. Minimum Common Value
// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

// Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
// Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
// Output: 2
// Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.

//! Algorithm:
// 1. Take two pointers i and j and initialize them to 0.
// 2. Traverse both the arrays simultaneously.
// 3. If the element at i and j is equal, return that element.
// 4. If the element at i is less than the element at j, increment i.
// 5. If the element at j is less than the element at i, increment j.
// 6. If the element at i and j is not equal, return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {2, 3, 4, 5};
    cout << s.getCommon(nums1, nums2);
    
    return 0;
}