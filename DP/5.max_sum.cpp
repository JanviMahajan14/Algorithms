#include <iostream>
using namespace std;

int max_subarray_sum(int a[], int n)
{
    int i = 0;
    int dp[n] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int max_ans = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_ans = max(max_ans, dp[i]);
    }
    return max_ans;
}

// FOR space optimised version check KADANE's algorithm

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_subarray_sum(a, n);
}