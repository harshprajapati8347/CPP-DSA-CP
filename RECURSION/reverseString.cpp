#include<iostream>
using namespace std;

void reverseString(string s){
    if(s.length() == 0){ // base case
        return;
    }
    string ros = s.substr(1); // first character
    reverseString(ros);
    cout << s[0];
}

int main()
{
    reverseString("binod");
    return 0;
}