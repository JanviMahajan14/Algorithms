#include <iostream>
#include <vector>
using namespace std;

int count_string(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    return count_string(n - 1) + count_string(n - 2);
}

void generate_strings(string s, int n, vector<string> &out)
{
    if (n == 0)
    {
        out.push_back(s);
        return;
    }

    if (n < 0) //Case if an extra int is pushed
    {
        s.pop_back();
        out.push_back(s);
        return;
    }

    s.push_back('0');
    generate_strings(s, n - 1, out);

    s.pop_back();
    s.push_back('1');
    s.push_back('0');
    generate_strings(s, n - 2, out);
}

int main()
{
    int n;
    cin >> n;
    vector<string> out;
    cout << count_string(n);
    cout << endl;
    generate_strings("", n, out);
    for (auto x : out)
    {
        cout << x << " ";
    }
}