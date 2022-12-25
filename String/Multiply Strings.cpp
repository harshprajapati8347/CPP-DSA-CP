// Important String Program
// TODO 43. Multiply Strings
// Input: num1 = "2", num2 = "3"
// Output: "6"
#include<iostream>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int n1 = num1.size(); 
        int n2 = num2.size();
        string res(n1 + n2, '0'); 
        for (int i = n1 - 1; i >= 0; i--) 
        {
            int carry = 0; 
            for (int j = n2 - 1; j >= 0; j--) 
            { 
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry; // res[i + j + 1] is the last digit of the result, res[i + j] is the first digit of the result
                res[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            res[i] += carry; // res[i] is the first digit of the result
        }
        size_t startpos = res.find_first_not_of("0"); // find the first digit that is not 0
        if (string::npos != startpos)
        {
            return res.substr(startpos);
        }
        return "0";
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