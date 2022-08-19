#include <iostream>
using namespace std;

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string temp = s.substr(0, i) + s.substr(i + 1);
        permutation(temp, ans + s[i]);
    }
}

int main()
{
    permutation("ABC", "");
    return 0;
}