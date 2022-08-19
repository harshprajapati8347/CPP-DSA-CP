#include<iostream>
using namespace std;

string moveXtoEOS(string str)
{
    if (str.length() == 0)
        return ""; //base case
    if (str.length() == 1)
        return str;
    if (str[0] == 'x')
        return moveXtoEOS(str.substr(1));
    else
        return str[0] + moveXtoEOS(str.substr(1));
}

int main()
{
    string str = "axbxcxdxexfx";
    cout << moveXtoEOS(str) << endl;
    
    return 0;
}