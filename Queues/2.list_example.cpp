//Oueue implementation using linked list
#include <iostream>
#include <list>
using namespace std;

class Queue
{
    list<int> l;
    int cs;

public:
    Queue()
    {
        cs = 0;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    // Don't need full because list is not full

    void push(int d)
    {
        l.push_back(d);
        cs++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            l.pop_front();
            cs--;
        }
    }

    int getFront()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 6; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
}