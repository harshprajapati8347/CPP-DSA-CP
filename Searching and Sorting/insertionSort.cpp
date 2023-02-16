// Insertion Sort
// Algorithm: Insertion Sort
// 1. Insert the second element in the array into the sorted subarray.
// 2. Insert the third element in the array into the sorted subarray.
// 3. Insert the fourth element in the array into the sorted subarray.
// 4. Repeat the process until the last element is inserted into the sorted subarray.
// 5. Repeat the process until the array is sorted.

#include<iostream>
using namespace std;

class Solution{
    public:
    void insertionSort(int arr[], int n){
        for(int i=1; i<n; i++){ // i=1 because we are assuming that the first element is already sorted
            int key = arr[i]; // key is the element which we are going to insert in the sorted subarray
            int j = i-1; // j is the last element of the sorted subarray
            while(j>=0 && arr[j]>key){ // if the last element of the sorted subarray is greater than the key then we will shift the element to the right
                arr[j+1] = arr[j]; // shifting the element to the right
                j--; 
            }
            arr[j+1] = key; // inserting the key in the sorted subarray
        }
    }
};

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    obj.insertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
      
    return 0;
}