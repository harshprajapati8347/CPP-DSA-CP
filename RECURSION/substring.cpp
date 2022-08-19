#include<iostream>
using namespace std;

void subSeq(string s, string ans){
    if(s.length() == 0){ //base case
        cout << ans << endl;
        return;
    }
    subSeq(s.substr(1), ans);
    subSeq(s.substr(1), ans + s[0]);
}

int main()
{
    string s = "abc";
    subSeq(s, "");
    return 0;
}