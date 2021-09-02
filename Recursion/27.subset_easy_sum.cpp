// got stuck because we can't consider null
// Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets.
// He has to find whether if the sum of any of the non-empty subsets of the set A is zero.
// testcase :
// 1
// 4 1 3 2 - 3
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_subset(int a[], int i, int n, int cnt, int num)
{
    // cnt -for storing the sum , num-for checking no of numbers we have traversed!
    if ((i == n) || (cnt == 0 && num > 0))
    {
        if (cnt == 0 && num > 0)
        {
            return true;
        }
        return false;
    }

    bool op1 = check_subset(a, i + 1, n, cnt + a[i], num + 1);
    bool op2 = check_subset(a, i + 1, n, cnt, num);

    if (op1 || op2)
    {
        return true;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool res = check_subset(a, 0, n, 0, 0);
        if (res)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No";
        }
    }
}