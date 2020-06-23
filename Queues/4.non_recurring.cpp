// Finding first non recuring chaacter in a given stream of characters
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};
    char ans;

    // A running stream until a dot comes
    char ch;
    while (1)
    {
        cin >> ch;
        if (ch == '.')
        {
            break;
        }

        // logic
        q.push(ch);
        freq[ch - 'a']++;
        //Continuously pop elements while we get element whose freq is 1
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << q.front() << endl;
        }
    }
}