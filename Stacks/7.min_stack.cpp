#include <iostream>
#include <stack>
using namespace std;

class specialStack
{
    stack<int> s;
    int min;

public:
    void push(int data)
    {

        if (s.size() == 0)
        {
            s.push(data);
            min = data;
        }

        else
        {
            if (data >= min)
            {
                s.push(data);
            }
            else
            {
                s.push(data + (data - min)); //making a mark to detect top < min
                min = data;
            }
        }
    }

    void pop()
    {
        if (s.size() == 0)
            return;
        int top = s.top();
        s.pop();
        if (top >= min)
        {
            return;
        }
        else
        {
            min = 2 * min - top;
            return;
        }
    }

    int top()
    {
        if (s.size() == 0)
        {
            return -1;
        }
        else
        {
            if (s.top() >= min)
            {
                return s.top();
            }
            else //mark detected
            {
                return min;
            }
        }
    }

    int get_min()
    {
        return min;
    }
};

int main()
{
    specialStack s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(1);
    cout << s.get_min() << " ";
    s.pop();
    cout << s.get_min() << " ";
    cout << s.top() << " ";
    s.pop();
    cout << s.get_min() << " ";
}
