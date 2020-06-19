#include <iostream>
#include <vector>
using namespace std;

class Stack
{

    //We don't want stack to be accessed by anyone directly
private:
    vector<int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }

    void pop()
    {
        if (!isEmpty())
        {
            v.pop_back();
        }
    }

    int top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack s;
    for (int i = 1; i < 6; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}