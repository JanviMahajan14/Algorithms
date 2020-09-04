#include <iostream>
#include <climits>
using namespace std;

int min_coins(int n, int coins[], int len, int dp[])
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (n - coins[i] >= 0)
        {
            int sol = min_coins(n - coins[i], coins, len, dp);
            ans = min(ans, sol);
        }
    }

    dp[n] = ans + 1;
    return dp[n];
}

// bottom up
int finding_min_coins(int n, int coins[], int len)
{
    int dp[n] = {0};
    dp[0] = 0;

    int solution, ans;
    for (int i = 1; i <= n; i++)
    {
        ans = INT_MAX;
        for (int j = 0; j < len; j++)
        {
            if (i - coins[j] >= 0)
            {
                solution = i - coins[j];
                ans = min(ans, dp[solution]);
            }
        }
        dp[i] = ans + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int coins[] = {1, 7, 10};
    int len = 3;
    int dp[100] = {0};
    // cout << min_coins(n, coins, len, dp);
    cout << finding_min_coins(n, coins, len);
}