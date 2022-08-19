#include <iostream>
using namespace std;
// Largest Word in a Sentence - DO OR DIE
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];

    cin.getline(arr, n);
    cin.ignore();

    int i = 0, curLen = 0, maxLen = 0;

    while (1)
    {
        if(arr[i] == " " || arr[i] == '\0')
        {
            if(curLen > maxLen)
                maxLen = curLen;
            i = 0;
        }
        else
        {
            i++;
        }


        curLen++;

        if(arr[i] == '\0')
            break;
        i++;
    }
    cout << maxLen;

    return 0;
}