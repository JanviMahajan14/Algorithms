#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;

    // Insert
    m.insert(make_pair("banana", 20));
    m["pineapple"] = 50;
    m["kiwi"] = 100;
    m["apple"] = 10;

    //Searching
    auto it = m.find("litchi");
    if (it != m.end())
    {
        cout << "It is present" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // Other way of searching with cnt which returns bool
    if (m.count("jel"))
    {
        cout << "It is present" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // deletion
    m.erase("banana");

    // iteration
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << (*it).first << ":" << (*it).second << endl;
    // }

    for (auto x : m)
    {
        cout << x.first << ":" << x.second << endl;
    }
}