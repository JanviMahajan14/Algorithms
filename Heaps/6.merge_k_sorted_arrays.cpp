#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int value;
    int array_index;
    int element_index;

    node(int v, int a, int e)
    {
        value = v;
        array_index = a;
        element_index = e;
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

vector<int> merge_K_sorted_array(vector<vector<int>> arr)
{
    int n = arr.size();
    priority_queue<node, vector<node>, Nodecompare> pq;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        node element(arr[i][0], i, 0);
        pq.push(element); //push the first element of all arrays
    }

    while (!pq.empty())
    {
        node element = pq.top();
        int y = element.element_index;
        int x = element.array_index;

        result.push_back(element.value);
        pq.pop();
        y++;

        if (y < arr[x].size())
        {
            node new_element(arr[x][y], x, y);
            pq.push(new_element);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> arr{{2, 4, 5, 9},
                            {23, 78, 100},
                            {4, 6, 20},
                            {2, 5}};

    vector<int> v = merge_K_sorted_array(arr);
    for (auto it : v)
    {
        cout << it << " ";
    }
}