#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int idx) //for forming max heap
{
    int min_idx = idx;
    int left = 2 * idx;
    int right = (2 * idx) + 1;

    if (left < v.size() && v[left] > v[min_idx])
    {
        min_idx = left;
    }
    if (right < v.size() && v[right] > v[min_idx])
    {
        min_idx = right;
    }
    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

//O(n)
void optimisedbuildHeap(vector<int> &t)
{
    for (int i = t.size() / 2; i >= 1; i--)
    {
        heapify(t, i);
    }
}

void sortwalaheapify(vector<int> &v, int idx, int n) //for forming max heap
{
    int min_idx = idx;
    int left = 2 * idx;
    int right = (2 * idx) + 1;

    if (left < n && v[left] > v[min_idx])
    {
        min_idx = left;
    }
    if (right < n && v[right] > v[min_idx])
    {
        min_idx = right;
    }
    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        sortwalaheapify(v, min_idx, n);
    }
}

void heapsort(vector<int> &t)
{

    optimisedbuildHeap(t); //building a heap O(n)
    int n = t.size();
    while (n > 1)
    {
        swap(t[1], t[n - 1]);
        n--;
        sortwalaheapify(t, 1, n); //O(logn)
    }
    //O(nlogn)

    for (int i = 1; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }
}

int main()
{
    vector<int> t{
        -1,
        10,
        20,
        5,
        6,
        1,
        8,
        9, 4};
    // optimisedbuildHeap(t);
    // for (auto it = t.begin(); it != t.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    heapsort(t);
}
