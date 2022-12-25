// 394. Decode String

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp = "";
                while (st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string num = "";
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    num = st.top() + num;
                    st.pop();
                }
                int n = stoi(num);
                string res = "";
                for (int i = 0; i < n; i++)
                {
                    res += temp;
                }
                for (int i = 0; i < res.length(); i++)
                {
                    st.push(res[i]);
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main()
{
    string s = "3[a2[c]]";
    Solution obj;
    cout << obj.decodeString(s);
    
    return 0;
}