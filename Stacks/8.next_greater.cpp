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