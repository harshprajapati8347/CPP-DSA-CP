#include <iostream>
using namespace std;

class Number
{
    int x;
    int y;

public:
    Number()
    {
        x = 0;
        y = 0;
    }
    Number(int n, int p)
    {
        x = n;
        y = p;
    }
    void displayNumber()
    {
        cout << "x: " << x << " And y: " << y << endl;
    }
    Number operator-()
    {
        x = -x;
        y = -y;
        return Number(x, y);
    }
};

int main()
{
    Number n1(-2, 10);
    -n1;
    n1.displayNumber();
    return 0;
}