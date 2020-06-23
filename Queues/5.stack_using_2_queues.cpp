//performing stack operation using 2 queues
#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    bool isEmpty()
    {
        return q1.empty() && q2.empty();
    }

    void push(int data)
    {
        if (q1.empty())
        {
            q1.push(data);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(data);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    void pop()
    {
        if (!q1.empty())
        {
            q1.pop();
        }
        else if (!q2.empty())
        {
            q2.pop();
        }
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.front();
        }
        else if (!q2.empty())
        {
            return q2.front();
        }
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 6; i++)
    {
        s.push(i);
    }
    s.pop();
    s.pop();
    s.pop();

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}