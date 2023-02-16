// 290. Word Pattern
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Input : pattern = "abba", s = "dog cat cat dog" Output : true

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
    class Solution
    {
    public:
        bool wordPattern(string pattern, string str)
        {
            const int n = pattern.length();
            istringstream iss(str);
            vector<int> charToIndex(128);
            unordered_map<string, int> stringToIndex;

            int i = 0;
            for (string word; iss >> word; ++i)
            {
                if (i == n) // Out of bound
                    return false;
                if (charToIndex[pattern[i]] != stringToIndex[word])
                    return false;
                charToIndex[pattern[i]] = i + 1;
                stringToIndex[word] = i + 1;
            }

            return i == n;
        }
    };
};

int main()
{
    Solution s;
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << s.wordPattern(pattern, str);

    return 0;
}