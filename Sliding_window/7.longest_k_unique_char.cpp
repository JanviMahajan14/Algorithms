#include <iostream>
#include <unordered_map>
using namespace std;

int longest_k_unique_char_substring(string s, int k)
{
    int ans = 0;
    int i = 0;
    int j = 0;
    unordered_map<char, int> m; //for storing frequency

    for (j = 0; j < s.length(); j++)
    {
        if (m.size() != k || m.count(s[j])) // Conditon imp
        {
            !m.count(s[j]) ? m[s[j]] = 1 : m[s[j]]++;
        }
        else
        {
            ans = max(ans, j - i);
            while (m.size() != 0 && m.size() == k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }

            m[s[j]] = 1;
        }
    }

    if (m.size() != k) // Edge case--------if unique characters are less than k
    {
        return -1;
    }

    ans = max(ans, j - i);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        cout << longest_k_unique_char_substring(s, k) << endl;
    }
}