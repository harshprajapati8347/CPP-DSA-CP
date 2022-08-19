#include <iostream>
using namespace std;

class Number
{
private:
    int num;

public:
    Number(int x)
    {
        num = x;
    }
    Number()
    {
        num = 0;
    }
    void printNumber()
    {
        cout << "Number is : " << num << endl;
    }

    Number operator++()
    {
        Number temp;
        temp.num = ++num;
        return temp;
    }
    Number operator++(int)
    {
        Number temp;
        temp.num = num++;
        return temp;
    }

    // same concept for decrement
};

int main()
{
    Number obj1, obj2;
    obj1 = ++obj1;
    obj2 = obj2++;
    obj1.printNumber();
    obj2.printNumber();

    return 0;
}