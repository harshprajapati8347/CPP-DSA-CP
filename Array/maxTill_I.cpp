#include <iostream>
using namespace std;
int main()
{
    int a[10], n;
    int mx = -1999;
    cout << "Enter the elements of the array: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);

        cout << mx;
    }
    return 0;
} 