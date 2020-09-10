#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Set internal implementation is BST/red-black-tree
    // Complexity of all operations is O(logn)
    // Stores unique elements
    // once inserted can't be modified
    set<int> s;
    int arr[] = {2, 4, 8, 9, 1, 9};
    for (int i = 0; i <= 5; i++)
    {
        s.insert(arr[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << " ";
    }
}
