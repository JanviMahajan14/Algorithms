#include <iostream>
#include <stack>
using namespace std;

void find_span(int *arr, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
        }
        else
        {
            while (!s.empty() && s.top <= arr[i])
            {
                s.pop();
            }
            s.push(arr[i]);
        }
    }
}

int main()
{
    int arr[] = {100,
                 80,
                 60,
                 70,
                 60,
                 75,
                 85};

    find_span(arr, 7);
}