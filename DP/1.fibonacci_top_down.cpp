#include <iostream>
using namespace std;

// Space and time: O(n)
int fib(int n, int dp[])
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = fib(n - 1, dp) + fib(n - 2, dp);
    dp[n] = ans;
    return ans;
}

// Bottom up approach
// Time : O(n) && Space O(n) because of extra array
int fibonacci(int n)
{
    int dp[100] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Bottom up with Optimised space O(1) && Time O(n)
int FastSpacefibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << fib(n, dp);
}