#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1] = {0};
        string name;
        int rank;

        for (int i = 0; i < n; i++)
        {
            cin >> name >> rank;
            arr[rank]++;
        }

        int sum = 0;
        int actual_rank = 1;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                sum += abs(actual_rank - i);
                actual_rank++;
                arr[i]--;
            }
        }
        cout << sum << endl;
    }
}