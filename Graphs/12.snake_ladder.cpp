#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<int> arr[37];

public:
    Graph(int v = 37)
    { //vertices from 0-36
        vertices = v;
    }

    void addEdge(int a, int b)
    {
        arr[a].push_back(b);
    }

    void shortest_bfs(int src, int dest)
    {
        queue<int> q;
        int dist[37] = {0};
        for (int i = 0; i <= 36; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        q.push(src);

        // We also need to store path --so keep an array of parent and backtrack
        int parent[37] = {0};
        parent[src] = src; //mark parent of src as src itself

        while (!q.empty())
        {
            int src = q.front();
            q.pop();

            for (auto nbr : arr[src])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[src] + 1;
                    parent[nbr] = src;
                }
            }
        }

        cout << dist[dest] << endl;
        // Print the path

        int temp = dest;
        while (temp != src)
        {
            cout << temp << "<-";
            temp = parent[temp];
        }
        cout << src;
    }
};

int main()
{
    int board[37] = {0};

    //Snakes //Ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //Add edges to graphs
    Graph g;

    for (int i = 0; i <= 36; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            int a = i;
            int b = a + j; //we need to add jump
            b += board[b];
            if (b <= 36)
            {
                g.addEdge(a, b);
            }
        }
    }

    g.shortest_bfs(0, 36);
}