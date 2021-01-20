#include <iostream>
#include <climits>
using namespace std;

int find_max_sum_in_window(int a[], int n, int k)
{
    int sum = 0;
    int maxSum = INT_MIN;

    int i = 0; //starting of window
    int j;     // j -> ending of window
    for (j = 0; j < 3; j++)
    {
        sum = sum + a[j];
    } //sum of k window

    maxSum = max(maxSum, sum);

    while (j < n)
    {
        sum = sum + a[j];
        j++;
        sum = sum - a[i];
        i++;
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k = 3;
    cout << find_max_sum_in_window(a, n, k);
}