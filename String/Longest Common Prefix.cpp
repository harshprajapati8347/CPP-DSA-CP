// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        if (strs.size() == 0)
            return prefix;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i]; // first string's ith character
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].size() || strs[j][i] != c) // if the ith character of any string is not equal to the first string's ith character
                    return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs);
    
    return 0;
}