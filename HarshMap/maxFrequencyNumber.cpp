// 13
// 2 12 2 11 -6 -12 2 -1 2 2 11 12 2
// Output: 2 (2 is occuring maximum number of times)

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int maxFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    //           <maxAns, maxFreq>
    int maxAns = 0;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
        }
    }
    return maxAns;
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxFrequency(arr, n) << endl;
    return 0;
}