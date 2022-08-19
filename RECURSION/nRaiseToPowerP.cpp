// TODO: Calculate N raise to power P
#include <iostream>
using namespace std;

int RaiseToPower(int N, int P)
{
    if (P == 0)
        return 1;
    else
        return N * RaiseToPower(N, P - 1);
}

int main()
{
    int N, P;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter P: ";
    cin >> P;
    cout << "N raise to power P is: " << RaiseToPower(N, P);

    return 0;
}