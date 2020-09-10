#include <iostream>
#include <set>
using namespace std;

int main()
{
    // That can store multiple elements
    // Stored in a sorted order
    // once inserted can't be modified
    // Underlying implementation is BST: O(logn)
    // associative container-- elements are referred by `values` and not by `index`

    int arr[] = {10, 20, 30, 20, 10, 10};
    multiset<int> m(arr, arr + 6);

    m.erase(20); //All occurences of 20 are erased
    for (auto x : m)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << m.count(10) << endl; //finding frequency of 10

    // LB >= and UB >
    // Een if = exists LB gives first possible element which satisfies the conditon >=
    for (auto it = m.lower_bound(10); it != m.upper_bound(30); it++)
    {
        cout << *it << " ";
    }
}