#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

// Given a undirected graph . Check if it is a tree
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

    bool iscyclic(int src, int *visited, int *parent)
    {
        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (visited[nbr] && parent[src] != nbr)
            {
                return true;
            }

            if (!visited[nbr])
            {
                parent[nbr] = src;
                return iscyclic(nbr, visited, parent);
            }
        }
        return false;
    }

    bool check_is_tree(int src)
    {

        int *visited = new int[V];
        int *parent = new int[V];

        // Initially no node is visited and parent of each node is node itseff;
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            visited[i] = false;
        }

        if (iscyclic(src, visited, parent))
        {
            return false;
        }

        for (int i = 0; i < V; i++) //check if all components are connected
        {
            if (!visited[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);

    cout << g.check_is_tree(0);
}