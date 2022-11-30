// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Input: s = "abccccdd" Output : 7 
// Explanation : One longest palindrome that can be built is "dccaccd", whose length is 7.

#include<iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = { 0 }; // 128 ASCII characters 
        for (char c : s) { // for each character in s 
            count[c]++; // increment the count of that character in the count array 
            // count['a'] = 1, count['b'] = 1, count['c'] = 4, count['d'] = 2
        }
        int ans = 0;
        for (int v : count) { // for each count
            ans += v / 2 * 2; // add the even counts
            if (ans % 2 == 0 && v % 2 == 1) { // if the answer is even and the count is odd            
                ans++; 
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abccccdd");
       
    return 0;
}