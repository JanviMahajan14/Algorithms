#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--)
    {
        int in;
        cin >> in;
        pq.push(in);
    }

    int sum = 0;
    while (!pq.empty() && pq.size() != 1)
    {
        int r1 = pq.top();
        pq.pop();
        int r2 = pq.top();
        pq.pop();
        sum = sum + r1 + r2;
        pq.push(r1 + r2);
    }

    cout << sum;
}