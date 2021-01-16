#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '^')
    {
        return 3;
    }
}

string infix_to_postfix(string s)
{
    stack<string> oprnds;
    stack<char> optor;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string t(1, s[i]);
            oprnds.push(t); //char mein khali string add karne se string mein change
        }
        else if (s[i] == '(')
        {
            optor.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!optor.empty() && optor.top() != '(')
            {
                char topOperator = optor.top();
                optor.pop();
                string v2 = oprnds.top();
                oprnds.pop();
                string v1 = oprnds.top();
                oprnds.pop();
                string t(1, topOperator);
                oprnds.push(v1 + v2 + t); //postorder
                // In case of preorder conversion order changes: t + v1 + v2
            }
            optor.pop();
        }
        else if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '^')
        {
            while (!optor.empty() && optor.top() != '(' && precedence(s[i]) <= precedence(optor.top()))
            {
                char topOperator = optor.top();
                optor.pop();
                string v2 = oprnds.top();
                oprnds.pop();
                string v1 = oprnds.top();
                oprnds.pop();
                string t(1, topOperator);
                oprnds.push(v1 + v2 + t); //postorder
            }

            optor.push(s[i]);
        }
    }

    while (!optor.empty())
    {
        char topOperator = optor.top();
        optor.pop();
        string v2 = oprnds.top();
        oprnds.pop();
        string v1 = oprnds.top();
        oprnds.pop();
        string t(1, topOperator);
        oprnds.push(v1 + v2 + t); //postorder
    }

    return oprnds.top();
}

int main()
{
    string s;
    cin >> s;
    cout << infix_to_postfix(s);
}