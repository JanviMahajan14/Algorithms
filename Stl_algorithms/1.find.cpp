#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int key;
    int n = 4;
    int arr[10] = {11,34,78,2};
    cin >> key;

    // Find returns an address works on linear search
    auto it = find(arr, arr+n, key);

    // To get the index subtract add from the base add:  address = arr + index
    int index = it - arr;

    if(index == n){
        cout << "No such element found";
    }

    else{
        cout << index;
    }


}