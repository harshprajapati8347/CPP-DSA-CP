// Set Intersection
// Find the intersection of two sorted lists of integers.Input : Your program should read lines of text from standard input.Each line will contain two comma separated lists of integers in ascending order,
//     one pair of lists per line.The lists are separated by a semicolon.Output : For each pair of input lists, print to standard output their sorted intersection in ascending order, comma separated, one intersection per line.
// Input  1, 2, 3, 4;4, 5, 6
// Output 4
#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.size();
    int a[1000] = {0};
    int b[1000] = {0};
    int c[1000] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    while (s[i] != ';')
    {
        if (s[i] != ',')
        {
            a[j] = a[j] * 10 + s[i] - '0';
        }
        else
        {
            j++;
        }
        i++;
    }
    i++;
    while (i < n)
    {
        if (s[i] != ',')
        {
            b[k] = b[k] * 10 + s[i] - '0';
        }
        else
        {
            k++;
        }
        i++;
    }
    int l = 0;
    for (int i = 0; i <= j; i++)
    {
        for (int m = 0; m <= k; m++)
        {
            if (a[i] == b[m])
            {
                c[l] = a[i];
                l++;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        cout << c[i];
        if (i != l - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
    
    
    return 0;
}