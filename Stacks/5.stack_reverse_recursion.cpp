#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int top)
{
    if (s.empty())
    {
        s.push(top);
        return;
    }
    int x = s.top();
    s.top();
    insertAtBottom(s, top);
    s.push(x);
}

void stack_reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    stack_reverse(s);
    insertAtBottom(s, top);
}

int main()
{
    stack<int> s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push(x);
    }
    stack_reverse(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}