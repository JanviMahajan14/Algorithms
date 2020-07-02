#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<int> pq; //by default max_heap
    priority_queue<int, vector<int>, greater<int>> pq; //to change order

    int in;
    cin >> in;
    while (in != -1)
    {
        pq.push(in); //O(logn)
        cin >> in;
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
