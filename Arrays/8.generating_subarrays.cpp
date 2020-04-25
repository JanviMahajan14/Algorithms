// Finding all the subarays of an array: Time complexity O(n^3)

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}