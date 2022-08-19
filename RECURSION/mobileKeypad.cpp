#include <iostream>
using namespace std;

string keyPadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void mobileKeypad(string s, string ans)
{
    if (s.length() == 0)
    { // base case
        cout << ans << endl;
        return;
    }

    char c = s[0];
    string code = keyPadArr[c - '0']; // converting to string from char
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        mobileKeypad(ros, ans + code[i]);
    }
}

int main()
{
    string s = "23";
    mobileKeypad(s, "");
    return 0;
}