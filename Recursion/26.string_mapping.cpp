// We are given a hashmap which maps all the letters with number.
// Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z.
// Given a number, you have to print all the possible strings.
// ex: 123 Output: [ABC, AW, LC], 102 : [JB]

#include <iostream>
#include <map>
using namespace std;

void print(map<int, char> m, string s, char out[], int i, int j)
{
    if (s[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    if (s[i + 1] != '0' && s[i] != '0') //edge cases
    {                                   //Modified
        out[j] = m[s[i] - '0'];
        print(m, s, out, i + 1, j + 1);
    }

    if (s[i + 1] != '\0' && s[i] != '0') //edge cases
    {

        int a = s[i] - '0';
        int b = s[i + 1] - '0';
        int con = a * 10 + b;
        if (con > 26)
        {
            return;
        } // Important condition testcase failing ----
        out[j] = m[con];
        print(m, s, out, i + 2, j + 1);
    }
}

int main()
{
    map<int, char> m;
    m[1] = 'A';
    for (int i = 2; i <= 26; i++)
    {
        m[i] = m[i - 1] + 1;
    }

    string s;
    cin >> s;
    char out[s.length() + 1];
    print(m, s, out, 0, 0);
}