#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *l;

    Graph(int vertices)
    {
        V = vertices;
        l = new list<int>[V]; //arrayList
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x); // Assuming we are creating a bidirectional edge
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto x : l[i])
            {
                cout << x << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.print();
}