#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    bool isEmpty()
    {
        return s1.size() == 0 && s2.size() == 0;
    }

    void push(int d)
    {
        s1.push(d);
    }

    void pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 6; i++)
    {
        q.push(i);
    }
    cout << q.front() << endl;
    cout << q.front() << endl;
    q.pop();
    q.pop();

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}