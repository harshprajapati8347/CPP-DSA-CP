#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++){
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    // Checking Left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    // Checking Right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr, int x, int n){
    if(x>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(arr,x,i,n)){
            arr[x][i]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][i]=0; // backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;
    // alllocating memory to 2d array
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n]; // allocating memory for each row
        for(int j=0;j<n;j++){
            arr[i][j] = 0; // initializing each element to 0 in 2d array
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution";
    } 
    return 0;
}