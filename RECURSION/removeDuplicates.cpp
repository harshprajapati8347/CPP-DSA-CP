#include<iostream>
using namespace std;

string removeDup(string str)
{
    if (str.length() == 0)
        return ""; //base case
    if (str.length() == 1)
        return str;
    if (str[0] == str[1])
        return removeDup(str.substr(1));
    else
        return str[0] + removeDup(str.substr(1));
}

int main()
{
    string str = "aaabbbccc";
    cout << removeDup(str) << endl;    
    return 0;
}