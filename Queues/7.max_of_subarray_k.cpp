#include <iostream>
#include <deque>
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
    int k, i;
    cin >> k;

    // Need to store a window of maximum k
    deque<int> Q(k);

    //index of largest first k elements
    for (i = 0; i < k; i++)
    {
        while (!Q.empty() && a[i] > a[Q.front()])
        {
            Q.pop_front();
        }
        Q.push_back(i);
    }

    //Process the remaining elements
    for (; i < n; i++)
    {
        cout << a[Q.front()] << " ";

        //remove the elements which are not the part of window
        while (!Q.empty() && Q.front() <= (i - k))
        {
            Q.pop_front();
        }

        // remove the elements which are smaller in window - not reqd
        while (!Q.empty() && a[Q.front()] < a[i])
        {
            Q.pop_front();
        }
        Q.push_back(i);
    }
}