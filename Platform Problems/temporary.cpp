#include <bits/stdc++.h>

using namespace std;

void arrayRotation(int arr[], int n)
{
    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = last;
}

int main()
{
    int n, turns; // size of the array
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Number of times the array is to be rotated
    cin >> turns;

    for (int i = 0; i < turns; i++)
        arrayRotation(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}