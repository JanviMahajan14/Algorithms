#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class Graph
{

    unordered_map<string, vector<pair<string, int>>> m;

public:
    void addEdge(string a, string b, int weight, bool bidirectional = false)
    {
        m[a].push_back(make_pair(b, weight));
        if (bidirectional)
        {
            m[b].push_back(make_pair(a, weight));
        }
    }

    void print()
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
            cout << it->first << " :";

            for (int i = 0; i < it->second.size(); i++)
            {
                pair<string, int> p = it->second[i];
                cout << p.first << "-" << p.second << ",";
            }
            cout << endl;
        }
    }

    void dijktra(string src)
    {
        unordered_map<string, int> dis;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            dis[i->first] = INT_MAX;
        }

        // Pick the one which is at min dist;
        set<pair<int, string>> s; //set mein by default sorting on the basis of first para
        dis[src] = 0;
        s.insert(make_pair(dis[src], src));

        while (!s.empty())
        {
            pair<int, string> p = *(s.begin());
            string src = p.second;
            int dist = p.first;
            //in case we have to find min distance of target node then break the
            //loop when target==*s.begin() because it is min distance from src.

            // erase the first node in the set because this distance is finalised
            s.erase(s.begin());

            for (auto nbr : m[src])
            {
                if (nbr.second + dist < dis[nbr.first])
                {
                    //if node already exists in set then delete it first and then update
                    auto f = s.find(make_pair(dis[nbr.first], nbr.first));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    dis[nbr.first] = nbr.second + dist;
                    s.insert(make_pair(dis[nbr.first], nbr.first));
                }
            }
        }

        for (auto it = dis.begin(); it != dis.end(); it++)
        {
            cout << it->second << " " << it->first << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("Amritsar", "Delhi", 8, true);
    g.addEdge("Amritsar", "Jaipur", 4);
    g.addEdge("Jaipur", "Delhi", 2);
    g.addEdge("Jaipur", "Mumbai", 8);
    g.addEdge("Bhopal", "Agra", 2);
    g.addEdge("Mumbai", "Bhopal", 3);
    g.addEdge("Agra", "Delhi", 1);

    g.dijktra("Amritsar");
}