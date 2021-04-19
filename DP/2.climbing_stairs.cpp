#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    int dp[n];
    dp[n] = 0; //n se n tak ke moves 0

    for (int i = n - 1; i >= 0; i--)
    {
        int ans = INT_MAX;
        for (int j = 1; j <= arr[i] && i + j <= n; j++)
        {
            if (arr[i + j] == 0) //we can't take dp[i]=0 because dp[n]=0
                continue;
            ans = min(ans, dp[j + i]);
        }

        if (arr[i] == 0)
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = ans + 1;
    }
    cout << dp[0];
}