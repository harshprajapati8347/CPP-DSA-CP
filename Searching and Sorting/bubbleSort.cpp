// Algorithm: Bubble Sort
// 1. Compare the first two elements and swap them if they are not in order.
// 2. Compare the second and third elements and swap them if they are not in order.
// 3. Compare the third and fourth elements and swap them if they are not in order.
// 4. Repeat the process until the last two elements are compared and swapped if they are not in order.
// 5. Repeat the process until the array is sorted.

#include <iostream>
using namespace std;

class Solution
{
public:
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    obj.bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}