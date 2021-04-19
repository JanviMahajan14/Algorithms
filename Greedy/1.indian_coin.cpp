#include <iostream>
#include <algorithm>
using namespace std;

void find_ans(int coins[], int n, int money)
{
    while (money != 0)
    {
        int idx = upper_bound(coins, coins + n, money) - coins - 1;
        cout << coins[idx] << " ";
        money = money - coins[idx];
    }
    //complexity: O(money*logn)
}

int main()
{
    int money;
    cin >> money;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    find_ans(coins, n, money);
}