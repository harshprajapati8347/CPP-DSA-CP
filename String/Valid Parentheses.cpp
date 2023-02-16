// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Input : s = "()[]{}" Output : true

#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s){
        stack<char> t;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                t.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (i == 0 || t.empty() || t.top() != '(')
                {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == ']')
            {
                if (i == 0 || t.empty() || t.top() != '[')
                {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == '}')
            {
                if (i == 0 || t.empty() || t.top() != '{')
                {
                    return false;
                }
                t.pop();
            }
        }
        return t.empty();
    }
};

int main()
{
    string s = "()[]{}";
    Solution sol;
    cout << sol.isValid(s);
    
    return 0;
}