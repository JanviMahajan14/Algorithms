#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
class Stack
{

    //We don't want stack to be accessed by anyone directly
private:
    vector<T> v;
    vector<U> v2;

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

    T top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack<char, char> s;
    for (int i = 65; i <= 70; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}