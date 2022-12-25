// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1, s2;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#' && !s1.empty())
            {
                s1.pop();
            }
            else if (s[i] != '#')
            {
                s1.push(s[i]);
            }
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#' && !s2.empty())
            {
                s2.pop();
            }
            else if (t[i] != '#')
            {
                s2.push(t[i]);
            }
        }
        if (s1.size() != s2.size())
        {
            return false;
        }
        while (!s1.empty())
        {
            if (s1.top() != s2.top())
            {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    Solution s1;
    cout << s1.backspaceCompare(s, t);
    
    return 0;
}