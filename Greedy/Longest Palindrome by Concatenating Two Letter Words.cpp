//! 2131. Longest Palindrome by Concatenating Two Letter Words

// You are given an array of strings words. Each element of words consists of two lowercase English letters.
// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
// A palindrome is a string that reads the same forward and backward.

//! Ex1:
// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.

// Algorithms: 
// 1. Create a 26*26 matrix to store the number of words between two letters
// 2. Check if there is a word between j and i, if yes, add 4 to the final answer and decrease the number of words between j and i by 1
// 3. If no, increase the number of words between i and j by 1
// 4. Check if there are any words between i and i, if yes, add 2 to the final answer
// 5. Return the final answer

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int ans = 0;
        vector<vector<int>> count(26, vector<int>(26)); 
        //create a 26*26 matrix to store the number of words between two letters

        for (const string &word : words)
        {
            const int i = word[0] - 'a';
            const int j = word[1] - 'a';
            if (count[j][i]) //check if there is a word between j and i
            {
                ans += 4; //if yes, add 4 to the final answer
                --count[j][i]; //decrease the number of words between j and i by 1
            }
            else
            {
                ++count[i][j]; //if no, increase the number of words between i and j by 1
            }
        }

        for (int i = 0; i < 26; ++i)
            if (count[i][i]) //check if there are any words between i and i
                return ans + 2; //if yes, add 2 to the final answer

        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << a.longestPalindrome(words) << endl;
    return 0;
}
