#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Passing fn as a parameter to another fn
bool compare(long long int a, long long int b)
{
    return a < b;
}

void bubble_sort(long long int a[], int n, bool (&cmp)(long long int a, long long int b))
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble_sort(a, n, compare);
}