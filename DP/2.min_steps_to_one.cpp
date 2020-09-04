#include <iostream>
#include <climits>
using namespace std;

// Top Down
int min_steps(int n, int dp[])
{
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 2 == 0)
    {
        op1 = min_steps(n / 2, dp);
    }
    if (n % 3 == 0)
    {
        op2 = min_steps(n / 3, dp);
    }
    op3 = min_steps(n - 1, dp);
    int ans = min(op1, min(op2, op3)) + 1;
    return dp[n] = ans;
}

// Bottom UP
int min_steps_bottom_up(int n)
{
    int dp[] = {0};
    int op1, op2, op3;

    for (int i = 2; i <= n; i++)
    {
        op1 = op2 = op3 = INT_MAX;
        if (i % 2 == 0)
        {
            op1 = dp[i / 2];
        }
        if (i % 3 == 0)
        {
            op2 = dp[i / 3];
        }
        op3 = dp[i - 1];
        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << min_steps(n, dp);
}