// Heaps - Median of Running Stream

#include <iostream>
#include <queue>
    using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x)
{
    if (pqmin.size() == pqmax.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }
        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        { // Two cases
            // case1: size of maxHeap > size of minHeap
            // case2: size of maxHeap < size of minHeap
            if (pqmax.size() > pqmin.size())
            {
                if (x < pqmax.top())
                {
                    pqmin.push(pqmax.top());
                    pqmax.pop();
                    pqmax.push(x);
                }
                else
                {
                    pqmin.push(x);
                }
            }
            else
            {
                if (x <= pqmin.top())
                {
                    pqmax.push(x);
                }
                else
                {
                    pqmax.push(pqmin.top());
                    pqmin.pop();
                    pqmin.push(x);
                }
            }
        }
    }
}

double findMedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            return pqmax.top();
        }
        else
        {
            return pqmin.top();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(x);
        cout << findMedian() << endl;
    }

    return 0;
}

// Input: 6
// 10 15 21 30 18 19
// Output:
// 10 12.5 15 18 18 18.5
// TC: O(nlogn)
// SC: O(n)
// https://www.youtube.com/watch?v=NIUgvZxt3Lg&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=131
