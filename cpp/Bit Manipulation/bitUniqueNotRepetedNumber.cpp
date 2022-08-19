#include <iostream>
using namespace std;
    int uniqueNum(int arr[],int n){
        int xorsum = 0;
        for(int i=0;i<n;i++){
            xorsum = xorsum ^ arr[i];
        }return xorsum;}
int main(){
    int arr[] = {1,2,5,1,3,2,3};
        cout<<uniqueNum(arr,7)<<endl;
        return 0;
}