#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long int kadane(vector<long long int> arr, long long int n)
{
    if (*max_element(arr.begin(), arr.end()) < 0)
    {
        return *max_element(arr.begin(), arr.end());
    }

    long long int sum = 0;
    long long int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    return ans;
}

long long sum_arr(vector<long long int> arr, int n)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long int> arr;
        arr.reserve(n);

        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }

        if (k == 1)
        {
            cout << kadane(arr, n) << endl;
        }

        else if (sum_arr(arr, n) < 0)
        {
            for (int i = 0; i < n; i++)
            {
                arr.push_back(arr[i]);
            }
            cout << kadane(arr, 2 * n) << endl;
        }

        else
        {
            for (int i = 0; i < n; i++)
            {
                arr.push_back(arr[i]);
            }
            cout << kadane(arr, 2 * n) + (k - 2) * sum_arr(arr, n) << endl;
        }
    }
}