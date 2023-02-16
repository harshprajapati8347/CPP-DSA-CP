// First Repeating Number 
// Use unordered_map

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int firstRepeatingNumber(int arr[], int n){
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[arr[i]] > 1){
                return arr[i];
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int arr[] = {1, 2, 3, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << s.firstRepeatingNumber(arr, n);
    return 0;    
}