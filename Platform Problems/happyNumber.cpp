// 202. Happy Number

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

//! Algorithm:
// 1. Take the number and find the sum of the squares of its digits.
// 2. If the sum is 1, then the number is a happy number.
// 3. If the sum is 4, then the number is not a happy number.
// 4. If the sum is neither 1 nor 4, then repeat the process from step 1.

#include<iostream>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1)
            return true;
        else if (sum == 4) // 4 is the only number that will never be a happy number
            return false;
        else
            return isHappy(sum); // recursion
    }
};

int main()
{
    Solution s;
    cout << s.isHappy(19) << endl;    
    return 0;
}