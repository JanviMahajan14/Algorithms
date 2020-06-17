#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    //init
    list<int> l1{1, 2, 3};
    list<string> l2{"apple", "mango", "gauva"};
    l2.push_back("pineapple"); //inserts a tail

    // Sort
    l2.sort();

    // Reverse
    l2.reverse();

    // pop_front()
    l2.pop_front();

    // push_front
    l2.push_front("kiwi");

    // iterate over the list
    for (auto it = l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }

    l2.push_back("orange");
    l2.push_back("gauva");

    // Remove all occurences
    l2.remove("gauva");

    cout << endl;
    for (auto s : l2)
    {
        cout << s << "->";
    }
}