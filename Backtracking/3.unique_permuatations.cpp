#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void permuatations(char *s, int i, char *out, int j)
{
    if (s[i] == '\0')
    {
        out[j] = '\0';
        string t(out);
        cout << out << " ";
        return;
    }

    for (int k = i; s[k] != '\0'; k++)
    {
        if (k != i && s[k] == s[i]) // Condition for unique permuatations
        {
            continue;
        }
        out[j] = s[k];
        swap(s[k], s[i]);
        permuatations(s, i + 1, out, j + 1);
        swap(s[i], s[k]);
    }
}

int main()
{
    char s[100];
    cin >> s;
    int n = 4;
    char out[100];
    sort(s, s + n);
    cout << s << endl;
    permuatations(s, 0, out, 0);
}

//Optimised approach : https: //www.geeksforgeeks.org/distinct-permutations-string-set-2/