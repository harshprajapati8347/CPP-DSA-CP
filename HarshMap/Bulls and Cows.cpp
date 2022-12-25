// 299. Bulls and Cows

// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1807"
//   |
// "7810"

#include <iostream>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        int n = secret.length();
        int m = guess.length();
        int arr[10] = {0};
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                arr[secret[i] - '0']++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (secret[i] != guess[i] && arr[guess[i] - '0'] > 0)
            {
                cows++;
                arr[guess[i] - '0']--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main()
{
    string secret = "1807";
    string guess = "7810";
    Solution s;
    cout << s.getHint(secret, guess);

    return 0;
}