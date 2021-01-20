#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    unordered_map<int, int> m; //for cumm_sum and index storage
    int ans = INT_MIN;
    int sum = 0;

    for (int j = 0; j < N; j++)
    {
        sum = sum + A[j];
        if (!m.count(sum))
        {
            m[sum] = j;
        }

        if (sum == K)
        {
            ans = max(ans, j + 1);
        }

        int val = sum - K;
        if (m.count(val))
        {
            ans = max(ans, j - m[val]);
        }
    }

    if (ans == INT_MIN)
        return 0;
    return ans;
}