#include <iostream>
#include <stack>
using namespace std;

void next_greater(int arr[], int n)
{
    stack<int> s; // for holding next max
    int ans[n];   //contains ans

    ans[n - 1] = -1;
    s.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }

        if (s.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
}

// In case of circular array------Just follow the same above approach. But some elements
// may have incorrect answers. So do 2 traversals i.e one more starting from the end
int main()
{
    stack<int> s;
    int n;
    cin >> n;
    int a[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    s.push(a[n - 1]);
    res[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (s.top() > a[i])
        {
            res[i] = s.top();
            s.push(a[i]);
        }
        else
        {
            while (!s.empty() && s.top() <= a[i])
            {
                s.pop();
            }
            s.empty() ? res[i] = -1 : res[i] = s.top();
            s.push(a[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.top() > a[i])
        {
            res[i] = s.top();
            s.push(a[i]);
        }
        else
        {
            while (!s.empty() && s.top() <= a[i])
            {
                s.pop();
            }
            s.empty() ? res[i] = -1 : res[i] = s.top();
            s.push(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}