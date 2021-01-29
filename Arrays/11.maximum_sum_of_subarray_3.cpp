// Kadane's algorithm: O(n)

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Best solution ----TECHDOSE
int kadane(int arr[], int n)
{
    // finding max subarray sum
    int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum < arr[i])
        {
            sum = arr[i];
        }
        ans = max(ans, sum);
    }
    return ans;
}

int length_max_subarray(int arr[], int n)
{
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = INT_MIN;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        right = i;
        if (sum < arr[i])
        {
            sum = arr[i];
            left = i;
        }
        if (sum > maxSum)
        {
            maxSum = sum;
            ans = right - left + 1; // finding length of subarray when we get max subarray
        }
    }
    return ans;
}

int main()
{
    int n, maxSum = INT_MIN;
    cin >> n;
    int a[n], countSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << kadane(a, n);
    cout << "\n"
         << length_max_subarray(a, n);
    // In case all the elements are negative then res is max element else run kadane's
    // if (*max_element(a, a + n) < 0)
    // {
    //     cout << *max_element(a, a + n) << endl;
    // }

    // // There is some modification regarding how will we find length of maxSubarray sum
    // // Keep three variables start, end, s;
    // else
    // {
    //     int start = 0, end = 0, s = 0;
    //     // Kadane's algo
    //     for (int i = 0; i < n; i++)
    //     {
    //         countSum = countSum + a[i];
    //         if (countSum < 0)
    //         {
    //             countSum = 0;
    //             s = i + 1; //Holds the value of new possible start
    //         }
    //         if (countSum > maxSum)
    //         {
    //             maxSum = countSum;
    //             start = s;
    //             end = i;
    //         }
    //     }
    //     cout << maxSum << endl;
    //     cout << end - start + 1;
    // }
}