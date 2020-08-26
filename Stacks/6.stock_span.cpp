#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res[n];
    // One for storing idx and other for storing number
    stack<pair<int, int>> s;
    s.push(make_pair(0, a[0]));
    res[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (s.top().second > a[i])
        {
            res[i] = 1;
            s.push(make_pair(i, a[i]));
        }
        else
        {
            while (!s.empty() && s.top().second <= a[i])
            {
                s.pop();
            }
            // Subtract index to get span else index+1
            !s.empty() ? res[i] = i - s.top().first : res[i] = i + 1;
            s.push(make_pair(i, a[i]));
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "END";
}