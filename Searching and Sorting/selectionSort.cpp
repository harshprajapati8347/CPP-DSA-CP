// Algorithm: Selection Sort
// 1. Find the smallest element in the array and swap it with the first element.
// 2. Find the second smallest element in the array and swap it with the second element.
// 3. Repeat the process until the array is sorted.
// Time Complexity: O(n^2)

#include <iostream>
using namespace std;

class Solution
{
public:
    void selectionSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }
}

int
main()
{
    int arr[] = {5, 4, 3, 2, 1};
    Solution obj;
    obj.selectionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}