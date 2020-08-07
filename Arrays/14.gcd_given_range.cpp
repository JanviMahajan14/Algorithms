#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    gcd(b, a % b); //Euclid's algo;
    // Brute force checkby divinding each no from 1 to min(a, b);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i, j;
    cin >> i >> j;

    int ans = 0;
    for (int x = i; x <= j; x++)
    {
        ans = gcd(ans, a[x]);
    }
    cout << ans;
}