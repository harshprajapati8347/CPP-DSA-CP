#include <bits/stdc++.h>
using namespace std;

int main()
{
    // init
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    const int N = 1e6 + 2;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }
    // init

    int minIndx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1)
        {
            minIndx = min(minIndx, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }

    if (minIndx == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minIndx + 1 << endl;
    }
    return 0;
}