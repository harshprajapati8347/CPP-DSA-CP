// TODO 438. Find All Anagrams in a String

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// TODO Example 1:
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Algorithm for this problem is as follows:
// 1. Create two vectors of size 26, one for p and one for s.
// 2. Count the frequency of each character in p and store it in the vector for p.
// 3. Count the frequency of each character in s and store it in the vector for s.
// 4. Compare the two vectors. If they are equal, push the index into the result vector.
// 5. Add the new character and remove the first character from the vector for s.
// 6. Repeat step 4 and 5 until the end of s.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res; // Result vector
        int sLength = s.size();
        int pLength = p.size();
        if (sLength < pLength)
        {
            return res;
        }
        vector<int> shash(26, 0);
        vector<int> phash(26, 0);
        // Ex. [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]

        // For the first window
        for (int i = 0; i < pLength; i++)
        {
            shash[s[i] - 'a']++;
            phash[p[i] - 'a']++;
            // phash => [ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
        }
        if (shash == phash) // Compare both hashs and if they are equal push windowFirstElement index (here 0) into the result vector
        {
            res.push_back(0);
        }
        // For the remaining windows
        for (int i = pLength; i < sLength; i++)
        {
            shash[s[i] - 'a']++;           // Add the new character
            shash[s[i - pLength] - 'a']--; // Remove the last character
            if (shash == phash)
            {
                res.push_back(i - pLength + 1);
            }
        }
        return res;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution sol;
    vector<int> res = sol.findAnagrams(s, p);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}