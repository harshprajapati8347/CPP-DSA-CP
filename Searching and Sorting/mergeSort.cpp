// Merge Sort Algorithm:
// 1. Divide the array into two sub-arrays
// 2. Recursively sort the two sub-arrays
// 3. Combine the two sub-arrays
// 4. Return the sorted array
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <iostream>

using namespace std;

class Solution
{
public:
    void mergeSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    void merge(int arr[], int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[low + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[mid + 1 + j];
        }
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    obj.mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}