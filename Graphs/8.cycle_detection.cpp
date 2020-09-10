#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

// Given a directed graph . Check if the cyclic exists using dfs
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
    }

    bool cyclic_helper(int src, bool *visited, bool *stack)
    {
        visited[src] = true;
        stack[src] = true;

        for (auto nbr : l[src])
        {
            if (stack[nbr] == true && visited[nbr] == true)
            {
                return true;
            }
            else if (!visited[nbr])
            {
                bool ans = cyclic_helper(nbr, visited, stack);
                if (ans)
                {
                    return true;
                }
            }
        }

        stack[src] = false;
        return false;
    }

    bool iscyclic(int src)
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = false;
        }
        return cyclic_helper(src, visited, stack);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);
    cout << g.iscyclic(0);
}