//Implementation of connected components in graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    unordered_map<int, list<int>> l;

    Graph(int ver)
    {
        V = ver;
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(int src, bool *visited, int &comp)
    {

        visited[src] = true;
        comp++;

        for (auto nbr : l[src])
        {
            if (visited[nbr] != true)
            {
                dfs(nbr, visited, comp);
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int x, y;

    Graph g(n);
    while (m--)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }

    int cnt = 0;

    int comp;
    vector<int> components; // include size of each components

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            comp = 0;
            g.dfs(i, visited, comp);
            components.push_back(comp);
            cnt++; //Includes total size of connected components
        }
    }

    int ans = 0;
    for (int i = 0; i < components.size(); i++)
    {
        for (int j = i + 1; j < components.size(); j++)
        {
            int pair = components[i] * components[j];
            ans = ans + pair;
        }
    }

    cout << ans;
}