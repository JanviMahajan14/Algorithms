//Longest Substring with At Most K Distinct Characters---LC
#include <iostream>
#include <unordered_map>
using namespace std;

int max_toys(string s, int k)
{
    int ans = 0;
    unordered_map<char, int> m;
    int i = 0;
    int j = 0;

    for (j = 0; j < s.length(); j++)
    {
        if (m.size() < k || m.count(s[j]))
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

    ans = max(ans, j - i);
    return ans;
}

int main()
{
    string s = "abaccab";
    int k = 2;
    cout << max_toys(s, k);
}
