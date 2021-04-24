#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> x;
        vector<int> y;

        int w, h, n;
        cin >> w >> h >> n;

        for (int i = 0; i < n; i++)
        {
            int xco, yco;
            cin >> xco >> yco;
            x.push_back(xco);
            y.push_back(yco);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int dx = x[0] - 1;
        int dy = y[0] - 1;

        for (int i = 1; i < n; i++)
        {
            dx = max(dx, x[i] - x[i - 1] - 1);
            dy = max(dy, y[i] - y[i - 1] - 1);
        }

        dx = max(dx, w - x[n - 1] - 1);
        dy = max(dy, h - y[n - 1] - 1);

        cout << dx * dy << endl;
    }
}