// Find area of largest rectangle .
#include <iostream>
#include <climits>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int lb[n];
    int rb[n];

    lb[0] = -1;    // Default case
    rb[n - 1] = n; // Default case when no smaller element on right side

    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        if (a[s.top()] < a[i])
        {
            lb[i] = s.top();
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[s.top()] >= a[i])
            {
                s.pop();
            }

            s.empty() ? lb[i] = -1 : lb[i] = s.top();
            s.push(i);
        }
    }

    while (!s.empty())
        s.pop();
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[s.top()] < a[i])
        {
            rb[i] = s.top();
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[s.top()] >= a[i])
            {
                s.pop();
            }
            s.empty() ? rb[i] = n : rb[i] = s.top();
            s.push(i);
        }
    }

    long long maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long int curr = (rb[i] - lb[i] - 1) * a[i];
        maxArea = max(maxArea, curr);
    }
    cout << maxArea;
}