#include <iostream>
using namespace std;

void subSeqAscii(string s, string ans)
{
    if (s.length() == 0)
    { // base case
        cout << ans << endl;
        return;
    }
    char c = s[0]; // get the first character
    int code = c; // get the ascii code of the character
    string ros = s.substr(1); // remove the first character from the string
    
    subSeqAscii(ros, ans); // call the function again
    subSeqAscii(ros, ans + c); // add the character to the answer
    subSeqAscii(ros, ans + to_string(code)); // add the ascii code to the answer
}

int main()
{
    string s = "AB";
    subSeqAscii(s, "");
    return 0;
}