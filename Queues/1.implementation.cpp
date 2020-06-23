//Oueue implementation using dynamic arrays
#include <iostream>
using namespace std;

class Queue
{
    int *arr, f, r, cs, ms;

public:
    Queue(int n = 5)
    {
        arr = new int[n];
        f = 0;
        r = n - 1;
        cs = 0;
        ms = n;
    }

    bool isFull()
    {
        return cs == ms;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    void push(int d)
    {
        if (!isFull())
        {
            r = (r + 1) % ms;
            arr[r] = d;
            cs++;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int getFront()
    {
        return arr[f];
    }

    //To destroy the heap memory
    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
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

    q.push(7);

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
}