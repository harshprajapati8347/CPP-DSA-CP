#include <bits/stdc++.h>
using namespace std;

void miniMaxSum(vector<int> arr){
    int min = 100000;
    int max = -100000;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    cout << sum - max << " " << sum - min << endl;
}

int main(){
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << miniMaxSum(arr);
    return 0;
}