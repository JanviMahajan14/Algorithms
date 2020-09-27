#include <iostream>
#include <climits>
using namespace std;

int solve_matrix(int a[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempans = solve_matrix(a, i, k) + solve_matrix(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        ans = min(ans, tempans);
    }

    return ans;
}

int main()
{
    int a[] = {1,
               2,
               3,
               4,
               3};
    int n = sizeof(a) / sizeof(int);
    cout << solve_matrix(a, 1, n - 1);
}