#include<iostream>
#include<vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
    int sum1 = 0;
    int sum2 = 0;
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        sum1 += arr[i][i];
        sum2 += arr[i][n-i-1];
    }
    return abs(sum1-sum2);
}

int main()
{
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {9,8,9}
    };
    cout<<diagonalDifference(arr);
    
    return 0;
}