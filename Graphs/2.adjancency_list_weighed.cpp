#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    int V;
    unordered_map<string, list<pair<string, int>>> l; //since we have char so we can't take arraylist

    Graph(int vertices)
    {
        V = vertices;
    }

    void addEdge(string x, string y, int w, bool bidirected)
    {
        l[x].push_back(make_pair(y, w));
        if (bidirected)
        {
            l[y].push_back(make_pair(x, w));
        }
    }

    void print()
    {
        for (auto it : l)
        {
            cout << it.first << "->";
            for (auto x : it.second)
            {
                cout << "(" << x.first << "," << x.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge("A", "B", 20, true); // true if bidirectional
    g.addEdge("B", "D", 30, true);
    g.addEdge("D", "C", 40, true);
    g.addEdge("C", "A", 10, true);
    g.addEdge("A", "D", 50, false);
    g.print();
}