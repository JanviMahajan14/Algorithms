#include <iostream>
using namespace std;

int find_no_of_ways(int n, int k, int dp[])
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = n - 1; i >= n - k && i >= 0; i--)
    {
        ans = ans + find_no_of_ways(i, k, dp);
    }
    return dp[n] = ans;
}

// Bottom up approach
int finding_ways(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = i - 1; j >= i - k && j >= 0; j--)
        {
            ans += dp[j];
        }
        dp[i] = ans;
    }
    return dp[n];
}

// Optimised BOTTOM UP
int fast_finding_ways(int n, int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;

    // Using slidng window technique
    for (int i = 2; i <= n; i++)
    {
        if (i - k - 1 < 0)
        {
            dp[i] = 2 * dp[i - 1];
        }
        else
        {
            dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};
    // cout << find_no_of_ways(n, k, dp);
    cout << fast_finding_ways(n, k);
}