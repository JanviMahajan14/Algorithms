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

    void bfs(int src)
    {
        queue<int> q;
        map<int, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void shortest_path(int src)
    {
        queue<int> q;
        map<int, int> dist; //here visited will contain distance from source node
        q.push(src);

        for (auto x : l)
        {
            dist[x.first] = INT_MAX;
        }
        dist[src] = 0;

        while (!q.empty())
        {
            int Node = q.front();
            q.pop();

            for (auto nbr : l[Node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[Node] + 1;
                }
            }
        }

        for (auto d : dist)
        {
            cout << "Distance of " << d.first << " is " << d.second << endl;
        }
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
        dfs_helper(src, visited);
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0); //Sending source vertex
    cout << endl;
    // g.shortest_path(0);
    g.dfs(0);
}
