#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end(), cmp);

        int res = 1;
        int prevFinishing = v[0].second;

        // Start picking activities
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= prevFinishing)
            {
                res++;
                prevFinishing = v[i].second;
            }
        }
        cout << res;
    }
}