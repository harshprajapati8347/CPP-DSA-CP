// recursively reverse an array
#include <bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int start, int end)
{
    if (start >= end) // if in middle or arr size = 1
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    printArray(arr, 6);
    rvereseArray(arr, 0, 5);
    cout << "Reversed array is" << endl;
    printArray(arr, 6);

    return 0;
}
