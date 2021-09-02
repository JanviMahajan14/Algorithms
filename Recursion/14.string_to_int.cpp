#include <iostream>
using namespace std;

int string_to_int(string n, int len)
{
    if (len == 0)
    {
        return 0;
    }
    int ans = string_to_int(n, len - 1);
    int digit = n[len - 1] - '0';
    return ans * 10 + digit;
    //in qs where we need to define initial values like ans=1 or cnt=1 of some variables return the initial
    // value from the base case;
}

int string_to_int(string n, int i, int &p)
{
    if (i == n.length())
    {
        return 0;
    }

    int ans = string_to_int(n, i + 1, p);
    int sum = ans + (n[i] - '0') * p;
    p = p * 10;
    return sum;
}

int main()
{
    string n;
    cin >> n;
    // cout << string_to_int(n, n.length()) << endl;
    // cout << string_to_int(n, n.length()) + 1;
    int p = 1;
    cout << string_to_int(n, 0, p);
}