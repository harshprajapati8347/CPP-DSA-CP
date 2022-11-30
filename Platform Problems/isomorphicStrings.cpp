// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("egg", "add") << endl;
    // cout << s.isIsomorphic("foo", "bar") << endl;
    // cout << s.isIsomorphic("paper", "title") << endl;
    // cout << s.isIsomorphic("ab", "aa") << endl;
    return 0;
}