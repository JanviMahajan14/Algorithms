// Given the largest number in the string = n (input). We need to form a max possible num
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    int a[n];
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = i;
    }

    int largest = n;
    for (int i = 0; i < n && k > 0; i++)
    {
        if (a[i] != largest)
        {
            m[a[i]] = m[largest];
            swap(a[i], a[m[largest]]);
            k--;
        }
        largest--;
    }

    for (auto x : a)
    {
        cout << x << " ";
    }
}
