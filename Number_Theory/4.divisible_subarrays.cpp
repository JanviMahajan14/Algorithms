//See qs from youtube

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int freq[n] = {0}; //It can have n possible values 0,1,2,3,4.....n-1
    freq[0] = 1;       //Because of null subarrays

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        sum = (sum % n + n) % n; //Using property
        freq[sum]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int m = freq[i];
        ans += (m) * (m - 1) / 2; //Formula for mc2
    }
    cout << ans << endl;
}
