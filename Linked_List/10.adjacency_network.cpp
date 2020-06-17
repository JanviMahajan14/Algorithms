#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n, e; //number of vertices and edges
    cin >> n >> e;
    list<pair<int, int>> l[n]; //Array of list
    int x, y, len;             //first vertex, second vertex, weight
    while (e--)
    {
        cin >> x >> y >> len;
        l[x].push_back(make_pair(y, len));
        l[y].push_back(make_pair(x, len));
    }

    for (int i = 0; i < n; i++)
    {
        for (auto x : l[i])
        {
            cout << i << ":";
            cout << x.first << "," << x.second << " ";
        }
        cout << endl;
    }
}