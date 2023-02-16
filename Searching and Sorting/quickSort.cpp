// Quick Sort Algorithm:
// 1. Pick a pivot element
// 2. Partition the array into two sub-arrays
// 3. Recursively sort the two sub-arrays
// 4. Combine the two sub-arrays
// 5. Return the sorted array
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include<iostream>
using namespace std;

class Solution{
    public:
    void quickSort(int arr[], int low, int high){
        if(low < high){
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
        }
    }
    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low-1;
        for(int j=low; j<high; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }
};

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    obj.quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}