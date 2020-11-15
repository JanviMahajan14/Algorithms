#include <iostream>
#include <stack>
using namespace std;

class specialStack
{
    stack<int> s;
    stack<int> min_stack;
    stack<int> max_stack;

public:
    void push(int data)
    {

        if (s.size() == 0)
        {
            s.push(data);
            min_stack.push(data);
            max_stack.push(data);
        }

        else
        {
            s.push(data);
            int curr_min = min(min_stack.top(), data);
            int curr_max = max(max_stack.top(), data);
            min_stack.push(curr_min);
            max_stack.push(curr_max);
        }
    }

    void pop()
    {
        s.pop();
        min_stack.pop();
        max_stack.pop();
    }

    int top()
    {
        return s.top();
    }

    int get_min()
    {
        return min_stack.top();
    }

    int get_max()
    {
        return max_stack.top();
    }
};

int main()
{
    specialStack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);
    cout << s.get_max() << endl;
    s.pop();
    cout << s.get_max() << endl;
    cout << s.get_min() << endl;

    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.get_max() << endl;
}
