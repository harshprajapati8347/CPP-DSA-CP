// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.A subsequence of a string is a new string that is formed from the original string by deletingsome(can be none) of the characters without disturbing the relative positions of the remaining characters.(i.e., "ace" is a subsequence of "abcde" while "aec" is not ).
#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
            i++;
        j++;
    }
    return i == s.size();
}

int main()
{
    cout << isSubsequence("ace", "abcde") << endl;
    cout << isSubsequence("aec", "abcde") << endl;
    return 0;
}