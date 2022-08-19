// find first repeating element in array
// Constraints
// 1<=N<=10^6
// 0<=Ai<=10^6
// 7
// 01253248
// op> 2(index no of repeating array)

#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e6 + 2;
    int idx[N];

    for (int i = 0; i < n; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }

    if (minidx == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minidx + 1 << endl;
    }

    return 0;
}