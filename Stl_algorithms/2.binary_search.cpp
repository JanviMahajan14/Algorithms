#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int key, n=7;
    cin >> key;
    int arr[10] = {10,23,40,40,40,67,89};

    // Using binary_search in sorted arrary
    bool res = binary_search(arr,arr+n,key);
    cout << res << endl;

    // To get a lower_bound return >=
    auto it = lower_bound(arr,arr+n,40);
    int index = it - arr;
    cout << "Lower bound " << index << endl;

    // To get a upper_bound return >s
    auto iter = upper_bound(arr,arr+n,40);
    int upper_index = iter - arr;
    cout << "Lower bound " << upper_index << endl;

    // Frequncy is 
    cout << upper_index - index << endl;


}