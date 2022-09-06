// Sliding Window Maximum
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;    
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back(); // remove all smaller elements
        dq.push_back(i); // add current element
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << endl;
    return 0;
}

// input: 9 3
// 1 3 -1 -3 5 3 6 7

// output: 3 3 5 5 6 7
// Time Complexity: O(n)
// Space Complexity: O(k)
