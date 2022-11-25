#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int a[26] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            a[s[i] - 'a']++;
        }
        else
        {
            a[s[i] - 'A']++;
        }
    }
    sort(a, a + 26);
    int ans = 0;
    int k = 26;
    for (int i = 25; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            ans += a[i] * k;
            k--;
        }
    }
    cout << ans << endl;
    
    return 0;
}
