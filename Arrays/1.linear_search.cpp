#include <iostream>
using namespace std;

int main(){
    int n, key, i;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> key;
    for(i=0; i<n; i++){
        if(a[i] == key){
            cout << "Element at index " << i << endl;
            break;
        }
    }
    if(i == n){
        cout << "No such element present";
    }
}