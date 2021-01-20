#include <iostream>
#include <unordered_map>
using namespace std;

int find_occurrences(string txt, string ptr)
{
    int ans = 0;
    unordered_map<char, int> m;
    // hashmap for second string
    for (auto x : ptr)
    {
        m.count(x) == 0 ? m[x] = 1 : m[x]++;
    }

    int i = 0;
    int j;
    int cnt = m.size(); //optimisation
    for (j = 0; j < ptr.length(); j++)
    {
        if (m.count(txt[j]))
        {
            m[txt[j]]--;
            if (m[txt[j]] == 0)
                cnt--;
        }
    }

    if (cnt == 0)
    {
        ans++;
    }

    while (j < txt.length())
    {
        // Since we have to remove the i
        if (m.count(txt[i]))
        {
            if (m[txt[i]] == 0)
                cnt++;
            m[txt[i]]++;
        }

        i++;
        if (m.count(txt[j]))
        {
            m[txt[j]]--;
            if (m[txt[j]] == 0)
                cnt--;
        }

        if (cnt == 0)
            ans++;
        j++;
    }
    return ans;
}

int main()
{
    string txt;
    string ptr;
    cin >> txt >> ptr;
    cout << find_occurrences(txt, ptr);
}