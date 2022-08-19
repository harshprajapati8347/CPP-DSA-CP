#include <bits/stdc++.h> // Vector
#include <algorithm>     // Sort
using namespace std;

bool myCompare (pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
};

int main()
{
    int arr[] = {10,16,7,14,5,3,2,9};
    vector <pair <int , int> > v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
    {
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(),myCompare);
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}