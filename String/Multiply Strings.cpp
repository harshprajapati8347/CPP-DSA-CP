// ! 43. Multiply Strings
// Input: num1 = "2", num2 = "3"
// Output: "6"
//! Psuedo Code:
// 1. Multiply each digit of num1 with each digit of num2
// 2. Add the result of each multiplication
// 3. Add the carry to the next digit
// 4. Reverse the result

#include <iostream>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        // num1Size (3)+ num2Size (3) <=6 && initializing with val 0
        string s(num1.length() + num2.length(), '0');

        for (int i = num1.length() - 1; i >= 0; --i)
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                // num1[i] -'0' => logic of converting string into integer
                const int mult = (num1[i] - '0') * (num2[j] - '0');
                const int sum = mult + (s[i + j + 1] - '0');
                s[i + j] += sum / 10;
                s[i + j + 1] = '0' + sum % 10;
            }

        const int i = s.find_first_not_of('0'); 
        return i == -1 ? "0" : s.substr(i);
    }
};

int main()
{
    Solution s;
    string num1 = "123";
    string num2 = "456";
    cout << s.multiply(num1, num2) << endl;

    return 0;
}