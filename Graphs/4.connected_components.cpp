#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

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
        l[y].push_back(x); //Assuming bidirectional
    }

    void dfs_helper(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (visited[nbr] != true)
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(int src)
    {
        map<int, bool> visited;
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] != true)
            {
                dfs_helper(i, visited);
                cnt++;
            }
        }

        cout << endl
             << cnt;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.dfs(0);
}