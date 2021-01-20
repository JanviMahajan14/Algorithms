#include <iostream>
#include <list>
using namespace std;

void find_max_in_subarray_k(int a[], int n, int k)
{
    list<int> l;
    int i = 0;
    int j;
    for (j = 0; j < k; j++)
    {
        if (l.empty())
        {
            l.push_back(j);
        }
        else
        {
            while (!l.empty() && a[l.back()] < a[j])
            {
                l.pop_back();
            }
            l.push_back(j);
        }
    }
    cout << a[l.front()] << " ";

    while (j < n)
    {
        while (!l.empty() && a[l.back()] < a[j])
        {
            l.pop_back();
        }
        l.push_back(j);

        if (l.front() == i)
        {
            l.pop_front();
        }

        cout << a[l.front()] << " ";
        i++;
        j++;
    }
}

int main()
{

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    find_max_in_subarray_k(a, n, k);
}