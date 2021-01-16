#include <iostream>
#include <stack>
using namespace std;

// Space O(1); time O(n)
void small_number(string in)
{
    int res[in.length() + 1];
    int cnt = 1;
    int i;
    for (i = 0; in[i] != '\0'; i++)
    {
        if (in[i] == 'I')
        {
            res[i] = cnt;
            cnt++;
            int j = i - 1;

            while (j >= 0 && in[j] != 'I')
            {
                res[j] = cnt;
                cnt++;
                j--;
            }
        }
    }

    res[i] = cnt;
    cnt++;
    int j = i - 1;
    while (j >= 0 && in[j] != 'I')
    {
        res[j] = cnt;
        cnt++;
        j--;
    }

    for (auto x : res)
    {
        cout << x;
    }
}

// Space O(n)
int main()
{
    string str;
    cin >> str;
    stack<int> s;
    small_number(str);
    // int cnt = 1;

    // for (int i = 0; str[i] != '\0'; i++)
    // {
    //     if (str[i] == 'D')
    //     {
    //         s.push(cnt);
    //         cnt++;
    //     }
    //     else
    //     { // it will be I so print in reverse order
    //         s.push(cnt);
    //         cnt++;
    //         while (!s.empty())
    //         {
    //             cout << s.top();
    //             s.pop();
    //         }
    //     }
    // }

    // //one num is left;
    // s.push(cnt);
    // while (!s.empty())
    // {
    //     cout << s.top();
    //     s.pop();
    // }
}