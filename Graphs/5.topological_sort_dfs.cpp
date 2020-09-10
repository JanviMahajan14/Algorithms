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
    map<string, list<string>> l;

    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(string x, string y)
    {
        l[x].push_back(y);
    }

    void dfs_helper(string src, map<string, bool> &visited, list<string> &result)
    {

        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (visited[nbr] != true)
            {
                dfs_helper(nbr, visited, result);
            }
        }

        result.push_front(src);
        return;
    }

    void dfs()
    {
        map<string, bool> visited;
        list<string> result;
        for (auto x : l)
        {
            if (visited[x.first] != true)
            {
                dfs_helper(x.first, visited, result);
            }
        }

        // Print the result list
        for (auto x : result)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    Graph g(9);
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("Python", "Data-processing");
    g.addEdge("Data-processing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FR");
    g.addEdge("Dataset", "FR");

    g.dfs();
}