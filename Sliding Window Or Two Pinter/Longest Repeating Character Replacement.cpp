// todo 424. Longest Repeating Character Replacement
// Sliding Window/Two Pointer

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

#include <iostream>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int left = 0, right = 0; // (left, right) is the sliding window SW
        int maxCount = 0;        // the max count of the character in SW
        int maxLength = 0;       // the max length of the SW
        int count[26] = {0};     // the count of each character in SW
        while (right < n)        // right is the right boundary of the SW
        {
            count[s[right] - 'A']++; // add the character to the SW
            maxCount = max(maxCount, count[s[right] - 'A']); // update the max count of the character in the SW
            if (right - left + 1 - maxCount > k) // if the number of characters that need to be replaced is greater than k
            {
                count[s[left] - 'A']--; // remove the character from the SW
                left++;                // move the left boundary of the SW to the right
            }
            maxLength = max(maxLength, right - left + 1); // update the max length of the SW
            right++; // move the right boundary of the SW to the right
        }
        return maxLength; // return the max length of the SW
    }
};

int main()
{
    Solution s;
    cout << s.characterReplacement("AABABBA", 1) << endl;

    return 0;
}