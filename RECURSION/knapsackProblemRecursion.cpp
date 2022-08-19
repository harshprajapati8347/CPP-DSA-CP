#include<iostream>
using namespace std;

int knapsack (int value[], int w[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    if(w[n-1]>W){
        return knapsack(value,w,n-1,W);
    }
    return max(value[n-1]+knapsack(value,w,n-1,W-w[n-1]),knapsack(value,w,n-1,W));
}

int main()
{
    int n,W;
    cin>>n>>W;
    int value[n],w[n];
    for(int i=0;i<n;i++){
        cin>>value[i]>>w[i];
    }
    cout<<knapsack(value,w,n,W);
    return 0;
}