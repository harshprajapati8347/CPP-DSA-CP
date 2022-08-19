#include <iostream>
using namespace std;
#define n 100

class stack
{
    int top;
    int *arr;

public:
    stack()
    {
        top = -1;
        arr = new int[n];
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "No Element to pop" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }
    int topElement()
    {
        if (top == -1)
        {
            cout << "Stack is empty so not top" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    int size()
    {
        return top + 1;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.size() << endl;
    s.pop();
    cout << s.topElement() << endl; //2
    s.pop();
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl; // true === 1
    return 0;
}