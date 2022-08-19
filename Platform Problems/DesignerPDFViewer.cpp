#include "bits/stdc++.h"
using namespace std;

int designerPdfViewer(vector<int> h, string word){
    int maxHeight = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (h[word[i] - 'a'] > maxHeight)
        {
            maxHeight = h[word[i] - 'a'];
        }
    }
    return maxHeight * word.size();
}

int main()
{
    vector<int> a(26);
    for (int i = 0; i < 26; i++)
        cin >> a[i];
    string word;
    cin >> word;
    cout << designerPdfViewer(a, word);
    return 0;
}