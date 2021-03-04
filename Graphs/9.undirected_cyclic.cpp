#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

// Given a undirected graph . Check if the cyclic exists using dfs
class Graph
{
public:
    int V;
    map<int, list<int>> l;

    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cyclic_helper(int src, bool *visited, int *parent)
    {
        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (visited[nbr] == true && parent[src] != nbr)
            {
                return true;
            }
            else if (visited[nbr] != true)
            {
                parent[nbr] = src;
                bool ans = cyclic_helper(nbr, visited, parent);
                if (ans)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool check_cyclic(int src)
    {
        bool *visited = new bool[V];
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        return cyclic_helper(src, visited, parent);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    // g.addEdge(4, 2);
    cout << g.check_cyclic(0);
}