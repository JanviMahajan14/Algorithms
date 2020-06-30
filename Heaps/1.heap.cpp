#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    void heapify(int idx)
    {
        int min_idx = idx;
        int left = 2 * idx;
        int right = (2 * idx) + 1;

        if (left < v.size() && compare(v[left], v[min_idx]))
        {
            min_idx = left;
        }
        if (right < v.size() && compare(v[right], v[min_idx]))
        {
            min_idx = right;
        }
        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    vector<int> v;
    bool minheap;

    bool compare(int a, int b)
    {
        if (minheap)
        {
            return a < b;
        }
        return a > b;
    }

    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minheap = type;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        //idx is not root
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx / 2;
        }
    }

    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    int get()
    {
        return v[1];
    }

    int empty()
    {
        return v.size();
    }
};

// O(nlogn)
void buildHeap(vector<int> &t)
{
    for (int i = 2; i < t.size(); i++)
    {
        int idx = i;
        int parent = i / 2;
        while (idx > 1 && t[idx] > t[parent]) //implementing max_heap
        {
            swap(t[idx], t[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

int main()
{
    // Heap h(9, false);
    // int data;
    // cin >> data;
    // while (data != -1)
    // {
    //     h.push(data);
    //     cin >> data;
    // }
    // while (h.empty() != 1)
    // {
    //     cout << h.get() << " ";
    //     h.pop();
    // }

    vector<int> t{-1, 5, 7, 2, 10, 17, 67};
    buildHeap(t);
    for (auto it = t.begin(); it != t.end(); it++)
    {
        cout << *it << " ";
    }
}