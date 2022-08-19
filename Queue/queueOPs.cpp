#include <iostream>
using namespace std;

#define n 20

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void pushENQUEUE(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        back++;
        arr[back] = x;
    }

    int popDEQUEUE()
    {
        if (front == -1 || front > back)
        {
            cout << "no element in queue" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        if (front > back)
        {
            front = -1;
            back = -1;
        }
        return x; // removed element
    }

    int topPEEK()
    {
        if (front == -1 || front > back)
        {
            cout << "no element in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.pushENQUEUE(1);
    q.pushENQUEUE(2);
    q.pushENQUEUE(3);
    q.pushENQUEUE(4);
    cout << q.topPEEK() << endl;
    cout << q.popDEQUEUE() << endl;
    cout << q.topPEEK() << endl;
    q.popDEQUEUE();
    q.popDEQUEUE();
    q.popDEQUEUE();
    cout << q.topPEEK() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}