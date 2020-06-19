#include <iostream>
#include <stack>
using namespace std;

bool check_balanced_parenthesis(string s)
{
    stack<char> p;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            p.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (p.empty()) //heve no open bracket
            {
                return false;
            }
            p.pop();
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << check_balanced_parenthesis(s);
}