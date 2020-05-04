#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);

    // Rotation of array around index 2
    rotate(arr,arr+2,arr+n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Rotation of array around index 4
    rotate(arr,arr+4,arr+n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Getting next permuation
    int a[] = {1,2,3};
    next_permutation(a,a+3);
    for(int i=0; i<3; i++){
        cout << a[i] << " ";
    }


    // Reversing only the first four elements of array
    reverse(arr,arr+4);
    cout << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    // We can perform all this operations on vectors also by using v.begin(),v.end()

}