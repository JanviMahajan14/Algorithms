#include <iostream>
using namespace std;

int subset(int a[], int n, int sum, int **dp)
{
    if (sum == 0)
    {
        return dp[n][sum] = 1; //In case of empty set
    }
    if (n == 0)
    {
        return dp[n][sum] = 0; //sum can't be obtained
    }
    if (dp[n][sum] != 2)
    {
        return dp[n][sum];
    }

    if (a[n - 1] <= sum)
    {
        int op1 = subset(a, n - 1, sum - a[n - 1], dp);
        int op2 = subset(a, n - 1, sum, dp);
        return dp[n][sum] = op1 || op2;
        // For finding count of subsets equal to given num return dp[n][sum] = op1+op2;
    }
    else
    {
        return dp[n][sum] = subset(a, n - 1, sum, dp);
    }
}

int main()
{
    int a[] = {3, 34, 2};
    int sum = 5;

    int **dp = new int *[4];
    for (int i = 0; i <= 3; i++)
    {
        dp[i] = new int[sum + 1];
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = 2;
        }
    }
    subset(a, 3, sum, dp);

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}