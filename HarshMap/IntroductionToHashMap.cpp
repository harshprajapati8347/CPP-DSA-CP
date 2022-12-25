#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    //! creation
    unordered_map<string, int> m;

    // insertion (Single entry of unique key)

    // 1
    pair<string, int> pair1 = make_pair("my", 3);
    m.insert(pair1);

    // 2
    pair<string, int> pair2("name", 2);
    m.insert(pair2);

    // 3
    m["harsh"] = 1; // entry creation
    m["harsh"] = 2; // entry updation

    //! Search => dunctions 1. at()

    cout << m["my"] << endl;
    cout << m.at("harsh") << endl;
    // cout << m.at("unKnownKey") << endl;
    cout << m["unKnownKey"] << endl;

    //! size()
    cout << m.size() << endl;

    // to check presence
    //! functions 1. count (return => Absent=0,Present=1) 2. find
    cout << m.count("bro") << endl;

    //! erase()
    m.erase("harsh");
    cout << m.size() << endl;

    //! Traversal
    // 1
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    // 2 using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}