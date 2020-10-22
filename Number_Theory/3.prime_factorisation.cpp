#include <iostream>
#include <vector>
using namespace std;

void find_prime_factors(int n)
{

    // Time complexity O(n)

    // IN worst case the outher loop will run n times and inner loop just one time so
    //  complexity is O(n). Other possible case is outher loop runs 1 and inner loop
    // log(n) times. But N > logN. So time complexity O(n)

    // for (int i = 2; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         while (n % i == 0)
    //         {
    //             n = n / i;
    //         }
    //         cout << i << " ";
    //     }
    // }

    // Time complexity O(sqrt(n))
    vector<pair<int, int>> p;
    for (int i = 2; i * i <= n; i++)
    {
        int cnt = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n = n / i;
                cnt++;
            }
            p.push_back(make_pair(i, cnt));
        }
    }

    if (n != 1)
    {
        p.push_back(make_pair(n, 1));
    }

    for (auto x : p)
    {
        cout << x.first << "^" << x.second << endl;
    }
}

void prime_sieve(int *p, int n)
{

    // mark all the relevant numbers as prime
    for (int i = 3; i <= n; i = i + 2)
    {
        p[i] = 1;
    }

    // mark all the multiples of nos from 3 as 0
    for (int i = 3; i <= n; i = i + 2)
    {
        if (p[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                p[j] = 0;
            }
        }
        // or less optimised way
        // for(int j=2*i; j<n; j=j+i){
        //     p[j]=0;
        // }
    }

    // mark all the even nos as not prime
    for (int i = 2; i < n; i = i + 2)
    {
        p[i] = 0;
    }

    // Special case
    p[2] = 1;
    p[0] = p[1] = 0;
}

// Time complexity : O(logn)
void prime_factors_seive(int n, vector<int> &p)
{
    vector<int> factors;

    for (int i = 0; p[i] * p[i] <= n; i++)
    {
        if (n % p[i] == 0)
        {
            while (n % p[i] == 0)
            {
                n = n / p[i];
            }
            factors.push_back(p[i]);
        }
    }

    if (n != 1)
    {
        factors.push_back(n);
    }

    for (auto x : factors)
    {
        cout << x << " ";
    }
}

void count_divisors(int n, vector<int> p)
{
    int ans = 1;
    for (int i = 0; p[i] * p[i] <= n; i++)
    {
        int cnt = 0;
        if (n % p[i] == 0)
        {
            while (n % p[i] == 0)
            {
                n = n / p[i];
                cnt++;
            }
            ans = ans * (cnt + 1);
        }
    }

    if (n != 1)
    {
        ans = ans * 2; //because power of prime number is 1 and we to mul with (q+1)
    }

    cout << endl
         << ans;
}

int main()
{
    int n;
    cin >> n;
    // find_prime_factors(n);
    int *p = new int[n + 1];

    prime_sieve(p, n);

    vector<int> primes; //will include all prime numbers till n
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            primes.push_back(i);
        }
    }

    prime_factors_seive(n, primes);
    count_divisors(n, primes);
}