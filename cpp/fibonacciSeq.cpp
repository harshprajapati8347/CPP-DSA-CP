#include <iostream>
using namespace std;
// 0,1,1,2,3,5,8,13,21,34
void fibonacciSeq(int n)
{
    int a = 0, b = 1, c = 0;
    cout << a << " " << b << " ";
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    fibonacciSeq(n);
    return 0;
}