#include <iostream>
using namespace std;
// strictly increasing

int firstLoc(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    return firstLoc(a, n, i + 1, key);
}

int lastLoc(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;
    int restArray = lastLoc(a, n, i + 1, key);
    if (restArray != -1)
        return restArray;
    if (a[i] == key)
        return i;
    return -1;
}

int main()
{
    int a[] = {5, 2, 1, 4, 7, 6, 4, 3, 1, 2};
    cout << firstLoc(a, 10, 0, 2) << endl;
    cout << lastLoc(a, 10, 0, 2) << endl;
    return 0;
}