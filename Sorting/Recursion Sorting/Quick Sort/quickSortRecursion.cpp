#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int main()
{
    int arr[] = {5, 2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}
// input: 5 2 1 3 4
// output: 1 2 3 4 5
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Method: Recursion