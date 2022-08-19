#include <iostream>
#include <vector>
using namespace std;

vector<int> circularArrayRotation(vector<int> arr, int k, vector<int> queries)
{
    int n = arr.size();
    for(int i = 0; i < k; i++){
        
    }
    vector<int> result;
    for(int i = 0; i < queries.size(); i++){
        result.push_back(arr[queries[i]]);
    }
    return result;
};

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i];
    vector<int> result = circularArrayRotation(a, k, queries);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " "; 
    
    return 0;
}