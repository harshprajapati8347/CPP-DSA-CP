// Binary Search by given key

//! Algorithm:
// 1. Take input of array and key
// 2. Initialize start and end
// 3. Loop until start is less than or equal to end
// 4. Find mid
// 5. If mid is equal to key then return mid
// 6. If mid is greater than key then end = mid-1
// 7. If mid is less than key then start = mid+1
// 8. If key is not found then return -1 

#include<iostream>
using namespace std;

class Solution{
    public:
    int binarySearch( int arr[], int n, int key){
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] > key){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    int arr[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;
    Solution ob;
    cout << ob.binarySearch(arr, n, key) << endl;
    
    return 0;
}