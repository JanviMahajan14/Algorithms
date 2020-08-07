#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    Hashmap<int> h;
    h.insert("Burger", 120);
    h.insert("Pepsi", 20);
    h.insert("Pizza", 150);
    h.insert("Noodles", 25);
    h.insert("Coke", 40);

    h.print();

    int *res = h.search("Noodles");
    if (res == NULL)
    {
        cout << "Not found ";
    }
    else
    {
        cout << *res;
    }
    h.erase("Noodles");
    h.print();

    h["dosa"] = 60;
    h["dosa"] += 10;
    cout << "Price of dosa" << h["dosa"];
    h.print();
}