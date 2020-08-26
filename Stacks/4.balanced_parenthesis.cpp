#include <iostream>
#include <stack>
using namespace std;

bool check_balanced_parenthesis(string s)
{
    stack<char> p;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            p.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (p.top() != '(')
            {
                if (p.top() == '{' || p.top() == '[')
                {
                    return false;
                }
                p.pop();
            }
            p.pop();
        }
        else if (s[i] == '}')
        {
            while (p.top() != '{')
            {
                if (p.top() == '(' || p.top() == '[')
                {
                    return false;
                }
                p.pop();
            }
            p.pop();
        }
        else if (s[i] == ']')
        {
            while (p.top() != '[')
            {
                if (p.top() == '(' || p.top() == '{')
                {
                    return false;
                }
                p.pop();
            }
            p.pop();
        }
        else
        {
            p.push(s[i]);
        }
    }

    if (p.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    check_balanced_parenthesis(s) ? cout << "Yes" : cout << "No";
}