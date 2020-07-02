#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int value;
    int i;
    int j;

    node(int v, int i_idx, int j_idx)
    {
        value = v;
        i = i_idx;
        j = j_idx;
    }
};

class Nodecompare
{
public:
    bool operator()(node A, node B)
    {
        return A.value > B.value;
    }
};

int find_kth_smallest(vector<vector<int>> arr, int k, int size)
{
    int cnt = 0, res;
    priority_queue<node, vector<node>, Nodecompare> pq;
    node element(arr[0][0], 0, 0);
    pq.push(element);

    while (cnt != k)
    {
        res = pq.top().value;
        int i = pq.top().i;
        int j = pq.top().j;
        cnt++;
        if (j + 1 < size && arr[i][j + 1] != -1)
        {
            node one(arr[i][j + 1], i, j + 1);
            pq.push(one);
            arr[i][j + 1] = -1;
        }
        if (i + 1 < size && arr[i + 1][j] != -1)
        {
            node two(arr[i + 1][j], i + 1, j);
            pq.push(two);
            arr[i + 1][j] = -1;
        }
        pq.pop();
    }

    return res;
}

int main()
{
    vector<vector<int>> arr{{10, 20, 30, 40},
                            {15, 25, 35, 48},
                            {24, 29, 37, 48},
                            {32, 33, 39, 50}};

    int k;
    cin >> k;
    cout << find_kth_smallest(arr, k, 4);
}