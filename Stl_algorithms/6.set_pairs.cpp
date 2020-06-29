#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<pair<int, int>> s;
    s.insert(make_pair(2, 4));
    s.insert(make_pair(10, 4));
    s.insert(make_pair(10, 20));
    s.insert(make_pair(2, 6));

    for (auto it : s)
    {
        cout << it.first << "," << it.second << endl;
    }

    auto iter = s.lower_bound(make_pair(10, 4));
    auto tell = s.upper_bound(make_pair(10, 4));
    cout << iter->first << "," << iter->second << ": " << tell->first << "," << tell->second;
}