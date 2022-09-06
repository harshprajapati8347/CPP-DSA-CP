#include "bits/stdc++.h"
using namespace std;

// Queue using Stack : POP using recursion and one stack

class que
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int x = s1.top();
        s1.pop();
        cout << "Popped element is " << x << endl;
    }
    void top()
    {
        if (s1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int x = s1.top();
        cout << "Top element is " << x << endl;
    }
    bool isEmpty()
    {
        return s1.empty();
    }
};

int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.top();
    q.pop();
    q.pop();
    q.pop();
    q.top();

    return 0;
}