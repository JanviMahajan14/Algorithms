// First negative integer in every window of size k
#include <iostream>
#include <queue>
using namespace std;

void first_negative_in_window(int a[], int n, int k)
{
    int i = 0;
    int j = 0;
    int ans = 0;
    queue<int> q; //for storing negative numbers

    for (j = 0; j < k; j++)
    {
        if (a[j] < 0)
        {
            q.push(a[j]);
        }
    }
    q.empty() ? ans = 0 : ans = q.front();
    cout << ans << " ";

    while (j < n)
    {
        if (a[j] < 0)
        {
            q.push(a[j]);
        }
        if (a[i] >= 0)
        {
            q.empty() ? ans = 0 : ans = q.front();
            cout << ans << " ";
        }
        else
        {
            q.pop();
            q.empty() ? ans = 0 : ans = q.front();
            cout << ans << " ";
        }
        i++;
        j++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k;
        cin >> k;
        first_negative_in_window(a, n, k);
        cout << endl;
    }
}