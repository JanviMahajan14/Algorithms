#include <iostream>
#include <climits>
using namespace std;

int find_min_round(int a[], int n, int sum)
{
    if (sum % n != 0)
    {
        return -1;
    }

    int each_load = sum / n;
    int ans = INT_MIN;
    int cumm_sum = 0;

    //O(n)approach
    for (int i = 0; i <= n - 2; i++)
    {
        cumm_sum = cumm_sum + a[i]; //sum of partition from o to i-1;
        ans = max(ans, abs((i + 1) * each_load - cumm_sum));
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }

    cout << find_min_round(a, n, sum);
}