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
    }

    void topological_sort()
    {
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {
            for (auto x : l[i])
            {
                indegree[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int Node = q.front();
            cout << Node << " ";
            q.pop();
            for (auto nbr : l[Node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    g.addEdge(2, 5);
    g.addEdge(4, 5);

    g.addEdge(5, 3);

    g.topological_sort();
}