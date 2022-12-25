// Circular Sentence
//         A sentence is a list of words that are separated by a single space with no leading or
//     trailing spaces.

//     For example,
//     "Hello World", "HELLO", "hello world hello world" are all sentences.Words consist of only uppercase and lowercase English letters.Uppercase and lowercase English letters are considered different.

//                             A sentence is circular if :

//     The last character of a word is equal to the first character of the next word.The last character of the last word is equal to the first character of the first word.For example,
//     "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences.However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

//                                                                                                                                                                     Given a string sentence,
//     return true if it is circular.Otherwise, return false.

//                                                     Input : sentence = "leetcode exercises sound delightful" Output : true Explanation : The words in sentence are["leetcode", "exercises", "sound", "delightful"].- leetcode 's last character is equal to exercises' s first character.- exercises 's last character is equal to sound' s first character.- sound 's last character is equal to delightful' s first character.- delightful 's last character is equal to leetcode' s first character.The sentence is circular.

#include<iostream>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        
        int i = 0;
        int j = 0;
        int count = 0;
        int len = sentence.length();
        while (i < len)
        {
            if (sentence[i] == ' ')
            {
                count++;
                if (sentence[i - 1] != sentence[j])
                {
                    return false;
                }
                j = i + 1;
            }
            i++;
        }
        if (sentence[len - 1] != sentence[j])
        {
            return false;
        }
        if (count == 0)
        {
            return false;
        }
        return true;
        
    }

};

int main()
{
    Solution s;
    string sentence = "leetcode exercises sound delightful";
    cout << s.isCircularSentence(sentence);
       
    return 0;
}