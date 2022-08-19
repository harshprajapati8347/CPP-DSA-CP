#include <iostream>
using namespace std;
int noOf1s(int n)
{
    int count = 0;
    while (n)
    {
        n = (n & (n - 1));
        count++;
    }
    return count;
}
int main()
{
    cout << noOf1s(19) << endl;
    return 0;
}