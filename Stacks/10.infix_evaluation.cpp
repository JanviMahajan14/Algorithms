#include <iostream>
#include <stack>
using namespace std;

int operation(int v1, int v2, char optor)
{
    if (optor == '+')
    {
        return v1 + v2;
    }
    else if (optor == '-')
    {
        return v1 - v2;
    }
    else if (optor == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}

int precedence(char optor)
{
    if (optor == '+' || optor == '-')
    {
        return 1;
    }
    else if (optor == '*' || optor == '/')
    {
        return 2;
    }
}

int main()
{
    stack<int> opnds;
    stack<char> optor;
    string s;
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            opnds.push(s[i] - '0');
        }
        else if (s[i] == '(')
        {
            optor.push(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {
            // CONDITION IMP
            while (!optor.empty() && optor.top() != '(' && precedence(s[i]) <= precedence(optor.top()))
            {
                char topOperator = optor.top();
                optor.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                int res = operation(v1, v2, topOperator);
                opnds.push(res);
            }
            optor.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!optor.empty() && optor.top() != '(')
            {
                char topOperator = optor.top();
                optor.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                int res = operation(v1, v2, topOperator);
                opnds.push(res);
            }
            optor.pop();
        }
    }

    while (!optor.empty())
    {
        char topOperator = optor.top();
        optor.pop();
        int v2 = opnds.top();
        opnds.pop();
        int v1 = opnds.top();
        opnds.pop();
        int res = operation(v1, v2, topOperator);
        opnds.push(res);
    }

    cout << opnds.top();
}