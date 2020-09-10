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

    bool check_is_tree(int src)
    {
        int *visited = new int[V];
        int *parent = new int[V];
        queue<int> q;

        // Initially no node is visited and parent of each node is node itseff;
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            visited[i] = false;
        }

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : l[node])
            {
                if (visited[nbr] == true && parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = node;
                }
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
    // g.addEdge(0, 3);

    cout << g.check_is_tree(0);
}