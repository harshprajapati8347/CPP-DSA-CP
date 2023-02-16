// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: s = "anagram", t = "nagaram"
// Output: true

// Input: s = "rat", t = "car"
// Output: false

#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;
        for (int i : count) if (i) return false;
        return true;
    }};

int main()
{
    
    return 0;
}